#pragma once

#include "../../HudObject.hpp"
#include <SFML/Graphics.hpp>

namespace Gengine {
    class Label : public HudObject {
        public:
            Label(
                GameComponentsRef& data,
                std::string text,
                sf::Vector2f size,
                sf::Color color = DEFAULT_HUD_BUTTON_FONT_COLOR,
                sf::Color hoverColor = DEFAULT_HUD_BUTTON_HOVER_COLOR,
                std::string font = DEFAULT_HUD_BUTTON_FONT
                );
            Label() {};
            ~Label() {};

            void init();
            void setPosition(sf::Vector2f position, std::string align = "center");
            sf::Vector2f getSize();
            void setText(std::string text);
            std::string getText();
            void handleInput(sf::Event event, const float dt);
            void update(float& dt);
            void draw(sf::RenderTarget* target);
        private:
            sf::Vector2f _position = {0.f, 0.f};
            sf::Vector2f _size= {0.f, 0.f};
            sf::Vector2f _padding;
            sf::Text _text;
            sf::Color _color;
            sf::Color _hoverColor;
            sf::Rect<float> _bounds;
            bool _isHovered = false;
            
    };
}