#include "WorldGenerator.hpp"

namespace Gengine {
    WorldGenerator::WorldGenerator() :
        m_worldWidthInChunks(0),
        m_worldHeightInChunks(0),
        m_worldDepthInChunks(0),
        m_chunkWidthInBlocks(0),
        m_chunkHeightInBlocks(0),
        m_chunkDepthInBlocks(0),
        m_terrainNoise(),
        m_biomeNoise()
    {
        // Set up the noise functions for terrain generation
        m_terrainNoise.SetNoiseType(FastNoiseLite::NoiseType_OpenSimplex2);
        m_terrainNoise.SetFractalType(FastNoiseLite::FractalType_FBm);
        m_terrainNoise.SetFrequency(0.02f);
        m_terrainNoise.SetFractalOctaves(4);
        m_terrainNoise.SetFractalLacunarity(2.0f);
        m_terrainNoise.SetFractalGain(0.5f);

        m_biomeNoise.SetNoiseType(FastNoiseLite::NoiseType_OpenSimplex2);
        m_biomeNoise.SetFrequency(0.05f);
    }

    void WorldGenerator::generateTerrain(Chunk* chunk) {
        // Get the chunk position in world coordinates
        int worldX = chunk->getX() * m_chunkWidthInBlocks;
        int worldY = chunk->getY() * m_chunkHeightInBlocks;
        int worldZ = chunk->getZ() * m_chunkDepthInBlocks;

        // Loop through all blocks in the chunk
        for (int x = 0; x < m_chunkWidthInBlocks; x++) {
            for (int z = 0; z < m_chunkDepthInBlocks; z++) {
                // Calculate the height of the terrain at this x,z position
                int height = getHeight(worldX + x, worldZ + z);

                // Loop through all blocks in the y direction
                for (int y = 0; y < m_chunkHeightInBlocks; y++) {
                    int blockType = BlockTypes::Air;

                    if (worldY + y < height) {
                        blockType = BlockTypes::Dirt;
                    }

                    // Set the block type in the chunk
                    chunk->setBlock({x, y, z}, blockType);
                }
            }
        }
    }

    int WorldGenerator::getHeight(int x, int z) {
        // Get the noise value for this x,z position
        float noiseValue = m_terrainNoise.GetNoise(static_cast<float>(x), static_cast<float>(z));

        // Map the noise value to a height value
        int height = static_cast<int>((noiseValue + 1) * m_chunkHeightInBlocks * 0.5f);

        return height;
    }

    void WorldGenerator::setChunkSize(int chunkWidthInBlocks, int chunkHeightInBlocks, int chunkDepthInBlocks) {
        m_chunkWidthInBlocks = chunkWidthInBlocks;
        m_chunkHeightInBlocks = chunkHeightInBlocks;
        m_chunkDepthInBlocks = chunkDepthInBlocks;
    }

    void WorldGenerator::generateFeatures(Chunk* chunk) {
        // TODO: Generate trees

        // Generate caves
        for (int x = 0; x < m_chunkWidthInBlocks; x++) {
            for (int y = 0; y < m_chunkHeightInBlocks; y++) {
                for (int z = 0; z < m_chunkDepthInBlocks; z++) {
                    // Determine if a cave should be generated at this position
                    float noise = m_terrainNoise.GetNoise(
                        (chunk->getX() * m_chunkWidthInBlocks + x) / 16.0f, y / 16.0f, (chunk->getZ() * m_chunkDepthInBlocks + z) / 16.0f
                    );
                    if (noise > 0.6f) {
                        // Generate the cave
                        CaveGenerator caveGenerator;
                        caveGenerator.generateCave(chunk);
                    }
                }
            }
        }
    }

    void WorldGenerator::generateEntities(Chunk* chunk) {
        //
    }

    void WorldGenerator::generateStructures(Chunk* chunk) {
        //
    }

    WorldPtr WorldGenerator::initializeWorld() {
        // Create a new world
        auto world = std::make_shared<World>();

        return world;
    }

    void WorldGenerator::generateWorld(WorldPtr world) {
        
        for (int x = 0; x < INITIAL_WORLD_SIZE_X_IN_CHUNKS; x++) {
            for (int y = 0; y < INITIAL_WORLD_SIZE_Y_IN_CHUNKS; y++) {
                for (int z = 0; z < INITIAL_WORLD_SIZE_Z_IN_CHUNKS; z++) {
                    // Get the chunk
                    std::cout << "Generating chunk: " << x << ", " << y << ", " << z << std::endl;
                    Chunk* chunk = new Chunk({x, y, z});

                    // Generate the terrain
                    generateTerrain(chunk);

                    // Generate features
                    // generateFeatures(chunk);

                    // Generate entities
                    generateEntities(chunk);

                    // Generate structures
                    generateStructures(chunk);

                    world->addChunk(chunk);
                }
            }
        }
    }
}