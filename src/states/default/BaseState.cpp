#include "BaseState.hpp"

namespace Gengine {
    void BaseState::init() {};
    void BaseState::handleInput(sf::Event event) {};
    void BaseState::update(float dt) {};
    void BaseState::draw(float dt) {};
    void BaseState::pause() {};
    void BaseState::resume() {};

    void BaseState::handleEvents() {
        sf::Event event;

        while (_data->windowManager.window.pollEvent(event))
        {
            this->handleDefaultInput(event);
            
            this->handleInput(event);
        }
    
    }
        
    void BaseState::handleDefaultInput(sf::Event event)
    {
        if (sf::Event::Closed == event.type)
        {
            _data->windowManager.window.close();
        }
        
    }
} // namespace Gengine