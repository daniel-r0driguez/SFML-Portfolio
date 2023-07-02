// Daniel Rodriguez - CS003A
// Bouncing Ball
// This cpp file contains the implementation of the Ball class.
#include "Ball.h"

Ball::Ball()
{
    this->xVelocity = 0;
    this->yVelocity = 0;
    this->radius = 0;
    this->circle.setRadius(this->radius);
    this->circle.setFillColor(sf::Color::White);
}

Ball::Ball(float radius, float xVelocity, float yVelocity)
{
    this->radius = radius;
    this->xVelocity = xVelocity;
    this->yVelocity = yVelocity;
    this->circle.setRadius(this->radius);
    this->circle.setFillColor(sf::Color::White);
}

Ball::Ball(float radius, float xVelocity, float yVelocity, const sf::Color &color)
{
    this->radius = radius;
    this->xVelocity = xVelocity;
    this->yVelocity = yVelocity;
    this->circle.setRadius(this->radius);
    this->circle.setFillColor(color);
}

float Ball::getXVelocity() const
{
    return this->xVelocity;
}

void Ball::setXVelocity(float newXVelocity)
{
    this->xVelocity = newXVelocity;
}

float Ball::getYVelocity() const
{
    return this->yVelocity;
}

void Ball::setYVelocity(float newYVelocity)
{
    this->yVelocity = newYVelocity;
}

float Ball::getRadius() const
{
    return this->radius;
}

void Ball::setRadius(float newRadius)
{
    this->radius = newRadius;
    this->circle.setRadius(newRadius);
}

float Ball::getDiameter() const
{
    return this->radius * 2;
}

sf::CircleShape& Ball::getBall()
{
    return this->circle;
}

void Ball::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(this->circle);
}
