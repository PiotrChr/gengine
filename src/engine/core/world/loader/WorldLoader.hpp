#pragma once

#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include "../Chunk.hpp"

constexpr int GRID_SIZE = 1000;
constexpr int SECTOR_SIZE = 100;

namespace Gengine {
    struct Vector3iHash {
        std::size_t operator()(const sf::Vector3i& v) const {
            std::size_t hx = std::hash<int>()(v.x);
            std::size_t hy = std::hash<int>()(v.y);
            std::size_t hz = std::hash<int>()(v.z);

            return hx ^ (hy * 31 + hz * 73);
        }
    };

    class WorldLoader {
    public:
        // Load a chunk from a file
        Chunk* loadChunk(sf::Vector3i position);

        // Save a chunk to a file
        void saveChunk(Chunk* chunk);

        // Save a vector of chunks to a file
        void saveWorld(std::unordered_map<sf::Vector3i, Chunk*, Vector3iHash> chunks);

        // Unload a chunk
        void unloadChunk(Chunk* chunk);
        
        // Unload a chunk at specified location
        void unloadChunk(sf::Vector3i position);

         // Check if a chunk is loaded
        bool isChunkLoaded(sf::Vector3i position);

    private:
        // Path to the directory containing the world files
        std::string m_worldDirectory = SAVE_MAP_ROOT_PATH;

        // Vector to store all loaded chunks
        std::unordered_map<sf::Vector3i, Chunk*, Vector3iHash> m_loadedChunks;
    };
}
