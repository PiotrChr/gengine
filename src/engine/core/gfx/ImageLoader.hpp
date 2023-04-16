#pragma once

#include "stb_image.h"
#include <vulkan/vulkan.h>
#include <string>
#include <vector>

class ImageLoader {
public:
    struct ImageData {
        int width;
        int height;
        int channels;
        std::vector<unsigned char> data;
    };

    static ImageData loadImage(const std::string& filepath);
    static void freeImageData(ImageData& imageData);
};
