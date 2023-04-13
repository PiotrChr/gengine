#include "LabeledDropDown.hpp"
#include <memory>
#include <algorithm>

namespace Gengine {
    void LabeledDropDown::init(std::string text,
        sf::Vector2f size,
        std::function<void(std::string)> clickHandler,
        std::vector<std::string> options,
        std::string currentOption,
        sf::Vector2f padding,
        sf::Vector2f dropDownPadding,
        sf::Color dropDownBackgroundColor,
        float margin,
        float buttonMargin,
        sf::Color textColor,
        sf::Color hoverColor
    ) {
        _text = text;
        _clickHandler = clickHandler;
        _padding = padding;
        _size = size;
        _margin = margin;
        _buttonMargin = buttonMargin;
        _dropDownPadding = dropDownPadding;
        _dropDownBackgroundColor = dropDownBackgroundColor;

        _label = std::make_shared<Label>(
            _data,
            text,
            sf::Vector2f(size.x - _margin, size.y),
            textColor,
            hoverColor
        );

        _currentOption = std::make_shared<Label>(
            _data,
            currentOption,
            sf::Vector2f(200.f, size.y),
            textColor,
            hoverColor
        );

        this->addChild(_label);
        this->addChild(_currentOption);

        _dropDownBackground = std::make_shared<GameRectangle>(sf::Vector2f(size.x, size.y * options.size()));
        _dropDownBackground->setFillColor(_dropDownBackgroundColor);
        
        float buttonSize = size.y - 5;

        for (int i = 0; i < options.size(); i++) {
            std::string option = options[i];
            Button button = Button(
                _data,
                option,
                {0,0},
                {200, buttonSize},
                [clickHandler, option]() { clickHandler(option); },
                DEFAULT_HUD_BUTTON_PADDING,
                true
            );
            
            auto btn = std::make_shared<Button>(button);
            btn->setZIndex(DROPDOWN_ELEMENTS_LAYER);
            btn->setActive(false);
            _options.push_back(btn);
            this->addChild(btn);
        }

        _label->init();
        _currentOption->init();
        
        for (int i = 0; i < _options.size(); i++) {
            ButtonRef& option = _options[i];
            option->init();
        }
    }

    std::string LabeledDropDown::getText() {
        return _text;
    }
    
    void LabeledDropDown::setCurrentOption(std::string option) {
        _isOpen = false;
        _currentOption->setText(option);
        
    }

    std::string LabeledDropDown::getCurrentOption() {
        return _currentOption->getText();
    }

    bool LabeledDropDown::handleInput(sf::Event event, const float dt) {
        _label->handleInput(event, dt);
        bool dirty = false;

        if (_data->inputManager.isActionTriggered(event, ACTION_MAIN)) {
            if (_bounds.contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
                _isOpen = !_isOpen;
                dirty = true;
            } else {
                _isOpen = false;
            }

            if (_isOpen) {
                _onOpen();
            } else {
                _onClose();
            }

            for (auto& option : _options) {
                option->setActive(_isOpen);
            }

            return dirty;
        }
    }

    void LabeledDropDown::update(const float& dt) {
        _label->update(dt);
        _currentOption->update(dt);
        if (_isOpen) {
            for (auto& option : _options) {
                option->update(dt);
            }
        }
    }

    void LabeledDropDown::draw(sf::RenderTarget* target) {
        if (_isOpen) {
            _dropDownBackground->draw(target);
        }
    }

    void LabeledDropDown::setPosition(sf::Vector2f position) {
        this->_position = position;
        this->_label->setPosition(this->_position, "left");
        
        this->_bounds = sf::Rect<float>(this->_position, this->_size);
        
        float maxOptionWidth = 0;
        float xPos = _position.x + _dropDownPadding.x + _size.x - 200;
        
        for (int i = 0; i < _options.size(); i++) {
            _options[i]->setPosition(sf::Vector2f(
                xPos,
                _position.y + _size.y + _margin + _dropDownPadding.y + i * (_size.y + _buttonMargin)
            ));
        }

        this->_currentOption->setPosition(sf::Vector2f(
            _position.x + _size.x - this->_currentOption->getSize().x - _dropDownPadding.x,
            _position.y
        ), "center");

        _dropDownBounds = sf::Rect<float>({
                xPos, _position.y + _size.y + _margin + _dropDownPadding.y
            }, {
                200 + _dropDownPadding.x * 2,
                _size.y * _options.size() + _dropDownPadding.y * 2 + (_options.size() - 1) * _buttonMargin
        });

        _dropDownBackground->setSize(sf::Vector2f(
            200 + _dropDownPadding.x * 2,
            _size.y * _options.size() + _dropDownPadding.y * 2 + (_options.size() - 1) * _buttonMargin
        ));

        _dropDownBackground->setPosition(sf::Vector2f(
            xPos,
            _position.y + _size.y + _margin + _dropDownPadding.y
        ));
    }

    void LabeledDropDown::setOnOpen(std::function<void()> onOpen) {
        _onOpen = onOpen;
    }

    void LabeledDropDown::setOnClose(std::function<void()> onClose) {
        _onClose = onClose;
    }
}