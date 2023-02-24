#include "WindowManager.hpp"

namespace Gengine {
    
    void WindowManager::setResolution(std::string resolution) {
        this->resolution = resolution;
        if (resolution == "800x600") {
            width = 800;
            height = 600;
        }
        else if (resolution == "1024x768") {
            width = 1024;
            height = 768;
        }
        else if (resolution == "1280x720") {
            width = 1280;
            height = 720;
        }
        else if (resolution == "1920x1080") {
            width = 1920;
            height = 1080;
        }
        else if (resolution == "5120x2880") {
            width = 5120;
            height = 2880;
        }
        
        else {
            this->resolution = "800x600";
            width = 800;
            height = 600;
        }
    }

    void WindowManager::init(std::string title) {
        std::cout << "Initializing window..." << std::endl;
        std::cout << "Window title: " << title << std::endl;
        std::cout << "Window resolution: " << resolution << std::endl;
        std::cout << "Window fullscreen: " << isFullscreen << std::endl;
        std::cout << "Window vsync: " << isVsync << std::endl;
        std::cout << "Window framerate: " << framerate << std::endl;
        std::cout << "Window antialiasing: " << antialiasing << std::endl;
        std::cout << "Window width: " << width << std::endl;
        std::cout << "Window height: " << height << std::endl;

        
        if (isFullscreen) {
            window = new sf::RenderWindow(sf::VideoMode(width, height), title, sf::Style::Fullscreen);
        }
        else {
            window = new sf::RenderWindow(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);
        }
        
    }

    bool WindowManager::isOpen() {
        return window->isOpen();
    }

    WindowManager::~WindowManager() {
        delete window;
    }
}
