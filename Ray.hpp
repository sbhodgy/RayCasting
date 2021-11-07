#ifndef RAY_HPP
#define RAY_HPP

#include "Wall.hpp"

#include <SFML/Graphics.hpp>

class Ray
{
public:
    Ray(sf::Vector2f position, float angle);

    void draw(sf::RenderWindow &window);

    void updatePosition(sf::Vector2i newStart);

    void updateEndPoint(std::vector<Wall> &walls);

private:
    sf::VertexArray mLine;
    sf::Vector2f startPt;
    sf::Vector2f endPt;
    double radians;
};

#endif // RAY_HPP