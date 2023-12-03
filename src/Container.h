#include <SFML/Graphics.hpp>
#include "Entity.h"

#ifndef CONTAINER_H
#define CONTAINER_H

class Container
{
public:
    Container();
    void draw(sf::RenderWindow& rw);
    bool contains(const Entity& entity) const;
private:
    static constexpr int width = 100;
    static constexpr int height = 100;
    sf::RectangleShape rect;
};

#endif