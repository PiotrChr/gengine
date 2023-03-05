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

        void setPosition(sf::Vector2f position);
        void setSize(sf::Vector2f size);
        void getPosition(int& x, int& y);

        void update(const float& dt);
        void draw(sf::RenderTarget& target);
    protected:
        sf::Vector2f _position;
        sf::Vector2f _size;
    private: 
        int _pos_x;
        int _pos_y;
        int _width;
        int _height;
    };
}