#include <SFML/Graphics.hpp>
#include <iostream>
#include "../include/Image.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");

    //std::cout << "sciezka do pliku: ";
    std::string path;
    //std::cin >> path;
    path = "images/zdj1.jpg/";
    Image image(path);
    image.Transform();
    sf::RectangleShape shape;
    sf::Texture texture = image.GetAsTexture();
    shape.setTexture(&texture);

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

    return 0;
}