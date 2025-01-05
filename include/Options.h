#ifndef OPTIONS_H
#define OPTIONS_H

#include "State.h"
#include <iostream>


class Options : public State {
public:
	Options();
	virtual ~Options();
	void enter();
	void update(float deltaTime);
	void render(sf::RenderWindow& window) override;
	void leave();
};
#endif // OPTIONS_H

