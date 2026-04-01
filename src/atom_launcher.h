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

        void onKeyEvent(int key, int scancode, int action, int mods);
        void onMouseButton(int button, int action, int mods);
        void onCursorPosition(double xpos, double ypos);


    private:
        GLFWwindow* m_window;
        void init();
        void updateVBO(std::vector<Atom>& atoms, GLuint VBO);
        bool m_inputMode;
        
        bool m_addAtomQueued;
        float m_mouseX;
        float m_mouseY;
};

#endif //ATOM_LAUNCHER_H