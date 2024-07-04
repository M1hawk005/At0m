#include "input_handler.h"
#include "atom_launcher.h"

void InputHandler::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods){
    if(key==GLFW_KEY_ESCAPE && action==GLFW_PRESS){
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
}