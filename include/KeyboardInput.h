#ifndef KEYBOARDINPUT_H
#define KEYBOARDINPUT_H

#include <iostream>
#include<SFML/System/Vector2.hpp>

class KeyboardInput{
public:
    sf::Vector2f getMovementDirection();
    bool isKeyPressed(int key) const;
    bool isButtonPressed(int button) const;
    bool isJumping() const; 
    bool operator==(const KeyboardInput& other) const; // Remove 'override' keyword
};

#endif // KEYBOARDINPUT_H
