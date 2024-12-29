#include "../include/MainMenu.h"
#include "../include/GameManager.h"

MainMenu::MainMenu() : selectedOption(0) {
	// Initialize menu text and options
}

MainMenu::~MainMenu()
{
}

void MainMenu::enter() 
{
}

void MainMenu::update(float deltaTime) {
	// Handle keyboard input for menu navigation
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		selectedOption = (selectedOption - 1 + 3) % 3;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		selectedOption = (selectedOption + 1) % 3;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
		switch (selectedOption) {
		case 0: // Start Game
			// gameManager->setState(gameplayState);
			break;
		case 1: // Options
			// gameManager->setState(optionsState);
			break;
		case 2: // Exit
			gameManager->getWindow().close();
			break;
		}
	}
}

void MainMenu::render(sf::RenderWindow& window) {
	// Render menu options
	// Use SFML text rendering instead of cout
	
}

void MainMenu::leave()
{
}
