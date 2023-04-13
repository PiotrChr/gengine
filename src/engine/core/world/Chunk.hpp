#pragma once

#include "../../DEFINITIONS.hpp"
#include <SFML/Graphics.hpp>
#include <vector>

namespace Gengine {
    
    class Chunk {
    public:
        Chunk(sf::Vector3i position);
        ~Chunk();

        // Get the x-coordinate of the chunk
        int getX() const;

        // Get the y-coordinate of the chunk
        int getY() const;

        // Get the z-coordinate of the chunk
        int getZ() const;

        // Get the width of the chunk in blocks
        int getWidth() const;

        // Get the height of the chunk in blocks
        int getHeight() const;

        // Get the depth of the chunk in blocks
        int getDepth() const;

        // Get the number of blocks in the chunk
        int getNumBlocks() const;

        // Get a block at the specified block coordinates
        int getBlock(sf::Vector3i position) const;

        // Set a block at the specified block coordinates
        void setBlock(sf::Vector3i position, int blockType);

        std::vector<int>* getBlocks();
        
        // Update the chunk
        void update(float deltaTime);

        // Draw the chunk
        void draw(sf::RenderTarget* target);

        // Check if the chunk is dirty and needs to be rebuilt
        bool isDirty() const;

        // Mark the chunk as dirty and in need of rebuilding
        void markDirty();

        sf::Vector3i getChunkPosition();

    private:
        // The x, y, and z coordinates of the chunk
        sf::Vector3i m_position;

        // The width, height, and depth of the chunk in blocks
        int m_width = CHUNK_SIZE_X;
        int m_height = CHUNK_SIZE_Y;
        int m_depth = CHUNK_SIZE_Z;

        // Vector to store the block data for the chunk
        std::vector<int> m_blocks;

        // Flag to indicate whether the chunk needs to be rebuilt
        bool m_dirty;
    };
}