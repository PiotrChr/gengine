#pragma once

#include "../../DEFINITIONS.hpp"
#include <glm/glm.hpp>
#include <array>

namespace Gengine {

    typedef std::array<std::array<std::array<int, CHUNK_SIZE_X>, CHUNK_SIZE_Y>, CHUNK_SIZE_Z> ChunkBlocks;
    
    class Chunk {
    public:
        Chunk(const glm::ivec3& position);
        ~Chunk();

        // Get the x-coordinate of the chunk
        int getX() const;

        // Get the y-coordinate of the chunk
        int getY() const;

        // Get the z-coordinate of the chunk
        int getZ() const;

        int getNumBlocks() const;

        int getBlock(const glm::ivec3& position) const;

        void setBlock(const glm::ivec3& position, int blockType);

        ChunkBlocks* getBlocks();
        
        void update(float deltaTime);

        void draw();

        bool isDirty() const;
        void markDirty();
        void markClean();

        const glm::ivec3& getChunkPosition();

    private:
        const glm::ivec3& m_position;

        int m_width = CHUNK_SIZE_X;
        int m_height = CHUNK_SIZE_Y;
        int m_depth = CHUNK_SIZE_Z;

        ChunkBlocks m_blocks;

        bool m_dirty;
    };
}