#pragma once

#include <map>
#include <SFML/Graphics.hpp>
#include "../../globals.hpp"

namespace Gengine {
    class AssetManager {
    public:
        AssetManager();
        ~AssetManager();

        void loadTexture(std::string name, std::string filePath);
        sf::Texture& getTexture(std::string name);

        void loadFont(std::string name, std::string filePath);
        sf::Font& getFont(std::string name);
    private:
        std::string getFilePath(std::string relativePath);
        std::map<std::string, sf::Texture> _textures;    
        std::map<std::string, sf::Font> _fonts;    
    };
}
