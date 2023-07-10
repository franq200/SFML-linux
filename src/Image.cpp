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
            u_int16_t colorAmount = (color.r + color.g + color.b)/3;
            m_img.setPixel(x, y, sf::Color(colorAmount, colorAmount, colorAmount));
        }
    }
}

sf::Texture Image::GetAsTexture()
{
    m_img.saveToFile("../images/zdj1.jpg/");
    sf::Texture img;
    img.loadFromFile("../images/zdj1.jpg/");
    return img;
}