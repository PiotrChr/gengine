#pragma once

#include "../../engine/core/state/State.hpp"
#include "../../engine/game/GameComponents.hpp"

namespace Gengine {
    class BaseState : public State {
    public:
        BaseState(GameComponentsRef& data) : _data(data) {};
        ~BaseState() {};
        void init();
        void handleInput(sf::Event event);
        void update(float dt);
        void draw(float dt);
        void pause();
        void resume();
        void handleEvents();
        void handleDefaultInput(sf::Event event);
    protected:
        GameComponentsRef _data;
        sf::Sprite _background;
    };
}