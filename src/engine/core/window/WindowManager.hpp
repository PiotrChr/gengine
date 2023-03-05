#pragma once

#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <map>

namespace Gengine {
    class WindowManager {
    public:
        WindowManager() {};
        ~WindowManager();
        
        void init(std::string title);
        void toggleFullscreen();
        void changeMode();
        void setFullscreen(bool fullscreen);
        void setResolution(std::string resolution, bool fullscreen = false);
        std::string getResolution();
        std::map<std::string, sf::VideoMode> getVideoModes();
        bool isOpen();
        sf::RenderWindow* window;
        bool isFullscreen;
        bool isVsync;
        int antialiasing;
        int framerate;
        std::string resolution;
        int width;
        int height;
        static std::string modeToString(sf::VideoMode mode);
        static sf::VideoMode stringToMode(std::string mode);
    private:
        std::map<std::string, sf::VideoMode> _videoModes;
    };
}
