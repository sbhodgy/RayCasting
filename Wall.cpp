#include "Wall.hpp"

Wall::Wall(sf::Vector2f startPt, sf::Vector2f endPt)
    : mLine(sf::Lines, 2),
      startPt(startPt),
      endPt(endPt)
{
    mLine[0].position = startPt;
    mLine[0].color = sf::Color::Red;

    mLine[1].position = endPt;
    mLine[1].color = sf::Color::Red;
}

void Wall::draw(sf::RenderWindow &window)
{
    window.draw(mLine);
}

sf::Vector2f Wall::getLineStart()
{
    return startPt;
}

sf::Vector2f Wall::getLineEnd()
{
    return endPt;
}