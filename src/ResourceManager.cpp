#include "../include/ResourceManager.h"

ResourceManager& ResourceManager::getInstance() {
    static ResourceManager instance;
    return instance;
}

bool ResourceManager::loadTexture(const std::string& id, const std::string& filepath) {
    auto texture = std::make_shared<sf::Texture>();
    if (texture->loadFromFile(filepath)) {
        textures[id] = texture;
        return true;
    }
    std::cerr << "Error: Failed to load texture from " << filepath << std::endl;
    return false;
}

sf::Texture& ResourceManager::getTexture(const std::string& id) {
    if (textures.find(id) != textures.end()) {
        return *textures.at(id);
    }
    throw std::runtime_error("Error: Texture ID '" + id + "' not found!");
}

void ResourceManager::deleteTexture(const std::string& id) {
    textures.erase(id);
}
