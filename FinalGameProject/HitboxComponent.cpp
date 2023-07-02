// Daniel Rodriguez : CS003A
// Super Mario but in SFML! | Final Game Project
#include "HitboxComponent.h"

HitboxComponent::HitboxComponent()
: HitboxComponent({0,0}, {0,0})
{

}

HitboxComponent::HitboxComponent(const sf::Vector2f &size, const sf::Vector2f& position)
: RectangleShape(size)
{
    setPosition(position);
    setFillColor(sf::Color::Red);
}