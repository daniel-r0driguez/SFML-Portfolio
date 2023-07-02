#include "ConsoleDeck.h"

const ConsoleCard ConsoleDeck::NULL_CARD = ConsoleCard(Ranks::LAST_RANK, Suits::LAST_SUIT);

ConsoleDeck::ConsoleDeck()
{
    srand(time(nullptr));
    this->cardIndex = 0;
    loadCards();
}

void ConsoleDeck::shuffle()
{
    int r;
    for (int i = 0; i < DECK_SIZE; ++i)
    {
        // The next random card to swap with.
        r = i + (rand() % (DECK_SIZE - i));
        swap(this->deck, i, r);
    }
    this->cardIndex = 0;
}

bool ConsoleDeck::empty() const
{
    if (this->cardIndex >= 52)
    {
        return true;
    }
    return false;
}

const ConsoleCard& ConsoleDeck::dealCard()
{
    if (empty())
    {
        return ConsoleDeck::NULL_CARD;
    }
    return this->deck[this->cardIndex++];
}

int ConsoleDeck::getNumOfCardsLeft() const
{
    return DECK_SIZE - this->cardIndex;
}

const ConsoleCard& ConsoleDeck::getCardAt(int index) const
{
    if (index < 0 || index > ConsoleDeck::DECK_SIZE - 1)
    {
        throw std::out_of_range(std::to_string(index) + " is out of bounds for deck indexes 0 - "+
        std::to_string(ConsoleDeck::DECK_SIZE - 1));
    }
    return this->deck[index];
}

std::ostream& operator << (std::ostream& out, const ConsoleDeck& deck)
{
    for (int i = 0; i < ConsoleDeck::DECK_SIZE; ++i)
    {
        out << i + 1 << ": " << deck.getCardAt(i) << "\n";
    }
    return out;
}

void ConsoleDeck::loadCards()
{
    int loadIndex = 0;
    for (int suit = 0; suit < Suits::LAST_SUIT; ++suit)
    {
        for (int rank = 0; rank < Ranks::LAST_RANK; ++rank)
        {
            this->deck[loadIndex] = ConsoleCard(static_cast<Ranks>(rank), static_cast<Suits>(suit));
            ++loadIndex;
        }
    }
}

void ConsoleDeck::swap(ConsoleCard *cards, int index1, int index2)
{
    ConsoleCard temp = *(cards + index1);
    *(cards + index1) = *(cards + index2);
    *(cards + index2) = temp;
}