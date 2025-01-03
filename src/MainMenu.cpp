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
    // Handle input and update main menu logic
    // Example: Transition to Options state on key press
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::O)) {
        GameManager::getInstance().setState(new Options());
    }
    // Example: Transition to gameplay state on key press
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
        GameManager::getInstance().setState(new GameplayState());
    }
}

void MainMenu::render(sf::RenderWindow& window) {
	// Render menu options
	// Use SFML text rendering instead of cout
	
}

void MainMenu::leave()
{
}
