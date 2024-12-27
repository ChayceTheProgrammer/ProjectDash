#ifndef PLAYERCONTROLLER_H
#define PLAYERCONTROLLER_H

#include <SFML/Graphics.hpp>

class PlayerController {
public:
    PlayerController(sf::Sprite& playerSprite);
    void handleJump();
    void update(float deltaTime);
    bool isJumping();

private:
    sf::Sprite& sprite;

    float speed;
};

#endif // PLAYERCONTROLLER_H
