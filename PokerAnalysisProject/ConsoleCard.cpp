#include "ConsoleCard.h"

ConsoleCard::ConsoleCard()
{
    this->_rank = Ranks::LAST_RANK;
    this->_suit = Suits::LAST_SUIT;
}

ConsoleCard::ConsoleCard(Ranks rank, Suits suit)
{
    this->_rank = rank;
    this->_suit = suit;
}

ConsoleCard::ConsoleCard(const ConsoleCard& copy)
{
    this->_rank = copy._rank;
    this->_suit = copy._suit;
}

Ranks ConsoleCard::getRank() const
{
    return this->_rank;
}

Suits ConsoleCard::getSuit() const
{
    return this->_suit;
}

std::string ConsoleCard::getRankStr() const
{
    switch (this->_rank)
    {
        case Ranks::TWO:
            return "Two";
        case Ranks::THREE:
            return "Three";
        case FOUR:
            return "Four";
        case FIVE:
            return "Five";
        case SIX:
            return "Six";
        case SEVEN:
            return "Seven";
        case EIGHT:
            return "Eight";
        case NINE:
            return "Nine";
        case TEN:
            return "Ten";
        case JACK:
            return "Jack";
        case QUEEN:
            return "Queen";
        case KING:
            return "King";
        case ACE:
            return "Ace";
        case LAST_RANK:
            return "Last Rank";
    }
}

std::string ConsoleCard::getSuitStr() const
{
    switch (this->_suit)
    {
        case Suits::HEARTS:
            return "Hearts";
        case DIAMONDS:
            return "Diamonds";
        case CLUBS:
            return "Clubs";
        case SPADES:
            return "Spades";
        case LAST_SUIT:
            return "Last Suit";
    }
}

void ConsoleCard::setRank(Ranks rank)
{
    this->_rank = rank;
}

void ConsoleCard::setSuit(Suits suit)
{
    this->_suit = suit;
}

ConsoleCard& ConsoleCard::operator=(const ConsoleCard& card)
{
    if (&card != this)
    {
        this->_rank = card._rank;
        this->_suit = card._suit;
    }
    return *this;
}

std::ostream& operator << (std::ostream& out, const ConsoleCard& card)
{
    return out << card.getRankStr() << " of " << card.getSuitStr();
}