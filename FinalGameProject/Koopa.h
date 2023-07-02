// Daniel Rodriguez : CS003A
// Super Mario but in SFML! | Final Game Project
#ifndef FINALPROJECTGAME_KOOPA_H
#define FINALPROJECTGAME_KOOPA_H
#include "Enemy.h"
#include "FinalGameImages.h"
#include "Solid.h"
#include "Player.h"

class Koopa : public Enemy {
private:
    enum KoopaState{WALKING_LEFT, WALKING_RIGHT, UNDER_SHELL};
    KoopaState _state;

public:
    Koopa();
    Koopa(const sf::Vector2f& size, const sf::Vector2f& position);

private:
    void move(float dt);
    void updatePosition(float dt);
    void handleEnemyCollision(sf::Vector2f collisionDirection, GameObject *object) override;
    void drawEnemy(sf::RenderTarget &target, sf::RenderStates states) const override;
    void updateEnemy(float dt) override;
    void setUpComponents();
    void kicked();
};


#endif //FINALPROJECTGAME_KOOPA_H
