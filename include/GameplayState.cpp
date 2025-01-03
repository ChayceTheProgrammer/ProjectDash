#include "GameplayState.h"
#include <SFML/Graphics.hpp>

void GameplayState::enter() {
    // Initialize gameplay resources (e.g., load level, set up entities)
    // Example: Load level data, initialize player position, etc.
}

void GameplayState::update(float deltaTime) {
    // Update game logic (e.g., player movement, collision detection)
    // Example: Update player position based on input
    GameManager::getInstance().getPlayerController()->update(deltaTime);
}

void GameplayState::render(sf::RenderWindow& window) {
    // Render game elements (e.g., player, enemies, environment)
    // Example: Draw player sprite
    window.draw(GameManager::getInstance().getPlayerSprite());
}

void GameplayState::leave() {
    // Clean up gameplay resources
    // Example: Save game state, release resources, etc.
}
