#pragma once

#include "../../DEFINITIONS.hpp"
#include "../../game/GameComponents.hpp"

namespace Gengine {
    class GameObject
    {
    public:
        GameObject(GameComponentsRef data) : _data(data) {};
        GameObject() {};
        virtual ~GameObject() {};
    protected:
        GameComponentsRef _data;
    };
}
    