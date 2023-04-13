#include "Player.hpp"

namespace Gengine {
    Player::Player(GameComponentsRef data) : _data(data) {
        // _playerSprite.setTexture(_data->assets.getTexture("player"));
        // _playerSprite.setPosition(0, 0);
    };

    void Player::update(float dt) {
        // _playerSprite.move(0.1f, 0.1f);
    };

    void Player::draw(sf::RenderTarget* target) {
        // _data->window.draw(_playerSprite);
    };

    sf::Vector3i Player::getBlockPosition() {
        return _blockPosition;
    };

    void Player::setPositionInBlocks(const sf::Vector3i& position) {
        _blockPosition = position;
    };

    sf::Vector3i Player::getChunkPosition() {
        return sf::Vector3i(
            _blockPosition.x / CHUNK_SIZE_X,
            _blockPosition.y / CHUNK_SIZE_Y,
            _blockPosition.z / CHUNK_SIZE_Z
        );
    };

    void Player::handleInput(sf::Event event, const float dt) {
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::W) {
                _blockPosition.z -= 1;
            } else if (event.key.code == sf::Keyboard::S) {
                _blockPosition.z += 1;
            } else if (event.key.code == sf::Keyboard::A) {
                _blockPosition.x -= 1;
            } else if (event.key.code == sf::Keyboard::D) {
                _blockPosition.x += 1;
            } else if (event.key.code == sf::Keyboard::Space) {
                _blockPosition.y += 1;
            } else if (event.key.code == sf::Keyboard::LShift) {
                _blockPosition.y -= 1;
            }
        }
    };
}