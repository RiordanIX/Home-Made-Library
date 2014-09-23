#include "button.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

void myFunction()
{
    std::cout << "I love You" << std::endl;
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(200,600), "HELLO, MAIN");
    Button gimp("Click-Button.png", &myFunction);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            else
                gimp.handleEvent(event);
        }

        window.clear();
        window.draw(gimp.m_sprite);
        window.display();
    }
    return 0;
}
