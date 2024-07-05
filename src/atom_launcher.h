#ifndef ATOM_LAUNCHER_H
#define ATOM_LAUNCHER_H

#include "atom.h"
#define GLFW_INCLUDE_NONE
#include<glad/glad.h>
#include<GLFW/glfw3.h> 


class AtomLauncher{
    public:
        AtomLauncher();
        void run();


    private:
        GLFWwindow* m_window;
        void init();

};

#endif //ATOM_LAUNCHER_H