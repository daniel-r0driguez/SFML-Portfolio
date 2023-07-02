// Daniel Rodriguez : CS003A
// Super Mario but in SFML! | Final Game Project
#include "Player.h"
#include <iostream>

Player::Player()
: Player({0.f, 0.f}, {0.f, 0.f})
{

}

Player::Player(const sf::Vector2f& size, const sf::Vector2f& position)
: _physicsComponent(0.55, 3.f, 100),
  _transformsComponent(position),
  _movementComponent(800.f, -5.5f),
  _inputComponent(),
  _healthComponent(1, 1),
  _damageComponent(1, 0),
  _hitboxComponent(size, position),
  _animatedSpriteComponent(FinalGameImages::getImage(Image_Enum::MARIO_SPRITE_SHEET), 6, 3)
{
    this->isGrounded = false;
    this->_hitboxComponent.setSize({12.f, 17.f});
    this->_animatedSpriteComponent.setTimeInterval(100);
    this->_physicsComponent.setGravityAcceleration(5.81);
    this->_physicsComponent.setGravity(true);
    this->_physicsComponent.setXFrictionOn(true);
    this->enumState = enumState::IDLE;
}

void Player::move(float dt)
{
    if (this->_inputComponent.isKeyPressed(Key::RIGHT_KEY))
    {
        this->_animatedSpriteComponent.setScale({1, 1});
        this->enumState = (this->enumState == enumState::JUMPING) ? enumState::JUMPING : enumState::RUNNING;
        if (this->_physicsComponent.getVelocity().x < 0 && this->enumState == enumState::RUNNING)
        {
            this->enumState = SKIDDING;
        }
        this->_physicsComponent.applyForce({this->_movementComponent.getMovementForce(), 0.f}, dt);
    }
    if (this->_inputComponent.isKeyPressed(Key::LEFT_KEY))
    {
        this->_animatedSpriteComponent.setScale({-1, 1});
        this->enumState = (this->enumState == enumState::JUMPING) ? enumState::JUMPING : enumState::RUNNING;
        if (this->_physicsComponent.getVelocity().x > 0 && this->enumState == enumState::RUNNING)
        {
            this->enumState = enumState::SKIDDING;
        }
        this->_physicsComponent.applyForce({-this->_movementComponent.getMovementForce(), 0.f}, dt);
    }
    // Jump key
    if (this->_inputComponent.wasKeyJustPressed(UP_KEY) && this->isGrounded)
    {
        SoundManager::playSound(Sound_Enum::MARIO_JUMP);
        this->isGrounded = false;
        this->enumState = enumState::JUMPING;
        this->_physicsComponent.setVelocity({_physicsComponent.getVelocity().x, _movementComponent.getJumpHeight()});
    }
}

void Player::updatePosition(float dt)
{
    this->_physicsComponent.update(dt);
    this->_transformsComponent.updatePosition(this->_physicsComponent.getVelocity());
    this->_hitboxComponent.setPosition(this->_transformsComponent.getPosition());
    this->_animatedSpriteComponent.setPosition(this->_hitboxComponent.getPosition(), true);
}

void Player::update(float dt)
{
    if (this->_healthComponent.isAlive() && this->_transformsComponent.getPosition().y < 1000.f)
    {
        move(dt);
        if (this->_physicsComponent.getVelocity().x > -0.3f && this->_physicsComponent.getVelocity().x < 0.3f)
            this->enumState = (this->enumState == enumState::JUMPING) ? enumState::JUMPING : enumState::IDLE;

        if (this->_inputComponent.isKeyPressed(Key::TAUNT_KEY))
        {
            this->enumState = enumState::VICTORY;
        }
        this->_animatedSpriteComponent.animate(this->enumState);
    }
    else
    {
        if (timeDead == 0.f)
        {
            die(dt);
        }
        else if (timeDead > 2.f)
        {
            respawn(dt);
            timeDead = 0.f;
        }
        if (!this->_healthComponent.isAlive()) timeDead += dt;
    }
    updatePosition(dt);
    this->_inputComponent.update();
}

void Player::die(float dt)
{
    this->_healthComponent.setCurrentHealth(0.f);
    this->_animatedSpriteComponent.animate(DIED);
    SoundManager::playSound(MARIO_DIE);
    setCollidable(false);
    this->_physicsComponent.setVelocity({0.f, -5.f});
}

void Player::respawn(float dt)
{
    this->_healthComponent.heal(this->_healthComponent.getMaxHealth());
    this->_physicsComponent.setVelocity({0.f, 0.f});
    setCollidable(true);
    this->_transformsComponent.setPosition({0.f, 0.f});
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(this->_animatedSpriteComponent);
}

sf::Vector2f Player::getPosition() const
{
    return this->_hitboxComponent.getPosition();
}

sf::Vector2f Player::getSize() const
{
    return this->_hitboxComponent.getSize();
}

sf::Vector2f Player::getVelocity() const
{
    return this->_physicsComponent.getVelocity();
}


void Player::handleCollision(sf::Vector2f collisionDirection, GameObject* object)
{
    if (auto* solid = dynamic_cast<Solid*>(object))
    {
        // Mario has hit his head on a solid.
        if (collisionDirection.y > 0)
        {
            this->_physicsComponent.setVelocity({this->_physicsComponent.getVelocity().x, 0.f});
            SoundManager::playSound(MARIO_BUMP);
        }
        // Mario has landed on the ground
        if (collisionDirection.y < 0)
        {
            this->enumState = enumState::IDLE;
            this->isGrounded = true;
        }
        this->_transformsComponent.updatePosition(collisionDirection);
        this->_physicsComponent.applyForce(collisionDirection * 1000.f, 0.1);
    }
    if (auto* enemy = dynamic_cast<Enemy*>(object))
    {
        if (enemy->isAlive() && this->_healthComponent.isAlive())
        {
            if (collisionDirection.y < 0)
            {
                SoundManager::playSound(MARIO_STOMP);
                this->_physicsComponent.setVelocity({this->_physicsComponent.getVelocity().x, -3.5f});
            }
            else
            {
                this->_healthComponent.takeDamage(enemy->getDamage());
            }
        }
    }
}

int Player::getDamage() const
{
    return this->_damageComponent.getTotalDamage();
}

sf::FloatRect Player::getBounds() const
{
    return this->_hitboxComponent.getGlobalBounds();
}

sf::Vector2f Player::getTransformedPoint(int index) const
{
    return this->_hitboxComponent.getTransform().transformPoint(this->_hitboxComponent.getPoint(index));
}

int Player::getPointCount() const
{
    return static_cast<int>(this->_hitboxComponent.getPointCount());
}

void Player::setPosition(const sf::Vector2f& position)
{
    this->_transformsComponent.setPosition(position);
}
