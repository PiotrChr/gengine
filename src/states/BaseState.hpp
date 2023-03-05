#pragma once

#include "../engine/core/state/State.hpp"
#include "../engine/game/GameComponents.hpp"

namespace Gengine {
    class BaseState : public State {
    public:
        BaseState(GameComponentsRef& data) : _data(data) {};
        ~BaseState() {};
        void init();
        void handleInput(sf::Event event, const float dt);
        void update(float dt);
        void draw(float dt);
        void pause();
        void resume();
        void handleEvents(const float dt);
        void handleDefaultInput(sf::Event event);
        void centerElement(sf::Sprite& element, sf::Vector2f offset = sf::Vector2f(0, 0));
        void scaleToWindow(sf::Sprite& element, sf::Vector2f margin = sf::Vector2f(0, 0));
    protected:
        GameComponentsRef _data;
        sf::Sprite _background;
        
    };
}