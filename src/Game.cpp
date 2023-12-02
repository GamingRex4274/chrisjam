#include "Game.h"
#include "RamWindow.h"

Game::Game(sf::RenderWindow& rw)
    :
    rw(rw)
{
}

void Game::run()
{
    processEvents();
    rw.clear();
    updateEntities();
    drawFrame();
    rw.display();
}

void Game::processEvents()
{
    sf::Event ev;
    while (rw.pollEvent(ev))
        if (ev.type == sf::Event::Closed)
            rw.close();
}

void Game::updateEntities()
{
    float dt = clock.restart().asSeconds();
    entity.update(rw, dt);
}

void Game::drawFrame()
{
    entity.draw(rw);
}