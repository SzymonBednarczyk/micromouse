#include "texture_manager.h"

void TextureManager::loadTexture(const std::string &name, const std::string &filename) {
    sf::Texture tex;
    tex.loadFromFile(filename);
    textures_[name] = tex;
}

sf::Texture& TextureManager::getTextureRef(const std::string& texture) {
    return textures_.at(texture);
}
