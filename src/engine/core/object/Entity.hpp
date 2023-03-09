#pragma once

#include <SFML/Graphics.hpp>


namespace Gengine {
    class Entity {
    public:
        Entity() {};
        virtual void draw(sf::RenderTarget* target) = 0;
        virtual ~Entity() {};
    };
}