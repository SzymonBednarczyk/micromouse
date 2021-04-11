#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include <SFML/Graphics.hpp>

#include <map>


class TextureManager {
public:
    TextureManager(){}
    void loadTexture(const std::string &name, const std::string &filename);
    sf::Texture& getTextureRef(const std::string& texture);
private:
    std::map<std::string, sf::Texture> textures_;
};

#endif // TEXTURE_MANAGER_H
