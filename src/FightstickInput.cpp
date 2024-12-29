#include "../include/FightstickInput.h"

FightstickInput::FightstickInput(unsigned int joystickId)
    : joystickId(joystickId)
{
}

sf::Vector2f FightstickInput::getMovementDirection() const {
    // Implementation...
	return sf::Vector2f(0.f, 0.f);
}

bool FightstickInput::isJumping() const {
    // Implementation...
    return false;
}