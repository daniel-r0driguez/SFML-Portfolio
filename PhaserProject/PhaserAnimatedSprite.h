#ifndef SFML_TUTORIAL_ANIMATEDSPRITE_H
#define SFML_TUTORIAL_ANIMATEDSPRITE_H
#include "SFML/Graphics.hpp"
#include "PhaserEventHandleable.h"
#include "cmath"

enum Direction {DOWN, LEFT, RIGHT, UP};

class PhaserAnimatedSprite : public PhaserComponent {
private:
    sf::Sprite sprite;
    sf::Clock clock;
    sf::IntRect textureRect;
    /// Physics stuff
    Direction direction;
    sf::Vector2f velocity;
    float friction;
    float maxSpeed;

    sf::Keyboard::Key _upKey = sf::Keyboard::Key::Up;
    sf::Keyboard::Key _downKey = sf::Keyboard::Key::Down;
    sf::Keyboard::Key _leftKey = sf::Keyboard::Key::Left;
    sf::Keyboard::Key _rightKey = sf::Keyboard::Key::Right;
public:
    void setUpKey(sf::Keyboard::Key upKey);

    void setDownKey(sf::Keyboard::Key downKey);

    void setLeftKey(sf::Keyboard::Key leftKey);

    void setRightKey(sf::Keyboard::Key rightKey);

private:
    int _timeInterval = 250;
    float acceleration;
    void move(float dt); ///
    void applyFriction(float dt); ///
    void setup(const sf::Texture& texture, int rows, int columns);
    void setupIntRect(const sf::Vector2u& size, int rows, int columns);


public:
    PhaserAnimatedSprite();
    PhaserAnimatedSprite(const sf::Texture& texture, int rows, int columns);
    void animate();
    void setTimeInterval(int timeInterval);
    int getTimeInterval() const;
    void eventHandler(sf::RenderWindow &window, sf::Event event) override;
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    void update(float dt) override;
};
#endif //SFML_TUTORIAL_ANIMATEDSPRITE_H