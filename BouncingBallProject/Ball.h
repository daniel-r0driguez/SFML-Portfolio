// Daniel Rodriguez - CS003A
// Bouncing Ball
// This header file contains the class declaration of the Ball class.
#ifndef SFML_TEMPLATE_BALL_H
#define SFML_TEMPLATE_BALL_H
#include <SFML/Graphics.hpp>


class Ball : public sf::Drawable {
private:
    float xVelocity;
    float yVelocity;
    float radius;
    sf::CircleShape circle;

public:
    // Default constructor. Sets the Ball's attributes to default values of 0.
    Ball();
    // Constructs a Ball object with a set radius, x-velocity, and y-velocity.
    Ball(float radius, float xVelocity, float yVelocity);
    // Constructs a Ball object with a set radius, x-velocity, y-velocity, and color.
    Ball(float radius, float xVelocity, float yVelocity, const sf::Color &color);

    // Returns the x-velocity that the Ball object should travel.
    float getXVelocity() const;
    // Sets the x-velocity of the Ball object.
    void setXVelocity(float newXVelocity);

    // Returns the y-velocity that the Ball object should travel.
    float getYVelocity() const;
    // Sets the y-velocity of the Ball object.
    void setYVelocity(float newYVelocity);

    // Returns the radius of the Ball object.
    float getRadius() const;
    // Sets the radius of the Ball object.
    void setRadius(float newRadius);
    // Returns the diameter of the Ball Object.
    float getDiameter() const;
    // Returns a reference to the sf::CircleShape instance variable.
    sf::CircleShape &getBall();
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};

#endif //SFML_TEMPLATE_BALL_H