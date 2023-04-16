#include "World.hpp"

namespace Gengine {
    const glm::ivec3& World::getPlayerChunkPosition() {
        Player* player = m_players[0];
        
        return player->getChunkPosition();
    }

    World::~World() {
        // Delete all the chunks in the world
        for (auto& chunk : m_chunks) {
            delete chunk.second;
        }
        m_chunks.clear();
    }

    void World::init() {
        m_blockRenderer.init();
    }

    void World::addPlayer(Player* player) {
        m_players.push_back(player);
    }

    bool World::isInWorldHeightBounds(int z) {
        return z >= 0 && z < WORLD_MAX_SIZE_Z_IN_CHUNKS;
    }

    bool World::isWithinLoadRadius(int dx, int dy, int dz) {
        int distanceSquared = dx * dx + dy * dy + dz * dz;

        return distanceSquared <= CHUNK_LOAD_RADIUS * CHUNK_LOAD_RADIUS;
    }

    bool World::isWithinUnloadRadius(int dx, int dy, int dz) {
        int distanceSquared = dx * dx + dy * dy + dz * dz;

        return distanceSquared <= CHUNK_UNLOAD_RADIUS * CHUNK_UNLOAD_RADIUS;
    }

    void World::update(float dt) {
        glm::ivec3 playerChunkPosition = getPlayerChunkPosition();

        // Load and unload chunks around the player
        for (int x = playerChunkPosition.x - CHUNK_UNLOAD_RADIUS; x <= playerChunkPosition.x + CHUNK_UNLOAD_RADIUS; x++) {
            for (int y = playerChunkPosition.y - CHUNK_UNLOAD_RADIUS; y <= playerChunkPosition.y + CHUNK_UNLOAD_RADIUS; y++) {
                for (int z = playerChunkPosition.z - CHUNK_UNLOAD_RADIUS; z <= playerChunkPosition.z + CHUNK_UNLOAD_RADIUS; z++) {
                    if (isInWorldHeightBounds(z)) {
                        glm::ivec3 chunkPos(x, y, z);
                        bool isChunkLoaded = m_worldLoader.isChunkLoaded(chunkPos);

                        int dx = x - playerChunkPosition.x;
                        int dy = y - playerChunkPosition.y;
                        int dz = z - playerChunkPosition.z;

                        if (isWithinLoadRadius(dx, dy, dz) && !isChunkLoaded) {
                            m_worldLoader.loadChunk(chunkPos);
                        } else if (isWithinUnloadRadius(dx, dy, dz) && isChunkLoaded) {
                            m_worldLoader.unloadChunk(chunkPos);
                        }
                    }
                }
            }
        }
    }

    int World::getBlock(const glm::ivec3& blockPosition) {
       // Get the chunk index
        glm::ivec3 chunkPosition(
            std::floor(blockPosition.x / m_chunkWidthInBlocks),
            std::floor(blockPosition.y / m_chunkHeightInBlocks),
            std::floor(blockPosition.z / m_chunkDepthInBlocks)
        );
        
        Chunk* chunk = getChunk(chunkPosition);

        // Get the block type
        return chunk->getBlock(blockPosition);
    }

    std::vector<std::pair<Chunk*, float>> World::getSortedChunks() {
        glm::ivec3 playerChunkPosition = getPlayerChunkPosition();

        // Create a vector of pairs containing chunk pointers and their distances to the player
        std::vector<std::pair<Chunk*, float>> sortedChunks;

        for (const auto& chunkPair : m_chunks) {
            Chunk* chunk = chunkPair.second;
            glm::ivec3 chunkPosition(
                chunk->getX() * m_chunkWidthInBlocks,
                chunk->getY() * m_chunkHeightInBlocks,
                chunk->getZ() * m_chunkDepthInBlocks
            );

            glm::ivec3 delta = playerChunkPosition - chunkPosition;
            float distanceSquared = delta.x * delta.x + delta.y * delta.y + delta.z * delta.z;

            sortedChunks.push_back(std::make_pair(chunk, distanceSquared));
        }

        // Sort the vector using the distance as the sorting criteria
        std::sort(sortedChunks.begin(), sortedChunks.end(), [](const auto& a, const auto& b) {
            return a.second < b.second;
        });

        return sortedChunks;
    }

    void World::draw() {
        auto chunks = getSortedChunks();

        // Draw the chunks
    }

    bool World::isBlockVisible(const glm::ivec3& blockPosition) {
        // implement later
        return true;
    }

    int World::getNumChunks() const {
        return m_chunks.size();
    }

    Chunk* World::getChunk(const glm::ivec3& chunkPosition) {
        // Find the corresponding chunk
        auto it = m_chunks.find(chunkPosition);
        if (it == m_chunks.end()) {
            return nullptr;
        }

        return it->second;
    }

    void World::addChunk(Chunk* chunk) {
        m_chunks[chunk->getChunkPosition()] = chunk;
    }

    void World::setBlock(const glm::ivec3& blockPosition, int blockType) {
        // Get the chunk index
        int chunkX = blockPosition.x / m_chunkWidthInBlocks;
        int chunkY = blockPosition.y / m_chunkHeightInBlocks;
        int chunkZ = blockPosition.z / m_chunkDepthInBlocks;
        auto chunk = getChunk({chunkX, chunkY, chunkZ});
        
        // Get the block index within the chunk
        int blockX = blockPosition.x % m_chunkWidthInBlocks;
        int blockY = blockPosition.y % m_chunkHeightInBlocks;
        int blockZ = blockPosition.z % m_chunkDepthInBlocks;

        // Set the block type
        chunk->setBlock({blockX, blockY, blockZ}, blockType);
    }

    ChunkMap World::getChunks() {
        return m_chunks;
    }

    void World::setChunk(Chunk* chunk) {
        auto it = m_chunks.find(chunk->getChunkPosition());
        if (it == m_chunks.end()) {
            // If the chunk does not exist, add it to the map
            addChunk(chunk);
        } else {
            // If the chunk exists, delete the old one and replace it with the new one
            delete it->second;
            it->second = chunk;
        }
    }
}
      