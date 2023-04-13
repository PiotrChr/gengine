#pragma once

#include "../World.hpp"
#include "../BlockTypes.hpp"
#include "../Chunk.hpp"
#include "FastNoiseLite.h"
#include "CaveGenerator.hpp"

namespace Gengine {
    class WorldGenerator {
    public:
        WorldGenerator();

        // Set the dimensions of the world in chunks
        void setWorldDimensions(int worldWidthInChunks, int worldHeightInChunks, int worldDepthInChunks);

        // Set the size of a chunk in blocks
        void setChunkSize(int chunkWidthInBlocks, int chunkHeightInBlocks, int chunkDepthInBlocks);

        // Generate the initial world
        void generateWorld(WorldPtr world);

        // Add a step to the map generation process
        void addStep(std::function<void(Chunk*)> generationStep);

        WorldPtr initializeWorld();

    private:
        // Generate terrain for a chunk at the specified coordinates
        void generateTerrain(Chunk* chunk);

        // Generate features (trees, caves, etc.) for a chunk at the specified coordinates
        void generateFeatures(Chunk* chunk);

        // Generate structures (villages, temples, etc.) for a chunk at the specified coordinates
        void generateStructures(Chunk* chunk);

        // Generate entities (animals, monsters, etc.) for a chunk at the specified coordinates
        void generateEntities(Chunk* chunk);

        // Helper function to get the height of a block at the specified x,z position
        int getHeight(int x, int z);

        // Noise functions used for terrain generation
        FastNoiseLite m_terrainNoise;
        FastNoiseLite m_biomeNoise;

        // Dimensions of the world in chunks
        int m_worldWidthInChunks = INITIAL_WORLD_SIZE_X_IN_CHUNKS;
        int m_worldHeightInChunks = INITIAL_WORLD_SIZE_Y_IN_CHUNKS;
        int m_worldDepthInChunks = INITIAL_WORLD_SIZE_Z_IN_CHUNKS;

        // Size of a chunk in blocks
        int m_chunkWidthInBlocks = CHUNK_SIZE_X;
        int m_chunkHeightInBlocks = CHUNK_SIZE_Y;
        int m_chunkDepthInBlocks = CHUNK_SIZE_Z;

        // Steps in the map generation process
        std::vector<std::function<void(Chunk*)>> m_generationSteps;
    };
}