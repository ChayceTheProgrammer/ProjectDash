#ifndef PLAYERCONTROLLER_H
#define PLAYERCONTROLLER_H

#include <memory>
#include <string>
#include <SFML/Graphics/Sprite.hpp>
#include "IInputDevice.h"

class PlayerController {
public:
    PlayerController(sf::Sprite& playerSprite, std::unique_ptr<IInputDevice> inputDevice);

    void update(float deltaTime);
    void setInputDevice(std::unique_ptr<IInputDevice> newInputDevice);


private:
    sf::Sprite& sprite;
    std::unique_ptr<IInputDevice> inputDevice;
    float speed;
    float health;

};

#endif // PLAYERCONTROLLER_H