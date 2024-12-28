#include <iostream>
#include <SFML/Graphics.hpp>
#include "../include/PlayerController.h"
#include "../include/GameManager.h"
#include "../include/ResourceManager.h"
#include "KeyboardInput.cpp"

GameManager::GameManager() : window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Project Dash!", sf::Style::Default) {
    initialize();
}

void GameManager::run() {
    while (window.isOpen()) {
        processEvents();
        update();
        render();
    }
}

void GameManager::initialize() {
    // Set window position
    window.setPosition(sf::Vector2i(10, 50));

    // Load textures
    if (!ResourceManager::getInstance().loadTexture("shadow", "assets/CharacterSpriteSheets/shadow-2.gif")) {
        throw std::runtime_error("Failed to load shadow texture!");
    }

    // Set up the player sprite
    playerSprite.setTexture(ResourceManager::getInstance().getTexture("shadow"));

    // Initialize player controller with keyboard input
    auto keyboardInput = std::make_unique<KeyboardInput>();
    playerController = std::make_unique<PlayerController>(playerSprite, std::move(keyboardInput));
}

void GameManager::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        // Handle window close event
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        // Handle other events (e.g., resizing, input)
    }
}

void GameManager::update() {
    float deltaTime = clock.restart().asSeconds();

    // Cap deltaTime to prevent issues when debugging or if the game lags
    if (deltaTime > 0.1f)
        deltaTime = 0.1f;

    playerController->update(deltaTime);
}

void GameManager::render() {
    window.clear();
    window.draw(playerSprite);
    window.display();
}
