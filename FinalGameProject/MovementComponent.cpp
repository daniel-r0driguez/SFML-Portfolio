// Daniel Rodriguez : CS003A
// Super Mario but in SFML! | Final Game Project
#include "MovementComponent.h"

MovementComponent::MovementComponent()
: MovementComponent(800.f, -5.5f)
{
}

MovementComponent::MovementComponent(float movementForce, float jumpHeight)
{
    this->_movementForce = movementForce;
    this->_jumpHeight = jumpHeight;
}

void MovementComponent::setDirection(int signedNum)
{
    if (signedNum < 0)
    {
        this->_movementForce = -this->_movementForce;
    }
    else
    {
        this->_movementForce = std::abs(this->_movementForce);
    }
}

float MovementComponent::getMovementForce() const
{
    return this->_movementForce;
}

void MovementComponent::setMovementForce(float movementForce)
{
    this->_movementForce = movementForce;
}

float MovementComponent::getJumpHeight() const
{
    return this->_jumpHeight;
}

void MovementComponent::setJumpHeight(float jumpHeight)
{
    this->_jumpHeight = jumpHeight;
}