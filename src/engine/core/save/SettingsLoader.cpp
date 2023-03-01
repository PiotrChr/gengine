#include "SettingsLoader.hpp"

namespace Gengine {
    void SettingsLoader::loadSettings(GameComponentsRef _data)
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
                if (key == "fullscreen")
                {
                    if (value == "true")
                    {
                        _data->windowManager.isFullscreen = true;
                    }
                    else
                    {
                        _data->windowManager.isFullscreen = false;
                    }
                }
                else if (key == "resolution")
                {
                    _data->windowManager.setResolution(value);
                }
                else if (key == "framerate")
                {
                    _data->windowManager.framerate = std::stoi(value);
                }
                else if (key == "vsync")
                {
                    if (value == "true")
                    {
                        _data->windowManager.isVsync = true;
                    }
                    else
                    {
                        _data->windowManager.isVsync = false;
                    }
                }
                else if (key == "antialiasing")
                {
                    _data->windowManager.antialiasing = std::stoi(value);
                }
                else if (key == "music")
                {
                    if (value == "true")
                    {
                        _data->audioManager.isMusic = true;
                    }
                    else
                    {
                        _data->audioManager.isMusic = false;
                    }
                }
                else if (key == "sound")
                {
                    if (value == "true")
                    {
                        _data->audioManager.isSound = true;
                    }
                    else
                    {
                        _data->audioManager.isSound = false;
                    }
                }
                else if (key == "musicVolume")
                {
                    _data->audioManager.musicVolume = std::stoi(value);
                }
                else if (key == "soundVolume")
                {
                    _data->audioManager.soundVolume = std::stoi(value);
                }

                // loads key bindings
                else if (key == "moveUp")
                {
                    _data->inputManager.keyBinds["MOVE_UP"] = std::stoi(value);
                }
                else if (key == "moveDown")
                {
                    _data->inputManager.keyBinds["MOVE_DOWN"] = std::stoi(value);
                }
                else if (key == "moveLeft")
                {
                    _data->inputManager.keyBinds["MOVE_LEFT"] = std::stoi(value);
                }
                else if (key == "moveRight")
                {
                    _data->inputManager.keyBinds["MOVE_RIGHT"] = std::stoi(value);
                }
                else if (key == "interact")
                {
                    _data->inputManager.keyBinds["INTERACT"] = std::stoi(value);
                }
                else if (key == "pause")
                {
                    _data->inputManager.keyBinds["PAUSE"] = std::stoi(value);
                }
                else if (key == "inventory")
                {
                    _data->inputManager.keyBinds["INVENTORY"] = std::stoi(value);
                }
                else if (key == "escape")
                {
                    _data->inputManager.keyBinds["ESCAPE"] = std::stoi(value);
                }
                else if (key == "debug")
                {
                    _data->inputManager.keyBinds["DEBUG"] = std::stoi(value);
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
            file << "fullscreen=" << DEFAULT_FULLSCREEN << std::endl;
            file << "resolution=" << DEFAULT_RESOLUTION << std::endl;
            file << "framerate=" << DEFAULT_FRAMERATE << std::endl;
            file << "vsync=" << DEFAULT_VSYNC << std::endl;
            file << "antialiasing=" << DEFAULT_ANTIALIASING << std::endl;
            file << "music=" << DEFAULT_MUSIC << std::endl;
            file << "sound=" << DEFAULT_SOUND << std::endl;
            file << "musicVolume=" << DEFAULT_MUSIC_VOLUME << std::endl;
            file << "soundVolume=" << DEFAULT_SOUND_VOLUME << std::endl;
            file << "moveUp=" << DEFAULT_MOVE_UP << std::endl;
            file << "moveDown=" << DEFAULT_MOVE_DOWN << std::endl;
            file << "moveLeft=" << DEFAULT_MOVE_LEFT << std::endl;
            file << "moveRight=" << DEFAULT_MOVE_RIGHT << std::endl;
            file << "interact=" << DEFAULT_INTERACT << std::endl;
            file << "pause=" << DEFAULT_PAUSE << std::endl;
            file << "inventory=" << DEFAULT_INVENTORY << std::endl;
            file << "escape=" << DEFAULT_ESCAPE << std::endl;
            file << "debug=" << DEFAULT_DEBUG << std::endl;
        }
        file.close();
    }

    void SettingsLoader::saveSettings(GameComponentsRef _data)
    {
        std::ofstream file;
        file.open(SAVE_SETTINGS_FILE_PATH);
        if (file.is_open())
        {
            file << "fullscreen=" << _data->windowManager.isFullscreen << std::endl;
            file << "resolution=" << _data->windowManager.resolution << std::endl;
            file << "framerate=" << _data->windowManager.framerate << std::endl;
            file << "vsync=" << _data->windowManager.isVsync << std::endl;
            file << "antialiasing=" << _data->windowManager.antialiasing << std::endl;
            file << "music=" << _data->audioManager.isMusic << std::endl;
            file << "sound=" << _data->audioManager.isSound << std::endl;
            file << "musicVolume=" << _data->audioManager.musicVolume << std::endl;
            file << "soundVolume=" << _data->audioManager.soundVolume << std::endl;
            file << "moveUp=" << _data->inputManager.keyBinds["MOVE_UP"] << std::endl;
            file << "moveDown=" << _data->inputManager.keyBinds["MOVE_DOWN"] << std::endl;
            file << "moveLeft=" << _data->inputManager.keyBinds["MOVE_LEFT"] << std::endl;
            file << "moveRight=" << _data->inputManager.keyBinds["MOVE_RIGHT"] << std::endl;
            file << "interact=" << _data->inputManager.keyBinds["INTERACT"] << std::endl;
            file << "pause=" << _data->inputManager.keyBinds["PAUSE"] << std::endl;
            file << "inventory=" << _data->inputManager.keyBinds["INVENTORY"] << std::endl;
            file << "escape=" << _data->inputManager.keyBinds["ESCAPE"] << std::endl;
            file << "debug=" << _data->inputManager.keyBinds["DEBUG"] << std::endl;
        
        }
        file.close();
    }
}