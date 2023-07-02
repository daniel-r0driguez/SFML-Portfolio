#ifndef SFML_TEMPLATE_CARDHANDSFML_H
#define SFML_TEMPLATE_CARDHANDSFML_H
#include <vector>
#include "../PlayingCardProject/CardSFML.h"
#include "../PlayingCardProject/Component.h"

/**
 * This is a visual, drawable version of the ConsoleCardHand object.
 * It contains a hand of CardSFML objects, able to be rendered as well.
 * Using the SFML library, the entire hand can be rendered on a window.
 */
class CardHandSFML : public Component {
private:
    // Member variables
    std::vector<CardSFML> _hand;
    float _spacingBetween;

public:
    /**
     * Default Constructor. Spacing between cards is set to 0.
     */
    CardHandSFML();

    /**
     * Clears the current hand of cards.
     */
    void clearHand();

    /**
     * Adds a new card to the current hand of cards.
     * @param card the card to add
     */
    void addCard(const CardSFML& card);

    /**
     * Replaces the card at the nth index.
     * @param index the position of the card to replace
     * @param newCard the new card replacing the old card
     */
    void replaceCardAt(int index, const CardSFML& newCard);

    /**
     * Returns a modifiable reference of the card at the nth index.
     * @param index the position to grab the card from
     * @return a modifiable reference to CardSFML object
     */
    CardSFML& getCardAt(int index);

    /**
     * Returns a constant, read-only, reference of the card at the nth index.
     *  @param index the position to grab the card from
     *  @return a constant reference to CardSFML object
     */
    const CardSFML& getCardAt(int index) const;

    /**
     * @return a constant reference to a vector containing the CardSFML objects
     */
    const std::vector<CardSFML>& getCards() const;

    /**
     * @return the current number of cards in the hand
     */
    int size() const;

    /**
     * Sorts the hand of cards.
     */
    void sortHand();

    // SFML functions!!!
    /**
     * Sets the spacing between the cards when being drawn.
     * @param spacing the desired spacing between cards
     */
    void setSpacing(float spacing);

    /**
     * Sets the scaling of the CardHandSFML object. This means every card in the hand is set to the new scale.
     * @param scale the new scale to apply to the hand of cards
     */
    void setCardScale(float scale);

    /**
     * @return the bounding width of the hand of cards
     */
    float getWidth() const;

    /**
     * @return the bounding height of the hand of cards
     */
    float getHeight() const;

    /**
     * @return the position (top-left corner) of the first card in the hand of cards.
     */
    sf::FloatRect getPosition() const;

    /**
     * Sets the position of the hand of cards.
     * @param xPos the new x-position of the hand of cards
     * @param yPos the new y-position of the hand of cards
     */
    void setPosition(float xPos, float yPos);

    /**
     * SFML overridden draw function.
     * @param window the sf::RenderTarget to be drawn on
     * @param state defines the states used for drawing to a RenderTarget
     */
    void draw(sf::RenderTarget& window, sf::RenderStates state) const override;

private:
    /**
     * Private helper function which updates the positioning of all the cards relative to each other.
     */
    void update();

    // Basic quicksort algorithm set-up
    static void quickSort(std::vector<CardSFML>& hand, int left, int right);
    static int partition(std::vector<CardSFML>& hand, int left, int right);
    static void swap(CardSFML& card1, CardSFML& card2);
};
#endif //SFML_TEMPLATE_CARDHANDSFML_H