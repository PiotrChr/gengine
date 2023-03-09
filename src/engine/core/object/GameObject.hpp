#pragma once

#include "../../DEFINITIONS.hpp"
#include "../../game/GameComponents.hpp"
#include "Entity.hpp"

namespace Gengine {
    class GameObject : public Entity
    {
    public:
        GameObject(GameComponentsRef data) : _data(data) {};
        GameObject() {};
        virtual ~GameObject() {};
    protected:
        GameComponentsRef _data;
    };
}
    