#include "SetHand.h"

void SetHand::setHandTo(PokerScore::Scores desiredHandScore, CardHandSFML& hand)
{
    switch (desiredHandScore)
    {
        case PokerScore::Scores::ROYAL_FLUSH:
            setRoyalFlushHand(hand);
            break;
        case PokerScore::STRAIGHT_FLUSH:
            setStraightFlushHand(hand);
            break;
        case PokerScore::FOUR_OF_A_KIND:
            setFourOfAKindHand(hand);
            break;
        case PokerScore::FULL_HOUSE:
            setFullHouseHand(hand);
            break;
        case PokerScore::FLUSH:
            setFlushHand(hand);
            break;
        case PokerScore::STRAIGHT:
            setStraightHand(hand);
            break;
        case PokerScore::THREE_OF_A_KIND:
            setThreeOfAKindHand(hand);
            break;
        case PokerScore::TWO_PAIR:
            setTwoPairHand(hand);
            break;
        case PokerScore::ONE_PAIR:
            setOnePairHand(hand);
            break;
        case PokerScore::HIGH_CARD:
            setHighCardHand(hand);
            break;
        case PokerScore::LAST_POKER_SCORE:
            break;
    }
    hand.sortHand();
}

void SetHand::setRoyalFlushHand(CardHandSFML &hand)
{
    hand.addCard(CardSFML(Ranks::TEN, Suits::HEARTS));
    hand.addCard(CardSFML(Ranks::QUEEN, Suits::HEARTS));
    hand.addCard(CardSFML(Ranks::ACE, Suits::HEARTS));
    hand.addCard(CardSFML(Ranks::KING, Suits::HEARTS));
    hand.addCard(CardSFML(Ranks::JACK, Suits::HEARTS));
}

void SetHand::setStraightFlushHand(CardHandSFML &hand)
{
    hand.addCard(CardSFML(Ranks::TEN, Suits::SPADES));
    hand.addCard(CardSFML(Ranks::NINE, Suits::SPADES));
    hand.addCard(CardSFML(Ranks::EIGHT, Suits::SPADES));
    hand.addCard(CardSFML(Ranks::SEVEN, Suits::SPADES));
    hand.addCard(CardSFML(Ranks::SIX, Suits::SPADES));
}

void SetHand::setFourOfAKindHand(CardHandSFML &hand)
{
    hand.addCard(CardSFML(Ranks::TWO, Suits::CLUBS));
    hand.addCard(CardSFML(Ranks::SEVEN, Suits::HEARTS));
    hand.addCard(CardSFML(Ranks::TWO, Suits::SPADES));
    hand.addCard(CardSFML(Ranks::TWO, Suits::DIAMONDS));
    hand.addCard(CardSFML(Ranks::TWO, Suits::HEARTS));
}

void SetHand::setFullHouseHand(CardHandSFML &hand)
{
    hand.addCard(CardSFML(Ranks::THREE, Suits::DIAMONDS));
    hand.addCard(CardSFML(Ranks::SEVEN, Suits::HEARTS));
    hand.addCard(CardSFML(Ranks::SEVEN, Suits::HEARTS));
    hand.addCard(CardSFML(Ranks::SEVEN, Suits::CLUBS));
    hand.addCard(CardSFML(Ranks::THREE, Suits::CLUBS));
}

void SetHand::setFlushHand(CardHandSFML &hand)
{
    hand.addCard(CardSFML(Ranks::TWO, Suits::CLUBS));
    hand.addCard(CardSFML(Ranks::FOUR, Suits::CLUBS));
    hand.addCard(CardSFML(Ranks::NINE, Suits::CLUBS));
    hand.addCard(CardSFML(Ranks::FIVE, Suits::CLUBS));
    hand.addCard(CardSFML(Ranks::ACE, Suits::CLUBS));
}

void SetHand::setStraightHand(CardHandSFML &hand)
{
    hand.addCard(CardSFML(Ranks::TWO, Suits::SPADES));
    hand.addCard(CardSFML(Ranks::SIX, Suits::HEARTS));
    hand.addCard(CardSFML(Ranks::THREE, Suits::DIAMONDS));
    hand.addCard(CardSFML(Ranks::FIVE, Suits::HEARTS));
    hand.addCard(CardSFML(Ranks::FOUR, Suits::SPADES));
}

void SetHand::setThreeOfAKindHand(CardHandSFML &hand)
{
    hand.addCard(CardSFML(Ranks::TEN, Suits::DIAMONDS));
    hand.addCard(CardSFML(Ranks::TEN, Suits::SPADES));
    hand.addCard(CardSFML(Ranks::TEN, Suits::CLUBS));
    hand.addCard(CardSFML(Ranks::KING, Suits::HEARTS));
    hand.addCard(CardSFML(Ranks::NINE, Suits::CLUBS));
}

void SetHand::setTwoPairHand(CardHandSFML &hand)
{
    hand.addCard(CardSFML(Ranks::FOUR, Suits::HEARTS));
    hand.addCard(CardSFML(Ranks::FOUR, Suits::DIAMONDS));
    hand.addCard(CardSFML(Ranks::ACE, Suits::HEARTS));
    hand.addCard(CardSFML(Ranks::SEVEN, Suits::SPADES));
    hand.addCard(CardSFML(Ranks::SEVEN, Suits::CLUBS));
}

void SetHand::setOnePairHand(CardHandSFML &hand)
{
    hand.addCard(CardSFML(Ranks::EIGHT, Suits::SPADES));
    hand.addCard(CardSFML(Ranks::EIGHT, Suits::CLUBS));
    hand.addCard(CardSFML(Ranks::ACE, Suits::SPADES));
    hand.addCard(CardSFML(Ranks::KING, Suits::DIAMONDS));
    hand.addCard(CardSFML(Ranks::JACK, Suits::DIAMONDS));
}

void SetHand::setHighCardHand(CardHandSFML &hand)
{
    hand.addCard(CardSFML(Ranks::TWO, Suits::CLUBS));
    hand.addCard(CardSFML(Ranks::QUEEN, Suits::SPADES));
    hand.addCard(CardSFML(Ranks::FOUR, Suits::DIAMONDS));
    hand.addCard(CardSFML(Ranks::KING, Suits::DIAMONDS));
    hand.addCard(CardSFML(Ranks::FIVE, Suits::HEARTS));
}






