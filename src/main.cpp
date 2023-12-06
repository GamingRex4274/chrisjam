#include "Game.h"
#include "RamWindow.h"

int main()
{
    // Create window.
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Bogo Gift Sort", sf::Style::Close);

    // Set window icon.
    const int icon_dim = 32;
    sf::Image icon;
    icon.loadFromFile("src\\Sprites\\gift.png");
    window.setIcon(icon_dim, icon_dim, icon.getPixelsPtr());

    // Window settings.
    window.setFramerateLimit(60);
    window.setKeyRepeatEnabled(false);

    // Start game loop.
    Game game(window);
    while (window.isOpen())
        game.run();

    return 0;
}