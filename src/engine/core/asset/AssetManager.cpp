#include "AssetManager.hpp"
#if _IS_MAC
    #include <mach-o/dyld.h>
#endif

namespace Gengine {
    AssetManager::AssetManager() {

    }

    AssetManager::~AssetManager() {

    }

    std::string AssetManager::getFilePath(std::string relativePath) {
        char path[1024];
        uint32_t size = sizeof(path);
        
        #if _IS_MAC
            _NSGetExecutablePath(path, &size);
            std::string pathStr = std::string(path);

            return pathStr.substr(0, pathStr.find_last_of("/")) + "/" + relativePath;
        #else
            return relativePath;
        #endif        
    }
    
    void AssetManager::loadTexture(std::string name, std::string filePath) {
        sf::Texture tex;

        if (this->_textures.find(name) == this->_textures.end()) {
            if (tex.loadFromFile(getFilePath(filePath))) {
                this->_textures[name] = tex;
            }
        }
    }

    sf::Texture& AssetManager::getTexture(std::string name) {
        return this->_textures.at(name);
    }

    void AssetManager::loadFont(std::string name, std::string filePath) {
        sf::Font font;

        if (this->_fonts.find(name) == this->_fonts.end()) {
            if (font.loadFromFile(getFilePath(filePath))) {
                this->_fonts[name] = font;
            }
        }
    }

    sf::Font& AssetManager::getFont(std::string name) {
        return this->_fonts.at(name);
    }
}