#pragma once

#include <SFML/Graphics.hpp>
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
        void draw(sf::RenderTarget* target);

        // Get a block at the specified block coordinates
        int getBlock(sf::Vector3i blockPosition);

        // Set a block at the specified block coordinates
        void setBlock(sf::Vector3i blockPosition, int blockType);

        // Get the chunk at the specified chunk coordinates
        void setChunk(Chunk* chunk);

        // Get the chunk at the specified chunk coordinates
        Chunk* getChunk(sf::Vector3i chunkPosition);

        // Get the chunk at the specified block coordinates
        std::unordered_map<sf::Vector3i, Chunk*, Vector3iHash> getChunks();

        void addChunk(Chunk* chunk);

        int getWorldHeightInChunks() const;

        int getWorldWidthInChunks() const;

        int getWorldDepthInChunks() const;

        // Get the width of a chunk in blocks
        int getChunkWidthInBlocks() const;

        // Get the height of a chunk in blocks
        int getChunkHeightInBlocks() const;

        // Get the depth of a chunk in blocks
        int getChunkDepthInBlocks() const;

        // Get the number of chunks in the world
        int getNumChunks() const;

        void addPlayer(Player* player);
    private:
        std::vector<std::pair<Chunk*, float>> getSortedChunks();
        bool isBlockVisible (const sf::Vector3i& blockPosition);

        sf::Vector3i getPlayerChunkPosition();

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
        std::unordered_map<sf::Vector3i, Chunk*, Vector3iHash> m_chunks;

        // World loader for loading and unloading chunks
        WorldLoader m_worldLoader;

        // Block renderer for drawing blocks
        BlockRenderer m_blockRenderer;

        // Players in the world
        std::vector<Player*> m_players;
    };

    typedef std::shared_ptr<World> WorldPtr;
}