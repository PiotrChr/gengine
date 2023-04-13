#pragma once

#include <SFML/Graphics.hpp>
#include "../../engine/game/GameComponents.hpp"
#include "../../engine/DEFINITIONS.hpp"

namespace Gengine {
    class Player {
    public:
        Player(GameComponentsRef data);
        ~Player() {};

        void setPositionInBlocks(const sf::Vector3i& position);
        sf::Vector3i getBlockPosition();
        
        sf::Vector3i getChunkPosition();

        void update(float dt);
        void draw(sf::RenderTarget* target);
        void handleInput(sf::Event event, const float dt);

    private:
        sf::Vector3i _blockPosition;
        GameComponentsRef _data;
    };
}