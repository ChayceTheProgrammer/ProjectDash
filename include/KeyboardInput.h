#ifndef KEYBOARDINPUT_H
#define KEYBOARDINPUT_H

#include "InputDevice.h"

class KeyboardInput : public IInputDevice {
public:
    sf::Vector2f getMovementDirection() const override;
    bool isJumping() const override;
    void update() override;
    bool isButtonPressed(int button) const override;
    bool isKeyPressed(int key) const override;
};

#endif // KEYBOARDINPUT_H
