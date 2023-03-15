#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <map>

namespace Gengine {
    class InputManager {
    public:
        InputManager();
        ~InputManager();

        bool isElemClicked(sf:: Sprite object, sf::Mouse::Button button, sf::RenderWindow* window);
        bool isElemClicked(sf::RectangleShape object, sf::Mouse::Button button, sf::RenderWindow* window);
        void initKeys();
        bool isActionTriggered(sf::Event event, std::string actionName);
        sf::Vector2f getMousePosition(sf::RenderWindow* window);
        std::map<std::string, int> keyBinds;
        std::map<std::string, int> mouseBinds;
        
    };
}
