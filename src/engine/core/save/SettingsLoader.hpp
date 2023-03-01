#pragma once

#include <fstream>
#include <iostream>
#include <sstream>
#include "../../DEFINITIONS.hpp"
#include "../../game/GameComponents.hpp"
#include "../../utils/window.hpp"

namespace Gengine
{
    class SettingsLoader
    {
    public:
        SettingsLoader() {};
        ~SettingsLoader() {};
        void loadSettings(GameComponentsRef data);
        void saveSettings(GameComponentsRef data);
        void createSettingsFile();
    };
} // namespace Gengine