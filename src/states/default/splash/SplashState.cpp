#include "SplashState.hpp"
#include "../mainMenu/MainMenuState.hpp"

namespace Gengine {
    void SplashState::init() {
        _data->assetManager.loadTexture("Splash State Background", SPLASH_SCENE_BACKGROUND_FILEPATH);
        _background.setTexture(_data->assetManager.getTexture("Splash State Background"));
    }
    
    void SplashState::handleInput(sf::Event event) {
        
    }

    void SplashState::update(float dt) {
        if (_clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME) {
            _data->stateMachine.addState(StateRef(new MainMenuState(_data)), true);
            
        }
    }
    
    void SplashState::pause() {
        
    }

    void SplashState::resume() {
        
    }

    void SplashState::draw(float dt) {
        _data->windowManager.window->clear(sf::Color::Red);
        _data->windowManager.window->draw(_background);
        _data->windowManager.window->display();
    }
}