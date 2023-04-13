#pragma once

#include "HudObject.hpp"
#include <vector>
#include <memory>

namespace Gengine {
    class Hud {
    public:
        void update(float dt);
        void draw(sf::RenderTarget* target);
        void addComponent(HudObjectRef component);
        void handleEvent(sf::Event event, float dt);
    private:
        std::vector<HudObjectRef> _components;
        void sortComponents();
    };
}