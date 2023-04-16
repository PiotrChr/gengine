#include "AssetManager.hpp"

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
        VkImage tex;

        // TODO: Load texture using Vulkan
    }

    VkImage& AssetManager::getTexture(std::string name) {
        return this->_textures.at(name);
    }

    void AssetManager::loadFont(std::string name, std::string filePath) {
        FT_Library ft;

        if (FT_Init_FreeType(&ft)) {
            throw std::runtime_error("Could not initialize FreeType library.");
        }

        FT_Face face;
        if (FT_New_Face(ft, getFilePath(filePath).c_str(), 0, &face)) {
            throw std::runtime_error("Could not load font: " + filePath);
        }

        // Store the font in the map
        this->_fonts[name] = face;
    }

    FT_Face& AssetManager::getFont(std::string name) {
        if (this->_fonts.find(name) != this->_fonts.end()) {
            return this->_fonts.at(name);
        }
        
        throw std::runtime_error("Font not found: " + name);
    }
}