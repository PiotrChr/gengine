#pragma once

#include "../../engine/core/object/InGameObject.hpp"

namespace Gengine {
    class TestPlayer : public InGameObject
    {
    public:
        TestPlayer(GameComponentsRef data);
        ~TestPlayer() {};

        void update(const float& dt);
        void move(const float dir_x, const float dir_y, const float dir_z, const float& dt);
        void draw(sf::RenderTarget* target);
    private:
        sf:: RectangleShape shape;
    };
}
