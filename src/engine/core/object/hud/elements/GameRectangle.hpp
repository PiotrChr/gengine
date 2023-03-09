#pragma once

#include <SFML/Graphics.hpp>
#include "../../Entity.hpp"

namespace Gengine {
    class GameRectangle : public Entity, public sf::RectangleShape {
    public:
        GameRectangle(const sf::Vector2f& size = sf::Vector2f(0, 0)) : sf::RectangleShape(size) {};
        void draw(sf::RenderTarget* target);
        virtual ~GameRectangle() {};
    };
}