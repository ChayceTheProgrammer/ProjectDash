#include "../include/ResourceManager.h"

// Load a texture and store it with a string identifier
bool ResourceManager::loadTexture(const std::string& id, const std::string& filepath) {
    auto texture = std::make_shared<sf::Texture>();
    if (texture->loadFromFile(filepath)) {
        textures[id] = texture;
        return true;
    }
    std::cerr << "Error: Failed to load texture from " << filepath << std::endl;
    return false;
}

// Get a loaded texture by its string identifier
sf::Texture& ResourceManager::getTexture(const std::string& id) {
    auto it = textures.find(id);
    if (it != textures.end()) {
        return *(it->second);
    }
    throw std::runtime_error("Error: Texture ID '" + id + "' not found!");
}

// Delete a texture by its string identifier
void ResourceManager::deleteTexture(const std::string& id) {
    textures.erase(id);
}