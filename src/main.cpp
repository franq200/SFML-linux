#include <SFML/Graphics.hpp>
#include <iostream>
#include "../include/Image.h"
#include <X11/Xlib.h>

Display* d = XOpenDisplay(NULL);
Screen*  s = DefaultScreenOfDisplay(d);


int main(int argc, char* argv[])
{
    std::cout << s->height << '\n' << s->width << std::flush;
    sf::RenderWindow window(sf::VideoMode(s->width, s->height), "SFML works!");

    std::string path = argv[1];
    Image image(path);
    image.Transform();
    sf::Sprite shape;
    sf::Texture texture;
    texture.loadFromImage(image.GetImage());
    sf::Vector2f imageSize = image.GetResolution();
    shape.setPosition(0, 0);
    shape.setTexture(texture);
    float height = s->height/imageSize.y;
    float width = s->width/imageSize.x;
    if (height < width)
    {
        shape.setScale({height, height});
        shape.setPosition(std::abs(s->width - imageSize.x)/2, 0);
        std::cout << s->width << '\n' << imageSize.x << '\n' << std::abs(s->width - imageSize.x) << '\n';
    }
    else
    {
        shape.setScale({width, width});
        shape.setPosition(0, std::abs(s->height - imageSize.y)/2);
    }
    sf::RectangleShape shape2;
    shape2.setSize({20, 20});
    shape2.setFillColor(sf::Color::Cyan);
    shape2.setPosition(s->width-2, 0);

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
        window.draw(shape2);
        window.display();
    }

    return 0;
}