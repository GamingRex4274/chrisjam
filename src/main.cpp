#include "Game.h"
#include "RamWindow.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Bogo Gift Sort", sf::Style::Close);
    window.setFramerateLimit(60);
    window.setKeyRepeatEnabled(false);

    Game game(window);
    while (window.isOpen())
        game.run();

    return 0;
}