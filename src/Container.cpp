#include "Container.h"

Container::Container(const sf::Vector2f& pos, const std::string& filename)
    :
    anim(pos, width, height, 2, 0.1f, filename)
{
}

void Container::update(float dt)
{
    anim.update(dt);
}

void Container::draw(sf::RenderWindow& rw)
{
    anim.draw(rw);
}

bool Container::contains(const Entity& entity) const
{
    const sf::FloatRect big = anim.getCurRect();
    const sf::FloatRect small = entity.getRect();
    return small.left >= big.left
        && small.left + small.width <= big.left + big.width
        && small.top >= big.top
        && small.top + small.height <= big.top + big.height;
}