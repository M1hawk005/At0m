#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <glad/glad.h>

class Shader{
    public:
        Shader(const std::string& vertexPath, const std::string& fragmentPath);
        GLuint getProgram() const;
    private:

        GLuint m_shaderProgram; 
        std::string loadShaderSource(const std::string& filename);
        GLuint compileShader(GLenum shaderType, const std::string& source);
        GLuint createShaderProgram(GLuint vertexShader, GLuint fragmentShader);
};


#endif //SHADER_H