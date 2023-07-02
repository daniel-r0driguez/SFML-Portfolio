#include "sfml2DArrayApplication.h"

sfml2DArrayApplication::sfml2DArrayApplication()
{
    this->_image = ThumbnailImage::SFML2D_ARRAY;
}

void sfml2DArrayApplication::run(sf::RenderWindow &mainWindow)
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

    // Update the texture rect of the sf::Sprite, which is our this->_textureToRender->
    // This way, the drawing does not look stretched out or messed up.
    this->_textureToRender->setTextureRect({0, 0, static_cast<int>(newTextureSize.x), static_cast<int>(newTextureSize.y)});

    bool isRunning = true;
    sf::Event event;

    sf::RectangleShape rect(sf::Vector2f(10, 10));
    rect.setFillColor(sf::Color::Red);

    SFMLGrid<sf::RectangleShape> grid1;
    grid1.push_back_column(rect);
    grid1.setGridElementSize(sf::Vector2f(20, 20));
    grid1.setPosition(100, 100);
    grid1.setSpacingBetween();

    while (isRunning)
    {
        while(mainWindow.pollEvent(event))
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
            if (event.type == sf::Event::KeyPressed)
            {
                grid1.eventHandler(mainWindow, event);
            }
        }
        this->_textureToDrawOn->clear(sf::Color::Cyan);
        this->_textureToDrawOn->draw(grid1);
        this->_textureToDrawOn->display();

        mainWindow.clear(sf::Color::Black);
        mainWindow.draw(*this->_textureToRender);
        mainWindow.display();
        grid1.randomColors();
    }
    // We have to reset to the previous  state that the sf::RenderTexture and sf::Sprite came in with.

    // Set the sf::RenderTexture to its previous size.
    this->_textureToDrawOn->create(originalTextureSize.x, originalTextureSize.y);
    // Set the textureRect to fit this original size.
    this->_textureToRender->setTextureRect({0, 0, static_cast<int>(originalTextureSize.x), static_cast<int>(originalTextureSize.y)});
    // Clear the contents drawn from this project, just in case any was left.
    this->_textureToDrawOn->clear();
}
