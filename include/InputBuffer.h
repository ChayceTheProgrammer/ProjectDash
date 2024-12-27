#ifndef INPUTBUFFER_H
#define INPUTBUFFER_H

#include <vector>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <queue>
#include <unordered_map>
#include <functional>
#include <iostream>

// Define a structure to represent an input event
struct InputEvent { //stores the key pressed and the frame at which it was pressed
    sf::Keyboard::Key key; // The key pressed
    int frame;             // The frame at which the input was registered
};

class InputBuffer { //implements a buffer for input events (header/prototype only)
public:
	InputBuffer(int bufferWindowSize) : bufferWindow(bufferWindowSize), currentFrame(0) {}
	void addInput(sf::Keyboard::Key key) {}
	void processInputs(const std::unordered_map<sf::Keyboard::Key, std::function<void()>>& actions) {}
	void nextFrame() {}

private:
    std::queue<InputEvent> buffer;  // Queue to store input events
    int bufferWindow;               // Number of frames to keep inputs in the buffer
    int currentFrame;               // Current frame count

};

#endif // INPUTBUFFER_H
