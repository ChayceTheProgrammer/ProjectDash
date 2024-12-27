// FightstickInput.cpp
#include "IInputDevice.h"
#include <SFML/Window/Joystick.hpp>
#include <SFML/System/Vector2.hpp>

class FightstickInput : public IInputDevice {
public:
    FightstickInput(unsigned int joystickId) : joystickId(joystickId) {}

    // Get the movement direction from the fightstick
    sf::Vector2f getMovementDirection() const override {
        sf::Vector2f direction(0.f, 0.f);

        if (sf::Joystick::isConnected(joystickId)) {
            // Read the X and Y axes of the joystick
            float x = sf::Joystick::getAxisPosition(joystickId, sf::Joystick::X);
            float y = sf::Joystick::getAxisPosition(joystickId, sf::Joystick::Y);

            if (x < -15.f) direction.x = -1.f; // Left
            if (x > 15.f) direction.x = 1.f;  // Right
            if (y < -15.f) direction.y = -1.f; // Up
            if (y > 15.f) direction.y = 1.f;  // Down
        }

        return direction;
    }

    // Check if the jump button (e.g., button 0) is pressed
    bool isJumping() const override {
        return sf::Joystick::isButtonPressed(joystickId, 0);
    }

private:
    unsigned int joystickId; // The ID of the joystick (0-7)
};