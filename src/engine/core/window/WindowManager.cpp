#include "WindowManager.hpp"

namespace Gengine {
    WindowManager::~WindowManager() {
        cleanupVulkan();
        glfwDestroyWindow(window);
        glfwTerminate();
    }
    
    void WindowManager::setResolution(std::string resolution, bool fullscreen) {    
        this->resolution = resolution;

        VkExtent2D extent = stringToExtent(resolution);
        
        width = extent.width;
        height = extent.height;

        if (fullscreen) {
            isFullscreen = true;
        }
    }

    void WindowManager::setFullscreen(bool fullscreen) {
        isFullscreen = fullscreen;
    }

    void WindowManager::init(std::string title) {
        glfwInit();

        #if _IS_MAC
            /* We need to explicitly ask for a 3.2 context on OS X */
            glfwWindowHint (GLFW_CONTEXT_VERSION_MAJOR, 3);
            glfwWindowHint (GLFW_CONTEXT_VERSION_MINOR, 2);
            glfwWindowHint (GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
            glfwWindowHint (GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        #endif

        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

        if (isFullscreen) {
            window = glfwCreateWindow(width, height, title.c_str(), glfwGetPrimaryMonitor(), nullptr);
        }
        else {
            window = glfwCreateWindow(width, height, title.c_str(), glfwGetPrimaryMonitor(), nullptr);
            std::cout << "s" << std::endl;
        }

        glfwMakeContextCurrent(window);


        initVulkan();
    }

    void WindowManager::initVulkan() {
        createInstance();
        pickPhysicalDevice();
        createLogicalDevice();
        createSwapChain();
    }

    void WindowManager::pickPhysicalDevice() {
        uint32_t deviceCount = 0;
        vkEnumeratePhysicalDevices(instance, &deviceCount, nullptr);

        if (deviceCount == 0) {
            throw std::runtime_error("Failed to find GPUs with Vulkan support!");
        }

        std::vector<VkPhysicalDevice> devices(deviceCount);
        vkEnumeratePhysicalDevices(instance, &deviceCount, devices.data());

        for (const auto& device : devices) {
            if (isDeviceSuitable(device)) {
                _physicalDevice = device;
                break;
            }
        }

        if (_physicalDevice == VK_NULL_HANDLE) {
            throw std::runtime_error("Failed to find a suitable GPU!");
        }
    }

    bool WindowManager::isDeviceSuitable(VkPhysicalDevice device) {
        
        return true;
    }

    void WindowManager::createLogicalDevice() {
        // Add code to create a logical device, queues, and other required resources.
        // ...
    }

    void WindowManager::createSwapChain() {
        // Add code to create a swap chain that suits your needs.
        // ...
    }

    void WindowManager::cleanupVulkan() {
        // Cleanup Vulkan resources
    }

    bool WindowManager::isOpen() {
        return !glfwWindowShouldClose(window);
    }

    void WindowManager::changeMode() {
        // TODO: Implement
    }

    std::map<std::string, VkExtent2D> WindowManager::getVideoModes() {
        return _videoModes;
    }

    std::string WindowManager::extentToString(VkExtent2D extent) {
        return std::to_string(extent.width) + "x" + std::to_string(extent.height);
    }

     VkExtent2D WindowManager::stringToExtent(std::string extent) {
        std::string width = "";
        std::string height = "";
        bool isWidth = true;
        for (int i = 0; i < extent.length(); i++) {
            if (extent[i] == 'x') {
                isWidth = false;
                continue;
            }
            if (isWidth) {
                width += extent[i];
            }
            else {
                height += extent[i];
            }
        }
        
        uint32_t w = std::stoul(width);
        uint32_t h = std::stoul(height);

        return VkExtent2D{w, h};
    }

    void WindowManager::createInstance() {
        VkApplicationInfo appInfo = {};
        appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
        appInfo.pApplicationName = "Gengine";
        appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
        appInfo.pEngineName = "No Engine";
        appInfo.engineVersion = VK_MAKE_VERSION(0, 0, 0);
        appInfo.apiVersion = VK_API_VERSION_1_2;

        VkInstanceCreateInfo createInfo = {};
        createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
        createInfo.pApplicationInfo = &appInfo;

        uint32_t glfwExtensionCount = 0;
        const char** glfwExtensions;

        glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);
        
        // Check if the required extensions are available
        uint32_t availableExtensionCount = 0;
        vkEnumerateInstanceExtensionProperties(nullptr, &availableExtensionCount, nullptr);
        std::vector<VkExtensionProperties> availableExtensions(availableExtensionCount);
        vkEnumerateInstanceExtensionProperties(nullptr, &availableExtensionCount, availableExtensions.data());

        bool allExtensionsFound = true;
        for (uint32_t i = 0; i < glfwExtensionCount; ++i) {
            bool extensionFound = false;
            for (const auto& availableExtension : availableExtensions) {
                if (strcmp(glfwExtensions[i], availableExtension.extensionName) == 0) {
                    extensionFound = true;
                    break;
                }
            }
            if (!extensionFound) {
                allExtensionsFound = false;
                break;
            }
        }

        if (!allExtensionsFound) {
            throw std::runtime_error("Failed to find required Vulkan extensions!");
        }

        createInfo.enabledExtensionCount = glfwExtensionCount;
        createInfo.ppEnabledExtensionNames = glfwExtensions;

        createInfo.enabledLayerCount = 0;

        int creationSuccess = vkCreateInstance(&createInfo, nullptr, &instance);

        if (creationSuccess != VK_SUCCESS) {
            throw std::runtime_error("Failed to create Vulkan instance.");
        }

    }

    std::string WindowManager::getResolution() {
        return resolution;
    }
}
