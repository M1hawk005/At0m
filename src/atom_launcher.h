#ifndef ATOM_LAUNCHER_H
#define ATOM_LAUNCHER_H

#include "atom.h"

#include<cmath>
#include<vector>
#include<iostream>
#include<stdlib.h>
#define GLFW_INCLUDE_NONE
#include<GLFW/glfw3.h> 
#include<glad/glad.h>

class AtomLauncher{
    public:
        AtomLauncher();
        void run();


    private:
        GLFWwindow* m_window;
        void init();

};

#endif //ATOM_LAUNCHER_H