#include "Chunk.hpp"

namespace Gengine {
    Chunk::Chunk(const glm::ivec3& position) :
        m_position(position),
        m_dirty(true),
        m_blocks()
    {
    }

    Chunk::~Chunk() {
    }

    int Chunk::getX() const {
        return m_position.x;
    }

    int Chunk::getY() const {
        return m_position.y;
    }

    int Chunk::getZ() const {
        return m_position.z;
    }

    int Chunk::getNumBlocks() const {
        return m_blocks.size();
    }

    int Chunk::getBlock(const glm::ivec3& position) const {
        return m_blocks[position.x][position.y][position.z];
    }

    void Chunk::setBlock(const glm::ivec3& position, int blockType) {
        m_blocks[position.x][position.y][position.z] = blockType;

        this->markDirty();
    }

    ChunkBlocks* Chunk::getBlocks() {
        return &m_blocks;
    }

    void Chunk::update(float deltaTime) {
    }

    void Chunk::draw() {
    }

    bool Chunk::isDirty() const {
        return m_dirty;
    }

    void Chunk::markDirty() {
        m_dirty = true;
    }

    void Chunk::markClean() {
        m_dirty = false;
    }

    const glm::ivec3& Chunk::getChunkPosition() {
        return m_position;
    }
}