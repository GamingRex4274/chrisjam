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
}

void Game::updateEntities()
{
}

void Game::drawFrame()
{
    float radius = 300.0f;
    sf::CircleShape circle(radius);
    circle.setFillColor(sf::Color::Blue);
    circle.setOrigin({radius, radius});
    circle.setPosition(GetScreenCenter());
    rw.draw(circle);
}