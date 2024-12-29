#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <iostream>
#include <exception>
#include <memory>
#include <SFML/Graphics.hpp>
#include "PlayerController.h"

class GameManager {
public:
	GameManager();
	void run();

private:
	
	static constexpr int WINDOW_WIDTH = 640;
	static constexpr int WINDOW_HEIGHT = 480;

	sf::RenderWindow window;
	sf::Sprite playerSprite;
	sf::Clock clock; // For delta time calculation
	std::unique_ptr<PlayerController> playerController;

	void initialize();
	void processEvents();
	void update();
	void render();
	
};
#endif // GAMEMANAGER_H