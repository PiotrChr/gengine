#include "HudObject.hpp"

namespace Gengine {
    
    void HudObject::setZIndex(int zIndex) {
        this->_zIndex = zIndex;
    }

    int HudObject::getZIndex() {
        return this->_zIndex;
    }

    bool HudObject::hasChildren() {
        return this->_children.size() > 0;
    }

    bool HudObject::isActive() {
        return this->_active;
    }

    void HudObject::setActive(bool active) {
        this->_active = active;
    }

    std::vector<HudObjectRef>& HudObject::getChildren() {
        return this->_children;
    }

    void HudObject::addChild(std::shared_ptr<HudObject> child) {
        this->_children.push_back(std::move(child));
    }

    void HudObject::setPosition(sf::Vector2f position) {
        this->_position = position;
    }

    void HudObject::getPosition(int& x, int& y) {
        x = this->_pos_x;
        y = this->_pos_y;
    }

    bool HudObject::contains(sf::Vector2i mousePos) {
        return this->_bounds.contains({float(mousePos.x), float(mousePos.y)});
    }
}