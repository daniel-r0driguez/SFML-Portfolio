#ifndef SFML_TEMPLATE_SETHAND_H
#define SFML_TEMPLATE_SETHAND_H
#include "CardHandSFML.h"
#include "CardHandScorer.h"
#include "PokerScore.h"

/**
 * This is a utility class necessary for setting a CardHandSFML object to a certain hand of cards for testing.
 */
class SetHand
{
public:
    /**
     * Sets the passed in CardHandSFML object to a desired hand. The hand is automatically sorted in this function call.
     * @param desiredHandScore a PokerScore::Scores enum which represents the highest score we want the hand to achieve
     * @param hand the CardHandSFML object to modify
     */
    static void setHandTo(PokerScore::Scores desiredHandScore, CardHandSFML& hand);

private:
    // These are private helper functions which set the CardHandSFML object to a desired card hand.
    // I think the function names are self-explanatory.
    static void setRoyalFlushHand(CardHandSFML& hand);
    static void setStraightFlushHand(CardHandSFML& hand);
    static void setFourOfAKindHand(CardHandSFML& hand);
    static void setFullHouseHand(CardHandSFML& hand);
    static void setFlushHand(CardHandSFML& hand);
    static void setStraightHand(CardHandSFML& hand);
    static void setThreeOfAKindHand(CardHandSFML& hand);
    static void setTwoPairHand(CardHandSFML& hand);
    static void setOnePairHand(CardHandSFML& hand);
    static void setHighCardHand(CardHandSFML& hand);
};

#endif //SFML_TEMPLATE_SETHAND_H