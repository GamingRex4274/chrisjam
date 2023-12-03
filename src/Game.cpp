#include "Game.h"
#include "RamWindow.h"
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

    // Execute collision of all entities with containers.
    for (int i = 0; i < entities.size(); i++)
        if (cont1.contains(entities[i]))
            if (entities[i].isGift())
                std::cout << "Box " << i << " is CORRECTLY contained in 1\n";
            else
                std::cout << "Box " << i << " is WRONGLY contained in 1\n";
        else if (cont2.contains(entities[i]))
            if (entities[i].isGift())
                std::cout << "Box " << i << " is WRONGLY contained in 2\n";
            else
                std::cout << "Box " << i << " is CORRECTLY contained in 2\n";
}

void Game::drawFrame()
{
    cont1.draw(rw);
    cont2.draw(rw);
    
    for (Entity& e : entities)
        e.draw(rw);
}