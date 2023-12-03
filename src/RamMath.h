// #include <SFML/Graphics.hpp>
// #include <cmath>

// static float GetLengthSq(const sf::Vector2f& v)
// {
//     return v.x * v.x + v.y * v.y;
// }

// static sf::Vector2f GetNormalized(const sf::Vector2f& v)
// {
//     const float sqLength = GetLengthSq(v);
//     if (sqLength != 0)
//         return v / float(sqrt(sqLength));
//     else
//         return v;
// }

// static sf::FloatRect GetExpanded(const sf::FloatRect& src, float offset)
// {
//     const float left = src.left - offset;
//     const float top = src.top - offset;
//     const float width = src.width + offset * 2;
//     const float height = src.height + offset * 2;
//     return sf::FloatRect(left, top, width, height);
// }