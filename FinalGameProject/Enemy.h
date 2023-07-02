// Daniel Rodriguez : CS003A
// Super Mario but in SFML! | Final Game Project
#ifndef FINALPROJECTGAME_ENEMY_H
#define FINALPROJECTGAME_ENEMY_H
#include "GameObject.h"
#include "SFML/Graphics.hpp"
#include "HitboxComponent.h"
#include "HealthComponent.h"
#include "PhysicsComponent.h"
#include "MovementComponent.h"
#include "AnimatedSpriteComponent.h"
#include "DamageComponent.h"
#include "TransformComponent.h"

class Enemy : public GameObject {
protected:
    DamageComponent _damageComponent;
    PhysicsComponent _physicsComponent;
    TransformComponent _transformsComponent;
    MovementComponent _movementComponent;
    HealthComponent _healthComponent;
    HitboxComponent _hitboxComponent;
    AnimatedSpriteComponent _animatedSpriteComponent;

public:
    // Pure virtual functions for enemies who will inherit from this base class.
    virtual void handleEnemyCollision(sf::Vector2f collisionDirection, GameObject* object) = 0;
    virtual void drawEnemy(sf::RenderTarget &target, sf::RenderStates states) const = 0;
    virtual void updateEnemy(float dt) = 0;
    Enemy();
    Enemy(const sf::Vector2f& size, const sf::Vector2f& position);
    int getDamage() const;
    void update(float dt) override;
    sf::Vector2f getPosition() const override;
    sf::Vector2f getSize() const override;
    sf::FloatRect getBounds() const override;
    sf::Vector2f getVelocity() const override;
    void setTexture(const sf::Texture& texture, int rows, int columns);
    void handleCollision(sf::Vector2f collisionDirection, GameObject* object) override;
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    sf::Vector2f getTransformedPoint(int index) const override;
    int getPointCount() const override;
    bool isAlive() const;

private:
    void setPosition(const sf::Vector2f& position) override;
};


#endif //FINALPROJECTGAME_ENEMY_H
