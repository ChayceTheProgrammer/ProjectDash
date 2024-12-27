#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <SFML/OpenGL.hpp>
#include "ResourceManager.h"
#include "KeyboardInput.h"
#include "PlayerController.h"
#include "FightstickInput.h"

class GameManager {
public:
    void Game();
    void run();

private:
    void processEvents();
    void update();
    void render();

    sf::RenderWindow window;
    sf::Sprite sprite;
};

#endif // GAMEMANAGER_H