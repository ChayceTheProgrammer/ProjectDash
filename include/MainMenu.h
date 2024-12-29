#ifndef MAINMENU_H
#define MAINMENU_H

#include <iostream>	
#include "State.h"

//inherit from base class 'State'
class MainMenu : public State {
public:
	MainMenu();
	virtual ~MainMenu();

	//These do NOT need to be virual because they are inheriting the State.h base methods
	void enter();
	void update(float deltaTime);
	void leave();



};
#endif // MAINMENU_H