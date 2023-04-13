#include "Chunk.hpp"

namespace Gengine {
    Chunk::Chunk(sf::Vector3i position) :
        m_position(position),
        m_blocks(m_width * m_height * m_depth),
        m_dirty(true)
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

    int Chunk::getWidth() const {
        return m_width;
    }

    int Chunk::getHeight() const {
        return m_height;
    }

    int Chunk::getDepth() const {
        return m_depth;
    }

    int Chunk::getNumBlocks() const {
        return m_blocks.size();
    }

    int Chunk::getBlock(sf::Vector3i position) const {
        return m_blocks[position.x + position.y * m_width + position.z * m_width * m_height];
    }

    void Chunk::setBlock(sf::Vector3i position, int blockType) {
        m_blocks[position.x + position.y * m_width + position.z * m_width * m_height] = blockType;
        m_dirty = true;
    }

    std::vector<int>* Chunk::getBlocks() {
        return &m_blocks;
    }

    void Chunk::update(float deltaTime) {
    }

    void Chunk::draw(sf::RenderTarget* target) {
    }

    bool Chunk::isDirty() const {
        return m_dirty;
    }

    void Chunk::markDirty() {
        m_dirty = true;
    }

    sf::Vector3i Chunk::getChunkPosition() {
        return m_position;
    }
}