#ifndef SFML_TEMPLATE_CONSOLECARD_H
#define SFML_TEMPLATE_CONSOLECARD_H
#include "../PlayingCardProject/Ranks.h"
#include "../PlayingCardProject/Suits.h"
#include <string>
#include <iostream>

/**
 * This is a console/text only representation of a playing card.
 */
class ConsoleCard {
private:
    // Member variables
    Ranks _rank;
    Suits _suit;

public:
    /**
     * Default constructor. Do not use this constructor unless you want an illegal card. It sets the rank and suit of the card to
     * Ranks::LAST_RANK and Suits::LAST_SUIT, indicating this is not a usable playing card.
     */
    ConsoleCard();
    /**
     * Overloaded constructor. This constructor should be used more often than not when creating new ConsoleCard objects.
     * @param rank the rank of the card
     * @param suit the suit of the card
     */
    ConsoleCard(Ranks rank, Suits suit);
    /**
     * Copy constructor. Creates a new ConsoleCard object which copies the state of the ConsoleCard object.
     * @param copy the ConsoleCard object to copy from
     */
    ConsoleCard(const ConsoleCard& copy);
    /**
     * @returns a Ranks enum representing the rank of the card.
     */
    Ranks getRank() const;
    /**
     * @return a Suits enum representing the suit of the card.
     */
    Suits getSuit() const;
    /**
     * @return the rank of the card in std::string form
     */
    std::string getRankStr() const;
    /**
     * @return the suit of the card in std::string form
     */
    std::string getSuitStr() const;
    /**
     * Sets the rank of the ConsoleCard.
     * @param rank the new rank to set
     */
    void setRank(Ranks rank);
    /**
     * Sets the suit of the ConsoleCard.
     * @param suit the new suit to set
     */
    void setSuit(Suits suit);
    /**
     * Overloaded assignment operator.
     * Reassigns the state of the invoking object to copy the ConsoleCard object on its right.
     * @param card the ConsoleCard object to copy from
     * @return *this
     */
    ConsoleCard& operator = (const ConsoleCard& card);
    /**
     * Overloaded insertion operator which outputs the state of the ConsoleCard to a stream.
     * @param out a reference to the std::ostream object to insert to
     * @param card the ConsoleCard object to output
     * @return parameter out
     */
    friend std::ostream& operator << (std::ostream& out, const ConsoleCard& card);
};

#endif //SFML_TEMPLATE_CONSOLECARD_H