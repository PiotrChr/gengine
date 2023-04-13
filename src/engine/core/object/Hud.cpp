#include "Hud.hpp"

namespace Gengine {

    void Hud::update(float dt) {
        for (auto& component : _components) {
            if (component->isActive()) {
                component->update(dt);
            }
        }
    };

    void Hud::draw(sf::RenderTarget* target) {
        for (const auto& component : _components) {
            if (component->isActive()) {
                component->draw(target);
            }
        }
    };

    void Hud::sortComponents() {
        std::sort(_components.begin(), _components.end(),
                [](const auto& a, const auto& b) { return a->getZIndex() < b->getZIndex(); });
    };

    void Hud::addComponent(HudObjectRef component) {
        if (component->hasChildren()) {
            const auto& children = component->getChildren();
            for (const auto& child : children) {
                this->addComponent(child);
            }
        } else {
            _components.emplace_back(component);
        }

        this->sortComponents();
    };

    void Hud::handleEvent(sf::Event event, float dt) {
        for (auto it = _components.rbegin(); it != _components.rend(); ++it) {
            auto& component = *it;
            if (component->isActive()) {
                bool handled = component->handleInput(event, dt);
                if (handled) {
                    break;
                }
            }
        }
    };
}