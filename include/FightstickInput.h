#ifndef FIGHTSTICKINPUT_H
#define FIGHTSTICKINPUT_H

#include "../include/IInputDevice.h"
#include <SFML/Window/Joystick.hpp>

class FightstickInput : public IInputDevice {
public:
    FightstickInput(unsigned int joystickId);
    void update() override;
    bool isButtonPressed(int button) const override;
	sf::Vector2f getMovementDirection() const override;
	bool isJumping() const override;


private:
    unsigned int joystickId; // The ID of the joystick (1-9)
	int button = joystickId;

};

#endif // FIGHTSTICKINPUT_H
