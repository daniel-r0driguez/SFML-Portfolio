#ifndef SFML_TEMPLATE_CONSOLEDECK_H
#define SFML_TEMPLATE_CONSOLEDECK_H
#include "ConsoleCard.h"
#include <iostream>
#include <ctime>
#include <exception>

/**
 * This is a console/text representation of a deck of cards.
 */
class ConsoleDeck {
private:
    static const int DECK_SIZE = 52;
    static const ConsoleCard NULL_CARD;
    ConsoleCard deck[DECK_SIZE];
    int cardIndex;

public:
    /**
     * Default constructor. Automatically loads all the cards usually found in a deck of cards.
     * All 13 ranks of each of the 4 suits are loaded.
     */
    ConsoleDeck();

    /**
     * Shuffles the deck of cards.
     */
    void shuffle();

    /**
     * @return true if the deck has no more cards to deal, false otherwise
     */
    bool empty() const;

    /**
     * @return the number of cards left to deal
     */
    int getNumOfCardsLeft() const;

    /**
     * @return a ConsoleCard object which was previously available in the deck
     */
    const ConsoleCard& dealCard();

    /**
     * Returns a ConsoleCard object at a certain index.
     * @param index the index to look into
     * @return the ConsoleCard object at the provided index
     */
    const ConsoleCard& getCardAt(int index) const;

    /**
     * Overloaded insertion operator. Outputs the ConsoleDeck data into a stream.
     * @param out the std::ostream object
     * @param deck the ConsoleDeck object to output
     * @return parameter out
     */
    friend std::ostream& operator<<(std::ostream& out, const ConsoleDeck& deck);

private:
    /**
     * Private helper function which loads all 52 cards necessary for a deck.
     */
    void loadCards();

    /**
     * Swaps the content of two indexes in the array containing the ConsoleCard objects.
     * @param cards the pointer to the array
     * @param index1 the first index to consider for swapping
     * @param index2 the second index to consider for swapping
     */
    static void swap(ConsoleCard *cards, int index1, int index2);
};


#endif //SFML_TEMPLATE_CONSOLEDECK_H
