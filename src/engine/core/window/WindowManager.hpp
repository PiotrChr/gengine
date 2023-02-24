#pragma once

#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


namespace Gengine {
    class WindowManager {
    public:
        WindowManager() {};
        ~WindowManager();
        
        void init(std::string title);
        void toggleFullscreen();
        void setResolution(std::string resolution);
        bool isOpen();
        sf::RenderWindow* window;
        bool isFullscreen;
        bool isVsync;
        int antialiasing;
        int framerate;
        std::string resolution;
        int width;
        int height;
    
    };
}
