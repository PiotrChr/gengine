
#include "OptionsContainer.hpp"

namespace Gengine {

    OptionsContainer::OptionsContainer(
        GameComponentsRef data,
        sf::Vector2f elementSize,
        float elementSpacing,
        sf::Vector2f padding
    ) : _data(data) {
        _elementSpacing = elementSpacing;
        _elementSize = elementSize;
        _padding = padding;
    };

    OptionsContainer::~OptionsContainer() {};

    void OptionsContainer::setPadding(sf::Vector2f padding) {
        _padding = padding;
    };

    void OptionsContainer::init() {
        _size = sf::Vector2f(
            _padding.x * 2 + _elementSize.x,
            _padding.y * 2 + _elementSize.y * _options.size() + _elementSpacing * (_options.size() - 1)
        );
    };

    void OptionsContainer::setCurrentOption(std::string optionName, std::string option) {
        for (int i = 0; i < _options.size(); i++) {
            LabeledDropDown& labeledDropDown = _options[i];

            if (labeledDropDown.getText() == optionName) {
                labeledDropDown.setCurrentOption(option);
            }
        }
    };

    std::string OptionsContainer::getCurrentOption(std::string optionName) {
        for (int i = 0; i < _options.size(); i++) {
            LabeledDropDown& labeledDropDown = _options[i];

            if (labeledDropDown.getText() == optionName) {
                return labeledDropDown.getCurrentOption();
            }
        }

        return "";
    };

    void OptionsContainer::handleInput(sf::Event event, float dt) {
        for (int i = 0; i < _options.size(); i++) {
            LabeledDropDown& option = _options[i];

            if (_openedOption == "") {
                option.handleInput(event, dt);
            } else {
                if (_openedOption == option.getText()) {
                    option.handleInput(event, dt);
                }
            }
        }
    };

    void OptionsContainer::update(float dt) {
        for (int i = 0; i < _options.size(); i++) {
            LabeledDropDown& option = _options[i];

            option.update(dt);
        }
    };

    void OptionsContainer::draw(sf::RenderTarget* target, float dt) {
        for (int i = 0; i < _options.size(); i++) {
            LabeledDropDown& option = _options[i];

            option.draw(target);
        }
    };

    void OptionsContainer::setPosition(sf::Vector2f position) {
        _position = position;
        for (int i = 0; i < _options.size(); i++) {
            LabeledDropDown& option = _options[i];

            option.setPosition(sf::Vector2f(
                _position.x,
                _position.y + (i * (_elementSize.y + _elementSpacing))
            ));
        }

        std::cout << "OptionsContainer::setPosition(" << _position.x << ", " << _position.y << ")" << std::endl;
        _bounds = sf::Rect<float>({_position.x, _position.y}, {_size.x, _size.y});
    };

    void OptionsContainer::addOption(
        std::string label,
        std::vector<std::string> options,
        std::string currentOption,
        std::function<void(std::string)> clickHandler
    ) {
        LabeledDropDown dropDown = LabeledDropDown(_data);
        dropDown.init(label, _elementSize, clickHandler, options, currentOption);
        dropDown.setOnOpen([this, label]() { this->_openedOption = label; });
        dropDown.setOnClose([this]() { this->_openedOption = ""; });

        _options.push_back(dropDown);
    };

    sf::Vector2f OptionsContainer::getSize() {
        return _size;
    };

    void OptionsContainer::setElementSize(sf::Vector2f size) {
        _elementSize = size;
    };

    void OptionsContainer::setElementSpacing(float spacing) {
        _elementSpacing = spacing;
    };

    
}