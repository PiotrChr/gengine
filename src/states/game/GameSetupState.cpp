#include "GameSetupState.hpp"

namespace Gengine {

    GameSetupState::~GameSetupState() {
        std::cout << "GameSetupState destroyed" << std::endl;
    }

    void GameSetupState::init() {
        auto generateWorldButton = std::make_shared<MainMenuButton>(
            _data, "Generate World", sf::Vector2f(400, 100),
            [this]() {
                this->generateWorld();
            }
        );
        generateWorldButton->setSize(sf::Vector2f(400, 100));

        auto backButton = std::make_shared<MainMenuButton>(
            _data, "Back", sf::Vector2f(400, 100),
            [this]() {
                _data->stateMachine.removeState();
            }
        );
        backButton->setSize(sf::Vector2f(400, 100));

        auto startGameButton = std::make_shared<MainMenuButton>(
            _data, "Start Game", sf::Vector2f(400, 100),
            [this]() {
                _data->stateMachine.addState(StateRef(new GameState(_data)));
            }
        );
        startGameButton->setSize(sf::Vector2f(400, 100));

        generateWorldButton->init();
        backButton->init();
        startGameButton->init();

        generateWorldButton->setPosition(sf::Vector2f(
            _data->windowManager.width/2 - generateWorldButton->getSize().x/2,
            _data->windowManager.height/2 - generateWorldButton->getSize().y/2 - 100
        ));
        startGameButton->setPosition(sf::Vector2f(
            generateWorldButton->getPosition().x,
            generateWorldButton->getPosition().y + generateWorldButton->getSize().y + 10
        ));
        backButton->setPosition(sf::Vector2f(
            generateWorldButton->getPosition().x,
            startGameButton->getPosition().y + startGameButton->getSize().y + 10
        ));

        _hud.addComponent(generateWorldButton);
        _hud.addComponent(backButton);
        _hud.addComponent(startGameButton);
    }

    void GameSetupState::generateWorld() {
        std::cout << "Initialize World" << std::endl;
        WorldPtr world = _worldGenerator.initializeWorld();
        std::cout << "Generate World" << std::endl;
        _worldGenerator.generateWorld(world);
        std::cout << "Saving World" << std::endl;
        _worldLoader.saveWorld(world->getChunks());
        std::cout << "Done Saving World" << std::endl;
    }

    void GameSetupState::handleInput(sf::Event event, const float dt) {
        _hud.handleEvent(event, dt);
    }

    void GameSetupState::update(float dt) {
        _hud.update(dt);
    }

    void GameSetupState::draw(float dt) {
        _data->windowManager.window->clear(sf::Color::Black);
        
        _hud.draw(_data->windowManager.window);
        
        _data->windowManager.window->display();
    }

    void GameSetupState::pause() {
        std::cout << "OptionsState paused" << std::endl;
    }

    void GameSetupState::resume() {
        std::cout << "OptionsState resumed" << std::endl;
    }
}