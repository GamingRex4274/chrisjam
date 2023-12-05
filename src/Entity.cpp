#include "Entity.h"
#include "RamWindow.h"
#include "RamMath.h"
#include <random>

Entity::Entity()
{
    std::mt19937 rng(std::random_device{}());

    // Randomize type (gift or coal).
    std::uniform_int_distribution<int> dist(0, 1);
    is_gift = dist(rng);

    // Set entity sprite based on type.
    if (is_gift)
        pTex = TextureManager::acquire("src\\Sprites\\gift.png");
    else
        pTex = TextureManager::acquire("src\\Sprites\\coal.png");
    sprite.setTexture(*pTex);

    // Randomize direction.
    std::uniform_real_distribution<float> dirDist(-1.0f, 1.0f);
    dir = GetNormalized({dirDist(rng), dirDist(rng)});

    sprite.setOrigin(sf::Vector2f(width, height) / 2.0f);
    sprite.setPosition(GetScreenCenter());
}

void Entity::startMovement()
{
    dragging = true;
}

void Entity::update(sf::RenderWindow& rw, float dt)
{
    if (dragging)
    {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            // Get mouse position.
            const sf::Vector2f pos = sf::Vector2f(sf::Mouse::getPosition(rw));
            sprite.setPosition(pos);
            clamp();
        }
        else
            dragging = false;
    }
    else
    {
        const sf::Vector2f pos = sprite.getPosition();
        move(dt);
    }
}

void Entity::draw(sf::RenderWindow& rw)
{
    rw.draw(sprite);
}

bool Entity::contains(const sf::Vector2f& pos) const
{
    // Expand hitbox to twice the size of the entity.
    return GetExpanded(sprite.getGlobalBounds(), width).contains(pos);
}

bool Entity::isGift() const
{
    return is_gift;
}

sf::FloatRect Entity::getRect() const
{
    return sprite.getGlobalBounds();
}

void Entity::move(float dt)
{
    // Change direction if entity hits screen edges.
    const sf::Vector2f pos = sprite.getPosition();
    if (pos.x - width / 2 < 0 || pos.x + width / 2 >= SCREEN_WIDTH)
        dir.x = -dir.x;
    if (pos.y - height / 2 < upperLimit || pos.y + height / 2 >= SCREEN_HEIGHT)
        dir.y = -dir.y;
    
    sprite.move(dir * speed * dt);
}

void Entity::clamp()
{
    sf::Vector2f pos = sprite.getPosition();

    // Check if center offset with dimensions go out of bounds.
    if (pos.x - width / 2 < 0)
        pos.x = width / 2;
    else if (pos.x + width / 2 >= SCREEN_WIDTH)
        pos.x = SCREEN_WIDTH - width / 2 - 1;
    
    if (pos.y - height / 2 < upperLimit)
        pos.y = height / 2;
    else if (pos.y + height / 2 >= SCREEN_HEIGHT)
        pos.y = SCREEN_HEIGHT - height / 2 - 1;
    
    sprite.setPosition(pos);
}