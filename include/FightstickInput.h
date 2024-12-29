#ifndef FIGHTSTICKINPUT_H
#define FIGHTSTICKINPUT_H

#include "IInputDevice.h"
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Joystick.hpp>

class FightstickInput : public IInputDevice {
public:
    explicit FightstickInput(unsigned int joystickId);

    sf::Vector2f getMovementDirection() const override;
    bool isJumping() const override;

private:
    unsigned int joystickId;
};

#endif // FIGHTSTICKINPUT_H