#include "CardHandScorer.h"

PokerScore CardHandScorer::scorePokerHand(const ConsoleCardHand& hand)
{
    bool isFlush = true;
    bool isStraight = true;
    int curRankStreak = 1;
    int highestRankStreak = 1;
    int pairCount = 0;
    bool skipThisCard = false;
    for (int i = 1; i < hand.size(); ++i)
    {
        const ConsoleCard& curCard = hand.getCardAt(i);
        // If any card does not have the same suit as the first card, it is not a flush.
        if (isFlush && curCard.getSuit() != hand.getCardAt(0).getSuit())
        {
            isFlush = false;
        }
        // If the card's rank on the left of the current card is not the difference of (current card's rank - 1)...
        // ...the hand can't score a Straight.
        if (isStraight && curCard.getRank() != hand.getCardAt(i - 1).getRank() + 1)
        {
            isStraight = false;
        }
        // If the card on the left has the same rank as the current card, increment the rank streak variable.
        if (curCard.getRank() == hand.getCardAt(i - 1).getRank())
        {
            ++curRankStreak;
            if (!skipThisCard)
            {
                ++pairCount;
                skipThisCard = true;
            }
            else
            {
                skipThisCard = false;
            }
        }
        else
        {
            skipThisCard = false;
            curRankStreak = 1;
        }
        if (curRankStreak > highestRankStreak)
        {
            highestRankStreak = curRankStreak;
        }
    }

    PokerScore score;
    if (isStraight && isFlush && hand.getCardAt(0).getRank() == Ranks::TEN)
    {
        score += PokerScore::Scores::ROYAL_FLUSH;
    }
    if (isStraight && isFlush)
    {
        score += PokerScore::Scores::STRAIGHT_FLUSH;
    }
    if (highestRankStreak >= 4)
    {
        score += PokerScore::Scores::FOUR_OF_A_KIND;
    }
    if (highestRankStreak == 3 && pairCount == 2)
    {
        score += PokerScore::Scores::FULL_HOUSE;
    }
    if (isFlush)
    {
        score += PokerScore::Scores::FLUSH;
    }
    if (isStraight)
    {
        score += PokerScore::Scores::STRAIGHT;
    }
    if (highestRankStreak >= 3)
    {
        score += PokerScore::Scores::THREE_OF_A_KIND;
    }
    if (pairCount >= 2)
    {
        score += PokerScore::Scores::TWO_PAIR;
    }
    if (pairCount >= 1)
    {
        score += PokerScore::Scores::ONE_PAIR;
    }
    score += PokerScore::Scores::HIGH_CARD;
    return score;
}

PokerScore CardHandScorer::scorePokerHand(const CardHandSFML& hand)
{
    bool isFlush = true;
    bool isStraight = true;
    int curRankStreak = 1;
    int highestRankStreak = 1;
    int pairCount = 0;
    bool skipThisCard = false;
    for (int i = 1; i < hand.size(); ++i)
    {
        const CardSFML& curCard = hand.getCardAt(i);
        // If any card does not have the same suit as the first card, it is not a flush.
        if (isFlush && curCard.getSuit() != hand.getCardAt(0).getSuit())
        {
            isFlush = false;
        }
        // If the card's rank on the left of the current card is not the difference of (current card's rank - 1)...
        // ...the hand can't score a Straight.
        if (isStraight && curCard.getRank() != hand.getCardAt(i - 1).getRank() + 1)
        {
            isStraight = false;
        }
        // If the card on the left has the same rank as the current card, increment the rank streak variable.
        if (curCard.getRank() == hand.getCardAt(i - 1).getRank())
        {
            ++curRankStreak;
            if (!skipThisCard)
            {
                ++pairCount;
                skipThisCard = true;
            }
            else
            {
                skipThisCard = false;
            }
        }
        else
        {
            skipThisCard = false;
            curRankStreak = 1;
        }
        if (curRankStreak > highestRankStreak)
        {
            highestRankStreak = curRankStreak;
        }
    }

    PokerScore score;
    if (isStraight && isFlush && hand.getCardAt(0).getRank() == Ranks::TEN)
    {
        score += PokerScore::Scores::ROYAL_FLUSH;
    }
    if (isStraight && isFlush)
    {
        score += PokerScore::Scores::STRAIGHT_FLUSH;
    }
    if (highestRankStreak >= 4)
    {
        score += PokerScore::Scores::FOUR_OF_A_KIND;
    }
    if (highestRankStreak == 3 && pairCount == 2)
    {
        score += PokerScore::Scores::FULL_HOUSE;
    }
    if (isFlush)
    {
        score += PokerScore::Scores::FLUSH;
    }
    if (isStraight)
    {
        score += PokerScore::Scores::STRAIGHT;
    }
    if (highestRankStreak >= 3)
    {
        score += PokerScore::Scores::THREE_OF_A_KIND;
    }
    if (pairCount >= 2)
    {
        score += PokerScore::Scores::TWO_PAIR;
    }
    if (pairCount >= 1)
    {
        score += PokerScore::Scores::ONE_PAIR;
    }
    score += PokerScore::Scores::HIGH_CARD;
    return score;
}