#include "Animation.h"

Animation::Animation(const sf::Vector2f& pos, int frameWidth, int frameHeight, int nFrames, float holdTime, const std::string& filename)
    :
    frameWidth(frameWidth),
    frameHeight(frameHeight),
    nFrames(nFrames),
    holdTime(holdTime)
{
    pTex = TextureManager::acquire(filename);
    totalWidth = pTex->getSize().x;
    sprite.setTexture(*pTex);
    sprite.setTextureRect({0, 0, frameWidth, frameHeight});
    sprite.setPosition(pos);
}

void Animation::update(float dt)
{
    curTime += dt;
    if (curTime >= holdTime)
    {
        curFrame++;
        const int new_x = (curFrame % nFrames) * frameWidth;
        sprite.setTextureRect({new_x, 0, frameWidth, frameHeight});
        curTime = 0.0f;
    }
}

void Animation::draw(sf::RenderWindow& rw)
{
    rw.draw(sprite);
}

const sf::FloatRect Animation::getCurRect() const
{
    return sprite.getGlobalBounds();
}