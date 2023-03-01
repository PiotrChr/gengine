#include "TestGameState.hpp"

namespace Gengine {
    TestGameState::TestGameState(GameComponentsRef& data) : BaseGameState(data), _player(data) {
        
    }

    void TestGameState::init() {
        _data->assetManager.loadTexture("TestGameState Background", TEST_GAME_STATE_BACKGROUND_FILEPATH);
        _background.setTexture(_data->assetManager.getTexture("TestGameState Background"));
        scaleToWindow(_background);

        _data->assetManager.loadTexture("TestGameState Sprite", TEST_GAME_STATE_SPRITE_FILEPATH);
        _testingSprite.setTexture(_data->assetManager.getTexture("TestGameState Sprite"));

        _testingSprite.setPosition({_data->windowManager.window->getSize().x - _testingSprite.getGlobalBounds().width - 10, 10});
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
    }
    
    void TestGameState::update(float dt) {
        _player.update(dt);
    }
    
    void TestGameState::draw(float dt) {
        _data->windowManager.window->clear();
        _data->windowManager.window->draw(_background);
        _data->windowManager.window->draw(_testingSprite);

        _player.draw(_data->windowManager.window);
        _data->windowManager.window->display();
    }
    
    void TestGameState::pause() {
        
    }
    
    void TestGameState::resume() {
        
    }
}