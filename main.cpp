#include "include/GameManager.h" 

int main() {
    try {
        GameManager TheGame;
        TheGame.run();
	}
	catch (const std::exception& e) {
		std::cout << "nothing to report" << std::endl;
		std::cerr << "An error occurred: " << e.what() << std::endl;
		return EXIT_FAILURE;
	}

    return 0;
}