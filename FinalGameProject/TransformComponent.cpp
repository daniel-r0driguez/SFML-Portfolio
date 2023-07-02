// Daniel Rodriguez : CS003A
// Super Mario but in SFML! | Final Game Project
#include "TransformComponent.h"

TransformComponent::TransformComponent()
{
    this->position = {0, 0};
    this->rotation = 0;
    this->scale = 1;
}

TransformComponent::TransformComponent(const sf::Vector2f &initialPosition)
{
    this->position = initialPosition;
    this->rotation = 0;
    this->scale = 1;
}

void TransformComponent::updatePosition(const sf::Vector2f &offset)
{
    this->position += offset;
}

void TransformComponent::setRotation(float degrees)
{
    this->rotation = degrees;
    degrees *= M_PI / 180;
    this->position.x = this->position.x * std::cos(degrees) - this->position.y * std::sin(degrees);
    this->position.y = this->position.y * std::sin(degrees) - this->position.x * std::cos(degrees);
}

float TransformComponent::getRotation() const
{
    return this->rotation;
}

void TransformComponent::setScale(float newScale)
{
    this->scale = newScale;
}

float TransformComponent::getScale() const
{
    return this->scale;
}

const sf::Vector2f &TransformComponent::getPosition() const
{
    return this->position;
}

void TransformComponent::setPosition(const sf::Vector2f &newPosition)
{
    this->position = newPosition;
}