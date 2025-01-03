#include "../include/KeyboardInput.h"

// Get the movement direction based on keyboard input
sf::Vector2f KeyboardInput::getMovementDirection() const
{
    sf::Vector2f direction(0.f, 0.f);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        direction.x -= 1.f;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        direction.x += 1.f;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        direction.y -= 1.f;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        direction.y += 1.f;
    }
    return direction;
}

// Check if the player wants to jump
bool KeyboardInput::isJumping() const {
    return sf::Keyboard::isKeyPressed(sf::Keyboard::Space);
}
