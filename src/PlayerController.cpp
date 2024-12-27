#include<iostream>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>
#include "IInputDevice.h"

/*
// Create a fightstick input device for joystick 0
FightstickInput fightstickInput(0);

// Switch from keyboard to fightstick
playerController.setInputDevice(&fightstickInput);
*/


class PlayerController {
public:
    PlayerController(sf::Sprite& playerSprite, IInputDevice* inputDevice)
        : sprite(playerSprite), inputDevice(inputDevice), speed(200.f) {
    }

    // Update the player's position based on input
    void update(float deltaTime) {
        if (!inputDevice) return;

        // Get movement direction from the input device
        sf::Vector2f direction = inputDevice->getMovementDirection();

        // Scale movement by speed and deltaTime
        sprite.move(direction * speed * deltaTime);

        // Handle jump action (if any)
        if (inputDevice->isJumping()) {
            // Jumping logic (e.g., apply vertical movement or physics)
            // Placeholder for now
            std::cout << "Player is jumping!" << std::endl;
        }
    }

    // Change the input device (e.g., swap from keyboard to fightstick)
    void setInputDevice(IInputDevice* newInputDevice) {
        inputDevice = newInputDevice;
    }

private:
    sf::Sprite& sprite;        // Reference to the player's sprite
    IInputDevice* inputDevice; // Pointer to the input device
    float speed;               // Movement speed in pixels per second
};
