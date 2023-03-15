#include "SettingsLoader.hpp"

namespace Gengine {
    void SettingsLoader::loadSettings(GameComponentsRef& _data)
    {
        if (!fileExists(SAVE_SETTINGS_FILE_PATH)) {
            this->createSettingsFile();
        }

        std::ifstream file;
        file.open(SAVE_SETTINGS_FILE_PATH);
        if (file.is_open())
        {
            std::string line;
            while (std::getline(file, line))
            {
                std::stringstream keystream(line);
                std::string key;
                std::string value;
                std::getline(keystream, key, '=');
                std::getline(keystream, value);
                if (key == KEY_FULLSCREEN)
                {
                    _data->windowManager.isFullscreen = std::stoi(value);
                }
                else if (key == KEY_RESOLUTION)
                {
                    _data->windowManager.setResolution(value);
                }
                else if (key == KEY_FRAMERATE)
                {
                    _data->windowManager.framerate = std::stoi(value);
                }
                else if (key == KEY_VSYNC)
                {
                    _data->windowManager.isVsync = std::stoi(value);
                    
                }
                else if (key == KEY_ANTIALIASING)
                {
                    _data->windowManager.antialiasing = std::stoi(value);
                }
                else if (key == KEY_MUSIC)
                {
                     _data->audioManager.isMusic = std::stoi(value);
                }
                else if (key == KEY_SOUND)
                {
                    _data->audioManager.isSound = std::stoi(value);
                }
                else if (key == KEY_MUSIC_VOLUME)
                {
                    _data->audioManager.musicVolume = std::stoi(value);
                }
                else if (key == KEY_SOUND_VOLUME)
                {
                    _data->audioManager.soundVolume = std::stoi(value);
                }

                // loads key bindings
                else if (key == ACTION_MOVE_UP)
                {
                    _data->inputManager.keyBinds[ACTION_MOVE_UP] = std::stoi(value);
                }
                else if (key == ACTION_MOVE_DOWN)
                {
                    _data->inputManager.keyBinds[ACTION_MOVE_DOWN] = std::stoi(value);
                }
                else if (key == ACTION_MOVE_LEFT)
                {
                    _data->inputManager.keyBinds[ACTION_MOVE_LEFT] = std::stoi(value);
                }
                else if (key == ACTION_MOVE_RIGHT)
                {
                    _data->inputManager.keyBinds[ACTION_MOVE_RIGHT] = std::stoi(value);
                }
                else if (key == ACTION_INTERACT)
                {
                    _data->inputManager.keyBinds[ACTION_INTERACT] = std::stoi(value);
                }
                else if (key == ACTION_PAUSE)
                {
                    _data->inputManager.keyBinds[ACTION_PAUSE] = std::stoi(value);
                }
                else if (key == ACTION_INVENTORY)
                {
                    _data->inputManager.keyBinds[ACTION_INVENTORY] = std::stoi(value);
                }
                else if (key == ACTION_ESCAPE)
                {
                    _data->inputManager.keyBinds[ACTION_ESCAPE] = std::stoi(value);
                }
                else if (key == ACTION_DEBUG)
                {
                    _data->inputManager.keyBinds[ACTION_DEBUG] = std::stoi(value);
                }

                else if (key == ACTION_MAIN) {
                    _data->inputManager.mouseBinds[ACTION_MAIN] = std::stoi(value);
                }
                else if (key == ACTION_SECONDARY) {
                    _data->inputManager.mouseBinds[ACTION_SECONDARY] = std::stoi(value);
                } else if (key == ACTION_TERTIARY) {
                    _data->inputManager.mouseBinds[ACTION_TERTIARY] = std::stoi(value);
                }
                
            }
        }
        file.close();
    }

    void SettingsLoader::createSettingsFile()
    {
        std::ofstream file;
        file.open(SAVE_SETTINGS_FILE_PATH);
        if (file.is_open())
        {
            file << KEY_FULLSCREEN << "=" << DEFAULT_FULLSCREEN << std::endl;
            file << KEY_RESOLUTION << "=" << DEFAULT_RESOLUTION << std::endl;
            file << KEY_FRAMERATE << "=" << DEFAULT_FRAMERATE << std::endl;
            file << KEY_VSYNC << "=" << DEFAULT_VSYNC << std::endl;
            file << KEY_ANTIALIASING << "=" << DEFAULT_ANTIALIASING << std::endl;
            file << KEY_MUSIC << "=" << DEFAULT_MUSIC << std::endl;
            file << KEY_SOUND << "=" << DEFAULT_SOUND << std::endl;
            file << KEY_MUSIC_VOLUME << "=" << DEFAULT_MUSIC_VOLUME << std::endl;
            file << KEY_SOUND_VOLUME << "=" << DEFAULT_SOUND_VOLUME << std::endl;
            file << ACTION_MOVE_UP << "=" << DEFAULT_MOVE_UP << std::endl;
            file << ACTION_MOVE_DOWN << "=" << DEFAULT_MOVE_DOWN << std::endl;
            file << ACTION_MOVE_LEFT << "=" << DEFAULT_MOVE_LEFT << std::endl;
            file << ACTION_MOVE_RIGHT << "=" << DEFAULT_MOVE_RIGHT << std::endl;
            file << ACTION_INTERACT << "=" << DEFAULT_INTERACT << std::endl;
            file << ACTION_PAUSE << "=" << DEFAULT_PAUSE << std::endl;
            file << ACTION_INVENTORY << "=" << DEFAULT_INVENTORY << std::endl;
            file << ACTION_ESCAPE << "=" << DEFAULT_ESCAPE << std::endl;
            file << ACTION_DEBUG << "=" << DEFAULT_DEBUG << std::endl;
            file << ACTION_MAIN << "=" << DEFAULT_MAIN_ACTION << std::endl;
            file << ACTION_SECONDARY << "=" << DEFAULT_SECONDARY_ACTION << std::endl;
            file << ACTION_TERTIARY << "=" << DEFAULT_TERTIARY_ACTION << std::endl;
        }
        file.close();
    }

    void SettingsLoader::saveSettings(GameComponentsRef& _data)
    {
        std::ofstream file;
        file.open(SAVE_SETTINGS_FILE_PATH);
        if (file.is_open())
        {
            file << KEY_FULLSCREEN << "=" << _data->windowManager.isFullscreen << std::endl;
            file << KEY_RESOLUTION << "=" << _data->windowManager.resolution << std::endl;
            file << KEY_FRAMERATE << "=" << _data->windowManager.framerate << std::endl;
            file << KEY_VSYNC << "=" << _data->windowManager.isVsync << std::endl;
            file << KEY_ANTIALIASING << "=" << _data->windowManager.antialiasing << std::endl;
            file << KEY_MUSIC << "=" << _data->audioManager.isMusic << std::endl;
            file << KEY_SOUND << "=" << _data->audioManager.isSound << std::endl;
            file << KEY_MUSIC_VOLUME << "=" << _data->audioManager.musicVolume << std::endl;
            file << KEY_SOUND_VOLUME << "=" << _data->audioManager.soundVolume << std::endl;
            file << ACTION_MOVE_UP << "=" << _data->inputManager.keyBinds[ACTION_MOVE_UP] << std::endl;
            file << ACTION_MOVE_DOWN << "=" << _data->inputManager.keyBinds[ACTION_MOVE_DOWN] << std::endl;
            file << ACTION_MOVE_LEFT << "=" << _data->inputManager.keyBinds[ACTION_MOVE_LEFT] << std::endl;
            file << ACTION_MOVE_RIGHT << "=" << _data->inputManager.keyBinds[ACTION_MOVE_RIGHT] << std::endl;
            file << ACTION_INTERACT << "=" << _data->inputManager.keyBinds[ACTION_INTERACT] << std::endl;
            file << ACTION_PAUSE << "=" << _data->inputManager.keyBinds[ACTION_PAUSE] << std::endl;
            file << ACTION_INVENTORY << "=" << _data->inputManager.keyBinds[ACTION_INVENTORY] << std::endl;
            file << ACTION_ESCAPE << "=" << _data->inputManager.keyBinds[ACTION_ESCAPE] << std::endl;
            file << ACTION_DEBUG << "=" << _data->inputManager.keyBinds[ACTION_DEBUG] << std::endl;
            file << ACTION_MAIN << "=" << _data->inputManager.mouseBinds[ACTION_MAIN] << std::endl;
            file << ACTION_SECONDARY << "=" << _data->inputManager.mouseBinds[ACTION_SECONDARY] << std::endl;
            file << ACTION_TERTIARY << "=" << _data->inputManager.mouseBinds[ACTION_TERTIARY] << std::endl;
        
        }
        file.close();
    }
}