#pragma once

#include <SFML/Graphics.hpp>
#include "../../DEFINITIONS.hpp"
#include "Cube.hpp"

namespace Gengine {
    class BlockRenderer {
    public:
        void init();
        void drawBlock(int blockType, const sf::Vector3i& chunkPosition, int blockIndex, sf::RenderTarget* target);
        void render(const glm::mat4& viewMatrix, const glm::mat4& projectionMatrix);
    private:
        sf::Vector3i getBlockPosition(const sf::Vector3i& chunkPosition, int blockIndex);

        Cube cube;
    };
}