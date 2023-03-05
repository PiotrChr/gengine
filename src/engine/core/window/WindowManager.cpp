#include "WindowManager.hpp"

namespace Gengine {
    
    void WindowManager::setResolution(std::string resolution, bool fullscreen) {    
        this->resolution = resolution;

        sf::VideoMode mode = stringToMode(resolution);
        
        width = mode.size.x;
        height = mode.size.y;

        if (fullscreen) {
            isFullscreen = true;
        }
    }

    void WindowManager::setFullscreen(bool fullscreen) {
        isFullscreen = fullscreen;
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

        for (auto mode : sf::VideoMode::getFullscreenModes()) {
            _videoModes[modeToString(mode)] = mode;
        }

        const sf::Vector2u size(width, height);

        if (isFullscreen) {
            window = new sf::RenderWindow(sf::VideoMode(size), title, sf::Style::Fullscreen);
        }
        else {
            window = new sf::RenderWindow(sf::VideoMode(size), title, sf::Style::Close | sf::Style::Titlebar);
        }
        
    }

    bool WindowManager::isOpen() {
        return window->isOpen();
    }

    WindowManager::~WindowManager() {
        delete window;
    }

    void WindowManager::changeMode() {
        window->close();
        const sf::Vector2u size(width, height);


        if (isFullscreen) {
            window->create(sf::VideoMode(size), "Gengine", sf::Style::Close | sf::Style::Titlebar);
            isFullscreen = false;
        }
        else {
            window->create(sf::VideoMode(size), "Gengine", sf::Style::Fullscreen);
            isFullscreen = true;
        }
    }

    std::map<std::string, sf::VideoMode> WindowManager::getVideoModes() {
        return _videoModes;
    }

    std::string WindowManager::modeToString(sf::VideoMode mode) {
        return std::to_string(mode.size.x) + "x" + std::to_string(mode.size.y);
    }

    sf::VideoMode WindowManager::stringToMode(std::string resolution) {
        std::string width = "";
        std::string height = "";
        bool isWidth = true;
        for (int i = 0; i < resolution.length(); i++) {
            if (resolution[i] == 'x') {
                isWidth = false;
                continue;
            }
            if (isWidth) {
                width += resolution[i];
            }
            else {
                height += resolution[i];
            }
        }
        
        unsigned int w = std::stoul(width);
        unsigned int h = std::stoul(height);

        return sf::VideoMode({w, h});
    }

    std::string WindowManager::getResolution() {
        return resolution;
    }
}
