// Daniel Rodriguez : CS003A
// Super Mario but in SFML! | Final Game Project
#ifndef FINALPROJECTGAME_ANIMATEDSPRITE_H
#define FINALPROJECTGAME_ANIMATEDSPRITE_H
#include "SFML/Graphics.hpp"
#include <cmath>

class AnimatedSpriteComponent : public sf::Drawable {
private:
    sf::Sprite _animatedSprite;
    sf::Clock _clock;
    sf::IntRect _textureRect;
    int _timeInterval;

public:
    AnimatedSpriteComponent();
    AnimatedSpriteComponent(const sf::Texture& texture, int rows, int columns);

    void setRow(int state);
    void setTexture(const sf::Texture& texture, int rows, int columns);
    const sf::Texture& getTexture() const;

    void setPosition(const sf::Vector2f& position, bool center = false);
    sf::Vector2f getPosition() const;

    void setTimeInterval(int timeInterval);
    int getTimeInterval() const;
    void animate(int state);

    sf::Vector2i getFramedSize() const;
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    void setScale(const sf::Vector2f& scale);
    void scaleToSize(const sf::Vector2f& size);

private:
    void setup(const sf::Texture& texture, int rows, int columns);
    void setupIntRect(const sf::Vector2u& size, int rows, int columns);
};

#endif //FINALPROJECTGAME_ANIMATEDSPRITE_H