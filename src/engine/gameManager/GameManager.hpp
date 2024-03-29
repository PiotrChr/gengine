
#pragma once 

#include "../game/Game.hpp"
#include "GameData.hpp"
#include "../game/GameComponents.hpp"
#include "../core/save/SettingsLoader.hpp"

namespace Gengine {
    class GameManager {
    public:
        GameManager(GameData gameData);
        GameManager();
        ~GameManager();
        void init();
        void pause();
        void resume();
    private:
        Game* _game;
        GameComponentsRef _data;
        SettingsLoader* _settingsLoader;
    };
}
