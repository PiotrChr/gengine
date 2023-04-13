#pragma once

#include <SFML/Graphics.hpp>
#include "BaseGameState.hpp"
#include "../default/mainMenu/MainMenuState.hpp"
#include "../../gameObjects/hud/game/GameButton.hpp"
#include "../../gameObjects/player/Player.hpp"
#include "../../engine/core/world/loader/WorldLoader.hpp"

namespace Gengine {
    class GameState : public BaseGameState {
    public:
        GameState(GameComponentsRef data) : BaseGameState(data), _player(data) {};
        ~GameState() {};
        void init();
        void handleInput(sf::Event event, const float dt);
        void update(float dt);
        void draw(float dt);
        void pause();
        void resume();
    private:
        sf::Clock _clock;
        WorldLoader _worldLoader;
        WorldPtr _world;
        Player _player;
    };
} // namespace Gengine