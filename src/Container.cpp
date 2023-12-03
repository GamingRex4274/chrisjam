#include "Container.h"

Container::Container()
    :
    rect({width, height})
{
    rect.setFillColor(sf::Color::White);
    rect.setPosition({10.0f, 250.0f});
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