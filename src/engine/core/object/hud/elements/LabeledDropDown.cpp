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

        _dropDownBackground = std::make_shared<GameRectangle>(sf::Vector2f(size.x, size.y * options.size()));
        _dropDownBackground->setFillColor(_dropDownBackgroundColor);

        _data->renderManager.addTo2DLayer(LAYER_2D_HUD, _currentOption.get());
        _data->renderManager.addTo2DLayer(LAYER_2D_HUD, _label.get());
        
        float buttonSize = size.y - 5;

        std::cout << "Button size: " << buttonSize << std::endl;

        for (int i = 0; i < options.size(); i++) {
            std::string option = options[i];
            Button button = Button(
                _data,
                option,
                {0,0},
                {200, buttonSize},
                [clickHandler, option]() { clickHandler(option); }
            );
            
            auto btn = std::make_shared<Button>(button);

            _options.push_back(btn);
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
        std::cout << "Setting current option to " << option << std::endl;
        _isOpen = false;
        _currentOption->setText(option);
        
    }

    std::string LabeledDropDown::getCurrentOption() {
        return _currentOption->getText();
    }

    void LabeledDropDown::handleInput(sf::Event event, const float dt) {
        _label->handleInput(event, dt);

        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
            if (_isOpen) {
                if (_dropDownBounds.contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
                    _isOpen = true;
                } else {
                    _isOpen = false;
                }
            } else {
                if (_bounds.contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
                    _isOpen = true;
                } else {
                    _isOpen = false;
                }                        
            }

            if (_isOpen) {
                _onOpen();
                for (auto& option : _options) {
                    _data->renderManager.addTo2DLayer(LAYER_2D_DROPDOWN, option.get());
                    _data->renderManager.addTo2DLayer(LAYER_2D_DROPDOWN_BG, _dropDownBackground.get());
                }
            } else {
                _onClose();

                for (auto& option : _options) {
                    _data->renderManager.removeFrom2DLayer(LAYER_2D_DROPDOWN, option.get());
                    _data->renderManager.removeFrom2DLayer(LAYER_2D_DROPDOWN_BG, _dropDownBackground.get());
                }
            }
            
        }

        if (_isOpen) {
            for (int i = 0; i < _options.size(); i++) {
                _options[i]->handleInput(event, dt);
            }
        }

    }

    void LabeledDropDown::update(float& dt) {
        _label->update(dt);
        _currentOption->update(dt);
        if (_isOpen) {
            for (int i = 0; i < _options.size(); i++) {
                _options[i]->update(dt);
            }
        }
    }

    void LabeledDropDown::draw(sf::RenderTarget* target) {}

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