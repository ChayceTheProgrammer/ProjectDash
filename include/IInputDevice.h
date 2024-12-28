// IInputDevice.h
#ifndef IINPUTDEVICE_H
#define IINPUTDEVICE_H

#include <SFML/System/Vector2.hpp> // For movement vector

class IInputDevice {
public:
    virtual ~IInputDevice() = default;

    // Returns the movement direction as a 2D vector (e.g., {-1, 0} for left)
    virtual sf::Vector2f getMovementDirection() const = 0;

    // Returns true if the device detects a jump action
    virtual bool isJumping() const = 0;
};

#endif // IINPUTDEVICE_H