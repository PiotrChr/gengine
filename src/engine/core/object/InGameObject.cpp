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
} // namespace Gengine