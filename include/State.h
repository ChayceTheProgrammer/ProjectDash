#ifndef STATE_H
#define STATE_H
//base state machine implementation

#include <SFML/Graphics.hpp>

class GameManager;

//Abstract Class of State Class (uses 'virtual' methods
//(will never be used itself but all other states must inherit this states methods)
class State {
public:
	//set all to '0' to enforce abstract propetries

	State();
	virtual ~State();
	
	virtual void enter() = 0; //set up variables for current state
	/* - set up music
	*  - set up cursor
    - load game settings
    - 
	*/

	//must include code to change states (keyboard input...etc)
	virtual void update(float deltaTime) = 0; 

	virtual void render(sf::RenderWindow& window) = 0;

	//free up memory of state for next state / cancel things from enter()
	virtual void leave() = 0;
	
	//States to implement into machine
	static State* mainMenuState;
	static State* optionsState;
	/*
	Credits
	Load Game
	Mode Select
	*/
protected:
	static GameManager* gameManager;

};
#endif // STATE_H