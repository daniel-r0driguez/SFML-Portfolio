// Daniel Rodriguez : CS003A
// Super Mario but in SFML! | Final Game Project
#ifndef FINALPROJECTGAME_SOLID_H
#define FINALPROJECTGAME_SOLID_H
#include "GameObject.h"

class Solid : public GameObject {
private:
    sf::RectangleShape rect;

public:
    Solid();
    Solid(const sf::Vector2f& size, const sf::Vector2f& position);
    Solid(const sf::Vector2f& size, const sf::Vector2f& position, const sf::Color& color);
    void update(float dt) override;
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    sf::Vector2f getPosition() const override;
    sf::Vector2f getSize() const override;
    sf::Vector2f getVelocity() const override;
    sf::FloatRect getBounds() const override;
    void handleCollision(sf::Vector2f collisionDirection, GameObject* object) override;

private:
    sf::Vector2f getTransformedPoint(int index) const override;
    int getPointCount() const override;
    void setPosition(const sf::Vector2f& position) override;
};

#endif //FINALPROJECTGAME_SOLID_H