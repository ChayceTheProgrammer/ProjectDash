#include "../include/PlayerController.h"

PlayerController::PlayerController(sf::Sprite& playerSprite, std::unique_ptr<IInputDevice> inputDevice)
    : sprite(playerSprite),
    inputDevice(std::move(inputDevice)),
    speed(200.f),
    health(100.f)
{
}

void PlayerController::update(float deltaTime) {
    if (!inputDevice)
        return;

    sf::Vector2f direction = inputDevice->getMovementDirection();
    sprite.move(direction * speed * deltaTime);

}

void PlayerController::setInputDevice(std::unique_ptr<IInputDevice> newInputDevice) {
    inputDevice = std::move(newInputDevice);
}

// Implement other methods similarly...