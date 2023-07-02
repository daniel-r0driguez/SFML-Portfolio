// Daniel Rodriguez - CS003A
// In-Class Lab (Cards Lab)
#ifndef SFML_TEMPLATE_IMAGES_H
#define SFML_TEMPLATE_IMAGES_H
#include "Suits.h"
#include <vector>
#include <SFML/Graphics.hpp>
#include <exception>
#include <string>

/**
 * Utility class whose purpose is to load and return references(pointers) to various images (textures).
 */
class Images {
private:
    static std::vector<sf::Texture> images;

    /**
     * Returns a std::string which represents the path necessary to find an image file
     * @param suit the desired Suit image to attempt to find
     * @return a std::string which represents the file path to the image
     */
    static std::string getPath(Suits suit);

    /**
     * Loads the necessary image.
     * @param suit the Suit image to attempt to load
     */
    static void loadFile(Suits suit);

public:
    /**
     * Returns a pointer to a sf::Texture object
     * @param suit the Suit image to attempt to retrieve
     * @return a pointer to a sf::Texture object
     */
    static sf::Texture* getImage(Suits suit);
};

#endif //SFML_TEMPLATE_IMAGES_H