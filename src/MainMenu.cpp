#include "../include/MainMenu.h"

MainMenu::MainMenu()
{
}

MainMenu::~MainMenu()
{
}

void MainMenu::enter()
{
	std::cout << "Entering Main Menu" << std::endl;

}

void MainMenu::update(float deltaTime)
{
	while (true)
	{
		std::cout << "Main Menu Options" << std::endl;
		std::cout << "1. Menu" << std::endl;
		std::cout << "2. Options" << std::endl;
		std::cout << "9. Exit" << std::endl;
		
		int choice = -1;
		std::cin >> choice;
		switch (choice) {
		case 1:
			std::cout << "Menu" << std::endl;
			currentState = mainMenuState;
			break;
		case 2:
			std::cout << "Options" << std::endl;
			currentState = optionsState;
			break;
		case 9:
			std::cout << "Exiting" << std::endl;
			exit(0);
			break;

		default:
			std::cout << "Invalid choice" << std::endl;
			break;
		}

	}
	
}

void MainMenu::leave()
{
	std::cout << "Leaving Main Menu" << std::endl;
}
