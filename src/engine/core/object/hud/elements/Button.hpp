#pragma once

#include "../../HudObject.hpp"
#include "../../../../DEFINITIONS.hpp"
#include <SFML/Graphics.hpp>

namespace Gengine {
    class Button : public HudObject {
    public:
        Button(
            GameComponentsRef data,
            std::string text,
            sf::Vector2f position,
            sf::Vector2f size,
            std::function<void(void)> clickHandler,
            sf::Vector2f padding = DEFAULT_HUD_BUTTON_PADDING,
            bool hasBorder = DEFAULT_HUD_DROPDOWN_HAS_BORDER,
            bool hasBackground = DEFAULT_HUD_BUTTON_HAS_BACKGROUND,
            bool hasIcon = DEFAULT_HUD_BUTTON_HAS_ICON,
            std::string font = DEFAULT_HUD_BUTTON_FONT,
            sf::Color textColor = DEFAULT_HUD_DROPDOWN_FONT_COLOR,
            int borderSize = DEFAULT_HUD_DROPDOWN_BORDER_SIZE,
            // int borderRadius = DEFAULT_HUD_BUTTON_BORDER_RADIUS,
            sf::Color borderColor = DEFAULT_HUD_DROPDOWN_BORDER_COLOR,
            sf::Color backgroundColor = DEFAULT_HUD_DROPDOWN_BACKGROUND_COLOR,
            sf::Color hoverColor = DEFAULT_HUD_DROPDOWN_HOVER_COLOR,
            sf::Color clickColor = DEFAULT_HUD_DROPDOWN_CLICK_COLOR,
            int iconPosition = DEFAULT_HUD_BUTTON_ICON_POSITION,
            int iconSize = DEFAULT_HUD_BUTTON_ICON_SIZE
        );
        ~Button();
        Button() {};
        void init();
        void update(const float& dt);
        void draw(sf::RenderTarget* target);
        
        sf::Vector2f getPosition();
        sf::Vector2f getSize();
        std::string getText();
    
        void setPosition(sf::Vector2f position);
        void setSize(sf::Vector2f size);
        void setBackgroundColor(sf::Color color);
        void setBorderColor(sf::Color color);
        void setTextColor(sf::Color color);
        void setText(std::string text);
        void setHoverColor(sf::Color color);
        void setClickColor(sf::Color color);
        void setPadding(sf::Vector2f padding);
        void setClickHandler(std::function<void(void)> handler);
        void handleInput(sf::Event event, const float dt);
    private:
        sf::Rect<float> _bounds;
        sf::Vector2f _size;
        sf::Vector2f _position;
        sf::Vector2f _padding;

        sf::Text _textObj;
        std::string _text;
        int _textSize;
        sf::Color _textColor;
        sf::Font _font;
        std::string _fontPath;

        bool _hasBorder;
        int _borderSize;
        // int _borderRadius;
        sf::Color _borderColor;
        sf::RectangleShape _borderObj;
        
        bool _hasBackground;
        sf::Color _backgroundColor;
        
        bool _isHovered;
        sf::Color _hoverColor;
        
        bool _isClicked;
        sf::Color _clickColor;

        bool _hasIcon;
        sf::Sprite _icon;
        int _iconPosition;
        int _iconSize;

        std::function<void(void)> _clickHandler;

        sf::Color _currentTextColor;
        sf::Color _currentBorderColor;
        sf::Color _currentBackgroundColor;
    };
}
