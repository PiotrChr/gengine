#pragma once

#include <map>
#include <vector>
#include "../object/Entity.hpp"

namespace Gengine {
    typedef Entity* GameObjectRef;

    class RenderManager {
    public:
        RenderManager() {};
        ~RenderManager() {};

        void add2DLayer(std::string layerName);
        void addTo2DLayer(std::string layerName, GameObjectRef entity);
        std::vector<GameObjectRef> popLayer(std::string layerName);
    private:
        std::map<std::string, std::vector<GameObjectRef>> _layers2D;
    };
}