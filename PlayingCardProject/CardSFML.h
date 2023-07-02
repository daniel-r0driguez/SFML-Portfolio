// Daniel Rodriguez - CS003A
// In-Class Lab (Cards Lab)
#ifndef SFML_TEMPLATE_CARDSFML_H
#define SFML_TEMPLATE_CARDSFML_H
#include "Suit.h"
#include "Rank.h"
#include "Background.h"
#include "Component.h"

/**
 * This is a visual and drawable version of the ConsoleCard class.
 */
class CardSFML : public Component {
private:
    // Member functions.
    static const unsigned int DEFAULT_SCALE;
    Background background;
    Rank _rank;
    Suit _suit;
    float scale;

public:
    /**
     * Default constructor. Constructs a default CardSFML object where all member variables are set to default values.
     * Recall that default Background objects are set to a size of 150 (width) by 210 (height), meaning
     * the CardSFML object will adjust accordingly to that size.
     */
    CardSFML();
    /**
     * Copy Constructor. Constructs a new CardSFML object by copying the state of of the passed in CardSFML object.
     * @param otherCard the CardSFML object to copy
     */
    CardSFML(const CardSFML& otherCard);
    /**
     * Constructs a default CardSFML object with a given Rank (Ex. ACE, KING, QUEEN, etc...) and Suit (Ex. HEARTS, CLUBS, etc..)
     */
    CardSFML(Ranks rank, Suits suit);
    /**
     * @return a Ranks enum representing the rank of the card
     */
    Ranks getRank() const;
    /**
     * @return a Suits enum representing the suit of the card
     */
    Suits getSuit() const;
    /**
     * @return a sf::FloatRect object which contains a collection of other properties such as left(x), top(y), width, and height.
     */
    sf::FloatRect getPosition() const;
    /**
     * Sets the position of the CardSFML object.
     */
    void setPosition(float xPosition, float yPosition);
    /**
     * Updates the position of the card by moving it by an offset.
     * @param offSetX the x-offset to move
     * @param offSetY the y-offset to move
     */
    void move(float offSetX, float offSetY);

    /**
     * Sets the scale of the CardSFML object. (Default size of a CardSFML object is 150 by 210).
     * @param newScale the new scale to be applied to the card, relative to the default size of 150 by 210.
     */
    void setScale(float newScale);

    /**
     * Overloaded assignment operator. Reassigns the invoking object to copy the state of the CardSFML object
     * on the right of the operator.
     * @param card the CardSFML object to copy
     * @return returns *this
     */
    CardSFML& operator = (const CardSFML& card);

    /**
     * SFML overridden draw function. Allows the CardSFML object to be displayed on a window.
     * @param window the sf::RenderTarget to be drawn on
     * @param state defines the states used for drawing to a RenderTarget
     */
    void draw(sf::RenderTarget& window, sf::RenderStates state) const override;


private:
    /**
     * Private helper function which sets the Rank color to match to Suit color.
     * @param suit the Suit enum to take into account for picking the color.
     */
    void setRankColor(Suits suit);
    /**
     * Updates the other drawable objects (Rank, and Suit) positions relative to Background object's current position.
     */
    void update();
    /**
     * Helper function which returns the absolute value of a float.
     * @param num the float in absolute form
     */
    static float absFloat(float num);
};

#endif //SFML_TEMPLATE_CARDSFML_H