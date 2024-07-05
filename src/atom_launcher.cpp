#include "atom_launcher.h"
#include "input_handler.h"
#include "shader/shader.h"
#include<cmath>
#include<vector>
#include<iostream>
#include<stdlib.h>


#include<imgui.h>
#include<backends/imgui_impl_glfw.h>
#include<backends/imgui_impl_opengl3.h>

void errorCallback(int error, char const* description){
        fprintf(stderr,"Error: %s\n",description);
    }


AtomLauncher::AtomLauncher(){
    init();
}



void AtomLauncher::init(){

    glfwSetErrorCallback(errorCallback);
    //Initialize GLFW
    if(!glfwInit()){
        std::cerr << "Failed to initialize GLFW" << std::endl;
        exit(EXIT_FAILURE);
    }

    //glfw hints 
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,1);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // Use core profile
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE); // Compatibility with macOS
    
    m_window = glfwCreateWindow(1920,1200,"At0m",NULL,NULL);
    
    
    
    //Create Window
    if(!m_window){
        std::cerr << "Failed to create window" << std::endl;
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(m_window);
    // Setup Dear ImGui context 
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();

    // Setup Platform/Renderer backends
    ImGui_ImplGlfw_InitForOpenGL(m_window, true);
    ImGui_ImplOpenGL3_Init("#version 410");


    if(!gladLoadGL()){
        std::cerr << "Failed to initialize glad" << std::endl;
        glfwDestroyWindow(m_window);
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    
    
    std::cout << "OpenGL Version: " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GLSL Version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;

    glfwSetKeyCallback(m_window, InputHandler::keyCallback);

    glfwSwapInterval(1);

    // Set viewport size
    int framebufferWidth, framebufferHeight;
    glfwGetFramebufferSize(m_window, &framebufferWidth, &framebufferHeight);
    glViewport(0, 0, framebufferWidth, framebufferHeight); 
    
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

   

}


void AtomLauncher::run(){

    std::vector<Atom> atoms; 

    atoms.emplace_back(std::array<float, 3>{0.0f, 0.0f, 0.0f}, std::array<float, 3>{1.0f, 0.0f, 0.0f}); // Red atom at center
    atoms.emplace_back(std::array<float, 3>{0.9f, 0.9f, 0.0f}, std::array<float, 3>{0.0f, 1.0f, 0.0f}); // Green atom at top-right

    GLuint VAO, VBO;
    glGenVertexArrays(1,&VAO);
    glGenBuffers(1,&VBO);


    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    std::vector<float> buffer;
    for (const auto& atom : atoms) {
        const auto& pos = atom.getPosition();
        const auto& col = atom.getColor();
        buffer.insert(buffer.end(), pos.begin(), pos.end());
        buffer.insert(buffer.end(), col.begin(), col.end());
    }

    glBufferData(GL_ARRAY_BUFFER, buffer.size() * sizeof(float), buffer.data(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    Shader shader("../src/shader/vertex_shader.glsl", "../src/shader/fragment_shader.glsl");
    GLuint shaderProgram= shader.getProgram();
    glBindBuffer(GL_ARRAY_BUFFER, 0);

  // Main rendering loop
    while (!glfwWindowShouldClose(m_window)) {
       
        // Start the Dear ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        // Your ImGui windows and controls go here
        ImGui::Begin("Hello, world!");
        ImGui::Text("This is some useful text.");
        ImGui::End();

        // Rendering
        ImGui::Render();
        // int display_w, display_h;
        // glfwGetFramebufferSize(m_window, &display_w, &display_h);
        // glViewport(0, 0, display_w, display_h);
        glClear(GL_COLOR_BUFFER_BIT);

        // Your OpenGL rendering code goes here
        glUseProgram(shaderProgram);
        glPointSize(10.0f); // Make the points larger so they're easier to see
        glDrawArrays(GL_POINTS, 0, atoms.size());
        
        
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());


        glfwSwapBuffers(m_window);
        glfwPollEvents();
    } 
 
    double time = glfwGetTime();
    glDeleteBuffers(1, &VBO);
    glDeleteVertexArrays(1, &VAO);
    glDeleteProgram(shaderProgram);
    glfwDestroyWindow(m_window);

    glfwTerminate();
}