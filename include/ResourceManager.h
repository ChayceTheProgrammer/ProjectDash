#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <SFML/Graphics.hpp>
#include <unordered_map>
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
    bool loadTexture(const std::string& id, const std::string& filepath);

    // Get a loaded texture by its string identifier
    sf::Texture& getTexture(const std::string& id);

    // Delete a texture by its string identifier
    void deleteTexture(const std::string& id);

private:
    ResourceManager() = default;  // Private constructor
    ResourceManager(const ResourceManager&) = delete;             // Prevent copying
    ResourceManager& operator=(const ResourceManager&) = delete;  // Prevent assignment

    std::unordered_map<std::string, std::shared_ptr<sf::Texture>> textures;
};

#endif // RESOURCEMANAGER_H