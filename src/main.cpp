#include <SFML/Graphics.hpp>
#include <iostream>
#include "../include/Image.h"

std::pair<unsigned int, unsigned int> GetScreenSize()
{
    unsigned int screenWidth = sf::VideoMode::getDesktopMode().width;
    unsigned int screenHeight = sf::VideoMode::getDesktopMode().height;
    return {screenWidth, screenHeight};
}

void FitImageToScreen(const Image& image, sf::Sprite& shape, const unsigned int screenWidth, const unsigned int screenHeight)
{
    sf::Vector2f imageSize = image.GetResolution();
    float heightScale = screenHeight/imageSize.y;
    float widthScale = screenWidth/imageSize.x;
    if (heightScale < widthScale)
    {
        shape.setScale({heightScale, heightScale});
        shape.setPosition(std::abs(screenWidth - imageSize.x * heightScale)/2, 0);
    }
    else
    {
        shape.setScale({widthScale, widthScale});
        shape.setPosition(0, std::abs(screenHeight - imageSize.y * widthScale)/2);
    }
}

sf::Sprite PrepareToDraw(const Image& image)
{
    sf::Texture texture;
    texture.loadFromImage(image.GetImage());

    sf::Sprite shape;
    shape.setPosition(0, 0);
    shape.setTexture(texture);
    return shape;
}

void Run(sf::RenderWindow& window, const sf::Sprite& shape)
{
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }
}

int main(int argc, char* argv[])
{
    const auto [screenWidth, screenHeight] = GetScreenSize();

    sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "SFML works!");

    Image image(argc > 1 ? argv[1] : "..//images//zdj1.jpg");
    image.Transform();

    sf::Sprite shape = PrepareToDraw(image);
    FitImageToScreen(image, shape, screenWidth, screenHeight);
    Run(window, shape);

    return 0;
}