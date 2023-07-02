// Daniel Rodriguez : CS003A
// Super Mario but in SFML! | Final Game Project
#ifndef FINALPROJECTGAME_HITBOXCOMPONENT_H
#define FINALPROJECTGAME_HITBOXCOMPONENT_H
#include "SFML/Graphics/RectangleShape.hpp"

class HitboxComponent : public sf::RectangleShape {
public:
    HitboxComponent();
    HitboxComponent(const sf::Vector2f& size, const sf::Vector2f& position);
};


#endif //FINALPROJECTGAME_HITBOXCOMPONENT_H
