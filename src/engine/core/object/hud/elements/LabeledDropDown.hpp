#pragma once

#include "LabeledOption.hpp"
#include "Button.hpp"
#include "Label.hpp"
#include "../../../../DEFINITIONS.hpp"

namespace Gengine {
    class LabeledDropDown {
    public:
        LabeledDropDown(GameComponentsRef& data): _data(data) {};
        ~LabeledDropDown() {};

        void init(
            std::string text,
            sf::Vector2f size,
            std::function<void(std::string)> clickHandler,
            std::vector<std::string> options,
            std::string currentOption,
            sf::Vector2f padding = {0 ,0},
            sf::Vector2f dropDownPadding = {0 ,0},
            sf::Color dropDownBackgroundColor = sf::Color::Transparent,
            float margin = 0,
            float buttonMargin = 0,
            sf::Color textColor = DEFAULT_HUD_BUTTON_FONT_COLOR,
            sf::Color hoverColor = DEFAULT_HUD_BUTTON_HOVER_COLOR
        );
        void setCurrentOption(std::string option);
        std::string getCurrentOption();
        std::string getText();
        void handleInput(sf::Event event, const float dt);
        void setPosition(sf::Vector2f position);
        void update(float& dt);
        void draw(sf::RenderTarget* target);
    private:
        GameComponentsRef& _data;
        std::string _text;
        sf::Rect<float> _bounds;
        sf::RectangleShape _background;
        sf::Vector2f _size;
        sf::Vector2f _position;
        sf::Vector2f _padding;
        float _margin;
        float _buttonMargin;
        Label _label;
        Label _currentOption;
        sf::Rect<float> _dropDownBounds;
        sf::RectangleShape _dropDownBackground;
        std::vector<std::shared_ptr<Button>> _options;
        std::function<void(std::string)> _clickHandler;
        sf::Color _dropDownBackgroundColor;
        sf::Vector2f _dropDownPadding;
        int _buttonSize;
        int _buttonPadding;
        int _labelMargin;
        bool _isOpen = false;
    };

    typedef std::shared_ptr<LabeledDropDown> LabeledDropDownRef;
    typedef std::shared_ptr<Button> ButtonRef;
}