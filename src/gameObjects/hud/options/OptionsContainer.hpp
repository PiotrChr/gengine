#pragma once

#include <SFML/Graphics.hpp>
#include "../../../engine/core/object/hud/elements/LabeledDropDown.hpp"
#include "../../../engine/core/object/HudObject.hpp"

namespace Gengine {

    class OptionsContainer : public HudObject {
        public:
            OptionsContainer(
                GameComponentsRef data,
                sf::Vector2f elementSize,
                float elementSpacing,
                sf::Vector2f padding
            );
            OptionsContainer(GameComponentsRef data) : HudObject(data) {

            };
            ~OptionsContainer();

            void init();
            bool handleInput(sf::Event event, float dt);
            void update(const float& dt);
            void draw(sf::RenderTarget* target);
            void setCurrentOption(std::string optionName, std::string option);
            std::string getCurrentOption(std::string optionName);
            void setElementSize(sf::Vector2f size);
            void setElementSpacing(float spacing);
            void setPadding(sf::Vector2f padding);
            void setPosition(sf::Vector2f position);
            void addOption(std::string label, std::vector<std::string> options, std::string currentOption, std::function<void(std::string)> clickHandler);
            sf::Vector2f getSize();
        private:
            std::vector<std::shared_ptr<LabeledDropDown>> _options;
            sf::Vector2f _position;
            sf::Vector2f _padding;
            sf::Vector2f _size;
            sf::Rect<float> _bounds;
            sf::RectangleShape _background;
            float _elementSpacing;
            sf::Vector2f _elementSize;
            std::string _openedOption = "";
    };

    typedef std::shared_ptr<LabeledDropDown> LabeledDropDownRef;
}