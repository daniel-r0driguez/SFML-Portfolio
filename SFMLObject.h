#ifndef PORTFOLIO_PROJECT_SFMLOBJECT_H
#define PORTFOLIO_PROJECT_SFMLOBJECT_H
#include "SFML/Graphics.hpp"

class SFMLObject : public sf::Drawable {
public:
    virtual sf::Vector2f getPosition() const = 0;
    virtual void setPosition(const sf::Vector2f& position) = 0;
    virtual sf::FloatRect getGlobalBounds() const = 0;
    virtual sf::FloatRect getLocalBounds() const = 0;
    virtual void eventHandler(sf::RenderWindow& target, sf::Event event) const = 0;
    virtual void update(float dt) const = 0;
};


#endif //PORTFOLIO_PROJECT_SFMLOBJECT_H
