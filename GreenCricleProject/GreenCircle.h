#ifndef GREENCIRCLEPROJECT_GREENCIRCLE_H
#define GREENCIRCLEPROJECT_GREENCIRCLE_H
#include "SFML/Graphics.hpp"
#include "../SFMLObject.h"

class GreenCircle : public SFMLObject {
private:
    sf::CircleShape _circle;

public:
    GreenCircle();
    explicit GreenCircle(float radius);
    sf::Vector2f getPosition() const override;
    void setPosition(const sf::Vector2f& position) override;
    sf::FloatRect getGlobalBounds() const override;

    sf::FloatRect getLocalBounds() const override;

    void eventHandler(sf::RenderWindow& target, sf::Event event) const override;
    void update(float dt) const override;
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};

#endif //GREENCIRCLEPROJECT_GREENCIRCLE_H