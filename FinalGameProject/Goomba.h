// Daniel Rodriguez : CS003A
// Super Mario but in SFML! | Final Game Project
#ifndef FINALPROJECTGAME_GOOMBA_H
#define FINALPROJECTGAME_GOOMBA_H
#include "Enemy.h"
#include "FinalGameImages.h"
#include "Player.h"
#include "Koopa.h"

class Goomba : public Enemy {
private:
    enum GoombaState {WALKING, DEAD};
    GoombaState _state;
    bool _goLeft = true;

public:
    Goomba();
    Goomba(const sf::Vector2f& size, const sf::Vector2f& position);


private:
    void die();
    void move(float dt);
    void handleEnemyCollision(sf::Vector2f collisionDirection, GameObject* object) override;

    void drawEnemy(sf::RenderTarget& target, sf::RenderStates states) const override;

    void updateEnemy(float dt) override;
    void setUpComponents();

};


#endif //FINALPROJECTGAME_GOOMBA_H
