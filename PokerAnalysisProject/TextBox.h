#ifndef SFML_TEMPLATE_TEXTBOX_H
#define SFML_TEMPLATE_TEXTBOX_H
#include <SFML/Graphics.hpp>
#include "../PlayingCardProject/Component.h"
#include "../PlayingCardProject/Font.h"
#include "../PlayingCardProject/Position.h"
#include <string>

/**
 * This class works as a simple textbox object which allows to display text.
 * The text can be displayed over a colored background and outline borders can be added as well.
 */
class TextBox : public Component {
private:
    sf::RectangleShape _box;
    sf::Text _text;
    float _xPadding;
    float _yPadding;

public:
    /**
     * Default constructor. Does nothing special
     */
    TextBox();

    /**
     * Overloaded constructor. Takes many arguments in order to construct a new TextBox object
     * @param text a std::string representing the desired text
     * @param characterSize the desired character size for the text
     * @param xPadding the horizontal padding between the edge of the box and the text
     * @param yPadding the vertical padding between the edge of the box and the text
     */
    TextBox(const std::string& text, unsigned int characterSize, float xPadding, float yPadding);

    /**
     * @return the current vertical padding of the TextBox
     */
    float getYPadding() const;

    /**
     * @return the current horizontal padding of the TextBox
     */
    float getXPadding() const;

    /**
     * Sets the padding of the TextBox object.
     * @param xPadding the horizontal padding between the edge of the box and text
     * @param yPadding the vertical padding between the edge of the box and text
     */
    void setPadding(float xPadding, float yPadding);

    /**
     * @return the current character size of the TextBox
     */
    unsigned int getCharacterSize() const;

    /**
     * Sets the character size of the TextBox.
     * @param size the new, desired character size
     */
    void setCharacterSize(unsigned int size);

    /**
     * @return a sf::FloatRect which contains the position and dimensions of the TextBox object
     */
    sf::FloatRect getPosition() const;

    /**
     * Sets the position of the TextBox object.
     * @param xPos the new x-position
     * @param yPos the new y-position
     */
    void setPosition(float xPos, float yPos);

    /**
     * Moves the TextBox object by an offset.
     * @param offsetX the horizontal movement of the TextBox
     * @param offsetY the vertical movement of the TextBox
     */
    void move(float offsetX, float offsetY);

    /**
     * @return a sf::String which represents the current text of the TextBox object
     */
    const sf::String& getText() const;

    /**
     * Sets the text of the TextBox object
     * @param text the new, desired text
     */
    void setText(const std::string& text);

    /**
     * @return a sf::Color object which represents the current color of the TextBox object's outline color
     */
    const sf::Color& getOutlineColor() const;

    /**
     * Sets the outline color of the TextBox object.
     * @param color a sf::Color object which represents the new, desired color
     */
    void setOutlineColor(const sf::Color& color);

    /**
     * Sets the outline thickness of the TextBox object.
     * @param thickness the desired thickness of the outline
     */
    void setOutlineThickness(float thickness);

    /**
     * @return a sf::Color object which represents the current color of the TextBox object's background color
     */
    const sf::Color& getBackgroundColor() const;

    /**
     * Sets the background color of the TextBox object.
     * @param color a sf::Color object which represents the new, desired background color
     */
    void setBackgroundColor(const sf::Color& color);

    /**
     * @return a sf::Color object which represents the current color of the text in the TextBox object
     */
    const sf::Color& getTextColor() const;

    /**
     * Sets the text in the TextBox object to a new color
     * @param color a sf::Color object which represents the new, desired color
     */
    void setTextColor(const sf::Color& color);

    /**
     * SFML draw function. Allows the TextBox object to be displayed on a RenderTarget.
     * @param window the sf::RenderTarget to draw to.
     * @param state defines the states used for drawing to a RenderTarget
     */
    void draw(sf::RenderTarget& window, sf::RenderStates state) const override;

private:
    /**
     * Helper function which updates the positioning of all sf::Drawable member variables in the TextBox object.
     */
    void update();
};


#endif //SFML_TEMPLATE_TEXTBOX_H
