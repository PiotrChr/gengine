#pragma once

#include "../Chunk.hpp"
#include <SFML/System/Vector3.hpp>
#include <vector>

namespace Gengine {
    class CaveGenerator {
    public:
        void generateCave(Chunk* chunk);

    };
}