#include "../include/FightstickInput.h"

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