// Daniel Rodriguez : CS003A
// Super Mario but in SFML! | Final Game Project
#include "Solid.h"

Solid::Solid()
: Solid({0.f, 0.f}, {0.f, 0.f}, sf::Color::White)
{

}

Solid::Solid(const sf::Vector2f& size, const sf::Vector2f& position)
: Solid(size, position, sf::Color::White)
{

}

Solid::Solid(const sf::Vector2f& size, const sf::Vector2f& position, const sf::Color& color)
: rect(size)
{
    this->rect.setPosition(position);
    this->rect.setFillColor(color);
}

sf::Vector2f Solid::getPosition() const
{
    return this->rect.getPosition();
}

sf::Vector2f Solid::getSize() const
{
    return this->rect.getSize();
}

sf::Vector2f Solid::getVelocity() const
{
    return {0.f,0.f};
}

void Solid::handleCollision(sf::Vector2f collisionDirection, GameObject* object)
{

}

void Solid::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(this->rect);
}


void Solid::update(float dt)
{

}

sf::FloatRect Solid::getBounds() const
{
    return this->rect.getGlobalBounds();
}

sf::Vector2f Solid::getTransformedPoint(int index) const
{
    return this->rect.getTransform().transformPoint(this->rect.getPoint(index));
}

int Solid::getPointCount() const
{
    return static_cast<int>(this->rect.getPointCount());
}

void Solid::setPosition(const sf::Vector2f& position)
{
    this->rect.setPosition(position);
}
