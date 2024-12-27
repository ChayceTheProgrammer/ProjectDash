#include "../include/GameManager.h"
#include "InputBuffer.cpp"


void GameManager::Game() {
    //create window and set position
    window.create(sf::VideoMode(640, 480), "Project Dash!", sf::Style::Default);
    window.setPosition(sf::Vector2i(10, 50));

    // Load textures
    if (!ResourceManager::getInstance().loadTexture("shadow", "assets/CharacterSpriteSheets/shadow-2.gif")) {
        throw std::runtime_error("Failed to load shadow texture!");
    }

    // Set up the sprite
    sprite.setTexture(ResourceManager::getInstance().getTexture("shadow"));

}

void GameManager::run() {
    while (window.isOpen()) {
        processEvents();
        update();
        render();
    }
}

void GameManager::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        switch (event.type) {
        case sf::Event::Closed:
            window.close();
            break;

        case sf::Event::TextEntered:
            if (event.text.unicode < 128) {
                std::cout << "ASCII character typed: " << static_cast<char>(event.text.unicode) << std::endl;
            }
            break;

        case sf::Event::MouseButtonPressed:
            if (event.mouseButton.button == sf::Mouse::Left) {
                std::cout << "Left mouse button pressed." << std::endl;
            }
            else if (event.mouseButton.button == sf::Mouse::Right) {
                std::cout << "Right mouse button pressed." << std::endl;
            }
            break;

        case sf::Event::GainedFocus:
            std::cout << "Gained Window Focus" << std::endl;
            break;

        case sf::Event::LostFocus:
            std::cout << "Lost Window Focus" << std::endl;
            break;

        default:
            break;
        }
    }
}

void GameManager::update() {
    // Add game logic updates here (e.g., sprite movement, collision detection)
}

void GameManager::render() {
    window.clear();
    window.draw(sprite);
    window.display();
}
