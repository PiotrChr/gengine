#pragma once

#include <SFML/Graphics.hpp>
#include "BaseGameState.hpp"
#include "../../gameObjects/player/TestPlayer.hpp"

namespace Gengine {
    class TestGameState : public BaseGameState {
    public:
        TestGameState(GameComponentsRef& data);
        ~TestGameState() {};
        void init();
        void handleInput(sf::Event event);
        void update(float dt);
        void draw(float dt);
        void pause();
        void resume();
    private:
        sf::Clock _clock;
        sf::Sprite _background;
        sf::Sprite _testingSprite;
        TestPlayer _player;
    };
} // namespace Gengine