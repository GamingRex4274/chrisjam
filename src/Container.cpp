#include "Container.h"

Container::Container(const sf::Vector2f& pos, const std::string& filename)
{
    pTex = TextureManager::acquire(filename);
    sprite.setTexture(*pTex);
    sprite.setTextureRect({0, 0, width, height});
    sprite.setPosition(pos);
}

void Container::draw(sf::RenderWindow& rw)
{
    rw.draw(sprite);
}

bool Container::contains(const Entity& entity) const
{
    const sf::FloatRect big = sprite.getGlobalBounds();
    const sf::FloatRect small = entity.getRect();
    return small.left >= big.left
        && small.left + small.width <= big.left + big.width
        && small.top >= big.top
        && small.top + small.height <= big.top + big.height;
}