#include "SimulatePokerRounds.h"

std::vector<int> SimulatePokerRounds::simulate(int rounds)
{
    std::vector<int> scores(10);
    ConsoleDeck deck;
    deck.shuffle();
    for (int i = 0; i < rounds; ++i)
    {
        simulateRound(deck, scores);
    }
    return scores;
}

void SimulatePokerRounds::simulateRound(ConsoleDeck &deck, std::vector<int> &scores)
{
    if (deck.empty())
    {
        deck.shuffle();
    }
    ConsoleCardHand hand;
    const int CARDS_PER_HAND = 5;
    for (int i = 0; i < CARDS_PER_HAND; ++i)
    {
        hand.addCard(deck.dealCard());
    }
    hand.sortHand();
    PokerScore handScore = CardHandScorer::scorePokerHand(hand);
    for (int i = 0; i < handScore.size(); ++i)
    {
        ++scores.at(handScore[i]);
    }
}