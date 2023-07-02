#ifndef SFML_TEMPLATE_POKERSCORE_H
#define SFML_TEMPLATE_POKERSCORE_H
#include <vector>
#include <iostream>

/**
 * This class contains a collection of Poker scores that a potential card hand could achieve.
 */
class PokerScore {
public:
    // Static variables/Enums
    enum Scores {
        ROYAL_FLUSH, // A, K, Q, J, 10, all the same suit.
        STRAIGHT_FLUSH, // five cards of the same suit and consecutive ranking
        FOUR_OF_A_KIND, // four cards of the same ranking
        FULL_HOUSE, // three cards of the same rank along with two cards of the same rank
        FLUSH, // five cards of the same suit
        STRAIGHT, // five cards in consecutive ranking
        THREE_OF_A_KIND, // three cards of the same rank
        TWO_PAIR, // two cards of the same rank along with another two cards of the same rank
        ONE_PAIR, // two cards of the same rank
        HIGH_CARD, // highest card in the player’s hand
        LAST_POKER_SCORE // Do not use. Not a poker score.
        };

    static const std::string SCORES_STR[LAST_POKER_SCORE];

    /**
     * Default constructor.
     */
    PokerScore();

    /**
     * Adds a new PokerScore::Scores enum to the PokerScore object.
     * @param score the new PokerScore::Scores enum to push
     */
    void operator += (PokerScore::Scores score);

    /**
     * Overloaded assignment operator. Reassigns the content of the invoking PokerScore object to
     * the PokerScore object on its right.
     * @param p the other PokerScore object to copy from
     * @return *this
     */
    PokerScore& operator = (const PokerScore& p);

    /**
     * Overloaded subscript operator. Returns a PokerScore::Scores enum at the provided index
     * @param index the index to look into
     * @return a PokerScore::Scores enum at the provided index
     */
    PokerScore::Scores operator[] (unsigned int index);

    /**
     * Overloaded insertion operator. Outputs the PokerScore object data to a stream.
     * @param out the std::ostream object
     * @param scores the PokerScore object to output
     * @return parameter out
     */
    friend std::ostream& operator << (std::ostream& out, const PokerScore& scores);

    /**
     * @return a std::string representation of the PokerScore object
     */
    std::string toString();

    /**
     * @return the current size of the PokerScore object
     */
    int size();

private:
    std::vector<Scores> _scores;
};


#endif //SFML_TEMPLATE_POKERSCORE_H
