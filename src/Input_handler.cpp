#include "input_handler.h"
#include "atom_launcher.h"
#include "util/global.h"

void InputHandler::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods){
    if(key==GLFW_KEY_ESCAPE && action==GLFW_PRESS){
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
}

void InputHandler::mouse_button_callback(GLFWwindow* window, int button, int action, int mods){
      if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
        double xpos, ypos;
        glfwGetCursorPos(window, &xpos, &ypos);
        int width, height;
        glfwGetWindowSize(window, &width, &height);

        // Convert to OpenGL coordinates
        float x = (float)xpos / width * 2.0f - 1.0f;
        float y = 1.0f - (float)ypos / height * 2.0f;
        
        std::lock_guard<std::mutex> lock(clickPositionMutex);
        clickPosition = {x,y};
    }
}