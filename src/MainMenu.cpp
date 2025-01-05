#include "../include/MainMenu.h"
#include "../include/GameManager.h"

MainMenu::MainMenu() : selectedOption(0) {
	// Initialize menu text and options
    // Load font
    if (!font.loadFromFile("assets/fonts/pixel_font.ttf")) {
        throw std::runtime_error("Failed to load font!");
    }

    // Set up menu options
    menuOptions.push_back("Start Game");
    menuOptions.push_back("Options");
    menuOptions.push_back("Exit");

    for (size_t i = 0; i < menuOptions.size(); ++i) {
        sf::Text text;
        text.setFont(font);
        text.setString(menuOptions[i]);
        text.setCharacterSize(24); // Pixel art style font size
        text.setFillColor(i == selectedOption ? sf::Color::Red : sf::Color::White);
        text.setPosition(100.f, 100.f + i * 50.f); // Position each option
        menuTexts.push_back(text);
    }

}

MainMenu::~MainMenu() { }

void MainMenu::enter() 
{
    // Any initialization when entering the menu
}

void MainMenu::update(float deltaTime) {
    // Handle keyboard input for menu navigation
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        if (selectedOption > 0) {
            selectedOption--;
            updateMenuColors();
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        if (selectedOption < menuOptions.size() - 1) {
            selectedOption++;
            updateMenuColors();
        }
    }
    // Handle selection
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
        if (selectedOption == 0) {
            // Start Game
            GameManager::getInstance().setState(new GameplayState());
        }
        else if (selectedOption == 1) {
            // Options
            GameManager::getInstance().setState(new Options());
        }
        else if (selectedOption == 2) {
            // Exit
            GameManager::getInstance().getWindow().close();
        }
    }
}

void MainMenu::render(sf::RenderWindow& window) {
	// Render menu options
	// Use SFML text rendering instead of cout
    for (const auto& text : menuTexts) {
        window.draw(text);
    }
}

void MainMenu::leave()
{
    //Cleanup Menu aka DELETE
}

void MainMenu::updateMenuColors() {
    for (size_t i = 0; i < menuTexts.size(); ++i) {
        menuTexts[i].setFillColor(i == selectedOption ? sf::Color::Red : sf::Color::White);
    }
}