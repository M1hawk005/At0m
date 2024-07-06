#ifndef ATOM_LAUNCHER_H
#define ATOM_LAUNCHER_H

#include "atom.h"
#define GLFW_INCLUDE_NONE
#include<glad/glad.h>
#include<GLFW/glfw3.h> 
#include<vector>
#include<mutex>

class AtomLauncher{
    public:
        AtomLauncher();
        void run();


    private:
        GLFWwindow* m_window;
        void init();
        void updateVBO(std::vector<Atom>& atoms, GLuint VBO);

};

#endif //ATOM_LAUNCHER_H