#pragma once

// #include "../../game/GameComponents.hpp"
#include <SFML/Graphics.hpp>

namespace Gengine {
    class State {
    public:
        State() {};
        virtual ~State() = default;
        virtual void init() = 0;
        virtual void handleInput(sf::Event event, const float dt) = 0;
        virtual void update(float dt) = 0;
        virtual void draw(float dt) = 0;
        virtual void cleanup() = 0;
        virtual void pause() = 0;
        virtual void resume() = 0;
        virtual void handleEvents(const float dt) = 0;
    protected:
        // void handleDefaultInput(sf::Event event);
        // GameComponentsRef _data = nullptr;
    };
}
