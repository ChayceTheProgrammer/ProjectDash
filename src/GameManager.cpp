#include "../include/GameManager.h"

GameManager::GameManager() :
    window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Project Dash!", sf::Style::Default),
    isGameRunning(true)
{
    initialize();
    currentState = new MainMenu();
    currentState->enter();
}

void GameManager::run() {
    while (window.isOpen() && isGameRunning) {
        processEvents();
        update();
        render();
    }
}

void GameManager::setState(State* newState) {
    if (currentState) {
        currentState->leave();
    }
    currentState = newState;
    if (currentState) {
        currentState->enter();
    }
}

void GameManager::initialize() {
    // Set window position
    window.setPosition(sf::Vector2i(10, 50));

    // Load textures
    if (!ResourceManager::getInstance().loadTexture("shadow", "assets/CharacterSpriteSheets/shadow.png")) {
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
    if (deltaTime > 0.1f) { deltaTime = 0.1f; }

    if (currentState) {
        currentState->update(deltaTime);
    }

    // Only update player when in gameplay state
    if (dynamic_cast<GameplayState*>(currentState)) {
        playerController->update(deltaTime);
    }
}

void GameManager::render() {
    window.clear();

    if (currentState) {
        currentState->render(window);
    }

    // Only render player when in gameplay state
    if (dynamic_cast<GameplayState*>(currentState)) {
        window.draw(playerSprite);
    }

    window.display();
}

sf::Sprite& GameManager::getPlayerSprite() {
    return playerSprite;
}

PlayerController* GameManager::getPlayerController() {
    return playerController.get();
}

sf::RenderWindow& GameManager::getWindow()
{
    // TODO: insert return statement here
}