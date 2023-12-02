#include <SFML/Graphics.hpp>

#ifndef ENTITY_H
#define ENTITY_H

class Entity
{
public:
    Entity();
    void update(sf::RenderWindow& rw, float dt);
    void draw(sf::RenderWindow& rw);
private:
    static constexpr int width = 32;
    static constexpr int height = 32;
    sf::RectangleShape rect;
};

#endif