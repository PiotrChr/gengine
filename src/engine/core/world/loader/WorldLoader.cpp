#include "WorldLoader.hpp"

namespace Gengine {
    Chunk* WorldLoader::loadChunk(const glm::ivec3& position) {
        // Check if the chunk is already loaded
        auto it = m_loadedChunks.find(position);
        if (it != m_loadedChunks.end()) {
            return it->second;
        }

        // Load the chunk from a file
        std::string filename = m_worldDirectory + "chunk_" + std::to_string(position.x) + "_" + std::to_string(position.y) + "_" + std::to_string(position.z) + ".dat";
        std::ifstream file(filename, std::ios::binary);
        if (!file.good()) {
            std::cout << "Failed to load chunk " << position.x << ", " << position.y << ", " << position.z << std::endl;
            return nullptr;
        }

        Chunk* chunk = new Chunk(position);

        for (int i = 0; i < CHUNK_SIZE_X; i++) {
            for (int j = 0; j < CHUNK_SIZE_Y; j++) {
                for (int k = 0; k < CHUNK_SIZE_Z; k++) {
                    int blockType = 0;
                    file.read((char*)&blockType, sizeof(int));
                    chunk->setBlock({i, j, k}, blockType);
                }
            }
        }

        file.close();

        m_loadedChunks[position] = chunk;

        return chunk;
    }

    void WorldLoader::saveChunk(Chunk* chunk) {
        // Save the chunk to a file
        std::string filename = m_worldDirectory
            + "chunk_"
            + std::to_string(chunk->getX())
            + "_" + std::to_string(chunk->getY())
            + "_" + std::to_string(chunk->getZ())
            + ".dat";

        std::filesystem::create_directory(SAVE_FILE_PATH);
        bool created = std::filesystem::create_directory(m_worldDirectory);
        
        std::ofstream file(filename, std::ios::binary);
        if (!file.good()) {
            throw std::runtime_error("Failed to save chunk " + std::to_string(chunk->getX()) + ", " + std::to_string(chunk->getY()) + ", " + std::to_string(chunk->getZ()) + " to file " + filename);
            return;
        }

        for (int i = 0; i < CHUNK_SIZE_X; i++) {
            for (int j = 0; j < CHUNK_SIZE_Y; j++) {
                for (int k = 0; k < CHUNK_SIZE_Z; k++) {
                    int blockType = chunk->getBlock({i, j, k});
                    file.write((char*)&blockType, sizeof(int));
                }
            }
        }

        file.close();
    }

    void WorldLoader::unloadChunk(Chunk* chunk) {
        // Unload the chunk
        for (auto it = m_loadedChunks.begin(); it != m_loadedChunks.end(); it++) {
            if (it->second == chunk) {
                m_loadedChunks.erase(it);
                delete chunk;
                return;
            }
        }
    }

    bool WorldLoader::isChunkLoaded(const glm::ivec3& position) {
        // Check if a chunk is loaded
        for (const auto& chunk_pair : m_loadedChunks) {
            if (chunk_pair.first == position) {
                return true;
            }
        }

        return false;
    }

    void WorldLoader::saveWorld(ChunkMap chunks) {
        for (const auto& chunk_pair : chunks) {
            Chunk* chunk = chunk_pair.second;
            saveChunk(chunk);
        }
    }

    void WorldLoader::unloadChunk(const glm::ivec3& position) {
        // Unload a chunk at specified location
        for (auto it = m_loadedChunks.begin(); it != m_loadedChunks.end(); ++it) {
            if (it->first == position) {
                delete it->second;
                m_loadedChunks.erase(it);
                return;
            }
        }
    }
}
