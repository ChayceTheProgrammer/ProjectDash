#include <iostream>
#include <SFML/Graphics/Sprite.hpp>
#include "../include/PlayerController.h"

PlayerController::PlayerController(sf::Sprite& playerSprite) 
    : sprite(playerSprite), speed(200.f) {};

void PlayerController::handleJump() {
    // Placeholder for jump logic
    std::cout << "Player is jumping!" << std::endl;
};

void PlayerController::update(float deltaTime) {
    // Get movement direction from the input device
    sf::Vector2f direction;

    // Scale movement by speed and deltaTime
    sprite.move(direction * speed * deltaTime);
};

bool PlayerController::isJumping() {
    // Placeholder for jump logic
    // if(player.x >= 0){
    //     return true;
    // }
    return false;
};
