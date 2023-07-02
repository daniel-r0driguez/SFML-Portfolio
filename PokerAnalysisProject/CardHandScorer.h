#ifndef SFML_TEMPLATE_CARDHANDSCORER_H
#define SFML_TEMPLATE_CARDHANDSCORER_H
#include "PokerScore.h"
#include "../PlayingCardProject/Ranks.h"
#include "ConsoleCardHand.h"
#include "CardHandSFML.h"

/**
 * This is a utility class mostly used for scoring a hands of cards.
 * Accepted object types are ConsoleCardHand and CardHandSFML.
 */
class CardHandScorer {
public:
    /**
     * Scores a ConsoleCardHand object.
     * Note: The ConsoleCardHand object should be sorted prior to attempting to score the hand.
     * @param hand the *sorted* ConsoleCardHand object to score
     * @return a PokerScore object which contains all the scores the hand was able to score
     */
    static PokerScore scorePokerHand(const ConsoleCardHand& hand);

    /**
     * Scores a CardHandSFML object.
     * Note: The CardHandSFML object should be sorted prior to attempting to score the hand.
     * @param hand the *sorted* CardHandSFML object to score
     * @return a PokerScore object which contains all the scores the hand was able to score
     */
    static PokerScore scorePokerHand(const CardHandSFML& hand);
};

#endif //SFML_TEMPLATE_CARDHANDSCORER_H
