// Daniel Rodriguez : CS003A
// Super Mario but in SFML! | Final Game Project
#include "Goomba.h"
#include "iostream"

Goomba::Goomba()
: Goomba({0.f, 0.f}, {0.f, 0.f})
{

}

Goomba::Goomba(const sf::Vector2f& size, const sf::Vector2f& position)
: Enemy(size, position)
{
    this->_state = WALKING;
    setUpComponents();
}

void Goomba::move(float dt)
{
    if (_goLeft)
    {
        this->_physicsComponent.applyForce({-this->_movementComponent.getMovementForce(), 0.f}, dt);
    }
    else
    {
        this->_physicsComponent.applyForce({this->_movementComponent.getMovementForce(), 0.f}, dt);
    }
    this->_transformsComponent.updatePosition(this->_physicsComponent.getVelocity());
    this->_hitboxComponent.setPosition(this->_transformsComponent.getPosition());
    this->_animatedSpriteComponent.setPosition(this->_hitboxComponent.getPosition(), true);
}

void Goomba::handleEnemyCollision(sf::Vector2f collisionDirection, GameObject* object)
{
    if (auto* player = dynamic_cast<Player*>(object))
    {
        if (collisionDirection.y > 0)
        {
            this->_healthComponent.takeDamage(player->getDamage());
        }
    }
    if (auto* koopa = dynamic_cast<Koopa*>(object))
    {
        if (!koopa->isAlive())
        {
            if (koopa->getVelocity().x != 0)
            {
                this->_healthComponent.takeDamage(koopa->getDamage());
                if (!this->isAlive())
                {
                    SoundManager::playSound(MARIO_STOMP);
                }
            }
        }
    }
    if (auto* solid = dynamic_cast<Solid*>(object))
    {
        // Goomba collided with a solid (wall) on its left.
        if (collisionDirection.x > 0)
        {
            this->_goLeft  = false;
        }
        // Goomba collided with a solid (wall) on its right.
        else if (collisionDirection.x < 0)
        {
            this->_goLeft = true;
        }
        this->_transformsComponent.updatePosition(collisionDirection);
        this->_physicsComponent.applyForce(collisionDirection * 1000.f, 0.1);
    }
}

void Goomba::drawEnemy(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(this->_animatedSpriteComponent);
}

void Goomba::updateEnemy(float dt)
{
    if (this->_healthComponent.isAlive())
    {
        move(dt);
        this->_physicsComponent.update(dt);
    }
    else
    {
        die();
    }
    this->_animatedSpriteComponent.animate(this->_state);
}

void Goomba::die()
{
    this->_state = DEAD;
    GameObject::setCollidable(false);
}

void Goomba::setUpComponents()
{
    this->_damageComponent.setBaseDamage(1);
    this->_physicsComponent.setGravityAcceleration(5.81f);
    this->_physicsComponent.setGravity(true);
    this->_physicsComponent.setMass(100.f);
    this->_physicsComponent.setMaxSpeed(1.f);
    this->_physicsComponent.setFrictionCoefficient(1.f);
    this->_physicsComponent.setXFrictionOn(true);
    this->_movementComponent.setMovementForce(1000.f);
    this->_movementComponent.setJumpHeight(0.f);
    this->_healthComponent.setCurrentHealth(1);
    this->_healthComponent.setMaxHealth(1);
    setTexture(FinalGameImages::getImage(GOOMBA_SPRITE_SHEET), 2, 2);
    this->_animatedSpriteComponent.setPosition(this->_hitboxComponent.getPosition(), true);
}