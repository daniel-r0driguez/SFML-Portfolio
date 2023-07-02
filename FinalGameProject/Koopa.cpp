// Daniel Rodriguez : CS003A
// Super Mario but in SFML! | Final Game Project
#include "Koopa.h"
#include "iostream"

Koopa::Koopa()
: Koopa({0.f, 0.f}, {0.f, 0.f})
{

}

Koopa::Koopa(const sf::Vector2f &size, const sf::Vector2f &position)
: Enemy(size, position)
{
    this->_state = WALKING_RIGHT;
    setUpComponents();
}

void Koopa::move(float dt)
{
    if (this->isAlive())
    {
        this->_physicsComponent.applyForce({this->_movementComponent.getMovementForce(), 0.f}, dt);
    }
    else
    {
        this->_physicsComponent.applyForce({this->_movementComponent.getMovementForce() * 5.f, 0.f}, dt);
    }
}

void Koopa::updatePosition(float dt)
{
    this->_physicsComponent.update(dt);
    this->_transformsComponent.updatePosition(this->_physicsComponent.getVelocity());
    this->_hitboxComponent.setPosition(this->_transformsComponent.getPosition());
    this->_animatedSpriteComponent.setPosition(this->_hitboxComponent.getPosition(), true);
}

void Koopa::handleEnemyCollision(sf::Vector2f collisionDirection, GameObject* object)
{
    if (auto* solid =  dynamic_cast<Solid*>(object))
    {
        // Koopa collided with a solid (wall) on its left.
        if (collisionDirection.x > 0)
        {
            if (this->_healthComponent.isAlive())
            {
                this->_state = WALKING_RIGHT;
            }
            this->_physicsComponent.setXVelocity(0.f);
            this->_movementComponent.setDirection(1);
        }
        // Koopa collided with a solid (wall) on its right.
        else if (collisionDirection.x < 0)
        {
            if (this->_healthComponent.isAlive())
            {
                this->_state = WALKING_LEFT;
            }
            this->_physicsComponent.setXVelocity(0.f);
            this->_movementComponent.setDirection(-1);
        }
        this->_transformsComponent.updatePosition(collisionDirection);
        this->_physicsComponent.applyForce(collisionDirection * 1000.f, 0.1);
    }
    if (auto* player = dynamic_cast<Player*>(object))
    {
        // Player stomped koopa
        if (collisionDirection.y > 0 && this->_state != UNDER_SHELL)
        {
            this->_healthComponent.takeDamage(player->getDamage());
        }
        else if (collisionDirection.y > 0 && this->_state == UNDER_SHELL)
        {
            this->_physicsComponent.setVelocity({0.f, 0.f});
            this->_state = WALKING_LEFT;
        }
    }
}

void Koopa::drawEnemy(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(this->_animatedSpriteComponent);
}

void Koopa::updateEnemy(float dt)
{
    move(dt);
    if (!this->isAlive())
    {
        this->_physicsComponent.setMaxSpeed(3.f);
        this->_state = UNDER_SHELL;
        this->_physicsComponent.setXFrictionOn(false);
    }
    this->_animatedSpriteComponent.animate(this->_state);
    updatePosition(dt);
}

void Koopa::setUpComponents()
{
    this->_damageComponent.setBaseDamage(1);
    this->_physicsComponent.setGravityAcceleration(5.81f);
    this->_physicsComponent.setGravity(true);
    this->_physicsComponent.setMass(150.f);
    this->_physicsComponent.setMaxSpeed(1.f);
    this->_physicsComponent.setFrictionCoefficient(1.f);
    this->_physicsComponent.setXFrictionOn(true);
    this->_movementComponent.setMovementForce(950.f);
    this->_movementComponent.setJumpHeight(0.f);
    this->_healthComponent.setCurrentHealth(1);
    this->_healthComponent.setMaxHealth(1);
    setTexture(FinalGameImages::getImage(KOOPA_SPRITE_SHEET), 3, 2);
    this->_animatedSpriteComponent.setPosition(this->_hitboxComponent.getPosition(), true);
}