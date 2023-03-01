#include "QuitState.hpp"

namespace Gengine {
    void QuitState::init() {
        _data->assetManager.loadTexture("Quit Background", QUIT_SCENE_BACKGROUND_FILEPATH);
        _background.setTexture(_data->assetManager.getTexture("Quit Background"));
    }

    void QuitState::handleInput(sf::Event event) {
        if (sf::Event::KeyPressed == event.type)
        {
            if (sf::Keyboard::Escape == event.key.code)
            {
                _data->windowManager.window->close();
            }
        }
    }

    void QuitState::update(float dt) {
        if (_clock.getElapsedTime().asSeconds() > QUIT_STATE_SHOW_TIME)
        {
            // Quit the game
            _data->windowManager.window->close();
            
        }
    }

    void QuitState::draw(float dt) {
        _data->windowManager.window->clear();
        _data->windowManager.window->draw(_background);
        _data->windowManager.window->display();
    }

    void QuitState::pause() {
        
    }

    void QuitState::resume() {
        
    }
} // namespace Gengine