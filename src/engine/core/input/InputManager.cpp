#include "InputManager.hpp"

namespace Gengine
{
    InputManager::InputManager() {

    }

    InputManager::~InputManager() {

    }

    bool InputManager::isElemClicked(sf::RectangleShape object, sf::Mouse::Button button, sf::RenderWindow* window) {
        if (sf::Mouse::isButtonPressed(button)) {
            
            sf::Rect tempRect(object.getPosition(), object.getSize());

            if (tempRect.contains(getMousePosition(window))) {
                return true;
            }
        }

        return false;
    }

    bool InputManager::isElemClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow* window) {
        if (sf::Mouse::isButtonPressed(button)) {
            sf::Rect tempRect(object.getPosition(), object.getGlobalBounds().getSize());

            if (tempRect.contains(getMousePosition(window))) {
                return true;
            }
        }

        return false;
    }

    sf::Vector2f InputManager::getMousePosition(sf::RenderWindow* window) {
        return sf::Vector2f(sf::Mouse::getPosition(*window));
    }

} // namespace Gengine
