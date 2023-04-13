#include "CaveGenerator.hpp"

namespace Gengine
{
    void CaveGenerator::generateCave(Chunk* chunk) {
    // Get the chunk coordinates and size
    int chunkX = chunk->getX();
    int chunkY = chunk->getY();
    int chunkZ = chunk->getZ();
    int chunkWidth = chunk->getWidth();
    int chunkHeight = chunk->getHeight();
    int chunkDepth = chunk->getDepth();

    // Calculate the center of the chunk
    float centerX = (chunkX + 0.5f) * chunkWidth;
    float centerY = (chunkY + 0.5f) * chunkHeight;
    float centerZ = (chunkZ + 0.5f) * chunkDepth;

    // Calculate the radius of the sphere
    float radius = std::min({chunkWidth, chunkHeight, chunkDepth}) / 2.0f;

    // Iterate over every block in the chunk
    for (int x = 0; x < chunkWidth; x++) {
        for (int y = 0; y < chunkHeight; y++) {
            for (int z = 0; z < chunkDepth; z++) {
                // Calculate the distance from the block to the center of the sphere
                float distance = std::sqrt(std::pow(x + 0.5f - centerX, 2.0f) +
                                           std::pow(y + 0.5f - centerY, 2.0f) +
                                           std::pow(z + 0.5f - centerZ, 2.0f));

                // If the block is inside the sphere, set it to air
                if (distance < radius) {
                    chunk->setBlock({x, y, z}, 0);
                }
            }
        }
    }
}
} // namespace Gengine