#include "MainMenuState.hpp"
#include "../quit/QuitState.hpp"
#include "../../game/TestGameState.hpp"

namespace Gengine {
    void MainMenuState::init() {
        _data->assetManager.loadTexture("Main Menu Background", MM_SCENE_BACKGROUND_FILEPATH);
        _background.setTexture(_data->assetManager.getTexture("Main Menu Background"));
        scaleToWindow(_background);
        
        _data->assetManager.loadTexture("Logo", MM_SCENE_LOGO_FILEPATH);
        _title.setTexture(_data->assetManager.getTexture("Logo"));
        _title.setPosition({
            _data->windowManager.width / 2 - _title.getGlobalBounds().width / 2,
            _data->windowManager.height / 2 - _title.getGlobalBounds().height / 2 - 300
        });        

        _playButton = MainMenuButton(_data, "Play", {
            _data->windowManager.width / 2 - _playButton.getSize().x / 2,
            _data->windowManager.height / 2 - _playButton.getSize().y / 2 - 100
        }, []() {
            std::cout << "Play button pressed" << std::endl;
        });
        _playButton.init();

        _testButton = MainMenuButton(_data, "Test", {
            _data->windowManager.width / 2 - _testButton.getSize().x / 2,
            _data->windowManager.height / 2 - _testButton.getSize().y / 2
        }, [this]() {
            _data->stateMachine.addState(StateRef(new TestGameState(_data)), false);
        });
        _testButton.init();

        _quitButton = MainMenuButton(_data, "Quit", {
            _data->windowManager.width / 2 - _quitButton.getSize().x / 2,
            _data->windowManager.height / 2 - _quitButton.getSize().y / 2 + 100
        }, [this]() {
            _data->stateMachine.addState(StateRef(new QuitState(_data)), true);
        });
        _quitButton.init();
    
    }
    
    void MainMenuState::handleInput(sf::Event event, const float dt) {
        _playButton.handleInput(event, dt);
        _testButton.handleInput(event, dt);
        _quitButton.handleInput(event, dt);
    }
    
    void MainMenuState::update(float dt) {
        _playButton.update(dt);
        _testButton.update(dt);
        _quitButton.update(dt);
    }
    
    void MainMenuState::draw(float dt) {
        _data->windowManager.window->clear(sf::Color::Red);
        _data->windowManager.window->draw(_background);

        _playButton.draw(_data->windowManager.window);
        _testButton.draw(_data->windowManager.window);
        _quitButton.draw(_data->windowManager.window);

        _data->windowManager.window->draw(_title);

        _data->windowManager.window->display();
    }
    
    void MainMenuState::pause() {
        
    }
    
    void MainMenuState::resume() {
        
    }
}