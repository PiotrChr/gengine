#pragma once

#include <memory>
#include <stack>
#include <iostream>

#include "State.hpp"

namespace Gengine {
    typedef std::unique_ptr<State> StateRef;

    class StateMachine {
    public:
        void addState(StateRef newState, bool isReplacing = true);
        void removeState();
        void processStateChanges();
        StateRef& getActiveState();
    private:
        std::stack<StateRef> _states;
        StateRef _newState;
        
        bool _isRemoving = false;
        bool _isAdding = false;
        bool _isReplacing = false;
    
    };
}