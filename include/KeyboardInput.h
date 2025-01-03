#ifndef KEYBOARDINPUT_H
#define KEYBOARDINPUT_H

#include "IInputDevice.h"
#include <SFML/Window/Keyboard.hpp>

class KeyboardInput : public IInputDevice {
public:
    // Get the movement direction based on keyboard input
    sf::Vector2f getMovementDirection() const override;

    // Check if the player wants to jump
    bool isJumping() const override;
};

#endif // KEYBOARDINPUT_H
