#include "Animation.h"
#include <unordered_map>

class AnimationManager {
public:
    void addAnimation(const std::string& name, Animation animation);
    void play(const std::string& name);
    void update(float deltaTime);
    void applyToSprite(sf::Sprite& sprite);

private:
    std::unordered_map<std::string, Animation> animations;
    Animation* currentAnimation;
};