#pragma once

#include "../../DEFINITIONS.hpp"
#include "Cube.hpp"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

/**
 * TODO: Implement more advanced culling techniques, such as
 *  - occlusion culling
 *  - frustum culling
 *  - level-of-detail (LOD)
 * 
*/

namespace Gengine {
    class BlockRenderer {
    public:
        void init();
        void drawBlock(int blockType, const glm::ivec3& chunkPosition, int blockIndex);
        void render(const glm::mat4& viewMatrix, const glm::mat4& projectionMatrix);
    private:
        glm::ivec3 getBlockPosition(const glm::ivec3& chunkPosition, int blockIndex);

        // TODO: Add "Cube cube";
    };
}