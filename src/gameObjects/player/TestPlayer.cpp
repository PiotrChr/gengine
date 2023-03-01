#include "TestPlayer.hpp"

namespace Gengine
{
    TestPlayer::TestPlayer(GameComponentsRef data) : InGameObject(data)
    {
        shape.setSize(sf::Vector2f(50, 100));
        shape.setFillColor(sf::Color::Red);
        shape.setPosition({100.0f, 100.0f});

        setSpeed(100.f);
    }

    void TestPlayer::handleInput(sf::Event event, const float dt) {
        std::cout << "TestPlayer::handleInput" << std::endl;
        std::cout << "event.type: " << event.type << std::endl;
        std::cout << "event.key.code: " << event.key.code << std::endl;

        std::cout << _data->inputManager.keyBinds["LEFT"] << std::endl;

        if (sf::Event::KeyPressed == event.type) {
            if (_data->inputManager.keyBinds["MOVE_LEFT"] == event.key.code) {
                setMovingLeft(true);
            } else if (_data->inputManager.keyBinds["MOVE_RIGHT"] == event.key.code) {
                setMovingRight(true);
            } else if (_data->inputManager.keyBinds["MOVE_UP"] == event.key.code) {
                setMovingUp(true);
            } else if (_data->inputManager.keyBinds["MOVE_DOWN"] == event.key.code) {
                setMovingDown(true);
            }
        }

        if (sf::Event::KeyReleased == event.type) {
            if (_data->inputManager.keyBinds["MOVE_LEFT"] == event.key.code) {
                setMovingLeft(false);
            } else if (_data->inputManager.keyBinds["MOVE_RIGHT"] == event.key.code) {
                setMovingRight(false);
            } else if (_data->inputManager.keyBinds["MOVE_UP"] == event.key.code) {
                setMovingUp(false);
            } else if (_data->inputManager.keyBinds["MOVE_DOWN"] == event.key.code) {
                setMovingDown(false);
            }
        }
    }

    void TestPlayer::update(const float& dt)
    {
        if (_data->inputManager.isElemClicked(shape, sf::Mouse::Left, _data->windowManager.window)) {
            shape.setFillColor(sf::Color::Green);
        }

        if (_data->inputManager.isElemClicked(shape, sf::Mouse::Right, _data->windowManager.window)) {
            shape.setFillColor(sf::Color::Red);
        }

        if (getMovingDown()) {
            move(0, 1, 0, dt);
        }

        if (getMovingUp()) {
            move(0, -1, 0, dt);
        }

        if (getMovingLeft()) {
            move(-1, 0, 0, dt);
        }

        if (getMovingRight()) {
            move(1, 0, 0, dt);
        }
    }

    void TestPlayer::draw(sf::RenderTarget* target)
    {
        target->draw(shape);
    }

    void TestPlayer::move(const float dir_x, const float dir_y, const float dir_z, const float& dt)
    {
        float speed = getSpeed();
        shape.move({dir_x * speed * dt, dir_y * speed * dt});
    }
} // namespace Gengine