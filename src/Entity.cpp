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

void Entity::startMovement()
{
    moving = true;
}

void Entity::update(sf::RenderWindow& rw, float dt)
{
    if (moving)
    {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            // Get mouse position.
            const sf::Vector2f pos = sf::Vector2f(sf::Mouse::getPosition(rw));
            rect.setPosition(pos);
            clamp();
        }
        else
            moving = false;
    }
}

void Entity::draw(sf::RenderWindow& rw)
{
    rw.draw(rect);
}

bool Entity::isMoving() const
{
    return moving;
}

bool Entity::contains(const sf::Vector2f& pos) const
{
    return rect.getGlobalBounds().contains(pos);
}

void Entity::clamp()
{
    sf::Vector2f pos = rect.getPosition();

    // Check if center offset with dimensions go out of bounds.
    if (pos.x - width / 2 < 0)
        pos.x = width / 2;
    else if (pos.x + width / 2 >= SCREEN_WIDTH)
        pos.x = SCREEN_WIDTH - width / 2 - 1;
    
    if (pos.y - height / 2 < 0)
        pos.y = height / 2;
    else if (pos.y + height / 2 >= SCREEN_HEIGHT)
        pos.y = SCREEN_HEIGHT - height / 2 - 1;
    
    rect.setPosition(pos);
}