#pragma once

#include <SFML/Graphics.hpp>
#include "../../BaseState.hpp"
#include "../../../engine/DEFINITIONS.hpp"
#include "../../../engine/game/GameComponents.hpp"

namespace Gengine {
    class QuitState : public BaseState {
    public:
        QuitState(GameComponentsRef& data): BaseState(data) {};
        ~QuitState() {};
        void init();
        void handleInput(sf::Event event);
        void update(float dt);
        void draw(float dt);
        void pause();
        void resume();
    private:
        sf::Sprite _background;
        sf::Clock _clock;
    };
} // namespace Gengine