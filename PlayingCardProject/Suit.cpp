// Daniel Rodriguez - CS003A
// In-Class Lab (Cards Lab)
#include "Suit.h"
const float Suit::DEFAULT_WIDTH = 70;
const float Suit::DEFAULT_HEIGHT = 70;

Suit::Suit()
{
    this->_suit = Suits::HEARTS;
}

Suit::Suit(Suits suit)
{
    this->_suit = suit;
    sf::Texture* tempTexture = Images::getImage(suit);
    this->suitSprite.setTexture(*tempTexture);
    this->suitSprite.setScale(Suit::DEFAULT_WIDTH / float(tempTexture->getSize().x),
                              Suit::DEFAULT_HEIGHT / float(tempTexture->getSize().y));
}

void Suit::setNewScale(float scaleFactor)
{
    const sf::Texture* tempTexture = this->suitSprite.getTexture();
    this->suitSprite.setScale(sf::Vector2f(Suit::DEFAULT_WIDTH * scaleFactor / float(tempTexture->getSize().x),
                                           Suit::DEFAULT_HEIGHT * scaleFactor / float(tempTexture->getSize().y)));
}

Suit& Suit::operator = (const Suit& otherSuit)
{
   if (&otherSuit != this)
   {
       this->_suit = otherSuit._suit;
       this->suitSprite.setTexture(*otherSuit.suitSprite.getTexture(), true);
       setNewScale(otherSuit.getSuitScale().x);
   }
   return *this;
}

Suits Suit::getSuit() const
{
    return this->_suit;
}

sf::Vector2f Suit::getSuitScale() const
{
    return this->suitSprite.getScale();
}

sf::Sprite& Suit::getSprite()
{
    return this->suitSprite;
}

void Suit::draw(sf::RenderTarget &window, sf::RenderStates state) const
{
    window.draw(this->suitSprite);
}