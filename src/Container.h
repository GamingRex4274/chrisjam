#include "Animation.h"
#include "Entity.h"

#ifndef CONTAINER_H
#define CONTAINER_H

class Container
{
public:
    Container(const sf::Vector2f& pos, const std::string& filename);
    void update(float dt);
    void draw(sf::RenderWindow& rw);
    bool contains(const Entity& entity) const;
private:
    static constexpr int width = 82;
    static constexpr int height = 81;
    Animation anim;
};

#endif