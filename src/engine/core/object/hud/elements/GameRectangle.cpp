#include "GameRectangle.hpp"

namespace Gengine {
    void GameRectangle::draw(sf::RenderTarget* target) {
        target->draw(*this);
    };
}