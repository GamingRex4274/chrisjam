#include <SFML/Graphics.hpp>
#include "Entity.h"

#ifndef CONTAINER_H
#define CONTAINER_H

class Container
{
public:
    Container(const sf::Vector2f& pos, sf::Color color);
    void draw(sf::RenderWindow& rw);
    bool contains(const Entity& entity) const;
private:
    static constexpr int width = 100;
    static constexpr int height = 100;
    sf::RectangleShape rect;
};

#endif