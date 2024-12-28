#include "../include/FightstickInput.h"
#include <SFML/Window/Joystick.hpp>

FightstickInput::FightstickInput(unsigned int joystickId)
    : joystickId(joystickId)
{
}

sf::Vector2f FightstickInput::getMovementDirection() const {
    // Implementation...
}

bool FightstickInput::isJumping() const {
    // Implementation...
}