#include <iostream>
#include "../include/Options.h"

Options::Options()
{
}

Options::~Options()
{
}

void Options::enter()
{
	std::cout << "Entered Options !" << std::endl;
}

void Options::update(float deltaTime)
{
}

void Options::render(sf::RenderWindow& window) {
    // Render state implementation
    // Example: Clear window and draw options menu
    window.clear();
    // Draw options menu items here
    window.display();
}

void Options::leave()
{
}
