#include "../include/InputBuffer.h"

void InputBuffer::addInput(sf::Keyboard::Key key) {
    buffer.push({ key, currentFrame });
}

void InputBuffer::processInputs(const std::unordered_map<sf::Keyboard::Key, std::function<void()>>& actions) {
    while (!buffer.empty()) {
        InputEvent event = buffer.front();

        if (currentFrame - event.frame > bufferWindow) {
            buffer.pop();
            continue;
        }

        if (actions.find(event.key) != actions.end()) {
            actions.at(event.key)();
        }

        buffer.pop();
    }
}

void InputBuffer::nextFrame() {
    currentFrame++;
}
