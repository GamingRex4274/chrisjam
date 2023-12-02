#include <SFML/Graphics.hpp>

static constexpr int SCREEN_WIDTH = 800;
static constexpr int SCREEN_HEIGHT = 600;

static sf::Vector2f GetScreenCenter()
{
    return sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT) / 2.0f;
}