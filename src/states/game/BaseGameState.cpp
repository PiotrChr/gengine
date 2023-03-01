#include "BaseGameState.hpp"

namespace Gengine {
    void BaseGameState::init() {
        _data->assetManager.loadTexture("Game Background", GAME_SCENE_BACKGROUND_FILEPATH);
        _background.setTexture(_data->assetManager.getTexture("Game Background"));

    };
    
    void BaseGameState::handleInput(sf::Event event) {};

    void BaseGameState::update(float dt) {};

    void BaseGameState::draw(float dt) {
        _data->windowManager.window->clear();
        _data->windowManager.window->draw(_background);
        _data->windowManager.window->display();
    };

    void BaseGameState::pause() {};

    void BaseGameState::resume() {};

} // namespace Gengine