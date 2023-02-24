#include "GameManager.hpp"

namespace Gengine {
    GameManager::GameManager(GameData gameData) {
        _game = new Game(gameData, _data);
        _settingsLoader = new SettingsLoader();
    }

    GameManager::GameManager() {
        
    }

    void GameManager::init() {
        _settingsLoader->loadSettings(_data);
        _game->init();
    }

    void GameManager::pause() {
        _game->pause();
    }

    void GameManager::resume() {
        _game->resume();
    }

    GameManager::~GameManager() {
        delete _settingsLoader;
        delete _game;
    }
}

