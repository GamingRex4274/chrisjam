#include "Container.h"

Container::Container(const sf::Vector2f& pos, sf::Color color)
    :
    rect({width, height})
{
    rect.setFillColor(color);
    rect.setPosition(pos);
}

void Container::draw(sf::RenderWindow& rw)
{
    rw.draw(rect);
}

bool Container::contains(const Entity& entity) const
{
    const sf::FloatRect big = rect.getGlobalBounds();
    const sf::FloatRect small = entity.getRect();
    return small.left >= big.left
        && small.left + small.width <= big.left + big.width
        && small.top >= big.top
        && small.top + small.height <= big.top + big.height;
}