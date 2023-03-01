#pragma once

#include "GameObject.hpp"
#include <SFML/Graphics.hpp>

namespace Gengine {
    class HudObject : public GameObject
    {
    public:
        HudObject(GameComponentsRef data) : GameObject(data) {};
        HudObject() {};
        virtual ~HudObject() {};

        void setPosition(int x, int y);
        void setSize(int width, int height);
        void getPosition(int& x, int& y);

        void update(const float& dt);
        void draw(sf::RenderTarget& target);
    private: 
        int _pos_x;
        int _pos_y;
        int _width;
        int _height;
    };
}