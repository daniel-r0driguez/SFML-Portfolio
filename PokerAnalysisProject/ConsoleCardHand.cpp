#include "ConsoleCardHand.h"

ConsoleCardHand::ConsoleCardHand()
{
    this->_hand.reserve(5);
}

void ConsoleCardHand::clearHand()
{
    this->_hand.clear();
}

void ConsoleCardHand::addCard(const ConsoleCard& card)
{
    this->_hand.push_back(card);
}

void ConsoleCardHand::replaceCardAt(int index, const ConsoleCard& card)
{
    this->_hand.at(index) = card;
}

ConsoleCard& ConsoleCardHand::getCardAt(int index)
{
    return this->_hand.at(index);
}

const ConsoleCard& ConsoleCardHand::getCardAt(int index) const
{
    return this->_hand.at(index);
}

const std::vector<ConsoleCard>& ConsoleCardHand::getCards() const
{
    return this->_hand;
}

std::ostream& operator << (std::ostream& out, const ConsoleCardHand& hand)
{
    for (int i = 0; i < hand._hand.size(); ++i)
    {
        out << i + 1 << ": " << hand._hand.at(i) << "\n";
    }
    return out;
}

int ConsoleCardHand::size() const
{
    return int(this->_hand.size());
}

void ConsoleCardHand::sortHand()
{
    quickSort(this->_hand, 0, int(this->_hand.size()) - 1);
}

void ConsoleCardHand::quickSort(std::vector<ConsoleCard>& hand, int left, int right)
{
    if (left < right)
    {
        int pivotIndex = partition(hand, left, right);
        quickSort(hand, left, pivotIndex - 1);
        quickSort(hand, pivotIndex + 1, right);
    }
}

int ConsoleCardHand::partition(std::vector<ConsoleCard>& hand, int left, int right)
{
    const ConsoleCard& pivotCard = hand.at(right);
    int pivotIndex = left;
    for (int i = left; i < right; ++i)
    {
        if (hand.at(i).getRank() < pivotCard.getRank())
        {
            swap(hand.at(i), hand.at(pivotIndex));
            ++pivotIndex;
        }
    }
    swap(hand.at(pivotIndex), hand.at(right));
    return pivotIndex;
}

void ConsoleCardHand::swap(ConsoleCard& card1, ConsoleCard& card2)
{
    ConsoleCard temp = card1;
    card1 = card2;
    card2 = temp;
}