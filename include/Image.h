#include <SFML/Graphics.hpp>
#include <string>
#pragma once

class Image
{
public:
    Image(const std::string& path);
    void Transform();
    sf::Texture GetAsTexture();
private:
    sf::Image m_img;
};