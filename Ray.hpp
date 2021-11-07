#ifndef RAY_HPP
#define RAY_HPP

#include "Wall.hpp"

#include <SFML/Graphics.hpp>

class Ray
{
public:
    Ray(sf::Vector2f position, sf::Vector2f direction);

    void draw(sf::RenderWindow &window);

    void updateEndPoint(std::vector<Wall> &walls);

private:
    sf::VertexArray mLine;
    sf::Vector2f startPt;
    sf::Vector2f endPt;
};

#endif // RAY_HPP