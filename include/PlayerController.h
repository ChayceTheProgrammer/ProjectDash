#ifndef PLAYERCONTROLLER_H
#define PLAYERCONTROLLER_H

#include <SFML/Graphics.hpp>
#include "IInputDevice.h"

class PlayerController {
public:
    PlayerController(sf::Sprite& playerSprite, IInputDevice* inputDevice);
    void update(float deltaTime);
    void setInputDevice(IInputDevice* newInputDevice);

private:
    sf::Sprite& sprite;
    IInputDevice* inputDevice;
    float speed;
};

#endif // PLAYERCONTROLLER_H
