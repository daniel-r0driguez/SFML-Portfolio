// Daniel Rodriguez : CS003A
// Super Mario but in SFML! | Final Game Project
#ifndef FINALPROJECTGAME_PHYSICSCOMPONENT_H
#define FINALPROJECTGAME_PHYSICSCOMPONENT_H
#include "SFML/Graphics.hpp"
#include "cmath"

class PhysicsComponent {
private:
    ////////////////// General Procedure of a Physics Engine. ////////////////////
    /// Step 1. Apply forces
    /// Step 2. Update positions, (TransformComponents), and velocities (PhysicsComponents).
    /// Step 3. Detect collisions
    /// Step 4. Solve constraints
    /// Step 5. Display results.
    /////////////////////////////////////////////////////////////////////////////
    sf::Vector2f _velocity;
    sf::Vector2f _acceleration;
    float _frictionCoefficient;
    float _mass;
    float _maxSpeed;
    float _gravityAcceleration;
    bool _gravityOn;
    bool _xFrictionOn;
    bool _yFrictionOn;

public:
    PhysicsComponent();
    PhysicsComponent(float frictionCoefficient, float maxSpeed, float mass);

    void update(float dt);
    void applyForce(const sf::Vector2f& force, float dt);

    const sf::Vector2f& getVelocity() const;
    void setVelocity(const sf::Vector2f& newVelocity);
    void setXVelocity(float xVel);
    void setYVelocity(float yVel);

    const sf::Vector2f& getAcceleration() const;
    void setAcceleration(const sf::Vector2f& newAcceleration);

    float getFrictionCoefficient() const;
    void setFrictionCoefficient(float frictionCoefficient);

    float getMass() const;
    void setMass(float mass);

    float getMaxSpeed() const;
    void setMaxSpeed(float maxSpeed);

    bool XFrictionOn() const;
    void setXFrictionOn(bool isOn);

    bool YFrictionOn() const;
    void setYFrictionOn(bool isOn);

    static float magnitude(const sf::Vector2f& vector);
    static sf::Vector2f getNormal(const sf::Vector2f& vector);

    float getGravityAcceleration() const;
    void setGravityAcceleration(float gravityAcceleration);

    bool isGravityOn() const;
    void setGravity(bool isOn);

private:
    static void resetAcceleration(sf::Vector2f& acceleration);
    void applyXFriction(float dt);
    void applyGravity(float dt);
    float normalForce() const;
};


#endif //FINALPROJECTGAME_PHYSICSCOMPONENT_H
