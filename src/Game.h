#include "Entity.h"
#include "Container.h"
#include <vector>

#ifndef GAME_H
#define GAME_H

class Game
{
public:
    Game(sf::RenderWindow& rw);
    void run();
private:
    void processEvents();
    void updateEntities();
    void drawFrame();
    /** Game Functions **/
    void reset();
    void doEntityContainment();
private:
    sf::RenderWindow& rw;
    sf::Clock clock;
    /** Game Variables **/
    std::vector<Entity> entities;
    Container cont1;
    Container cont2;
    static constexpr float spawnTime = 2.0f;
    float curTime = 0.0f;
    bool gameIsOver = false;
};

#endif