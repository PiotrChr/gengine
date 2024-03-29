#include "StateMachine.hpp"

namespace Gengine {
    void StateMachine::addState(StateRef newState, bool isReplacing) {
        this->_isAdding = true;
        this->_isReplacing = isReplacing;
        this->_newState = std::move(newState);
    }

    void StateMachine::removeState() {
        this->_isRemoving = true;
    }

    void StateMachine::processStateChanges() {
        if (this->_isRemoving == true && !this->_states.empty() ) {
            std::cout << "Removing state" << std::endl;
            this->_isRemoving = false;
            this->getActiveState()->cleanup();
            this->_states.pop();

            if (!this->_states.empty()) {
                this->_states.top()->resume();
            }
        }

        if (this->_isAdding) {
            if (!this->_states.empty()) {
                if (!this->_isReplacing) {
                    this->_states.pop();
                } else {
                    this->_states.top()->pause();
                }
            }

            this->_states.push(std::move(this->_newState));
            this->_states.top()->init();

            this->_isAdding = false;
        }
    }

    StateRef& StateMachine::getActiveState() {
        return this->_states.top();
    }
}