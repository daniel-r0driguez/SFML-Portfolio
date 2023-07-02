#ifndef SFML_TEMPLATE_SFMLGRID_H
#define SFML_TEMPLATE_SFMLGRID_H
#include "SFML/Graphics.hpp"
#include "Grid.h"

// This class is a child class of the Grid class. Therefore, it inherits all the dynamic allocation of arrays.
// It supports the most common functions for classes inherited from the sf::Drawable class.
template <typename T>
class SFMLGrid : public Grid<T>, public sf::Drawable {
private:
    float _velocity = 10;
public:
    // Getters
    sf::Vector2f getPosition();

    // SFML Functions.
    // Draws the entire SFMLGrid object to a window.
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    // Sets the position of the SFMLGrid object.
    void setPosition(float xPos, float yPos);
    // Sets the spacing between each shape object in the SFMLGrid.
    void setSpacingBetween();
    // Sets specific spacing between each shape object in the SFMLGrid.
    void setSpacingBetween(float xSpacing, float ySpacing);
    // Sets the size of each element in the SFMLGrid.
    void setGridElementSize(const sf::Vector2f& size);
    // Assigns random colors to every element in the SFMLGrid.
    void randomColors();
    // Handles keyboard events.
    void eventHandler(sf::RenderWindow& window, sf::Event event);
};


#include "SFMLGrid.cpp"
#endif //SFML_TEMPLATE_SFMLGRID_H