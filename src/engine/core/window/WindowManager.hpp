#pragma once

#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


namespace Gengine {
    class WindowManager {
    public:
        void init(int width, int height, std::string title);
        bool isOpen();
        sf::RenderWindow window;
    };
}
