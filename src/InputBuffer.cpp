#include "../include/InputBuffer.h"

void InputBuffer::addInput(sf::Keyboard::Key key) {
    std::cout << "Input added: " << key << " at frame " << currentFrame << std::endl;
    buffer.push({ key, currentFrame });
};

void InputBuffer::processInputs(const std::unordered_map<sf::Keyboard::Key, std::function<void()>>& actions) {
    while (!buffer.empty()) {
        InputEvent event = buffer.front();

        if (currentFrame - event.frame > bufferWindow) {
            buffer.pop();
            continue;
        }

        if (actions.find(event.key) != actions.end()) {
            std::cout << "Processing input: " << event.key << std::endl;
            actions.at(event.key)();
        }

        buffer.pop();
    }
};

std::unordered_map<sf::Keyboard::Key, std::function<void()>> actions = {
    { sf::Keyboard::A, []() { std::cout << "Action A triggered!" << std::endl; } },
    { sf::Keyboard::S, []() { std::cout << "Action S triggered!" << std::endl; } }
};

void InputBuffer::nextFrame() {
    currentFrame++;
    processInputs(actions);
};