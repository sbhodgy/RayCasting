#include "Ray.hpp"
#include "Wall.hpp"

#include <SFML/Graphics.hpp>

#include <cmath>

#include <iostream>

int main()
{
    std::vector<Ray> rays;
    std::vector<Wall> walls;

    std::srand(std::time(nullptr));

    float offset = 5.f;
    float edge = 595.f;

    walls.push_back(Wall(sf::Vector2f(offset, offset), sf::Vector2f(edge, offset)));
    walls.push_back(Wall(sf::Vector2f(offset, offset), sf::Vector2f(offset, edge)));
    walls.push_back(Wall(sf::Vector2f(edge, offset), sf::Vector2f(edge, edge)));
    walls.push_back(Wall(sf::Vector2f(offset, edge), sf::Vector2f(edge, edge)));

    for (int i = 0; i < 5; i++)
    {
        float x1 = rand() % 600;
        float y1 = rand() % 600;
        float x2 = rand() % 600;
        float y2 = rand() % 600;

        Wall wall(sf::Vector2f(x1, y1), sf::Vector2f(x2, y2));

        walls.push_back(wall);
    }

    for (int i = 0; i < 360; i += 10)
    {
        // convert to radians

        double rad = i * 3.14159 / 180;

        float x = cos(rad) * 1000.f;
        float y = sin(rad) * 1000.f;

        std::cout << i << "   " << x << "   " << y << std::endl;

        Ray ray(sf::Vector2f(300.f, 300.f), sf::Vector2f(x, y));

        rays.push_back(ray);
    }

    sf::RenderWindow window(sf::VideoMode(600, 600), "Quad Tree Example");

    sf::Clock clock;

    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    const sf::Time TimePerFrame = sf::seconds(1.f / 60.f);

    while (window.isOpen())
    {
        sf::Time deltaTime = clock.restart();

        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        timeSinceLastUpdate += deltaTime;

        while (timeSinceLastUpdate > TimePerFrame)
        {
            timeSinceLastUpdate -= TimePerFrame;
        }

        window.clear(sf::Color::Black);

        for (auto itr = rays.begin(); itr != rays.end(); ++itr)
            itr->draw(window);

        for (auto itr = walls.begin(); itr != walls.end(); ++itr)
            itr->draw(window);

        window.display();
    }

    return 0;
}
