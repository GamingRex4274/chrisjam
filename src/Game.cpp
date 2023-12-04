#include "Game.h"
#include "RamWindow.h"
#include <cassert>
#include <iostream>

Game::Game(sf::RenderWindow& rw)
    :
    rw(rw),
    cont1({20.0f, 250.0f}, sf::Color::Green),
    cont2({SCREEN_WIDTH - 120.0f, 250.0f}, sf::Color::Blue)
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
                for (Entity& e : entities)
                    if (e.contains(pos))
                    {
                        e.startMovement();
                        break;
                    }
            }
}

void Game::updateEntities()
{
    float dt = clock.restart().asSeconds();

    // Spawn new entities.
    curTime += dt;
    if (curTime >= spawnTime)
    {
        entities.emplace_back();
        curTime = 0.0f;
    }

    // Update all entities
    for (Entity& e : entities)
        e.update(rw, dt);

    doEntityContainment();
}

void Game::drawFrame()
{
    cont1.draw(rw);
    cont2.draw(rw);
    
    for (Entity& e : entities)
        e.draw(rw);
}

void Game::doEntityContainment()
{
    // Execute collision of all entities with containers.
    auto i = entities.begin();
    while (i != entities.end())
        if (cont1.contains(*i))
            if (i->isGift())
                // Delete and adjust iterator.
                i = entities.erase(i);
            else
            {
                std::cout << "YOU LOSE.\n";
                // Advance iterator normally.
                i++;
            }
        else if (cont2.contains(*i))
            if (i->isGift())
            {
                std::cout << "YOU LOSE.\n";
                // Advance iterator normally.
                i++;
            }
            else
                // Delete and adjust iterator.
                i = entities.erase(i);
        else
            // Advance iterator normally.
            i++;
}