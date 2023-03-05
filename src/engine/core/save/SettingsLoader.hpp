#include "../../game/GameComponents.hpp"

#pragma once

#include <fstream>
#include <iostream>
#include <sstream>
#include "../../DEFINITIONS.hpp"
#include "../../utils/window.hpp"

namespace Gengine
{
    typedef std::shared_ptr<GameComponents> GameComponentsRef;

    class SettingsLoader
    {
    public:
        SettingsLoader() {};
        ~SettingsLoader() {};
        void loadSettings(GameComponentsRef& data);
        void saveSettings(GameComponentsRef& data);
        void createSettingsFile();
    };
} // namespace Gengine