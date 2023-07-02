// Daniel Rodriguez : CS003A
// Super Mario but in SFML! | Final Game Project
#ifndef FINALPROJECTGAME_GAMECOMPONENT_H
#define FINALPROJECTGAME_GAMECOMPONENT_H
#include "SFML/Graphics.hpp"

class GameObject : public sf::Drawable {
public:
    bool _isCollidable = true;
    virtual void update(float dt) = 0;
    virtual sf::Vector2f getPosition() const = 0;
    virtual sf::Vector2f getSize() const = 0;
    virtual sf::FloatRect getBounds() const = 0;
    virtual sf::Vector2f getVelocity() const = 0;

    bool isCollidable() const
    {
        return this->_isCollidable;
    }

    void setCollidable(bool isCollidable)
    {
        this->_isCollidable = isCollidable;
    }
    virtual void handleCollision(sf::Vector2f collisionDirection, GameObject* object) = 0;
    virtual sf::Vector2f getTransformedPoint(int index) const = 0;
    virtual int getPointCount() const = 0;

private:
    friend class CameraComponent;
    virtual void setPosition(const sf::Vector2f& position) = 0;

};
#endif //FINALPROJECTGAME_GAMECOMPONENT_H