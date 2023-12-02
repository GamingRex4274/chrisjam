#include "Entity.h"
#include "RamWindow.h"

Entity::Entity()
    :
    rect({width, height})
{
    rect.setFillColor(sf::Color::Red);
    rect.setOrigin(sf::Vector2f(width, height) / 2.0f);
    rect.setPosition(GetScreenCenter());
}

void Entity::update(sf::RenderWindow& rw, float dt)
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        const sf::Vector2f pos = sf::Vector2f(sf::Mouse::getPosition(rw));
        if (rect.getGlobalBounds().contains(pos))
            rect.setPosition(pos);
    }
}

void Entity::draw(sf::RenderWindow& rw)
{
    rw.draw(rect);
}