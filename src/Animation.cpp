#include "../include/Animation.h"

Animation::Animation(const sf::Texture& texture, int frameWidth, int frameHeight, int numFrames, float frameDuration) :
	frameWidth(frameWidth),
	frameHeight(frameHeight),
	numFrames(numFrames),
	frameDuration(frameDuration),
	elapsedTime(0),
	currentFrame(0),
	currentFrameRect(0, 0, frameWidth, frameHeight)
{
}
	
void Animation::update(float deltaTime) {
    elapsedTime += deltaTime;
    if (elapsedTime >= frameDuration) {
        elapsedTime -= frameDuration;
        currentFrame = (currentFrame + 1) % numFrames;
    }
}

void Animation::setAnimation(int startFrame, int endFrame)
{
}

void Animation::applyToSprite(sf::Sprite& sprite)
{
}
