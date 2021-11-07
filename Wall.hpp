#ifndef WALL_HPP
#define WALL_HPP

#include <SFML/Graphics.hpp>

class Wall
{
public:
    Wall(sf::Vector2f startPt, sf::Vector2f endPt);

    void draw(sf::RenderWindow &window);

private:
    sf::VertexArray mLine;
    sf::Vector2f startPt;
    sf::Vector2f endPt;
};

#endif // WALL_HPP