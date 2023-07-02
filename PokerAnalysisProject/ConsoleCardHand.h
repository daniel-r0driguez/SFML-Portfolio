#ifndef SFML_TEMPLATE_CONSOLECARDHAND_H
#define SFML_TEMPLATE_CONSOLECARDHAND_H
#include <vector>
#include <iostream>
#include "ConsoleCard.h"

/**
 * This is a console/text only representation of a hand of cards.
 */
class ConsoleCardHand {
private:
    std::vector<ConsoleCard> _hand;

public:
    /**
     * Default constructor. Allocates enough memory for five ConsoleCard objects.
     */
    ConsoleCardHand();

    /**
     * Clears the hand of cards. After this function call the hand is empty.
     */
    void clearHand();

    /**
     * Adds a new ConsoleCard object to the hand of cards.
     * @param card the new card to add
     */
    void addCard(const ConsoleCard& card);

    /**
     * Replaces a ConsoleCard object at a certain index.
     * @param index the index to replace
     * @param card the new card which will replace the old card
     */
    void replaceCardAt(int index, const ConsoleCard& card);

    /**
     * Returns a modifiable reference to the ConsoleCard object at a certain index.
     * @param index the index to look into
     * @return the ConsoleCard object at the provided index
     */
    ConsoleCard& getCardAt(int index);

    /**
     * Returns a constant reference to the ConsoleCard object at a certain index.
     * @param index the index to look into
     * @return the ConsoleCard object at the provided index
     */
    const ConsoleCard& getCardAt(int index) const;

    /**
     * @return a constant reference to vector holding the collection of ConsoleCard objects
     */
    const std::vector<ConsoleCard>& getCards() const;

    /**
     * Overloaded insertion operator. Outputs the ConsoleCard hand data to a stream.
     * @param out the std::ostream object
     * @param cardHand the hand of cards to output
     * @return parameter out
     */
    friend std::ostream& operator << (std::ostream& out, const ConsoleCardHand& cardHand);

    /**
     * @return the size of the hand of cards
     */
    int size() const;
    /**
     * Sorts the hand of cards, from lowest to highest in ranking.
     */
    void sortHand();

private:
    // General quickSort algorithm set-up.
    static void quickSort(std::vector<ConsoleCard>& hand, int left, int right);
    static int partition(std::vector<ConsoleCard>& hand, int left, int right);
    static void swap(ConsoleCard& card1, ConsoleCard& card2);
};

#endif //SFML_TEMPLATE_CONSOLECARDHAND_H