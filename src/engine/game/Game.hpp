#pragma once

#include <memory>
#include <string>
#include "GameComponents.hpp"
#include "../gameManager/GameData.hpp"
// #include "../../states/default/splash/SplashState.hpp"

namespace Gengine {
    class Game {
    public:
        Game(GameData gameData, GameComponentsRef data);
        ~Game();
        void init();
        void draw(float dt);
        void update(float dt);
        void pause();
        void resume();
    private:
        int _res_w;
        int _res_h;
        bool _paused;
        std::string _title;
        const float dt = 1.0f / 60.0f;
        // sf::Clock _clock;
        GameComponentsRef _data;
        bool isRunning();
        void run();
    };
}
