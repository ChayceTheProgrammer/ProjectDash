#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <SFML/Graphics.hpp>
#include <map>
#include <string>
#include <iostream>
#include <memory>

class ResourceManager {
public:
    static ResourceManager& getInstance();
    bool loadTexture(const std::string& name, const std::string& filename);
    sf::Texture& getTexture(const std::string& name);
	void deleteTexture(const std::string& name);

private:
	ResourceManager() = default;                                        //Private constructor
	ResourceManager(const ResourceManager&) = delete;   	            //Prevent copying    
	ResourceManager& operator=(const ResourceManager&) = delete;		//Prevent assignment
	std::map < std::string, std::shared_ptr<sf::Texture> > textures;	//Map to store textures
	
};

#endif // RESOURCEMANAGER_H
