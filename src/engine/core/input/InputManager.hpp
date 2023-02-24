#pragma once

#include <SFML/Graphics.hpp>

namespace Gengine {
    class InputManager {
    public:
        InputManager();
        ~InputManager();

        bool isElemClicked(sf:: Sprite object, sf::Mouse::Button button, sf::RenderWindow* window);
        bool isElemClicked(sf::RectangleShape object, sf::Mouse::Button button, sf::RenderWindow* window);
        void initKeys();
        sf::Vector2i getMousePosition(sf::RenderWindow* window);
        std::map<std::string, int> keyBinds;
    
    };
}
