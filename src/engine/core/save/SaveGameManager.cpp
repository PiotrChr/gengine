#include "SaveGameManager.hpp"

namespace Gengine {
    void SaveGameManager::loadSave()
    {
        std::ifstream saveFile;
        saveFile.open(SAVE_FILE_PATH);
        if (saveFile.is_open())
        {
            std::string line;
            while (std::getline(saveFile, line))
            {
                std::istringstream iss(line);
                std::string key;
                if (std::getline(iss, key, '='))
                {
                    std::string value;
                    if (std::getline(iss, value))
                    {
                        if (key == "level")
                        {
                            _level = std::stoi(value);
                        }
                        else if (key == "score")
                        {
                            _score = std::stoi(value);
                        }
                        else if (key == "lives")
                        {
                            _lives = std::stoi(value);
                        }
                    }
                }
            }
            saveFile.close();
        }
    }

    void SaveGameManager::saveSave()
    {
        std::ofstream saveFile;
        saveFile.open(SAVE_FILE_PATH);
        if (saveFile.is_open())
        {
            saveFile << "level=" << _level << std::endl;
            saveFile << "score=" << _score << std::endl;
            saveFile << "lives=" << _lives << std::endl;
            saveFile.close();
        }
    }
}