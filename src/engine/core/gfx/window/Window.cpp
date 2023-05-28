#include "Window.hpp"

namespace Gengine {
    Window::~Window() {
        glfwDestroyWindow(window);
        glfwTerminate();
    }

    bool Window::shouldClose() {
        return glfwWindowShouldClose(window);
    }

    void Window::setResolution(int width, int height) {
        this->width = width;
        this->height = height;
    }

    void Window::initWindow() {
        glfwInit();

        int major, minor, rev;
        glfwGetVersion(&major, &minor, &rev);
        printf("GLFW Version: %d.%d.%d\n", major, minor, rev);

        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

        window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
    }

    void Window::createWindowSurface(VkInstance instance, VkSurfaceKHR* surface) {
        if (glfwCreateWindowSurface(instance, window, nullptr, surface) != VK_SUCCESS) {
            throw std::runtime_error("Failed to create Vulkan surface.");
        }
    }

}