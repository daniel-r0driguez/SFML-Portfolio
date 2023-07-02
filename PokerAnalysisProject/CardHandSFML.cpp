#include "CardHandSFML.h"

CardHandSFML::CardHandSFML()
{
    this->_hand.reserve(5);
    this->_spacingBetween = 0;
}

void CardHandSFML::clearHand()
{
    this->_hand.clear();
}

void CardHandSFML::addCard(const CardSFML& card)
{
    this->_hand.push_back(card);
}

void CardHandSFML::replaceCardAt(int index, const CardSFML& newCard)
{
    this->_hand.at(index) = newCard;
}

CardSFML& CardHandSFML::getCardAt(int index)
{
    return this->_hand.at(index);
}

const CardSFML& CardHandSFML::getCardAt(int index) const
{
    return this->_hand.at(index);
}

const std::vector<CardSFML>& CardHandSFML::getCards() const
{
    return this->_hand;
}

int CardHandSFML::size() const
{
    return int(this->_hand.size());
}

void CardHandSFML::sortHand()
{
    quickSort(this->_hand, 0, this->size() - 1);
}

void CardHandSFML::setSpacing(float spacing)
{
    this->_spacingBetween = spacing;
    update();
}

void CardHandSFML::setCardScale(float scale)
{
    for (CardSFML& card : this->_hand)
    {
        card.setScale(scale);
    }
    update();
}

float CardHandSFML::getWidth() const
{
    sf::FloatRect firstCardBounds = this->_hand.at(0).getPosition();
    sf::FloatRect lastCardBounds = this->_hand.at(size() - 1).getPosition();
    if (firstCardBounds.left < lastCardBounds.left)
    {
        return lastCardBounds.left + lastCardBounds.width - firstCardBounds.left;
    }
    else
    {
        return firstCardBounds.left + firstCardBounds.width - lastCardBounds.left;
    }
}

float CardHandSFML::getHeight() const
{
    return this->_hand.at(0).getPosition().height;
}

sf::FloatRect CardHandSFML::getPosition() const
{
    return this->_hand.at(0).getPosition();
}

void CardHandSFML::setPosition(float xPos, float yPos)
{
    sf::FloatRect cardBounds;
    for (int i = 0; i < size(); ++i)
    {
        cardBounds = this->_hand.at(i).getPosition();
        this->_hand.at(i).setPosition(xPos + (cardBounds.width * float(i)) + (this->_spacingBetween * float(i)), yPos);
    }
}

void CardHandSFML::draw(sf::RenderTarget& window, sf::RenderStates state) const
{
    for (const CardSFML& card : this->_hand)
    {
        card.draw(window, state);
    }
}

void CardHandSFML::update()
{
    sf::FloatRect prevCardBounds;
    for (int i = 1; i < size(); ++i)
    {
        prevCardBounds = this->_hand.at(i - 1).getPosition();
        this->_hand.at(i).setPosition(prevCardBounds.left + prevCardBounds.width + this->_spacingBetween, prevCardBounds.top);
    }
}

void CardHandSFML::quickSort(std::vector<CardSFML>& hand, int left, int right)
{
    if (left < right)
    {
        int pivotIndex = partition(hand, left, right);
        quickSort(hand, left, pivotIndex - 1);
        quickSort(hand, pivotIndex + 1, right);
    }
}

int CardHandSFML::partition(std::vector<CardSFML>& hand, int left, int right)
{
    const CardSFML& pivotCard = hand.at(right);
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

void CardHandSFML::swap(CardSFML& card1, CardSFML& card2)
{
    CardSFML temp = card1;
    card1 = card2;
    card2 = temp;
}

