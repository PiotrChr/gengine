#include "Label.hpp"

namespace Gengine {
    Label::Label(
        GameComponentsRef data,
        std::string text,
        sf::Vector2f size,
        sf::Color color,
        sf::Color hoverColor,
        std::string font
    ) : HudObject(data) {
        this->_size = size;
        this->_color = color;
        this->_hoverColor = hoverColor;
        this->_fontPath = font;
        this->_textString = text;
    }

    void Label::init() {
        this->_data->assetManager.loadFont(_fontPath, _fontPath);
        this->_text.setFont(_data->assetManager.getFont(_fontPath));
        this->_text.setString(_textString);

        std::cout << "Label init" << std::endl;
        std::cout << "Label size: " << _size.y - 2*_padding.y << std::endl;
        this->_text.setCharacterSize(_size.y - 2*_padding.y);
        this->_text.setFillColor(_color);
    }

    void Label::setText(std::string text) {
        _text.setString(text);
    }

    sf::Vector2f Label::getSize() {
        return _size;
    }

    std::string Label::getText() {
        return _text.getString();
    }

    void Label::setPosition(sf::Vector2f position, std::string align) {
        std::cout << "Label position: " << position.x << ", " << position.y << std::endl;
        sf::Vector2f textPosition;

        this->_position = position;

        std::cout << "Label text position: " << this->_text.getPosition().x << ", " << this->_text.getPosition().y << std::endl;
        std:: cout << this->_position.x << ", " << this->_position.y << std::endl;
        std:: cout << this->_size.x << ", " << this->_size.y << std::endl;
        std:: cout << this->_text.getLocalBounds().width << ", " << this->_text.getLocalBounds().height << std::endl;
        
        float hPos = this->_position.y + this->_size.y/2 - this->_text.getLocalBounds().height/1.5f;

        if (align == "center") {
            textPosition = {this->_position.x + this->_size.x/2 - this->_text.getLocalBounds().width/2, hPos};
        } else if (align == "left") {
            textPosition = {this->_position.x + this->_padding.x, hPos};
        } else {
            textPosition = {this->_position.x + this->_size.x - this->_text.getLocalBounds().width - this->_padding.x, hPos};
        }

        _text.setPosition(textPosition);
        _bounds = sf::Rect<float>({_position.x, _position.y}, {_size.x, _size.y});
    }

    void Label::handleInput(sf::Event event, const float dt) {
        if (event.type == sf::Event::MouseMoved) {
            if (_bounds.contains(sf::Vector2f(event.mouseMove.x, event.mouseMove.y))) {
                _isHovered = true;
            } else {
                _isHovered = false;
            }
        }
    }

    void Label::update(float& dt) {
        if (_isHovered) {
            _text.setFillColor(_hoverColor);
        } else {
            _text.setFillColor(_color);
        }
    }

    void Label::draw(sf::RenderTarget* target) {
        target->draw(_text);
    }
}