#pragma once

#include "../core/asset/AssetManager.hpp"
#include "../core/state/StateMachine.hpp"
#include "../core/window/WindowManager.hpp"
#include "../core/input/InputManager.hpp"
#include "../core/object/ObjectManager.hpp"
#include "../core/audio/AudioManager.hpp"
#include "../core/gfx/RenderManager.hpp"

namespace Gengine {
    struct GameComponents {
        AssetManager assetManager;
        InputManager inputManager;
        WindowManager windowManager;
        ObjectManager objectManager;
        StateMachine stateMachine;
        AudioManager audioManager;
        RenderManager renderManager;
    };

    typedef std::shared_ptr<GameComponents> GameComponentsRef;
}
