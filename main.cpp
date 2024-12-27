#include "src/GameManager.cpp" 

int main() {
    try {
        GameManager TheGame;
		TheGame.Game();
        TheGame.run();
	}
	catch (const std::exception& e) {
		std::cerr << "An error occurred: " << e.what() << std::endl;
		return EXIT_FAILURE;
	}

    return 0;
}