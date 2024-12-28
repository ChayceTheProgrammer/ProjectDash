#ifndef ANIMATION_H
#define ANIMATION_H
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

class Animation {
public:
    Animation(const sf::Texture& texture, int frameWidth, int frameHeight, int numFrames, float frameDuration);
    void update(float deltaTime);
    void setAnimation(int startFrame, int endFrame);
    void applyToSprite(sf::Sprite& sprite);

private:
    sf::IntRect currentFrameRect;
    int frameWidth, frameHeight;
    int numFrames;
    float frameDuration;
    float elapsedTime;
    int currentFrame;
};

#endif // ANIMATION_H