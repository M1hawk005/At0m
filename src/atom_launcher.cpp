#include "atom_launcher.h"
#include "input_handler.h"


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
    
    m_window = glfwCreateWindow(640,480,"At0m",NULL,NULL);

    //Create Window
    if(!m_window){
        std::cerr << "Failed to create window" << std::endl;
        glfwTerminate();
        exit(EXIT_FAILURE);
    }


    glfwMakeContextCurrent(m_window);

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
    
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);

   

}


void AtomLauncher::run(){

    std::vector<GLfloat> vertices= {
        0.5f,  0.5f, 0.0f,  // Top right
        0.5f, -0.5f, 0.0f,  // Bottom right
        -0.5f, -0.5f, 0.0f, // Bottom left
        -0.5f,  0.5f, 0.0f  // Top left 
    };
    
    std::vector<GLuint> indices = {
        0, 1, 3, // First triangle
        1, 2, 3  // Second triangle
    };

    

    GLuint VAO;
    glGenVertexArrays(1,&VAO);
    glBindVertexArray(VAO);
    
    GLuint EBO;
    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size()*sizeof(GLint), indices.data(), GL_STATIC_DRAW);



    GLuint VBO;
    glGenBuffers(1,&VBO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size()*sizeof(float), vertices.data(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3*sizeof(GLfloat), (void*)0);
    glEnableVertexAttribArray(0);
    //vertexShaderSource
    const GLchar *vertexShaderSrc =R"( 
    #version 410 core
    layout(location=0) in vec3 Pos;
    void main(){
        gl_Position = vec4(Pos,1.0);
    })";
    
    GLuint vertexShader= glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSrc, NULL);
    glCompileShader(vertexShader);
    // Check for compilation errors
    GLint success;
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        char infoLog[512];
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cerr << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    const GLchar *fragmentShaderSrc=R"( 
    #version 410 core
    out vec4 FragColor;
    void main(){
        FragColor=vec4(1.0f,0.5f,0.2f,1.0f);
    }
    )";

    GLuint fragmentShader= glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSrc, NULL);
    glCompileShader(fragmentShader);
    // Check for compilation errors
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        char infoLog[512];
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cerr << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    GLuint shaderProgram = glCreateProgram();
    
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);

    glLinkProgram(shaderProgram);
    // Check for linking errors
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        char infoLog[512];
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cerr << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    glBindBuffer(GL_ARRAY_BUFFER, 0);

  // Main rendering loop
    while (!glfwWindowShouldClose(m_window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shaderProgram);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        glfwSwapBuffers(m_window);
        glfwPollEvents();
    } 
 
    double time = glfwGetTime();
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
    glDeleteVertexArrays(1, &VAO);
    glDeleteProgram(shaderProgram);
    glfwDestroyWindow(m_window);

    glfwTerminate();
}