#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <vulkan/vulkan.h>
#include <GLFW/glfw3native.h>
#include <string>

namespace Gengine {
    class Window {
    public:
        Window(int width, int height, std::string title): width(width), height(height), title(title) {};
        ~Window();

        Window(const Window&) = delete;
        Window& operator=(const Window&) = delete;

        void initWindow();
        GLFWwindow* getWindow() { return window; }
        void setResolution(int width, int height);

        void createWindowSurface(VkInstance instance, VkSurfaceKHR* surface);
        VkExtent2D getExtent() {
            return { static_cast<uint32_t>(width), static_cast<uint32_t>(height) };
        }
        bool shouldClose();
    private:
        int width;
        int height;
        std::string title;
        GLFWwindow* window;
    };    
}

