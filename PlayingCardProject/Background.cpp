#include "Background.h"

const float Background::DEFAULT_WIDTH = 150;
const float Background::DEFAULT_HEIGHT = 210;
const float Background::DEFAULT_SCALE = 1;
const float Background::DEFAULT_OUTLINE_THICKNESS = -4;


Background::Background()
{
    this->scale = DEFAULT_SCALE;
    // Configuring the sf::RectangleShape object...
    this->background.setSize(sf::Vector2f(DEFAULT_WIDTH * this->scale, DEFAULT_HEIGHT * this->scale));
    this->background.setPosition(0, 0);
    this->background.setOutlineThickness(DEFAULT_OUTLINE_THICKNESS);
    this->background.setOutlineColor(sf::Color::Black);
}

Background::Background(float xPosition, float yPosition, float scaleFactor)
{
    this->scale = scaleFactor;
    // Configure the sf::RectangleShape object.
    this->background.setSize(sf::Vector2f(DEFAULT_WIDTH * this->scale, DEFAULT_HEIGHT * this->scale));
    this->background.setPosition(xPosition, yPosition);
    this->background.setOutlineThickness(DEFAULT_OUTLINE_THICKNESS);
    this->background.setOutlineColor(sf::Color::Black);
}

Background& Background::operator = (const Background& otherBackground)
{
    if (&otherBackground != this)
    {
        this->background = otherBackground.background;
        this->scale = otherBackground.scale;
    }
    return *this;
}

float Background::getScale() const
{
    return this->scale;
}

void Background::setNewScale(float scaleFactor)
{
    this->scale = scaleFactor;
    this->background.setSize(sf::Vector2f(DEFAULT_WIDTH * this->scale, DEFAULT_HEIGHT * this->scale));
    this->background.setOutlineThickness(this->background.getOutlineThickness() * scaleFactor);
}


void Background::setSize(float newWidth, float newHeight)
{
    this->background.setSize(sf::Vector2f(newWidth, newHeight));
}

sf::FloatRect Background::getPosition() const
{
    return this->background.getGlobalBounds();
}

void Background::setPosition(float xPosition, float yPosition)
{
    this->background.setPosition(xPosition, yPosition);
}

const sf::RectangleShape& Background::getRectangleShape()
{
    return this->background;
}

void Background::draw(sf::RenderTarget &window, sf::RenderStates state) const
{
    window.draw(this->background);
}