#include "TextureManager.h"

#ifndef ANIMATION_H
#define ANIMATION_H

class Animation
{
public:
    Animation(const sf::Vector2f& pos, int frameWidth, int frameHeight, int nFrames, float holdTime, const std::string& filename);
    void update(float dt);
    void draw(sf::RenderWindow& rw);
    const sf::FloatRect getCurRect() const;
private:
    std::shared_ptr<sf::Texture> pTex;
    sf::Sprite sprite;
    int frameWidth;
    int frameHeight;
    int totalWidth;
    int nFrames;
    float holdTime;
    float curTime = 0.0f;
    int curFrame = 0;
};

#endif