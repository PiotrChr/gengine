#include "RenderManager.hpp"

namespace Gengine {
    void RenderManager::add2DLayer(std::string layerName) {
        std::vector<GameObjectRef> layer;
        
        _layers2D[layerName] = layer;
    };

    void RenderManager::addTo2DLayer(std::string layerName, GameObjectRef gameObject) {
        _layers2D[layerName].push_back(gameObject);
    };

    std::vector<GameObjectRef> RenderManager::popLayer(std::string layerName) {
        std::vector<GameObjectRef> layer = _layers2D[layerName];
        // _layers2D[layerName].clear();

        return layer;
    };

    void RenderManager::removeFrom2DLayer(std::string layerName, GameObjectRef gameObject) {
        std::vector<GameObjectRef>& layer = _layers2D[layerName];
        
        for (int i = 0; i < layer.size(); i++) {
            if (layer[i] == gameObject) {
                layer.erase(layer.begin() + i);
            }
        }
    };

    void RenderManager::removeAll2DLayers() {
        _layers2D.clear();
    };

    void RenderManager::removeLayer(std::string layerName) {
        _layers2D.erase(layerName);
    };
}