#ifndef INPUTBUFFER_H
#define INPUTBUFFER_H

#include <SFML/Window.hpp>
#include <queue>
#include <unordered_map>
#include <functional>

struct InputEvent {
    sf::Keyboard::Key key;
    int frame;
};

class InputBuffer {
public:
    explicit InputBuffer(int bufferWindowSize);
    void addInput(sf::Keyboard::Key key);
    void processInputs(const std::unordered_map<sf::Keyboard::Key, std::function<void()>>& actions);
    void nextFrame();

private:
    std::queue<InputEvent> buffer;
    int bufferWindow;
    int currentFrame;
};
#endif // INPUTBUFFER_H