#include "../include/KeyboardInput.h"
#include <SFML/Window/Keyboard.hpp>
#include <SFML/System/Vector2.hpp>

bool KeyboardInput::isKeyPressed(int key) const {
    return sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(key));
};

bool KeyboardInput::isButtonPressed(int button) const {
    return false;
};

bool KeyboardInput::operator==(const KeyboardInput& other) const {
    return false;
};

bool KeyboardInput::isJumping() const
{
    return false;
};

sf::Vector2f KeyboardInput::getMovementDirection() {
    sf::Vector2f direction(0.f, 0.f);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        std::cout << "Left key pressed" << std::endl;
        direction.x -= 1.f;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        std::cout << "Right key pressed" << std::endl;
        direction.x += 1.f;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        std::cout << "Up key pressed" << std::endl;
        direction.y -= 1.f;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        std::cout << "Down key pressed" << std::endl;
        direction.y += 1.f;
    }

    return direction;
};