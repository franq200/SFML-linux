#include <SFML/Graphics.hpp>
#include <string>
#pragma once

class Image
{
public:
    Image(const std::string& path);
    void Transform();
    sf::Texture GetAsTexture() const;
    const sf::Image& GetImage() const;
    sf::Vector2f GetResolution() const;
private:
    sf::Image m_img;
};