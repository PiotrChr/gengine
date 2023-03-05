#include "GameButton.hpp"

namespace Gengine {
    GameButton::GameButton(
        GameComponentsRef& data,
        std::string text,
        sf::Vector2f position,
        std::function<void(void)> clickHandler,
        sf::Color textColor,
        sf::Color hoverColor
    ) : Button(
        data,
        text,
        position,
        sf::Vector2f(150.f, 38.f),
        clickHandler,
        sf::Vector2f(0.0f, 7.0f),
        true,
        false,
        false,
        DEFAULT_HUD_BUTTON_FONT,
        textColor,
        2,
        // 0,
        textColor,
        textColor,
        hoverColor,
        hoverColor,
        0,
        0
    ) {};
}