// Daniel Rodriguez : CS003A
#include "BouncingBallApplication.h"

BouncingBallApplication::BouncingBallApplication()
{
    this->_image = ThumbnailImage::BOUNCING_BALL;
}

void BouncingBallApplication::bounce(const sf::Vector2u &windowSize, Ball &ball)
{
    // Check if ball hit the bottom of the screen.
    if (ball.getBall().getGlobalBounds().top + ball.getDiameter() > float(windowSize.y))
    {
        ball.getBall().setFillColor(sf::Color::Red);
        ball.setYVelocity(ball.getYVelocity() * -1);
    }
    // Check if the ball hit the top of the screen.
    if (ball.getBall().getGlobalBounds().top < 0)
    {
        ball.getBall().setFillColor(sf::Color::Cyan);
        ball.setYVelocity(ball.getYVelocity() * -1);
    }
    // Check if the ball hit the right of the screen.
    if (ball.getBall().getGlobalBounds().left + ball.getDiameter() > float(windowSize.x))
    {
        ball.getBall().setFillColor(sf::Color::Magenta);
        ball.setXVelocity(ball.getXVelocity() * -1);
    }
    // Check if the ball hit the left of the screen.
    if (ball.getBall().getGlobalBounds().left < 0)
    {
        ball.getBall().setFillColor(sf::Color::Green);
        ball.setXVelocity(ball.getXVelocity() * -1);
    }

    // Bounce the ball after updating its velocity.
    ball.getBall().move(ball.getXVelocity(), ball.getYVelocity());
}

void BouncingBallApplication::run(sf::RenderWindow &mainWindow)
{
    checkIfRunnable();
    // The original size of the texture. Usually from the main SFML loop.
    sf::Vector2u originalTextureSize = this->_textureToDrawOn->getSize();

    // The new size of the texture for this particular project.
    sf::Vector2u newTextureSize = {700, 500};

    // Clear the contents from before.
    this->_textureToDrawOn->clear();
    // Set the new size of the sf::RenderTexture.
    this->_textureToDrawOn->create(newTextureSize.x, newTextureSize.y);

    // Update the texture rect of the sf::Sprite, which is our this->_textureToRender->
    // This way, the drawing does not look stretched out or messed up.
    this->_textureToRender->setTextureRect({0, 0, static_cast<int>(newTextureSize.x), static_cast<int>(newTextureSize.y)});

    bool isRunning = true;
    sf::Event event;

    Ball ball(50, 5, 5);

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
        bounce(newTextureSize, ball);
        this->_textureToDrawOn->clear(sf::Color::Blue);
        this->_textureToDrawOn->draw(ball);
        this->_textureToDrawOn->display();

        mainWindow.clear(sf::Color::Black);
        mainWindow.draw(*this->_textureToRender);
        mainWindow.display();
    }
    // We have to reset to the previous state that the sf::RenderTexture and sf::Sprite came in with.

    // Set the sf::RenderTexture to its previous size.
    this->_textureToDrawOn->create(originalTextureSize.x, originalTextureSize.y);
    // Set the textureRect to fit this original size.
    this->_textureToRender->setTextureRect({0, 0, static_cast<int>(originalTextureSize.x), static_cast<int>(originalTextureSize.y)});
    // Clear the contents drawn from this project, just in case any was left.
    this->_textureToDrawOn->clear();
}
