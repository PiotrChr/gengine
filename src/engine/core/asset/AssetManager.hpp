#pragma once

#include <map>
#include <vulkan/vulkan.h>
#include <iostream>
#include <ft2build.h>
#include FT_FREETYPE_H
#include "../../globals.hpp"
#if _IS_MAC
    #include <mach-o/dyld.h>
#endif

namespace Gengine {
    class AssetManager {
    public:
        AssetManager();
        ~AssetManager();

        void loadTexture(std::string name, std::string filePath);
        VkImage& getTexture(std::string name);

        void loadFont(std::string name, std::string filePath);
        FT_Face& getFont(std::string name);
    private:
        std::string getFilePath(std::string relativePath);
        std::map<std::string, VkImage> _textures;    
        std::map<std::string, FT_Face> _fonts;    
    };
}
