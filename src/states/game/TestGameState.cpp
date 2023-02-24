#include "TestGameState.hpp"

namespace Gengine {
    TestGameState::TestGameState(GameComponentsRef& data) : BaseGameState(data), _player(data) {
        
    }

    void TestGameState::init() {
        _data->assetManager.loadTexture("TestGameState Background", TEST_GAME_STATE_BACKGROUND_FILEPATH);
        _background.setTexture(_data->assetManager.getTexture("TestGameState Background"));

        _data->assetManager.loadTexture("TestGameState Sprite", TEST_GAME_STATE_SPRITE_FILEPATH);
        _testingSprite.setTexture(_data->assetManager.getTexture("TestGameState Sprite"));

        _testingSprite.setPosition(
            _data->windowManager.window->getSize().x - _testingSprite.getGlobalBounds().width - 10,
            10
        );
    }
    
    void TestGameState::handleInput(sf::Event event) {
        if (sf::Event::KeyPressed == event.type)
        {
            if (sf::Keyboard::Escape == event.key.code)
            {
                _data->stateMachine.removeState();
            }
        }
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