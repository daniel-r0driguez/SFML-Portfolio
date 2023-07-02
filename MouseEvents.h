#ifndef PORTFOLIO_PROJECT_MOUSEEVENTS_H
#define PORTFOLIO_PROJECT_MOUSEEVENTS_H
#include "SFML/Graphics.hpp"
#include "SFMLObject.h"

class MouseEvents {
public:
    static bool isHovered(const SFMLObject& obj, const sf::RenderWindow& window);
    static bool isClicked(const SFMLObject& obj, const sf::RenderWindow& window);
};

#endif //PORTFOLIO_PROJECT_MOUSEEVENTS_H