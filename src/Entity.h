#include "TextureManager.h"

#ifndef ENTITY_H
#define ENTITY_H

class Entity
{
public:
    Entity();
    void startMovement();
    void update(sf::RenderWindow& rw, float dt);
    void draw(sf::RenderWindow& rw);
    bool contains(const sf::Vector2f& pos) const;
    bool isGift() const;
    sf::FloatRect getRect() const;
private:
    void move(float dt);
    void clamp();
private:
    static constexpr int upperLimit = 175;
    sf::Vector2f dir;
    bool dragging = false;
    bool is_gift = false;
    static constexpr float speed = 75.0f;
    static constexpr int width = 32;
    static constexpr int height = 32;
    std::shared_ptr<sf::Texture> pTex;
    sf::Sprite sprite;
};

#endif