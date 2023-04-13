#pragma once

#include "../../DEFINITIONS.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <vulkan/vulkan.h>
#include <GLFW/glfw3.h>
#define GLFW_INCLUDE_NONE
#define GLFW_INCLUDE_VULKAN
#if (_IS_MAC)
    #define VK_USE_PLATFORM_MACOS_MVK
#endif

namespace Gengine {
    class WindowManager {
    public:
        WindowManager() {};
        ~WindowManager();
        
        void init(std::string title);
        void initVulkan();
        void cleanupVulkan();
        
        void toggleFullscreen();
        void changeMode();
        void setFullscreen(bool fullscreen);
        void setResolution(std::string resolution, bool fullscreen = false);
        std::string getResolution();
        std::map<std::string, VkExtent2D> getVideoModes();
        bool isOpen();
        GLFWwindow* window;
        bool isFullscreen;
        bool isVsync;
        int antialiasing;
        int framerate;
        std::string resolution;
        int width;
        int height;

        static std::string extentToString(VkExtent2D extent);
        static VkExtent2D stringToExtent(std::string extent);
    private:
        void pickPhysicalDevice();
        void createLogicalDevice();
        void createSwapChain();
        void createInstance();
        bool isDeviceSuitable(VkPhysicalDevice device);
        std::map<std::string, VkExtent2D> _videoModes;
        VkPhysicalDevice _physicalDevice = VK_NULL_HANDLE;
        VkInstance instance;
        // PFN_vkGetInstanceProcAddr vkGetInstanceProcAddr;
        // PFN_vkCreateInstance vkCreateInstance;
    };
}
