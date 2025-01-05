#ifndef MAINMENU_H
#define MAINMENU_H

#include "State.h"
#include <iostream>	
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>

//inherit from base class "State"
class MainMenu : public State {
public:
	MainMenu();
	~MainMenu();

	//These do NOT need to be virual because they are inheriting the State.h base methods
	void enter() override;
	void update(float deltaTime) override;
	void render(sf::RenderWindow& window) override;
	void leave() override;

private:
	sf::Font font;
	std::vector<std::string> menuOptions;
	std::vector<sf::Text> menuTexts;
	size_t selectedOption;

	void updateMenuColors();

};
#endif // MAINMENU_H