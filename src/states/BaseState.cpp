#include "BaseState.hpp"

namespace Gengine {
    void BaseState::init() {};
    void BaseState::handleInput(sf::Event event, const float dt) {};
    void BaseState::update(float dt) {};
    void BaseState::draw(float dt) {};
    void BaseState::pause() {};
    void BaseState::resume() {};

    void BaseState::handleEvents(const float dt) {
        sf::Event event;

        while (_data->windowManager.window->pollEvent(event))
        {
            this->handleDefaultInput(event);
            
            this->handleInput(event, dt);
        }
    
    }
        
    void BaseState::handleDefaultInput(sf::Event event)
    {
        if (sf::Event::Closed == event.type)
        {
            std::cout << "Event closed" << std::endl;
            _data->windowManager.window->close();
        }
        
    }
    
    void BaseState::scaleToWindow(sf::Sprite& element, sf::Vector2f margin) {
        sf::Vector2f windowSize = sf::Vector2f(_data->windowManager.window->getSize());
        sf::Vector2f elementSize = sf::Vector2f(element.getTexture()->getSize());
        element.setScale({
            (windowSize.x - margin.x) / elementSize.x,
            (windowSize.y - margin.y) / elementSize.y
        });
    }

    void BaseState::centerElement(sf::Sprite& element, sf::Vector2f offset) {
        sf::Vector2f windowSize = sf::Vector2f(_data->windowManager.window->getSize());
        sf::Vector2f elementSize = sf::Vector2f(element.getTexture()->getSize());
        element.setPosition({
            (windowSize.x / 2) - (elementSize.x / 2) + offset.x,
            (windowSize.y / 2) - (elementSize.y / 2) + offset.y
        });
    }

} // namespace Gengine