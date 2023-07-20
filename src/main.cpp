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
    static sf::Texture texture;
    texture.loadFromImage(image.GetImage());

    sf::Sprite shape;
    shape.setPosition(0, 0);
    shape.setTexture(texture);
    return shape;
}

void ViewControl(sf::View& view, sf::Event& event)
{
    static sf::Clock timer;
    sf::Time elapsedTime = timer.getElapsedTime();
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Add) && elapsedTime.asSeconds() > 0.1)
    {
        view.zoom(0.98);
        timer.restart();
        return;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Subtract) && elapsedTime.asSeconds() > 0.1)
    {
        view.zoom(1.02);
        timer.restart();
        return;
    }
    if(event.type == sf::Event::MouseWheelMoved)
    {
        view.zoom((-1 * event.mouseWheel.delta) * 0.02 + 1);
    }
}

void Run(sf::RenderWindow& window, const sf::Sprite& shape, sf::View& view)
{
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            ViewControl(view, event);
        }

        window.setView(view);

        window.clear();
        window.draw(shape);
        window.display();
    }
}

int main(int argc, char* argv[])
{
    const auto [screenWidth, screenHeight] = GetScreenSize();

    sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "SFML works!");
    sf::View view(sf::FloatRect(0.f, 0.f, screenWidth, screenHeight));
    window.setView(view);

    Image image(argc > 1 ? argv[1] : "..//images//zdj1.jpg");
    image.Transform();

    sf::Sprite shape = PrepareToDraw(image);
    FitImageToScreen(image, shape, screenWidth, screenHeight);
    Run(window, shape, view);

    return 0;
}