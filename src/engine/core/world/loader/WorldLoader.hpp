#pragma once

#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include "../Chunk.hpp"
#include <unordered_map>

constexpr int GRID_SIZE = 1000;
constexpr int SECTOR_SIZE = 100;

namespace Gengine {
    struct Vector3iHash {
        std::size_t operator()(const glm::ivec3& v) const {
            std::size_t hx = std::hash<int>()(v.x);
            std::size_t hy = std::hash<int>()(v.y);
            std::size_t hz = std::hash<int>()(v.z);

            return hx ^ (hy * 31 + hz * 73);
        }
    };

    struct Vector3iEqual {
        bool operator()(const glm::ivec3& lhs, const glm::ivec3& rhs) const {
            return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z;
        }
    };

    typedef std::unordered_map<glm::ivec3, Chunk*, Vector3iHash, Vector3iEqual> ChunkMap;

    class WorldLoader {
    public:
        // Load a chunk from a file
        Chunk* loadChunk(const glm::ivec3& position);

        // Save a chunk to a file
        void saveChunk(Chunk* chunk);

        // Save a vector of chunks to a file
        void saveWorld(ChunkMap chunks);

        // Unload a chunk
        void unloadChunk(Chunk* chunk);
        
        // Unload a chunk at specified location
        void unloadChunk(const glm::ivec3& position);

         // Check if a chunk is loaded
        bool isChunkLoaded(const glm::ivec3& position);

    private:
        // Path to the directory containing the world files
        std::string m_worldDirectory = SAVE_MAP_ROOT_PATH;

        // Vector to store all loaded chunks
        ChunkMap m_loadedChunks;
    };
}
