#include "Game.hpp"

namespace Gengine {
    Game::Game(GameData gameData, GameComponentsRef data) : _data(data) {
        _res_w = gameData.width;
        _res_h = gameData.height;
        _title = gameData.title;

    }

    Game::~Game() {

    }

    void Game::draw(float dt) {

    }

    void Game::update(float dt) {

    }

    void Game::resume() {

    }

    void Game::pause() {

    }

    void Game::init() {
        // _data->stateMachine.addState(StateRef(new SplashState(_data)), true);
        
        std::cout << "Initializing game..." << std::endl;

        _data->windowManager.setTitle(_title);
        _data->windowManager.init();

        this->run();
    }

    bool Game::isRunning() {
        return this->_data->windowManager.isOpen();
    }

    void Game::run() {
        float newTime, frameTime, interpolation;

        // float currentTime = this->_clock.getElapsedTime().asSeconds();
        float accumulator = 0.0f;

        while(this->isRunning()) {
            glfwPollEvents();
            
        }
    }
}