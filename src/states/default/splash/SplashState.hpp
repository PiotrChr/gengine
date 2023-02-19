#pragma once


#include <SFML/Graphics.hpp>
#include "../../../engine/DEFINITIONS.hpp"
#include "../BaseState.hpp"
#include "../../../engine/game/GameComponents.hpp"

namespace Gengine {
    class SplashState : public BaseState {
    public:
        SplashState(GameComponentsRef& data) : BaseState(data) {};
        ~SplashState() {};
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