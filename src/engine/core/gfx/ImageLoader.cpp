#include "ImageLoader.hpp"

ImageLoader::ImageData ImageLoader::loadImage(const std::string& filepath) {
    ImageData imageData;
    stbi_uc* pixels = stbi_load(filepath.c_str(), &imageData.width, &imageData.height, &imageData.channels, STBI_rgb_alpha);
    if (!pixels) {
        throw std::runtime_error("Failed to load image: " + filepath);
    }

    imageData.data = std::vector<unsigned char>(pixels, pixels + imageData.width * imageData.height * 4);
    stbi_image_free(pixels);
    return imageData;
}

void ImageLoader::freeImageData(ImageData& imageData) {
    imageData.data.clear();
    imageData.width = 0;
    imageData.height = 0;
    imageData.channels = 0;
}
