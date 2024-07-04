#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

struct GLFWwindow;

class InputHandler{
    
    public:
        static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
};

#endif //INPUT_HANDLER_H