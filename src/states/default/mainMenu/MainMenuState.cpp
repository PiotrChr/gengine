#include "MainMenuState.hpp"
#include "../quit/QuitState.hpp"

namespace Gengine {
    void MainMenuState::init() {
        _data->assetManager.loadTexture("Main Menu Background", MM_SCENE_BACKGROUND_FILEPATH);
        _background.setTexture(_data->assetManager.getTexture("Main Menu Background"));

        _data->assetManager.loadTexture("Play button", MM_SCENE_BUTTON_PLAY);
        _playButton.setTexture(_data->assetManager.getTexture("Play button"));
        _playButton.setPosition(
            DEFAULT_SCREEN_WIDTH / 2 - _playButton.getGlobalBounds().width / 2,
            DEFAULT_SCREEN_WIDTH / 2 - _playButton.getGlobalBounds().height / 2
        );

        _data->assetManager.loadTexture("Button outer", MM_SCENE_BUTTON_OUTER);
        _playButtonOuter.setTexture(_data->assetManager.getTexture("Button outer"));
        _playButtonOuter.setPosition(
            DEFAULT_SCREEN_WIDTH / 2 - _playButtonOuter.getGlobalBounds().width / 2,
            DEFAULT_SCREEN_WIDTH / 2 - _playButtonOuter.getGlobalBounds().height / 2
        );

        _data->assetManager.loadTexture("Test button", MM_SCENE_BUTTON_TEST);
        _testButton.setTexture(_data->assetManager.getTexture("Test button"));
        _testButton.setPosition(
            DEFAULT_SCREEN_WIDTH / 2 - _testButton.getGlobalBounds().width / 2,
            DEFAULT_SCREEN_WIDTH / 2 - _testButton.getGlobalBounds().height / 2 + 100
        );

        _data->assetManager.loadTexture("Quit button", MM_SCENE_BUTTON_QUIT);
        _quitButton.setTexture(_data->assetManager.getTexture("Quit button"));
        _quitButton.setPosition(
            DEFAULT_SCREEN_WIDTH / 2 - _quitButton.getGlobalBounds().width / 2,
            DEFAULT_SCREEN_WIDTH / 2 - _quitButton.getGlobalBounds().height / 2 + 200
        );

        _data->assetManager.loadTexture("Logo", MM_SCENE_LOGO_FILEPATH);
        _title.setTexture(_data->assetManager.getTexture("Logo"));
        _title.setPosition(
            DEFAULT_SCREEN_WIDTH / 2 - _title.getGlobalBounds().width / 2,
            DEFAULT_SCREEN_WIDTH / 2 - _title.getGlobalBounds().height / 2 - 200
        );        
    }
    
    void MainMenuState::handleInput(sf::Event event) {
        if (sf::Event::MouseButtonPressed) {
            if (_data->inputManager.isSpriteClicked(_playButton, sf::Mouse::Left, _data->windowManager.window)) {
                std::cout << "Play button clicked" << std::endl;
            }
            if (_data->inputManager.isSpriteClicked(_testButton, sf::Mouse::Left, _data->windowManager.window)) {
                std::cout << "Test button clicked" << std::endl;
            }
            if (_data->inputManager.isSpriteClicked(_quitButton, sf::Mouse::Left, _data->windowManager.window)) {
                // Sets new state to quit state
                _data->stateMachine.addState(StateRef(new QuitState(_data)), true);
            }
        }
    }
    
    void MainMenuState::update(float dt) {
        
    }
    
    void MainMenuState::draw(float dt) {
        _data->windowManager.window.clear(sf::Color::Red);
        _data->windowManager.window.draw(_background);
        _data->windowManager.window.draw(_playButtonOuter);
        _data->windowManager.window.draw(_playButton);
        _data->windowManager.window.draw(_testButton);
        _data->windowManager.window.draw(_quitButton);
        _data->windowManager.window.draw(_title);

        _data->windowManager.window.display();
    }
    
    void MainMenuState::pause() {
        
    }
    
    void MainMenuState::resume() {
        
    }
}