#include "Game.h"
#include "RamWindow.h"
#include <iostream>

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
        if (ev.type == sf::Event::MouseButtonPressed)
            if (ev.mouseButton.button == sf::Mouse::Left)
            {
                const sf::Vector2f pos = sf::Vector2f(ev.mouseButton.x, ev.mouseButton.y);
                if (entity.contains(pos))
                    entity.startMovement();
            }
}

void Game::updateEntities()
{
    float dt = clock.restart().asSeconds();
    entity.update(rw, dt);

    if (cont.contains(entity))
        std::cout << "Box is contained!\n";
}

void Game::drawFrame()
{
    cont.draw(rw);
    entity.draw(rw);
}