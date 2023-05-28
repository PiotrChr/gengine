#include "WindowManager.hpp"

namespace Gengine {
    void WindowManager::setResolution(std::string resolution, bool fullscreen) {    
        this->resolution = resolution;

        VkExtent2D extent = stringToExtent(resolution);
        
        width = extent.width;
        height = extent.height;
        
        if (fullscreen) {
            isFullscreen = true;
        }

        if (window != nullptr) {
            window->setResolution(width, height);
        }
    }

    void WindowManager::setFullscreen(bool fullscreen) {
        isFullscreen = fullscreen;
    }

    void WindowManager::init() {
        window = new Window(width, height, title);
        window->initWindow();

        device = new Device(*window);
        swapChain = new SwapChain(*device, window->getExtent());
    }

    Window& WindowManager::getWindow() {
        return *window;
    }

    GLFWwindow* WindowManager::getGLFWWindow() {
        return window->getWindow();
    }

    void WindowManager::cleanup() {
        
    }

    bool WindowManager::isOpen() {
        return !window->shouldClose();
    }

    void WindowManager::changeMode() {
        // TODO: Implement
    }

    void WindowManager::setTitle(std::string title) {
        this->title = title;
    }

    std::map<std::string, VkExtent2D> WindowManager::getVideoModes() {
        return _videoModes;
    }

    std::string WindowManager::extentToString(VkExtent2D extent) {
        return std::to_string(extent.width) + "x" + std::to_string(extent.height);
    }

    VkExtent2D WindowManager::stringToExtent(std::string extent) {
        std::string _width = "";
        std::string _height = "";
        bool isWidth = true;
        for (int i = 0; i < extent.length(); i++) {
            if (extent[i] == 'x') {
                isWidth = false;
                continue;
            }
            if (isWidth) {
                _width += extent[i];
            }
            else {
                _height += extent[i];
            }
        }
        
        uint32_t w = std::stoul(_width);
        uint32_t h = std::stoul(_height);

        return VkExtent2D{w, h};
    }

    std::string WindowManager::getResolution() {
        return resolution;
    }
}
