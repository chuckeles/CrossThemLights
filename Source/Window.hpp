#pragma once

#include <string>
#include <memory>

#include "Singleton.hpp"


/**
 * GLFW window wrapper.
 */


class GLFWwindow;


class Window : public Singleton<Window> {

public:

    static std::shared_ptr<Window> Create(unsigned int width, unsigned int height, std::string title,
                                          bool fullscreen = false);

    static std::shared_ptr<Window> CreateHidden();

    void SwapBuffers();
    void PollEvents();
    void Close();

    void GetSize(int &width, int &height) const;
    bool IsClosed() const;

    GLFWwindow *GetInternalPtr() const; // TODO: Refactor code so this is not necessary

    ~Window();


private:

    static void PreInit();
    static void PostInit(GLFWwindow* window);

    Window() {};


private:

    GLFWwindow *mGlfwWindow = 0;

};

