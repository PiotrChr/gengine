#pragma once

#include "../../engine/game/GameComponents.hpp"
#include "../../engine/DEFINITIONS.hpp"
#include "glm/glm.hpp"

namespace Gengine {
    class Player {
    public:
        Player(GameComponentsRef data);
        ~Player() {};

        void setPositionInBlocks(glm::ivec3& position);
        glm::ivec3& getBlockPosition();
        glm::ivec3 getChunkPosition();

        void update(float dt);
        void draw();
        void handleInput();

    private:
        glm::ivec3 _blockPosition;
        GameComponentsRef _data;
    };
}