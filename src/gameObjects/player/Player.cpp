#include "Player.hpp"

namespace Gengine {
    Player::Player(GameComponentsRef data) : _data(data) {
        // _playerSprite.setTexture(_data->assets.getTexture("player"));
        // _playerSprite.setPosition(0, 0);
    };

    void Player::update(float dt) {
        // _playerSprite.move(0.1f, 0.1f);
    };

    void Player::draw() {
        // _data->window.draw(_playerSprite);
    };

    glm::ivec3& Player::getBlockPosition() {
        return _blockPosition;
    };

    void Player::setPositionInBlocks(glm::ivec3& position) {
        _blockPosition = position;
    };

    glm::ivec3 Player::getChunkPosition() {
        return glm::ivec3(
            _blockPosition.x / CHUNK_SIZE_X,
            _blockPosition.y / CHUNK_SIZE_Y,
            _blockPosition.z / CHUNK_SIZE_Z
        );
    };

    void Player::handleInput() {
        
    };
}