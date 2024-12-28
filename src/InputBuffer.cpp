#include <SFML/Window.hpp>
#include <queue>
#include <unordered_map>
#include <functional>
#include <iostream>

struct InputEvent {
    sf::Keyboard::Key key;
    int frame;
};

class InputBuffer {
private:
    std::queue<InputEvent> buffer;
    int bufferWindow;
    int currentFrame;

public:
    explicit InputBuffer(int bufferWindowSize) : bufferWindow(bufferWindowSize), currentFrame(0) {}

    void addInput(sf::Keyboard::Key key) {
        buffer.push({ key, currentFrame });
    }

    void processInputs(const std::unordered_map<sf::Keyboard::Key, std::function<void()>>& actions) {
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

    void nextFrame() {
        currentFrame++;
    }
};