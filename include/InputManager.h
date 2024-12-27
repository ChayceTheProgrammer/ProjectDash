#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include "InputBuffer.h"
#include <SFML/Window.hpp>

class InputManager {
private:
    InputBuffer& inputBuffer;

public:
    explicit InputManager(InputBuffer& buffer) : inputBuffer(buffer) {}
    void pollInputs();
};

#endif // INPUTMANAGER_H
