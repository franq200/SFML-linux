#include "../include/Image.h"

Image::Image(const std::string& path)
{
    m_img.loadFromFile(path);
}

void Image::Transform()
{
    sf::Vector2u size = m_img.getSize();
    for (u_int16_t x = 0; x < size.x; ++x)
    {
        for (u_int16_t y = 0; y < size.y; ++y)
        {
            sf::Color color = m_img.getPixel(x, y);
            u_int16_t colorAverage = (color.r + color.g + color.b)/3;
            m_img.setPixel(x, y, sf::Color(colorAverage, colorAverage, colorAverage));
        }
    }
}

sf::Texture Image::GetAsTexture() const 
{
    sf::Texture texture;
    texture.loadFromImage(m_img);
    return texture;
}

const sf::Image& Image::GetImage() const
{
    return m_img;
}

sf::Vector2f Image::GetResolution() const
{
    return sf::Vector2f(m_img.getSize());
}