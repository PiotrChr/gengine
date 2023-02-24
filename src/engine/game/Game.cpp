#include "Game.hpp"
#include "../../states/default/splash/SplashState.hpp"

namespace Gengine {
    Game::Game(GameData gameData, GameComponentsRef& data) : _data(data) {
        _res_w = gameData.width;
        _res_h = gameData.height;
        _title = gameData.title;

        
        _data->stateMachine.addState(StateRef(new SplashState(_data)), true);
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
        std::cout << "Initializing game..." << std::endl;

        _data->windowManager.init(_title);

        this->run();
    }

    bool Game::isRunning() {
        return this->_data->windowManager.isOpen();
    }

    void Game::run() {
        float newTime, frameTime, interpolation;

        float currentTime = this->_clock.getElapsedTime().asSeconds();
        float accumulator = 0.0f;

        while(this->isRunning()) {
            this->_data->stateMachine.processStateChanges();
            
            newTime = this->_clock.getElapsedTime().asSeconds();

            frameTime = newTime - currentTime;

            if (frameTime > 0.25f) {
                frameTime = 0.25f;
            }

            currentTime = newTime;
            accumulator += frameTime;

            StateRef &activeState = this->_data->stateMachine.getActiveState();

            while (accumulator >= dt) {
                activeState->handleEvents();
                activeState->update(dt);
                
                accumulator -= dt;
            }
            interpolation = accumulator / dt;
            activeState->draw(interpolation);
        }
    }
}