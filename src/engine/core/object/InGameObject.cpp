#include "InGameObject.hpp"

namespace Gengine
{
    void InGameObject::setPosition(float x, float y, float z)
    {
        _pos_x = x;
        _pos_y = y;
        _pos_z = z;
    }

    void InGameObject::setSpeed(float speed)
    {
        _speed = speed;
    }

    void InGameObject::getPosition(float& x, float& y, float& z)
    {
        x = _pos_x;
        y = _pos_y;
        z = _pos_z;
    }

    float InGameObject::getSpeed()
    {
        return _speed;
    }

    bool InGameObject::getMovingUp()
    {
        return _moving_up;
    }

    bool InGameObject::getMovingDown()
    {
        return _moving_down;
    }

    bool InGameObject::getMovingLeft()
    {
        return _moving_left;
    }

    bool InGameObject::getMovingRight()
    {
        return _moving_right;
    }

    void InGameObject::setMovingUp(bool moving)
    {
        _moving_up = moving;
    }

    void InGameObject::setMovingDown(bool moving)
    {
        _moving_down = moving;
    }

    void InGameObject::setMovingLeft(bool moving)
    {
        _moving_left = moving;
    }

    void InGameObject::setMovingRight(bool moving)
    {
        _moving_right = moving;
    }

} // namespace Gengine