#pragma once

#include "GameObject.hpp"
#include <SFML/Graphics.hpp>

namespace Gengine {
    class InGameObject : public GameObject
    {
    public:
        InGameObject(GameComponentsRef data) : GameObject(data) {};
        virtual ~InGameObject() {};

        void setPosition(float x, float y, float z);
        void getPosition(float& x, float& y, float& z);
        float getSpeed();
        void setSpeed(float speed);

        bool getMovingUp();
        bool getMovingDown();
        bool getMovingLeft();
        bool getMovingRight();
        void setMovingUp(bool moving);
        void setMovingDown(bool moving);
        void setMovingLeft(bool moving);
        void setMovingRight(bool moving);

        virtual void move(const float x, const float y, const float z, const float& dt) = 0;
        virtual void update(const float& dt) = 0;
        virtual void draw(sf::RenderTarget* target) = 0;
        
    private: 
        bool _moving_up;
        bool _moving_down;
        bool _moving_left;
        bool _moving_right;
        int _pos_x;
        int _pos_y;
        int _pos_z;
        int _width;
        int _height;
        int _depth;
        float _speed;
       
    };
}