// Daniel Rodriguez - CS003A
// In-Class Lab (Cards Lab)
#include "Images.h"

// Declare the static variable.
std::vector<sf::Texture> Images::images(LAST_SUIT, sf::Texture());

std::string Images::getPath(Suits suit)
{
    std::string filePath = "PlayingCardProject/";
    switch(suit)
    {
        case Suits::HEARTS:
            return filePath + "heart.png";
        case Suits::DIAMONDS:
            return filePath + "diamonds.png";
        case Suits::SPADES:
            return filePath + "spades.png";
        case Suits::CLUBS:
            return filePath + "club.png";
        case LAST_SUIT:
            throw std::runtime_error("Image failed to load");
    }
}

void Images::loadFile(Suits suit)
{
    Images::images.at(suit).setSmooth(true);
    if (!Images::images.at(suit).loadFromFile(getPath(suit)))
    {
        throw std::runtime_error("Error. File " + getPath(suit) + " could not be found.");
    }
}

sf::Texture* Images::getImage(Suits suit)
{
    loadFile(suit);
    return &Images::images.at(suit);
}