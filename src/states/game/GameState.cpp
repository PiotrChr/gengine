#include "GameState.hpp"

namespace Gengine {
    void GameState::init() {
        _clock.restart();

        _player.setPositionInBlocks(sf::Vector3i(
            INITIAL_WORLD_SIZE_X_IN_CHUNKS * CHUNK_SIZE_X / 2,
            INITIAL_WORLD_SIZE_Y_IN_CHUNKS * CHUNK_SIZE_Y / 2,
            INITIAL_WORLD_SIZE_Z_IN_CHUNKS * CHUNK_SIZE_Z / 2
        ));
        
        _world = std::make_shared<World>();
        
        auto initChunk = _worldLoader.loadChunk(_player.getChunkPosition());

        if (initChunk == nullptr) {
            throw std::runtime_error("Could not load initial chunk");
        }

        std::cout << "Initial chunk loaded" << std::endl;
        
        _world->addChunk(initChunk);

        _world->addPlayer(&_player);

        std::cout << "World State Init" << std::endl;

        _world->init();

        std::cout << "World State Init Complete" << std::endl;
    }

    void GameState::handleInput(sf::Event event, const float dt) {
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Escape) {
                _data->stateMachine.addState(StateRef(new MainMenuState(_data)), true);
            }
        }

        _player.handleInput(event, dt);

    }

    void GameState::update(float dt) {
        sf::Time time = _clock.getElapsedTime();
        if (time.asSeconds() > 1) {
            _clock.restart();
            std::cout << "1 second has passed" << std::endl;
        }

        _world->update(dt);
    }

    void GameState::draw(float dt) {
        _data->windowManager.window->clear(sf::Color::Black);
        _data->windowManager.enableGLStates();

        _world->draw(_data->windowManager.window);

        _data->windowManager.window->display();
    }

    void GameState::pause() {
        std::cout << "Game Paused" << std::endl;
    }

    void GameState::resume() {
        std::cout << "Game Resumed" << std::endl;
    }
}