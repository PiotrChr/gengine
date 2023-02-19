#include "AssetManager.hpp"

namespace Gengine {
    AssetManager::AssetManager() {

    }

    AssetManager::~AssetManager() {

    }

    void AssetManager::loadTexture(std::string name, std::string filePath) {
        sf::Texture tex;

        if (tex.loadFromFile(filePath)) {
            this->_textures[name] = tex;
        }
    }

    sf::Texture& AssetManager::getTexture(std::string name) {
        return this->_textures.at(name);
    }

    void AssetManager::loadFont(std::string name, std::string filePath) {
        sf::Font font;

        if (font.loadFromFile(filePath)) {
            this->_fonts[name] = font;
        }
    }

    sf::Font& AssetManager::getFont(std::string name) {
        return this->_fonts.at(name);
    }
}