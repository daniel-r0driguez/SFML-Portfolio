#ifndef POKERANALYSIS_SIMULATEPOKERROUNDS_H
#define POKERANALYSIS_SIMULATEPOKERROUNDS_H
#include "ConsoleDeck.h"
#include "ConsoleCardHand.h"
#include "CardHandScorer.h"
#include <vector>

/**
 * Utility class which allows for the simulation of poker rounds.
 */
class SimulatePokerRounds {
public:
    /**
     * Simulates poker rounds a desired amount of times.
     * @param rounds the number of times to simulate a poker round
     * @return a std::vector representing the cumulative number of times a score was achieved
     */
    static std::vector<int> simulate(int rounds);

private:
    /**
     * Private helper function which simulates a single round of poker.
     * @param deck the deck of cards to deal cards from
     * @param scores the std::vector which will be updated on the latest achieved scores
     */
    static void simulateRound(ConsoleDeck& deck, std::vector<int>& scores);
};


#endif //POKERANALYSIS_SIMULATEPOKERROUNDS_H
