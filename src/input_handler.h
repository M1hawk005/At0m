#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

struct GLFWwindow;

class InputHandler{
    
    public:
        static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
        static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
        static void cursorPositionCallback(GLFWwindow* window, double xpos, double ypos);
};

#endif //INPUT_HANDLER_H