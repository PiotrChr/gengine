#include "RenderManager.hpp"

namespace Gengine {
    void RenderManager::add2DLayer(std::string layerName) {
        _layers2D[layerName] = std::vector<GameObjectRef>();
    };

    void RenderManager::addTo2DLayer(std::string layerName, GameObjectRef gameObject) {
        _layers2D[layerName].push_back(gameObject);
    };

    std::vector<GameObjectRef> RenderManager::popLayer(std::string layerName) {
        std::vector<GameObjectRef> layer = _layers2D[layerName];
        _layers2D[layerName].clear();

        return layer;
    };

}