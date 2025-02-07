#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <iostream>
#include <exception>
#include <memory>
#include <SFML/Graphics.hpp>

//states (add all states in header instead of .cpp)
#include "State.h"
#include "MainMenu.h"
#include "Options.h"
#include "GameplayState.h"

#include "PlayerController.h"
#include "ResourceManager.h"
#include "KeyboardInput.h"

class GameManager {
public:
    GameManager();
    //no public constructor to ensure only one instance of GameManager exists
    static GameManager& getInstance();
    void run();
    void setState(State* newState);
    static constexpr int WINDOW_WIDTH = 640;
    static constexpr int WINDOW_HEIGHT = 480;
    sf::RenderWindow window;
    sf::Sprite& getPlayerSprite(); // Add this method in .cpp
    sf::RenderWindow& getWindow(); // Add this method
    PlayerController* getPlayerController(); // Add this method

private:
    
    sf::Sprite playerSprite;
    sf::Clock clock;
    std::unique_ptr<PlayerController> playerController;
    State* currentState;
    bool isGameRunning;
    void initialize();
    void processEvents();
    void update();
    void render();
};

#endif // GAMEMANAGER_H