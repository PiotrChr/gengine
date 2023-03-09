#pragma once

#include "../../../engine/core/object/hud/elements/Button.hpp"

namespace Gengine {
    class MainMenuButton : public Button {
    public:
        MainMenuButton(
            GameComponentsRef data,
            std::string text,
            sf::Vector2f position,
            std::function<void(void)> clickHandler,
            sf::Color textColor = DEFAULT_HUD_BUTTON_FONT_COLOR,
            sf::Color hoverColor = DEFAULT_HUD_BUTTON_HOVER_COLOR
        );
        MainMenuButton() {};
        ~MainMenuButton() {};
    };
}
