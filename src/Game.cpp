#include "Game.h"
#include "RamWindow.h"
#include <cassert>
#include <iostream>
#include <fstream>

Game::Game(sf::RenderWindow& rw)
    :
    rw(rw),
    cont1({20.0f, 250.0f}, sf::Color::Green),
    cont2({SCREEN_WIDTH - 120.0f, 250.0f}, sf::Color::Blue)
{
    font.loadFromFile("src\\Fonts\\consola.ttf");
    scoreText.setCharacterSize(20);
    scoreText.setFont(font);
    scoreText.setPosition({5, 5});

    loadTopScore();
    topScoreText.setCharacterSize(20);
    topScoreText.setFont(font);
    topScoreText.setPosition({SCREEN_WIDTH - 8 * 20, 5});
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

    if (!gameIsOver)
    {
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
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
        reset();
}

void Game::drawFrame()
{
    cont1.draw(rw);
    cont2.draw(rw);
    
    for (Entity& e : entities)
        e.draw(rw);
    
    scoreText.setString("SCORE\n" + std::to_string(score));
    rw.draw(scoreText);

    topScoreText.setString("HI-SCORE\n" + std::to_string(topScore));
    rw.draw(topScoreText);
}

void Game::endGame()
{
    gameIsOver = true;
    saveTopScore();
}

void Game::reset()
{
    entities.clear();
    curTime = 0.0f;
    score = 0;
    spawnTime = maxTime;
    gameIsOver = false;
}

void Game::doEntityContainment()
{
    // Execute collision of all entities with containers.
    auto i = entities.begin();
    while (i != entities.end())
        // Process gift container.
        if (cont1.contains(*i))
            if (i->isGift())
            {
                // Delete and adjust iterator.
                i = entities.erase(i);
                score++;
                spawnTime = std::max(minTime, spawnTime - step);
            }
            else
            {
                // Coal entered gift container.
                endGame();
                break;
            }
        // Process coal container.
        else if (cont2.contains(*i))
            if (i->isGift())
            {
                // Gift entered coal container.
                endGame();
                break;
            }
            else
            {
                // Delete and adjust iterator.
                i = entities.erase(i);
                score++;
                spawnTime = std::max(minTime, spawnTime - step);
            }
        else
            // Advance iterator normally.
            i++;
}

void Game::saveTopScore()
{
    if (score > topScore)
    {
        // Set top score to the new score.
        topScore = score;
        // Write into a new or existing file.
        std::ofstream out("score.dat", std::ios::binary);
        out.write(reinterpret_cast<char*>(&topScore), sizeof(topScore));
    }
}

void Game::loadTopScore()
{
    // Attempt to open score file.
    std::ifstream in("score.dat", std::ios::binary);
    if (in)
        // Read top score from file.
        in.read(reinterpret_cast<char*>(&topScore), sizeof(topScore));
}