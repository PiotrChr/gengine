#pragma once

#include "../../DEFINITIONS.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "../gfx/window/Window.hpp"
#include "../gfx/device/Device.hpp"
#include "../gfx/swapChain/SwapChain.hpp"


namespace Gengine {
    class WindowManager {
    public:
        WindowManager(): window() {};
        ~WindowManager() {};
        
        void init();
        void cleanup();

        void setTitle(std::string title);
        void changeMode();
        void setFullscreen(bool fullscreen);
        void setResolution(std::string resolution, bool fullscreen = false);
        Window& getWindow();
        GLFWwindow* getGLFWWindow();
        
        std::string getResolution();
        std::map<std::string, VkExtent2D> getVideoModes();
        bool isOpen();

        static std::string extentToString(VkExtent2D extent);
        static VkExtent2D stringToExtent(std::string extent);

        bool isFullscreen;
        bool isVsync;
        int antialiasing;
        int framerate;
        std::string resolution;
        int width;
        int height;
    private:
        Window* window;
        Device* device;
        SwapChain* swapChain;
        std::string title;
        std::map<std::string, VkExtent2D> _videoModes;
    };
}
