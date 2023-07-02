#include "GreenCircle.h"

GreenCircle::GreenCircle()
: GreenCircle(250.f)
{

}

GreenCircle::GreenCircle(float radius)
{
    this->_circle.setFillColor(sf::Color::Green);
    this->_circle.setRadius(radius);
}

sf::Vector2f GreenCircle::getPosition() const
{
    return this->_circle.getPosition();
}

void GreenCircle::eventHandler(sf::RenderWindow &target, sf::Event event) const
{

}

void GreenCircle::update(float dt) const
{

}

void GreenCircle::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(this->_circle);
}

sf::FloatRect GreenCircle::getGlobalBounds() const
{
    return this->_circle.getGlobalBounds();
}

void GreenCircle::setPosition(const sf::Vector2f& position)
{
    this->_circle.setPosition(position);
}

sf::FloatRect GreenCircle::getLocalBounds() const
{
    return this->_circle.getLocalBounds();
}
