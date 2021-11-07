#include "Ray.hpp"

Ray::Ray(sf::Vector2f position, sf::Vector2f direction)
    : mLine(sf::Lines, 2),
      startPt(position),
      endPt(position + direction)
{
    mLine[0].position = startPt;
    mLine[0].color = sf::Color::White;

    mLine[1].position = endPt;
    mLine[1].color = sf::Color::White;
}

void Ray::draw(sf::RenderWindow &window)
{
    window.draw(mLine);
}

void Ray::updateEndPoint(std::vector<Wall> &walls)
{
    for(auto itr = walls.begin(); itr != walls.end(); itr++)
    {
        // first check whether the ray and the wall intersect

        

    }
}
