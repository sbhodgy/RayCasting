#include "Ray.hpp"

#include <cmath>

Ray::Ray(sf::Vector2f position, float angle)
    : mLine(sf::Lines, 2),
      startPt(position),
      radians(angle * 3.14159 / 180),
      endPt(position + sf::Vector2f(cos(radians) * 1000.f, sin(radians) * 1000.f))
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

void Ray::updatePosition(sf::Vector2i newStart)
{
    startPt = static_cast<sf::Vector2f>(newStart);
    endPt = startPt + sf::Vector2f(cos(radians) * 1000.f, sin(radians) * 1000.f);

    mLine[0].position = startPt;
    mLine[1].position = endPt;
}

void Ray::updateEndPoint(std::vector<Wall> &walls)
{
    for (auto itr = walls.begin(); itr != walls.end(); itr++)
    {
        // first check whether the ray and the wall intersect

        float x1 = startPt.x;
        float y1 = startPt.y;
        float x2 = endPt.x;
        float y2 = endPt.y;

        float d = std::sqrt(std::pow((endPt.y - startPt.y), 2) + std::pow((endPt.x - startPt.x), 2));

        float x3 = itr->getLineStart().x;
        float y3 = itr->getLineStart().y;
        float x4 = itr->getLineEnd().x;
        float y4 = itr->getLineEnd().y;

        float den = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);

        float t = ((x1 - x3) * (y3 - y4) - (y1 - y3) * (x3 - x4)) / den;
        float u = ((x1 - x3) * (y1 - y2) - (y1 - y3) * (x1 - x2)) / den;

        if (u >= 0 && u <= 1 && t >= 0 && t <= 1)
        {
            // reset the end point

            endPt = sf::Vector2f(x1 + t * (x2 - x1),
                                 y1 + t * (y2 - y1));

            mLine[1].position.x = endPt.x;
            mLine[1].position.y = endPt.y;
        }
    }
}
