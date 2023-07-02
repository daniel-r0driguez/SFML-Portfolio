// Daniel Rodriguez - CS003A
// In-Class Lab (Cards Lab)
#ifndef SFML_TEMPLATE_FONT_H
#define SFML_TEMPLATE_FONT_H
#include <SFML/Graphics.hpp>

/**
 * Utility class whose only purpose is to load and return a sf::Font object.
 */
class Font {
private:
    static sf::Font font;

    /**
     * Loads the necessary font for the sf::Font object
     */
    static void loadFont();

public:
    /**
     * @return the sf::Font object necessary for displaying text
     */
    static sf::Font& getFont();
};

#endif //SFML_TEMPLATE_FONT_H