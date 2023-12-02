#include "Entity.h"
#include "RamWindow.h"
#include "RamMath.h"

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
        // Get mouse position.
        const sf::Vector2f pos = sf::Vector2f(sf::Mouse::getPosition(rw));

        // Check bounding rect. twice as big as source rect.
        if (GetExpanded(rect.getGlobalBounds(), width).contains(pos))
            rect.setPosition(pos);
    }
}

void Entity::draw(sf::RenderWindow& rw)
{
    rw.draw(rect);
}