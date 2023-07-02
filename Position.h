#ifndef SFML_TEMPLATE_POSITION_H
#define SFML_TEMPLATE_POSITION_H
#include <SFML/Graphics.hpp>

/**
 * Simple utility class which positions two sf::Drawable objects relative to each other.
 */
class Position {
public:
    /**
     * Positions one sf::Drawable to be in the center of another sf::Drawable object
     * @tparam T Any class which inherits from sf::Drawable
     * @tparam S Any class which inherits from sf::Drawable
     * @param constObj the sf::Drawable object which will be taken as reference for centering
     * @param obj the other sf::Drawable object which will be centered
     */
    template<typename T, typename S>
    static void center(const T& constObj, S& obj);

    /**
     * Positions one sf::Drawable to be in the top left corner of another sf::Drawable object
     * @tparam T Any class which inherits from sf::Drawable
     * @tparam S Any class which inherits from sf::Drawable
     * @param constObj the sf::Drawable object which will be taken as reference for positioning
     * @param obj the other sf::Drawable object which will be positioned in the top left corner
     * @param xMargin the desired amount of margin (whitespace) from the left most boundary
     * @param yMargin the the desired amount of margin (whitespace) from the top
     */
    template<typename T, typename S>
    static void topLeft(const T& constObj, S& obj, float xMargin, float yMargin);


    /**
     * Positions one sf::Drawable to be in the bottom right corner of another sf::Drawable object
     * @tparam T Any class which inherits from sf::Drawable
     * @tparam S Any class which inherits from sf::Drawable
     * @param constObj the sf::Drawable object which will be taken as reference for positioning
     * @param obj the other sf::Drawable object which will be positioned in the bottom right corner
     * @param xMargin the desired amount of margin (whitespace) from the right most boundary
     * @param yMargin the the desired amount of margin (whitespace) from the bottom
     */
    template<typename T, typename S>
    static void bottomRight(const T& constObj, S& obj, float xMargin, float yMargin);
};

#include "Position.cpp"
#endif //SFML_TEMPLATE_POSITION_H
