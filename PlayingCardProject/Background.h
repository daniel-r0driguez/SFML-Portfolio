#ifndef SFML_TEMPLATE_BACKGROUND_H
#define SFML_TEMPLATE_BACKGROUND_H
#include <SFML/Graphics.hpp>
#include "Component.h"

/**
 * This Background class is specifically designed for a Card Object.
 * It has a default size of 150 (width) by 210 (height).
 * However, scaling may be applied and effectively resize the card while sticking to
 * the 5 : 7 ratio of normal playing cards.
 */
class Background : public Component {
private:
    // Some static variables for defaulting the size of a Background object.
    static const float DEFAULT_WIDTH;
    static const float DEFAULT_HEIGHT;
    static const float DEFAULT_SCALE;
    static const float DEFAULT_OUTLINE_THICKNESS;

    // Member Variables.
    sf::RectangleShape background;
    float scale;

public:
    /**
     * Default Constructor. Any Background object created with the default constructor will have a size of
     * 150 (width) by 210 (height).
     */
    Background();
    /**
     * Overloaded constructor. Sets the Background object's position and scaling accordingly.
     * @param xPosition the x-position to be set
     * @param yPosition the y-position to be set
     * @param scaleFactor the scaling to apply to the Background object
     */
    Background(float xPosition, float yPosition, float scaleFactor);

    /**
     * @return the current scale of the Background object.
     */
    float getScale() const;
    /**
     * Sets the object to a new scale.
     * @param scaleFactor the desired scaling to apply to the Background object
     */
    void setNewScale(float scaleFactor);
    /**
     * @return the position, as well as the dimensions, of the Background object.
     */
    sf::FloatRect getPosition() const;
    /**
     * Set the object to a new position in the 2D environment.
     * @param xPosition the new x-position of the Background
     * @param yPosition the new y-position of the Background
     */
    void setPosition(float xPosition, float yPosition);
    /**
     * @return a constant reference to the sf::RectangleShape object.
     */
    const sf::RectangleShape& getRectangleShape();

    /**
     * Overloaded assignment operator. Reassigns the invoking Background to have the same values as
     * the Background object on the right of the operator.
     * @param background the Background object to copy for reassignment
     */
    Background& operator = (const Background& background);

    /**
     * SFML draw function needed to display the Background object in the SFML environment.
     * @param window the sf::RenderTarget to be drawn on
     * @param state defines the states used for drawing to a RenderTarget
     */
    void draw(sf::RenderTarget& window, sf::RenderStates state) const override;

private:
    /**
     * Private helper function which sets the size of the Background object.
     * @param width the new width of the Background
     * @param height the new height of the Background
     */
    void setSize(float width, float height);
};


#endif //SFML_TEMPLATE_BACKGROUND_H