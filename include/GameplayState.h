#pragma once
#include "State.h"
#include "GameManager.h"

class GameplayState : public State {
public:
    void enter() override;
    void update(float deltaTime) override;
    void render(sf::RenderWindow& window) override;
    void leave() override;
};
