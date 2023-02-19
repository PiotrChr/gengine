#include "GameManager.hpp"

namespace Gengine {
    GameManager::GameManager(GameData gameData) {
        _game = new Game(gameData, _data);
    }

    GameManager::GameManager() {
        
    }

    void GameManager::init() {
        _game->init();
    }

    void GameManager::pause() {
        _game->pause();
    }

    void GameManager::resume() {
        _game->resume();
    }

    GameManager::~GameManager() {
        delete _game;
    }
}

