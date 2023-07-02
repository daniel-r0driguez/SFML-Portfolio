#ifndef SFML_TEMPLATE_SUIT_H
#define SFML_TEMPLATE_SUIT_H
#include <SFML/Graphics.hpp>
#include "Component.h"
#include "Suits.h"
#include "Images.h"

/**
 * This class is a visual representation of the Suit of a card.
 * Note: The default size of a Suit object is 70 x 70, so scaling should be relative to these dimensions.
 */
class Suit : public Component {
private:
    static const float DEFAULT_WIDTH;
    static const float DEFAULT_HEIGHT;
    sf::Sprite suitSprite;
    Suits _suit;

public:
    /**
     * Default constructor. If used, the Suits object is automatically set to Suits::Hearts
     */
    Suit();

    /**
     * Overloaded constructor. Constructs a new Suit object and sets the Suit to the passed in Suits enum.
     * @param suit the Suits enum which represents the desired suit
     */
    explicit Suit(Suits suit);

    /**
     * Scales the Suit object, relative to its default dimensions 70 x 70.
     * @param scaleFactor the new, desired scale factor
     */
    void setNewScale(float scaleFactor);

    /**
     * Overloaded assignment operator. Reassigns the data of the invoking Suit
     * object to that of the Suit object on its right.
     * @param otherSuit the other Suit object to copy
     * @return *this
     */
    Suit& operator = (const Suit& otherSuit);

    /**
     * @return the a Suits enum representing the suit of the Suit object
     */
    Suits getSuit() const;

    /**
     * @return a sf::Vector2f object which contains the x and y scaling of the Suit object
     */
    sf::Vector2f getSuitScale() const;

    /**
     * @return the sf::Sprite object which visually represents the Suit object
     */
    sf::Sprite& getSprite();

    /**
     * SFML draw function. Allows the Suit object to be displayed on a RenderTarget
     * @param window the sf::RenderTarget to draw to
     * @param state defines the states used for drawing to a RenderTarget
     */
    void draw(sf::RenderTarget& window, sf::RenderStates state) const override;
};
#endif //SFML_TEMPLATE_SUIT_H
