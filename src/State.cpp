#include "../include/State.h"

// Define static members
State* State::mainMenuState = nullptr;
State* State::optionsState = nullptr;
GameManager* State::gameManager = nullptr;

State::State()
{
}

State::~State()
{
}

void State::enter()
{
}

void State::update(float deltaTime)
{
}

void State::leave()
{
}
