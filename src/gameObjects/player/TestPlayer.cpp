#include "TestPlayer.hpp"

namespace Gengine
{
    TestPlayer::TestPlayer(GameComponentsRef data) : InGameObject(data)
    {
        shape.setSize(sf::Vector2f(50, 100));
        shape.setFillColor(sf::Color::Red);
        shape.setPosition(100, 100);

        setSpeed(100.f);
    }

    void TestPlayer::update(const float& dt)
    {
        if (_data->inputManager.isElemClicked(shape, sf::Mouse::Left, _data->windowManager.window)) {
            shape.setFillColor(sf::Color::Green);
        }

        if (_data->inputManager.isElemClicked(shape, sf::Mouse::Right, _data->windowManager.window)) {
            shape.setFillColor(sf::Color::Red);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            move(-1, 0, 0, dt);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            move(1, 0, 0, dt);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            move(0, -1, 0, dt);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            move(0, 1, 0, dt);
        }
    }

    void TestPlayer::draw(sf::RenderTarget* target)
    {
        target->draw(shape);
    }

    void TestPlayer::move(const float dir_x, const float dir_y, const float dir_z, const float& dt)
    {
        float speed = getSpeed();
        shape.move(dir_x * speed * dt, dir_y * speed * dt);
    }
} // namespace Gengine