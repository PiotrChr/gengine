#pragma once

#include <SFML/Graphics.hpp>
#include "../../../engine/core/object/hud/elements/LabeledDropDown.hpp"

namespace Gengine {

    class OptionsContainer {
        public:
            OptionsContainer(
                GameComponentsRef data,
                sf::Vector2f elementSize,
                float elementSpacing,
                sf::Vector2f padding
            );
            OptionsContainer(GameComponentsRef data) : _data(data) {};
            ~OptionsContainer();

            void init();
            void handleInput(sf::Event event, float dt);
            void update(float dt);
            void draw(sf::RenderTarget* target, float dt);
            void setCurrentOption(std::string optionName, std::string option);
            std::string getCurrentOption(std::string optionName);
            void setElementSize(sf::Vector2f size);
            void setElementSpacing(float spacing);
            void setPadding(sf::Vector2f padding);
            void setPosition(sf::Vector2f position);
            void addOption(std::string label, std::vector<std::string> options, std::string currentOption, std::function<void(std::string)> clickHandler);
            sf::Vector2f getSize();
        private:
            std::vector<LabeledDropDown> _options;
            GameComponentsRef _data;
            sf::Vector2f _position;
            sf::Vector2f _padding;
            sf::Vector2f _size;
            sf::Rect<float> _bounds;
            sf::RectangleShape _background;
            float _elementSpacing;
            sf::Vector2f _elementSize;
            std::string _openedOption = "";
    };
}