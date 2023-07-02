// Daniel Rodriguez : CS003A
// Super Mario but in SFML! | Final Game Project
#ifndef TRANSFORMCOMPONENT_H
#define TRANSFORMCOMPONENT_H
#include "SFML/Graphics.hpp"
#include <cmath>

class TransformComponent {
private:
    sf::Vector2f position;
    float rotation;
    float scale;

public:
    TransformComponent();
    explicit TransformComponent(const sf::Vector2f& initialPosition);
    void updatePosition(const sf::Vector2f& offset);
    void setRotation(float degrees);
    float getRotation() const;

    void setScale(float newScale);
    float getScale() const;

    const sf::Vector2f& getPosition() const;
    void setPosition(const sf::Vector2f& newPosition);
};


#endif //TRANSFORMCOMPONENT_H
