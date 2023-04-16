#pragma once

#include <vector>
#include "../../DEFINITIONS.hpp"
#include "Chunk.hpp"
#include "BlockTypes.hpp"
#include "loader/WorldLoader.hpp"
#include "../../../gameObjects/player/Player.hpp"
#include "../gfx/BlockRenderer.hpp"
#include <map>

namespace Gengine {
    class World {
    public:
        World() {};
        ~World();

        // Update the world
        void update(float deltaTime);

        void init();

        // Draw the world
        void draw();

        // Get a block at the specified block coordinates
        int getBlock(const glm::ivec3& blockPosition);

        // Set a block at the specified block coordinates
        void setBlock(const glm::ivec3& blockPosition, int blockType);

        // Get the chunk at the specified chunk coordinates
        void setChunk(Chunk* chunk);

        // Get the chunk at the specified chunk coordinates
        Chunk* getChunk(const glm::ivec3& chunkPosition);

        ChunkMap getChunks();

        void addChunk(Chunk* chunk);

        // Get the number of chunks in the world
        int getNumChunks() const;

        void addPlayer(Player* player);
    private:
        std::vector<std::pair<Chunk*, float>> getSortedChunks();
        bool isBlockVisible (const glm::ivec3& blockPosition);

        const glm::ivec3& getPlayerChunkPosition();

        bool isInWorldHeightBounds(int z);
        bool isWithinLoadRadius(int dx, int dy, int dz);
        bool isWithinUnloadRadius(int dx, int dy, int dz);
        
        // World dimensions in chunks
        int m_worldWidthInChunks;
        int m_worldHeightInChunks;
        int m_worldDepthInChunks;

        // Chunk dimensions in blocks
        int m_chunkWidthInBlocks;
        int m_chunkHeightInBlocks;
        int m_chunkDepthInBlocks;

        // Vector to store all the chunks in the world
        ChunkMap m_chunks;

        // World loader for loading and unloading chunks
        WorldLoader m_worldLoader;

        // Block renderer for drawing blocks
        BlockRenderer m_blockRenderer;

        // Players in the world
        std::vector<Player*> m_players;
    };

    typedef std::shared_ptr<World> WorldPtr;
}