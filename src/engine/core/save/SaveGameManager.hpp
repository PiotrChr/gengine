#pragma once

#include <fstream>
#include <istream>
#include <iostream>
#include <sstream>
#include <string>
#include "../../DEFINITIONS.hpp"

namespace Gengine {
    class SaveGameManager
    {
    public:
        SaveGameManager() {};
        ~SaveGameManager() {};
        void loadSave();
        void saveSave();
    private:
        int _level;
        int _score;
        int _lives;
    };
}