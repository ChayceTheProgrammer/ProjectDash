#ifndef MAINMENU_H
#define MAINMENU_H

#include "State.h"
#include <iostream>	
#include <SFML/Graphics.hpp>

//inherit from base class 'State'
class MainMenu : public State {
public:
	MainMenu();
	virtual ~MainMenu();

	//These do NOT need to be virual because they are inheriting the State.h base methods
	void enter() override;
	void update(float deltaTime) override;
	void render(sf::RenderWindow& window) override;
	void leave() override;

private:
	sf::Text menuText;
	int selectedOption;


};
#endif // MAINMENU_H