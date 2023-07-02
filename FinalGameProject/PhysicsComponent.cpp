// Daniel Rodriguez : CS003A
// Super Mario but in SFML! | Final Game Project
#include "PhysicsComponent.h"
#include "iostream"

PhysicsComponent::PhysicsComponent()
: PhysicsComponent(0.6f, 10.f, 100.f)
{

}

PhysicsComponent::PhysicsComponent(float frictionCoefficient, float maxSpeed, float mass)
{
    this->_velocity = {0.f, 0.f};
    this->_acceleration = {0.f, 0.f};
    this->_frictionCoefficient = frictionCoefficient;
    this->_mass = mass;
    this->_maxSpeed = maxSpeed;
    this->_xFrictionOn = false;
    this->_yFrictionOn = false;
    this->_gravityAcceleration = 9.81;
    this->_gravityOn = false;
}

void PhysicsComponent::update(float dt)
{
    if (this->_xFrictionOn) applyXFriction(dt);
    if (this->_gravityOn) applyGravity(dt);
    if (std::abs(this->_velocity.x + this->_acceleration.x * dt) < this->_maxSpeed)
    {
        this->_velocity.x += this->_acceleration.x * dt;
    }
    this->_velocity.y += this->_acceleration.y * dt;
    resetAcceleration(this->_acceleration);
}

void PhysicsComponent::applyForce(const sf::Vector2f& force, float dt)
{
    this->_acceleration += force / this->_mass;
}

void PhysicsComponent::applyXFriction(float dt)
{
    this->_acceleration.x += this->_frictionCoefficient * -300.0f * this->_velocity.x * dt;
}

const sf::Vector2f& PhysicsComponent::getVelocity() const
{
    return this->_velocity;
}

void PhysicsComponent::setVelocity(const sf::Vector2f& newVelocity)
{
    this->_velocity = newVelocity;
}

void PhysicsComponent::setXVelocity(float xVel)
{
    this->_velocity.x = xVel;
}

void PhysicsComponent::setYVelocity(float yVel)
{
    this->_velocity.y = yVel;
}

const sf::Vector2f& PhysicsComponent::getAcceleration() const
{
    return this->_acceleration;
}

void PhysicsComponent::setAcceleration(const sf::Vector2f& newAcceleration)
{
    this->_acceleration = newAcceleration;
}

float PhysicsComponent::getFrictionCoefficient() const
{
    return this->_frictionCoefficient;
}

void PhysicsComponent::setFrictionCoefficient(float frictionCoefficient)
{
    this->_frictionCoefficient = frictionCoefficient;
}

float PhysicsComponent::getMass() const
{
    return this->_mass;
}

void PhysicsComponent::setMass(float mass)
{
    this->_mass = mass;
}

float PhysicsComponent::getMaxSpeed() const
{
    return this->_maxSpeed;
}

void PhysicsComponent::setMaxSpeed(float maxSpeed)
{
    this->_maxSpeed = maxSpeed;
}

bool PhysicsComponent::XFrictionOn() const
{
    return this->_xFrictionOn;
}

void PhysicsComponent::setXFrictionOn(bool isOn)
{
    this->_xFrictionOn = isOn;
}

bool PhysicsComponent::YFrictionOn() const
{
    return this->_yFrictionOn;
}

void PhysicsComponent::setYFrictionOn(bool isOn)
{
    this->_yFrictionOn = isOn;
}

float PhysicsComponent::magnitude(const sf::Vector2f& vector)
{
    return static_cast<float>(sqrt(vector.x * vector.x + vector.y + vector.y));
}

sf::Vector2f PhysicsComponent::getNormal(const sf::Vector2f& vector)
{
    return vector / magnitude(vector);
}

void PhysicsComponent::resetAcceleration(sf::Vector2f &acceleration)
{
    acceleration.x = 0;
    acceleration.y = 0;
}

float PhysicsComponent::getGravityAcceleration() const
{
    return this->_gravityAcceleration;
}

void PhysicsComponent::setGravityAcceleration(float gravityAcceleration)
{
    this->_gravityAcceleration = gravityAcceleration;
}

void PhysicsComponent::applyGravity(float dt)
{
    this->_acceleration.y += (this->_mass * this->_gravityAcceleration) * dt;
}


bool PhysicsComponent::isGravityOn() const
{
    return this->_gravityOn;
}

void PhysicsComponent::setGravity(bool isOn)
{
    this->_gravityOn = isOn;
}

float PhysicsComponent::normalForce() const
{
    return this->_mass * this->_gravityAcceleration;
}
