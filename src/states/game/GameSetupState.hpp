#pragma once

#include <SFML/Graphics.hpp>
#include "BaseGameState.hpp"
#include "../../gameObjects/player/TestPlayer.hpp"
#include "../../engine/core/object/Hud.hpp"
#include "../../engine/core/world/generator/WorldGenerator.hpp"
#include "../../engine/core/world/loader/WorldLoader.hpp"
#include "../../gameObjects/hud/mainMenu/MainMenuButton.hpp"
#include "GameState.hpp"

namespace Gengine {
    class GameSetupState : public BaseGameState {
    public:
        GameSetupState(GameComponentsRef data) : BaseGameState(data) {};
        ~GameSetupState();
        void init();
        void handleInput(sf::Event event, const float dt);
        void cleanup() {};
        void update(float dt);
        void draw(float dt);
        void pause();
        void resume();
    private:
        void generateWorld();
        Hud _hud;
        WorldGenerator _worldGenerator;
        WorldLoader _worldLoader;
    };
}