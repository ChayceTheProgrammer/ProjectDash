#ifndef KEYBOARDINPUT_H
#define KEYBOARDINPUT_H

#include "IInputDevice.h"

class KeyboardInput : public IInputDevice {
public:
    void update() override;
    bool isKeyPressed(int key) const override;
};

#endif // KEYBOARDINPUT_H
