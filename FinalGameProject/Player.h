// Daniel Rodriguez : CS003A
// Super Mario but in SFML! | Final Game Project
#ifndef FINALPROJECTGAME_MOVEABLE_H
#define FINALPROJECTGAME_MOVEABLE_H
#include "GameObject.h"
#include "FinalGameImages.h"
#include "Goomba.h"

// Components
#include "PhysicsComponent.h"
#include "SoundManager.h"
#include "Bitmask.h"
#include "TransformComponent.h"
#include "MovementComponent.h"
#include "HealthComponent.h"
#include "HitboxComponent.h"
#include "AnimatedSpriteComponent.h"
#include "InputComponent.h"
#include "DamageComponent.h"
#include "Solid.h"
#include <cmath>

class Player : public GameObject {
private:
enum enumState {IDLE, RUNNING, SKIDDING, JUMPING, DIED, VICTORY,
        LAST_STATE};
    enumState enumState;
    InputComponent _inputComponent;
    DamageComponent _damageComponent;
    PhysicsComponent _physicsComponent;
    TransformComponent _transformsComponent;
    MovementComponent _movementComponent;
    HealthComponent _healthComponent;
    HitboxComponent _hitboxComponent;
    AnimatedSpriteComponent _animatedSpriteComponent;
    bool isGrounded;
    float timeDead = 0;

public:
    Player();
    Player(const sf::Vector2f& size, const sf::Vector2f& position);
    void update(float dt) override;
    sf::Vector2f getPosition() const override;
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    sf::Vector2f getSize() const override;
    sf::Vector2f getVelocity() const override;
    sf::FloatRect getBounds() const override;
    void handleCollision(sf::Vector2f collisionDirection, GameObject* object) override;
    int getDamage() const;
    void die(float dt);
    void respawn(float dt);

private:
    void move(float dt);
    void updatePosition(float dt);
    sf::Vector2f getTransformedPoint(int index) const override;
    int getPointCount() const override;
    void setPosition(const sf::Vector2f& position) override;
};


#endif //FINALPROJECTGAME_MOVEABLE_H