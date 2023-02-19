#include "MainMenuState.hpp"

namespace Gengine {
    void MainMenuState::init() {
        _data->assetManager.loadTexture("Main Menu Background", MM_SCENE_BACKGROUND_FILEPATH);
        _background.setTexture(_data->assetManager.getTexture("Main Menu Background"));
    }
    
    void MainMenuState::handleInput(sf::Event event) {
        
    }
    
    void MainMenuState::update(float dt) {
        
    }
    
    void MainMenuState::draw(float dt) {
        _data->windowManager.window.clear(sf::Color::Red);
        _data->windowManager.window.draw(_background);
        _data->windowManager.window.display();
    }
    
    void MainMenuState::pause() {
        
    }
    
    void MainMenuState::resume() {
        
    }
}