// ResourceManager.h
#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <SFML/Graphics.hpp>
#include <map>
#include <memory>
#include <string>
#include <iostream>

class ResourceManager {
public:
    // Singleton pattern to ensure only one instance exists
    static ResourceManager& getInstance() {
        static ResourceManager instance;
        return instance;
    }

    // Load a texture and store it with a string identifier
    bool loadTexture(const std::string& id, const std::string& filepath) {
        auto texture = std::make_shared<sf::Texture>();
        if (texture->loadFromFile(filepath)) {
            textures[id] = texture;
            return true;
        }
        std::cerr << "Error: Failed to load texture from " << filepath << std::endl;
        return false;
    }

    // Get a loaded texture by its string identifier
    sf::Texture& getTexture(const std::string& id) {
        if (textures.find(id) != textures.end()) {
            return *textures.at(id);
        }
        throw std::runtime_error("Error: Texture ID '" + id + "' not found!");
    }

    // Delete a texture by its string identifier
    void deleteTexture(const std::string& id) {
        textures.erase(id);
    }

private:
    ResourceManager() = default;  // Private constructor
    ResourceManager(const ResourceManager&) = delete;             // Prevent copying
    ResourceManager& operator=(const ResourceManager&) = delete;  // Prevent assignment

    std::map<std::string, std::shared_ptr<sf::Texture>> textures;
};

#endif // RESOURCEMANAGER_H
