#ifndef SFML_TEMPLATE_RANK_H
#define SFML_TEMPLATE_RANK_H
#include <SFML/Graphics.hpp>
#include "Component.h"
#include "Ranks.h"
#include "Font.h"
#include <vector>

/**
 * This class represents a visible card rank which is usually seen in the top-left and bottom right corners
 * of a playing card.
 * Note: The default character size of a Rank object is 30. So scaling will be relative to this default size.
 */
class Rank : public Component {
private:
    static const std::vector<std::string> rankStr;
    static const unsigned int DEFAULT_TEXT_SIZE;
    sf::Text top, bottom;
    Ranks _rank;

public:
    /**
     * Default constructor. If used, the Rank object is by default set to Ranks::ACE.
     */
    Rank();

    /**
     * Overloaded constructor. Constructs a new Rank object according to whatever Ranks enum is passed in.
     * @param rank the Ranks enum to set the new constructed Rank object
     */
    explicit Rank(Ranks rank);

    /**
     * Copy constructor. Constructs a new Rank object by copying the data of another Rank object.
     * @param rank the Rank object to copy from
     */
    Rank(const Rank& rank);

    /**
     * @return the current rank of the Rank object
     */
    Ranks getRank() const;

    /**
     * Sets the text of the Rank object
     * @param text a std::string representing the desired text
     */
    void setText(const std::string& text);

    /**
     * Sets the Rank object to a new scale.
     * @param scale the new, desired scaling factor
     */
    void setNewScale(float scale);

    /**
     * Sets the Rank object to a new color.
     * @param color the new, desired color
     */
    void setTextColor(sf::Color color);

    /**
     * Overloaded assignment operator. Reassigns the data of the invoking Rank object to that of the Rank object on its right.
     * @param otherRank the other Rank object to copy
     * @return *this
     */
    Rank& operator = (const Rank& otherRank);

    /**
     * @return the sf::Text object which represents the top text of the Rank object
     */
    sf::Text& getTopText();

    /**
     * @return the sf::Text object which represents the bottom text of the Rank object
     */
    sf::Text& getBottomText();

    /**
     * SFML draw function. Draws the Rank object to the passed in sf::RenderTarget
     * @param window the sf::RenderTarget object to draw to
     * @param state defines the states used for drawing to a RenderTarget
     */
    void draw(sf::RenderTarget& window, sf::RenderStates state) const override;
};

#endif //SFML_TEMPLATE_RANK_H