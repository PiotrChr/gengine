#include "Button.hpp"

namespace Gengine {
    Button::Button(
        GameComponentsRef& data,
        std::string text,
        sf::Vector2f position,
        sf::Vector2f size,
        std::function<void(void)> clickHandler,
        sf::Vector2i padding,
        bool hasBorder,
        bool hasBackground,
        bool hasIcon,
        std::string font,
        sf::Color textColor,
        int borderSize,
        // int borderRadius,
        sf::Color borderColor,
        sf::Color backgroundColor,
        sf::Color hoverColor,
        sf::Color clickColor,
        int iconPosition,
        int iconSize
        ) : HudObject(data) {
            _position = position;
            _padding = padding;
            _text = text;
            _size = size;
            
            _textColor = textColor;
            _currentTextColor = textColor;
            
            std::cout << "Loading font: " << font << std::endl;
            _data->assetManager.loadFont("menu-font", font);

            _font = _data->assetManager.getFont("menu-font");

            _hasBorder = hasBorder;
            _borderSize = borderSize;
            // _borderRadius = borderRadius;
            _borderColor = borderColor;
            
            _textSize = _size.y - 2*_padding.y - 2*_borderSize;

            _bounds = sf::Rect<float>(
                {_position.x, _position.y},
                {_size.x, _size.y}
            );

            _hasBackground = hasBackground;
            _backgroundColor = backgroundColor;
            
            _isHovered = false;
            _hoverColor = hoverColor;
            
            _isClicked = false;
            _clickColor = clickColor;

            _hasIcon = hasIcon;
            _iconPosition = iconPosition;
            _iconSize = iconSize;

            _clickHandler = clickHandler;
        };

    Button::~Button() {};

    void Button::init() {
        _textObj.setFont(_font);
        _textObj.setString(_text);
        _textObj.setCharacterSize(_textSize);
        _textObj.setFillColor(_currentTextColor);
        _textObj.setPosition({
            _position.x + _size.x/2 - _textObj.getLocalBounds().width/2,
            _position.y + _size.y/2 - _textObj.getLocalBounds().height/1.5f
        });

        if (_hasBorder) {
            _borderObj.setSize(_size);
            _borderObj.setPosition(_position);
            _borderObj.setFillColor(sf::Color::Transparent);
            _borderObj.setOutlineColor(_currentTextColor);
            _borderObj.setOutlineThickness(_borderSize);
            
        }
    };

    void Button::handleInput(sf::Event event, const float dt) {
        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                if (_bounds.contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
                    _isClicked = true;
                    _clickHandler();
                }
            }
        }

        if (event.type == sf::Event::MouseButtonReleased) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                _isClicked = false;
            }
        }

        if (event.type == sf::Event::MouseMoved) {
            if (_bounds.contains(sf::Vector2f(event.mouseMove.x, event.mouseMove.y))) {
                _isHovered = true;
            } else {
                _isHovered = false;
            }
        }
    };

    void Button::update(const float& dt) {
        if (_isHovered && !_isClicked) {
            _borderObj.setOutlineColor(_textColor);
            _borderObj.setFillColor(_hoverColor);
        } else if (_isClicked) {
            _textObj.setFillColor(_hoverColor);
            _borderObj.setOutlineColor(_currentTextColor);
        } else {
            _textObj.setFillColor(_textColor);
            _borderObj.setOutlineColor(_borderColor);
            _borderObj.setFillColor(sf::Color::Transparent);
        }
    };

    void Button::draw(sf::RenderTarget* target) {
        if (_hasBorder) {
            target->draw(_borderObj);
        }
        
        target->draw(_textObj);
    };
    
    sf::Vector2f Button::getSize() {
        return _size;
    };

    sf::Vector2f Button::getPosition() {
        return _position;
    };
    
    void Button::setPosition(sf::Vector2f position) {
        _position = position;
    };

    void Button::setClickHandler(std::function<void(void)> clickHandler) {
        _clickHandler = clickHandler;
    };
}