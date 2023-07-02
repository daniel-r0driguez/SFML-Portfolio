#include "TextBox.h"

TextBox::TextBox()
{
    this->_text.setFont(Font::getFont());
    this->_xPadding = 0;
    this->_yPadding = 0;
}

TextBox::TextBox(const std::string& text, unsigned int characterSize, float xPadding, float yPadding)
: _text(text, Font::getFont(), characterSize)
{
    this->_xPadding = xPadding;
    this->_yPadding = yPadding;
    update();
}

float TextBox::getYPadding() const
{
    return this->_yPadding;
}

float TextBox::getXPadding() const
{
    return this->_xPadding;
}

void TextBox::setPadding(float xPadding, float yPadding)
{
    this->_xPadding = xPadding;
    this->_yPadding = yPadding;
    update();
}

unsigned int TextBox::getCharacterSize() const
{
    return this->_text.getCharacterSize();
}

void TextBox::setCharacterSize(unsigned int size)
{
    this->_text.setCharacterSize(size);
    update();
}

sf::FloatRect TextBox::getPosition() const
{
    return this->_box.getGlobalBounds();
}

void TextBox::setPosition(float xPos, float yPos)
{
    this->_text.setPosition(xPos + this->_xPadding,
                            yPos + this->_yPadding);
    update();
}

void TextBox::move(float offsetX, float offsetY)
{
    this->_text.move(offsetX, offsetY);
    update();
}

const sf::Color& TextBox::getBackgroundColor() const
{
    return this->_box.getFillColor();
}

const sf::String& TextBox::getText() const
{
    return this->_text.getString();
}

void TextBox::setText(const std::string& text)
{
    this->_text.setString(text);
    update();
}

const sf::Color& TextBox::getOutlineColor() const
{
    return this->_box.getOutlineColor();
}

void TextBox::setOutlineColor(const sf::Color& color)
{
    this->_box.setOutlineColor(color);
}

void TextBox::setOutlineThickness(float thickness)
{
    this->_box.setOutlineThickness(thickness);
    update();
}

void TextBox::setBackgroundColor(const sf::Color& color)
{
    this->_box.setFillColor(color);
}

const sf::Color& TextBox::getTextColor() const
{
    return this->_text.getFillColor();
}

void TextBox::setTextColor(const sf::Color& color)
{
    this->_text.setFillColor(color);
}

void TextBox::draw(sf::RenderTarget& window, sf::RenderStates state) const
{
    window.draw(this->_box);
    window.draw(this->_text);
}

void TextBox::update()
{
    this->_box.setSize(sf::Vector2f(this->_text.getGlobalBounds().width + (_xPadding + _xPadding),
                                    this->_text.getGlobalBounds().height + (_yPadding + _xPadding)));
    Position::center(this->_text, this->_box);
}