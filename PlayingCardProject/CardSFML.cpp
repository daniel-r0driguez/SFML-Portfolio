// Daniel Rodriguez - CS003A
// In-Class Lab (Cards Lab)
#include "CardSFML.h"
#include "Position.h"

const unsigned int CardSFML::DEFAULT_SCALE = 1;

CardSFML::CardSFML()
: background(0, 0, DEFAULT_SCALE), _rank(), _suit()
{
    this->scale = DEFAULT_SCALE;
    update();
}

CardSFML::CardSFML(const CardSFML& otherCard)
{
    this->scale = otherCard.scale;
    *this = otherCard;
    update();
}

CardSFML::CardSFML(Ranks rank, Suits suit)
: background(0, 0, DEFAULT_SCALE), _rank(rank), _suit(suit)
{
    this->scale = DEFAULT_SCALE;
    setRankColor(suit);
    update();
}

Ranks CardSFML::getRank() const
{
    return this->_rank.getRank();
}

Suits CardSFML::getSuit() const
{
    return this->_suit.getSuit();
}

sf::FloatRect CardSFML::getPosition() const
{
    return this->background.getPosition();
}

void CardSFML::setPosition(float xPosition, float yPosition)
{
    this->background.setPosition(xPosition, yPosition);
    update();
}

void CardSFML::move(float offSetX, float offSetY)
{
    this->background.setPosition(this->background.getPosition().left + offSetX,
                                 this->background.getPosition().top + offSetY);
    update();
}

void CardSFML::setScale(float newScale)
{
    this->scale = absFloat(newScale);
    this->background.setNewScale(this->scale);
    this->_rank.setNewScale(this->scale);
    this->_suit.setNewScale(this->scale);
    update();
}

void CardSFML::setRankColor(Suits suit)
{
    switch (suit) {
        case Suits::HEARTS:
        case Suits::DIAMONDS:
            this->_rank.setTextColor(sf::Color::Red);
            break;
        default:
            this->_rank.setTextColor(sf::Color::Black);
            break;
    }
}

CardSFML& CardSFML::operator = (const CardSFML& otherCard)
{
    if (&otherCard != this)
    {
        this->background = otherCard.background;
        this->_rank = otherCard._rank;
        this->_suit = otherCard._suit;
        this->scale = otherCard.scale;
    }
    return *this;
}

void CardSFML::draw(sf::RenderTarget& window, sf::RenderStates state) const
{
    this->background.draw(window, state);
    this->_suit.draw(window, state);
    this->_rank.draw(window, state);
}

float CardSFML::absFloat(float num)
{
    if (num < 0)
    {
        return (num * -1);
    }
    return num;
}

void CardSFML::update()
{
    Position::center(this->background.getRectangleShape(), this->_suit.getSprite());
    Position::topLeft(this->background.getRectangleShape(), this->_rank.getTopText(), 10 * this->scale, 10 * this->scale);
    Position::bottomRight(this->background.getRectangleShape(), this->_rank.getBottomText(), 10 * this->scale, 10 * this->scale);
}

