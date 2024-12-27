#ifndef IINPUTDEVICE_H
#define IINPUTDEVICE_H

#include <SFML/System/Vector2.hpp> 

class IInputDevice {
public:
    virtual ~IInputDevice() = default;

    // Returns the movement direction as a 2D vector (e.g., {-1, 0} for left)
    virtual sf::Vector2f getMovementDirection() const = 0;

    // Returns true if the device detects a jump action
    virtual bool isJumping() const = 0;

    // Update the input device state
    virtual void update() = 0;

    // Check if a specific button is pressed
    virtual bool isButtonPressed(int button) const = 0;

    // Check if a specific key is pressed
    virtual bool isKeyPressed(int key) const = 0;
};

#endif // IINPUTDEVICE_H