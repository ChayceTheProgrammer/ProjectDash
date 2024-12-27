#include "InputBuffer.cpp"

class InputManager {
private:
    InputBuffer& inputBuffer;

public:
    InputManager(InputBuffer& buffer) : inputBuffer(buffer) {}

    // Poll for real-time inputs
    void pollInputs() {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            inputBuffer.addInput(sf::Keyboard::Left);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            inputBuffer.addInput(sf::Keyboard::Right);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            inputBuffer.addInput(sf::Keyboard::A);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            inputBuffer.addInput(sf::Keyboard::S);
        }
    }
};