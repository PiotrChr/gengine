#include "BaseState.hpp"

namespace Gengine {
    void BaseState::init() {};
    void BaseState::handleInput() {};
    void BaseState::update(float dt) {};
    void BaseState::draw(float dt) {};
    void BaseState::pause() {};
    void BaseState::resume() {};

    void BaseState::handleEvents() {
        
    }
        
    void BaseState::handleDefaultInput()
    {
        
        
    }
} // namespace Gengine