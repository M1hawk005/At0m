#include<cmath>
#include<vector>
#include<iostream>
#include<stdlib.h>
#define GLFW_INCLUDE_NONE
#include<GLFW/glfw3.h> 
#include<glad/glad.h>

void error_callback(int error, char const* description){
        fprintf(stderr,"Error: %s\n",description);
    }

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods){
    if(key==GLFW_KEY_ESCAPE && action==GLFW_PRESS){
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
}

int main(void){
    
    glfwSetErrorCallback(error_callback);
    
    //Initialize GLFW
    if(!glfwInit()){
        std::cerr << "Failed to initialize GLFW" << std::endl;
        exit(EXIT_FAILURE);
    }
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,1);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // Use core profile
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE); // Compatibility with macOS
    
    GLFWwindow* window = glfwCreateWindow(640,480,"At0m",NULL,NULL);

    //Create Window
    if(!window){
        std::cerr << "Failed to create window" << std::endl;
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwSetKeyCallback(window, key_callback);

    glfwMakeContextCurrent(window);

    if(!gladLoadGL()){
        std::cerr << "Failed to initialize glad" << std::endl;
        glfwDestroyWindow(window);
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    
    
    std::cout << "OpenGL Version: " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GLSL Version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;

    glfwSwapInterval(1);

    // Set viewport size
    int framebufferWidth, framebufferHeight;
    glfwGetFramebufferSize(window, &framebufferWidth, &framebufferHeight);
    glViewport(0, 0, framebufferWidth, framebufferHeight); 

   // Vertex data for particles
    std::vector<float> particleVertices;
    int numParticles = 1000; // Number of particles
    float particleSize = 5.0f; // Size of each particle

    for (int i = 0; i < numParticles; ++i) {
        float x = static_cast<float>(rand() % framebufferWidth);
        float y = static_cast<float>(rand() % framebufferHeight);
        particleVertices.push_back(x);
        particleVertices.push_back(y);
    }

    // Create and bind VAO and VBO for particles
    GLuint vao, vbo;
    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);

    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, particleVertices.size() * sizeof(float), particleVertices.data(), GL_STATIC_DRAW);

    // Specify vertex attribute pointers
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // Unbind VAO and VBO
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    // Main rendering loop
    while (!glfwWindowShouldClose(window)) {
        // Process events
        glfwPollEvents();

        // Clear the screen
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Use a simple shader program to render particles (shader setup omitted for brevity)

        // Bind VAO for particles
        glBindVertexArray(vao);

        // Draw particles
        glDrawArrays(GL_POINTS, 0, numParticles);

        // Unbind VAO
        glBindVertexArray(0);

        // Swap buffers
        glfwSwapBuffers(window);
    } 
 
    double time = glfwGetTime();
    glfwDestroyWindow(window);

    glfwTerminate();
    return 0;
}