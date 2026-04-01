#include "input_handler.h"
#include "atom_launcher.h"

#include<imgui.h>
#include<backends/imgui_impl_glfw.h>
#include<backends/imgui_impl_opengl3.h>

void InputHandler::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods){
    AtomLauncher* app = static_cast<AtomLauncher*>(glfwGetWindowUserPointer(window));
    if(app) {
        app->onKeyEvent(key, scancode, action, mods);
    }
}

void InputHandler::mouse_button_callback(GLFWwindow* window, int button, int action, int mods){
    ImGuiIO& io = ImGui::GetIO();
    if (io.WantCaptureMouse){
        return;
    }

    AtomLauncher* app = static_cast<AtomLauncher*>(glfwGetWindowUserPointer(window));
    if(app) {
        app->onMouseButton(button, action, mods);
    }
}

void InputHandler::cursorPositionCallback(GLFWwindow* window, double xpos, double ypos) {
    AtomLauncher* app = static_cast<AtomLauncher*>(glfwGetWindowUserPointer(window));
    if(app) {
        app->onCursorPosition(xpos, ypos);
    }
}