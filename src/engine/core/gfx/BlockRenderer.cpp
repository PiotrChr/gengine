#include "BlockRenderer.hpp"

namespace Gengine {
    void BlockRenderer::drawBlock(
        int blockType,
        const sf::Vector3i& chunkPosition,
        int blockIndex,
        sf::RenderTarget* target
    ) {
        auto blockPosition = getBlockPosition(chunkPosition, blockIndex);

        glm::mat4 model = glm::translate(glm::mat4(1.0f), glm::vec3(blockPosition.x, blockPosition.y, blockPosition.z));
        cube.addInstance(model);
    }

    void BlockRenderer::init() {
        cube.init();
    }

    void BlockRenderer::render(const glm::mat4& viewMatrix, const glm::mat4& projectionMatrix) {
        cube.draw(viewMatrix, projectionMatrix);
    }

    sf::Vector3i BlockRenderer::getBlockPosition(const sf::Vector3i& chunkPosition, int blockIndex) {
        return sf::Vector3i(
            (chunkPosition.x * CHUNK_SIZE_X + (blockIndex % CHUNK_SIZE_X)) * BLOCK_SIZE,
            (chunkPosition.y * CHUNK_SIZE_Y + ((blockIndex / CHUNK_SIZE_X) % CHUNK_SIZE_Y)) * BLOCK_SIZE,
            (chunkPosition.z * CHUNK_SIZE_Z + (blockIndex / (CHUNK_SIZE_X * CHUNK_SIZE_Y))) * BLOCK_SIZE
        );
    }
}