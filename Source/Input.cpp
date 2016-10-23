#include "Input.hpp"

#include <GLFW/glfw3.h>

#include "Window.hpp"


bool Input::IsKeyPressed(Key key) {
    return glfwGetKey(Window::GetSingleton()->mGlfwWindow, (int) key) == GLFW_PRESS;
}
