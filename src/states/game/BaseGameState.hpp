#pragma once

#include <SFML/Graphics.hpp>
#include "../BaseState.hpp"
#include "../../engine/DEFINITIONS.hpp"

namespace Gengine {
    class BaseGameState : public BaseState {
    public:
        BaseGameState(GameComponentsRef& data) : BaseState(data) {};
        ~BaseGameState() {};
        void init();
        void handleInput(sf::Event event);
        void update(float dt);
        void draw(float dt);
        void pause();
        void resume();
    private:
        sf::Clock _clock;
        sf::Sprite _background;
    };
}