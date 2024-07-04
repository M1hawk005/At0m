#include "shader.h"

#include <iostream>
#include <sstream>
#include <fstream>


Shader::Shader(const std::string& vertexPath, const std::string& fragmentPath){
    std::string vertexCode= loadShaderSource(vertexPath);
    std::string fragmentCode= loadShaderSource(fragmentPath);

    GLuint vertexShader= compileShader(GL_VERTEX_SHADER, vertexCode);
    GLuint fragmentShader= compileShader(GL_FRAGMENT_SHADER, fragmentCode);

    m_shaderProgram= createShaderProgram(vertexShader, fragmentShader);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);



}

std::string Shader::loadShaderSource(const std::string& filename){
    std::ifstream file(filename);
    if(!file.is_open()){
        std::cerr << "Failed to open shader file: " << filename << std::endl;
        return "";
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

GLuint Shader::compileShader(GLenum shaderType, const std::string& source){
    GLuint shader= glCreateShader(shaderType);
    const char* shaderSrc= source.c_str();
    glShaderSource(shader, 1, &shaderSrc, NULL);
    glCompileShader(shader);
    // Check for compilation errors
    GLint success;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        char infoLog[512];
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        std::cerr << "ERROR::" << shaderType << "::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    return shader;
}


GLuint Shader::createShaderProgram(GLuint vertexShader, GLuint fragmentShader){
    GLuint shaderProgram= glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    // Check for linking errors
    GLint success;
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        char infoLog[512];
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cerr << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }
    return shaderProgram;
}

GLuint Shader::getProgram() const {
    return m_shaderProgram;
}
