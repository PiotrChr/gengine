#pragma once

#include "LabeledOption.hpp"
#include "Button.hpp"
#include "Label.hpp"
#include "GameRectangle.hpp"
#include "../../HudObject.hpp"
#include "../../../../DEFINITIONS.hpp"

namespace Gengine {
    typedef std::shared_ptr<Label> LabelRef;
    typedef std::shared_ptr<GameRectangle> RectangleRef;

    class LabeledDropDown : public HudObject {
    public:
        LabeledDropDown(GameComponentsRef data): HudObject(data) {

        };
        ~LabeledDropDown() {};

        void init(
            std::string text,
            sf::Vector2f size,
            std::function<void(std::string)> clickHandler,
            std::vector<std::string> options,
            std::string currentOption,
            sf::Vector2f padding = DEFAULT_HUD_DROPDOWN_PADDING,
            sf::Vector2f dropDownPadding = DEFAULT_HUD_DROPDOWN_BUTTON_PADDING,
            sf::Color dropDownBackgroundColor = DEFAULT_HUD_DROPDOWN_BACKGROUND_COLOR,
            float margin = DEFAULT_HUD_DROPDOWN_MARGIN,
            float buttonMargin = DEFAULT_HUD_DROPDOWN_BUTTON_MARGIN,
            sf::Color textColor = DEFAULT_HUD_BUTTON_FONT_COLOR,
            sf::Color hoverColor = DEFAULT_HUD_BUTTON_HOVER_COLOR
        );
        void setCurrentOption(std::string option);
        void setOnOpen(std::function<void()> onOpen);
        void setOnClose(std::function<void()> onClose);
        std::string getCurrentOption();
        std::string getText();
        bool handleInput(sf::Event event, const float dt);
        void setPosition(sf::Vector2f position);
        void update(const float& dt);
        void draw(sf::RenderTarget* target);
    private:
        std::string _text;
        sf::Rect<float> _bounds;
        sf::RectangleShape _background;
        sf::Vector2f _size;
        sf::Vector2f _position;
        sf::Vector2f _padding;
        float _margin;
        float _buttonMargin;
        LabelRef _label;
        LabelRef _currentOption;
        sf::Rect<float> _dropDownBounds;
        RectangleRef _dropDownBackground;
        std::vector<std::shared_ptr<Button>> _options;
        std::function<void(std::string)> _clickHandler;
        std::function<void()> _onOpen;
        std::function<void()> _onClose;
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