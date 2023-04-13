#pragma once

#include "GameObject.hpp"
#include <SFML/Graphics.hpp>

namespace Gengine {
    class HudObject : public GameObject
    {
    public:
        HudObject(GameComponentsRef data) : GameObject(data) {};
        HudObject() {};
        virtual ~HudObject() {};

        void setPosition(sf::Vector2f position);
        void getPosition(int& x, int& y);
        
        void setActive(bool active);
        bool isActive();

        virtual void update(const float& dt) = 0;
        virtual void draw(sf::RenderTarget* target) = 0;

        virtual bool handleInput(sf::Event event, float dt) = 0;
        bool contains(sf::Vector2i mousePos);

        void addChild(std::shared_ptr<HudObject> child);
        bool hasChildren();
        std::vector<std::shared_ptr<HudObject>>& getChildren();

        void setZIndex(int zIndex);
        int getZIndex();
    protected:
        sf::Vector2f _position;
        sf::Vector2f _size;
        sf::Rect<float> _bounds;
    private:
        std::vector<std::shared_ptr<HudObject>> _children;
        bool _active = true;
        int _pos_x;
        int _pos_y;
        int _width;
        int _height;
        int _zIndex = 0;
    };

    typedef std::shared_ptr<HudObject> HudObjectRef;
}