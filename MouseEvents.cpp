#include "MouseEvents.h"

bool MouseEvents::isHovered(const SFMLObject& obj, const sf::RenderWindow& window)
{
    sf::Vector2<float> mousePos = (sf::Vector2f) sf::Mouse::getPosition(window);
    return obj.getGlobalBounds().contains(mousePos);
}

bool MouseEvents::isClicked(const SFMLObject& obj, const sf::RenderWindow& window)
{
    return isHovered(obj, window) && sf::Mouse::isButtonPressed(sf::Mouse::Left);
}