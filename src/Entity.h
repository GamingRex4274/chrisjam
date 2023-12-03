#include <SFML/Graphics.hpp>

#ifndef ENTITY_H
#define ENTITY_H

class Entity
{
public:
    Entity();
    void startMovement();
    void update(sf::RenderWindow& rw, float dt);
    void draw(sf::RenderWindow& rw);
    bool isMoving() const;
    bool contains(const sf::Vector2f& pos) const;
    sf::FloatRect getRect() const;
private:
    void clamp();
private:
    bool moving = false;
    static constexpr int width = 32;
    static constexpr int height = 32;
    sf::RectangleShape rect;
};

#endif