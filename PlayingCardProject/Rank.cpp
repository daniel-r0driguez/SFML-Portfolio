#include "Rank.h"

const std::vector<std::string> Rank::rankStr = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
const unsigned int Rank::DEFAULT_TEXT_SIZE = 30;

Rank::Rank()
{
    this->_rank = Ranks::ACE;
}

Rank::Rank(Ranks rank)
{
    this->_rank = rank;

    // Set the Rank object's font.
    this->top.setFont(Font::getFont());
    this->bottom.setFont(Font::getFont());

    // Set the Rank object's text.
    this->top.setString(rankStr.at(rank));
    this->bottom.setString(rankStr.at(rank));

    // Set the default fill color.
    setTextColor(sf::Color::Black);

    // Set the Rank object's text size.
    this->top.setCharacterSize(DEFAULT_TEXT_SIZE);
    this->bottom.setCharacterSize(DEFAULT_TEXT_SIZE);

    // Rotate the bottom Rank.
    this->bottom.rotate(180);
}

Rank::Rank(const Rank& rank)
{
    this->_rank = rank._rank;
    *this = rank;
}

Ranks Rank::getRank() const
{
    return this->_rank;
}

void Rank::setText(const std::string &text)
{
    this->top.setString(text);
    this->bottom.setString(text);
}

void Rank::setNewScale(float scale)
{
    this->top.setCharacterSize(int(DEFAULT_TEXT_SIZE * scale));
    this->bottom.setCharacterSize(int(DEFAULT_TEXT_SIZE * scale));
}

void Rank::setTextColor(sf::Color color)
{
    // Set the fill color
    this->top.setFillColor(color);
    this->bottom.setFillColor(color);
}

Rank& Rank::operator = (const Rank& otherRank)
{
   if (&otherRank != this)
   {
       this->_rank = otherRank._rank;
       this->top = otherRank.top;
       this->bottom = otherRank.bottom;
   }
   return *this;
}

sf::Text& Rank::getTopText()
{
    return this->top;
}

sf::Text& Rank::getBottomText()
{
    return this->bottom;
}

void Rank::draw(sf::RenderTarget &window, sf::RenderStates state) const
{
    window.draw(this->top);
    window.draw(this->bottom);
}