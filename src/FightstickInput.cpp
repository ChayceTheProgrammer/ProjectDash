#include "../include/FightstickInput.h"

FightstickInput::FightstickInput(unsigned int joystickId) : joystickId(joystickId) {};

void FightstickInput::update() {
    // *UPDATE LOGIC*
};

bool FightstickInput::isButtonPressed(int button) const {
    return sf::Joystick::isButtonPressed(joystickId, button);
}

sf::Vector2f FightstickInput::getMovementDirection() const {
    sf::Vector2f direction(0.f, 0.f);

    if (sf::Joystick::isConnected(joystickId)) {
        float x = sf::Joystick::getAxisPosition(joystickId, sf::Joystick::X);
        float y = sf::Joystick::getAxisPosition(joystickId, sf::Joystick::Y);

        if (x < -15.f) direction.x = -1.f; // Left
        if (x > 15.f) direction.x = 1.f;  // Right
        if (y < -15.f) direction.y = -1.f; // Up
        if (y > 15.f) direction.y = 1.f;  // Down
    }

    return direction;
};

bool FightstickInput::isJumping() const {
    return sf::Joystick::isButtonPressed(joystickId, 0);
};