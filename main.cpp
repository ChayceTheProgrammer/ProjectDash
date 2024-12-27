#include <iostream>
#include "src/ResourceManager.cpp" // Include the resource manager
#include "src/GameManager.cpp" // Include the game manager

int main() {
    try {
        Game game;
        game.run();
	}
	catch (const std::exception& e) {
		std::cerr << "An error occurred: " << e.what() << std::endl;
		return EXIT_FAILURE;
	}

    return 0;
}