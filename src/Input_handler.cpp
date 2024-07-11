#include "input_handler.h"
#include "atom_launcher.h"
#include "util/global.h"

#include<imgui.h>
#include<backends/imgui_impl_glfw.h>
#include<backends/imgui_impl_opengl3.h>

void InputHandler::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods){
    if(key==GLFW_KEY_ESCAPE && action==GLFW_PRESS){
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
}

void InputHandler::mouse_button_callback(GLFWwindow* window, int button, int action, int mods){
    ImGuiIO& io = ImGui::GetIO();
    if (io.WantCaptureMouse){
        return;
    }

    std::lock_guard<std::mutex> lock(mousePositionMutex);
    if(button == GLFW_MOUSE_BUTTON_LEFT){
        if (action == GLFW_PRESS){
            mousePosition.updated= true;
        }
        else if(action == GLFW_RELEASE){
            mousePosition.updated= false;
        }
    }

}

void InputHandler::cursorPositionCallback(GLFWwindow* window, double xpos, double ypos) {
    // std::lock_guard<std::mutex> lock(mousePositionMutex);
    if(mousePosition.updated){
        
        int width, height;
        glfwGetWindowSize(window, &width, &height);
        
        // Convert to OpenGL coordinates
        float x = (float)xpos / width * 2.0f - 1.0f;
        float y = 1.0f - (float)ypos / height * 2.0f;
        mousePosition.x= x;
        mousePosition.y= y;
    }
    
}