// Daniel Rodriguez : CS003A
// Super Mario but in SFML! | Final Game Project
#ifndef MOVEMENTCOMPONENT_H
#define MOVEMENTCOMPONENT_H
#include "SFML/Graphics.hpp"

class MovementComponent {
private:
    float _movementForce;
    float _jumpHeight;

public:
    MovementComponent();
    MovementComponent(float movementForce, float jumpHeight);

    void setDirection(int signedNum);
    float getMovementForce() const;
    void setMovementForce(float movementForce);
    float getJumpHeight() const;
    void setJumpHeight(float jumpHeight);
};


#endif //MOVEMENTCOMPONENT_H
