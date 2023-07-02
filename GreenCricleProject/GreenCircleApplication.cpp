#include "GreenCircleApplication.h"

GreenCircleApplication::GreenCircleApplication()
{
    this->_image = ThumbnailImage::GREEN_CIRCLE;
}

void GreenCircleApplication::run(sf::RenderWindow& mainWindow)
{
    checkIfRunnable();
    // The original size of the texture. Usually from the main SFML loop.
    sf::Vector2u originalTextureSize = this->_textureToDrawOn->getSize();

    // The new size of the texture for this particular project.
    sf::Vector2u newTextureSize = {500, 500};

    // Clear the contents from before.
    this->_textureToDrawOn->clear();
    // Set the new size of the sf::RenderTexture.
    this->_textureToDrawOn->create(newTextureSize.x, newTextureSize.y);

    // Update the texture rect of the sf::Sprite, which is our textureToRender.
    // This way, the drawing does not look stretched out or messed up.
    this->_textureToRender->setTextureRect({0, 0, static_cast<int>(newTextureSize.x), static_cast<int>(newTextureSize.y)});

    bool isRunning = true;
    sf::Event event;

    GreenCircle greenCircle(250.f);

    while (isRunning)
    {
        while (mainWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                isRunning = false;
                mainWindow.close();
            }
            if (event.key.code == sf::Keyboard::Escape)
            {
                isRunning = false;
            }
        }
        this->_textureToDrawOn->clear(sf::Color::Black);
        this->_textureToDrawOn->draw(greenCircle);
        this->_textureToDrawOn->display();

        mainWindow.clear(sf::Color::Black);
        mainWindow.draw(*this->_textureToRender);
        mainWindow.display();
    }
    // We have to reset to the previous  state that the sf::RenderTexture and sf::Sprite came in with.

    // Set the sf::RenderTexture to its previous size.
    this->_textureToDrawOn->create(originalTextureSize.x, originalTextureSize.y);
    // Set the textureRect to fit this original size.
    this->_textureToRender->setTextureRect({0, 0, static_cast<int>(originalTextureSize.x), static_cast<int>(originalTextureSize.y)});
    // Clear the contents drawn from this project, just in case any was left.
    this->_textureToDrawOn->clear();
}