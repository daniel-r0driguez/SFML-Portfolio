// Daniel Rodriguez : CS003A
// Super Mario but in SFML! | Final Game Project
#include "Enemy.h"

Enemy::Enemy()
: Enemy({0.f, 0.f}, {0.f, 0.f})
{

}

Enemy::Enemy(const sf::Vector2f& size, const sf::Vector2f& position)
: _physicsComponent(),
_hitboxComponent(size, position),
_animatedSpriteComponent(),
_damageComponent(),
_healthComponent(),
_movementComponent(),
_transformsComponent(position)
{

}

int Enemy::getDamage() const
{
    return this->_damageComponent.getTotalDamage();
}

void Enemy::update(float dt)
{
    updateEnemy(dt);
}

sf::Vector2f Enemy::getPosition() const
{
    return this->_hitboxComponent.getPosition();
}

sf::Vector2f Enemy::getSize() const
{
    return this->_hitboxComponent.getSize();
}

sf::FloatRect Enemy::getBounds() const
{
    return this->_hitboxComponent.getGlobalBounds();
}

sf::Vector2f Enemy::getVelocity() const
{
    return this->_physicsComponent.getVelocity();
}

void Enemy::setTexture(const sf::Texture& texture, int rows, int columns)
{
    this->_animatedSpriteComponent.setTexture(texture, rows, columns);
}

void Enemy::handleCollision(sf::Vector2f collisionDirection, GameObject* object)
{
    handleEnemyCollision(collisionDirection, object);
}

void Enemy::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    drawEnemy(target, states);
}

sf::Vector2f Enemy::getTransformedPoint(int index) const
{
    return this->_hitboxComponent.getTransform().transformPoint(this->_hitboxComponent.getPoint(index));
}

int Enemy::getPointCount() const
{
    return static_cast<int>(this->_hitboxComponent.getPointCount());
}

bool Enemy::isAlive() const
{
    return this->_healthComponent.isAlive();
}

void Enemy::setPosition(const sf::Vector2f& position)
{
    this->_transformsComponent.setPosition(position);
}
