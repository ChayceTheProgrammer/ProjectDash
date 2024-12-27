#include "InputBuffer.h"

class InputBuffer { //implements a buffer for input events
private:
    std::queue<InputEvent> buffer; // Queue to store input events
    int bufferWindow;              // Number of frames to keep inputs in the buffer
    int currentFrame;              // Current frame count

public:
    InputBuffer(int bufferWindowSize) : bufferWindow(bufferWindowSize), currentFrame(0) {}

    // Add an input to the buffer
    void addInput(sf::Keyboard::Key key) {
        buffer.push({ key, currentFrame });
    }

    // Process inputs in the buffer
    void processInputs(const std::unordered_map<sf::Keyboard::Key, std::function<void()>>& actions) {
        while (!buffer.empty()) {
            InputEvent event = buffer.front();

            // Remove inputs that are outside the buffer window
            if (currentFrame - event.frame > bufferWindow) {
                buffer.pop();
                continue;
            }

            // Execute the action associated with the key
            if (actions.find(event.key) != actions.end()) {
                actions.at(event.key)();
            }

            buffer.pop();
        }
    }

    // Increment the frame counter
    void nextFrame() {
        currentFrame++;
    }
};