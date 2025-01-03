#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <iostream>
#include <exception>
#include <memory>
#include <SFML/Graphics.hpp>

//states
#include "State.h"
#include "MainMenu.h"
#include "Options.h"

#include "PlayerController.h"
#include "ResourceManager.h"
#include "KeyboardInput.h"

class GameManager {
public:
	GameManager();
	void run();
	void setState(State* newState);
	sf::RenderWindow& getWindow() { return window; }

private:
	
	static constexpr int WINDOW_WIDTH = 640;
	static constexpr int WINDOW_HEIGHT = 480;

	sf::RenderWindow window;
	sf::Sprite playerSprite;
	sf::Clock clock; // For delta time calculation
	std::unique_ptr<PlayerController> playerController;

	State* currentState;
	bool isGameRunning;

	void initialize();
	void processEvents();
	void update();
	void render();
	
};
#endif // GAMEMANAGER_H