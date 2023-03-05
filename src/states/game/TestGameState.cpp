#include "TestGameState.hpp"

namespace Gengine {
    void TestGameState::init() {
        _data->assetManager.loadTexture("TestGameState Background", TEST_GAME_STATE_BACKGROUND_FILEPATH);
        _background.setTexture(_data->assetManager.getTexture("TestGameState Background"));
        scaleToWindow(_background);

        _data->assetManager.loadTexture("TestGameState Sprite", TEST_GAME_STATE_SPRITE_FILEPATH);
        _testingSprite.setTexture(_data->assetManager.getTexture("TestGameState Sprite"));

        _testingSprite.setPosition({_data->windowManager.window->getSize().x - _testingSprite.getGlobalBounds().width - 10, 10});
        
        _mainMenuButton = GameButton(_data, "Main Menu", {0, 0},
        [this]() {
            _data->stateMachine.removeState();
        });
        _mainMenuButton.setPosition({
            _data->windowManager.width - _mainMenuButton.getSize().x - 10,
            _data->windowManager.height - _mainMenuButton.getSize().y - 10
        });
        _mainMenuButton.init();
    }
    
    void TestGameState::handleInput(sf::Event event, const float dt) {  
        if (sf::Event::KeyPressed == event.type)
        {
            std::cout << "TestGameState: Key pressed" << std::endl;
            std::cout << "TestGameState: Key code: " << event.key.code << std::endl;

            if (sf::Keyboard::Escape == event.key.code)
            {
                std::cout << "TestGameState: Escape key pressed, going back to MainMenuState" << std::endl;
                _data->stateMachine.removeState();
            }
        }

        _player.handleInput(event, dt);
        _mainMenuButton.handleInput(event, dt);
    }
    
    void TestGameState::update(float dt) {
        _player.update(dt);
        _mainMenuButton.update(dt);
    }
    
    void TestGameState::draw(float dt) {
        _data->windowManager.window->clear();
        
        _data->windowManager.window->draw(_background);
        _data->windowManager.window->draw(_testingSprite);

        _player.draw(_data->windowManager.window);
        _mainMenuButton.draw(_data->windowManager.window);

        _data->windowManager.window->display();
    }
    
    void TestGameState::pause() {
        
    }
    
    void TestGameState::resume() {
        
    }
}