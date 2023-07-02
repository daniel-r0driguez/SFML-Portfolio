#ifndef PORTFOLIO_PROJECT_RUNNABLE_H
#define PORTFOLIO_PROJECT_RUNNABLE_H
#include "SFML/Graphics.hpp"
#include "SFMLObject.h"
#include "vector"
#include "exception"
#include "PortfolioImages.h"

class Runnable {
protected:
    sf::RenderTexture* _textureToDrawOn = nullptr;
    sf::Sprite* _textureToRender = nullptr;
    ThumbnailImage _image = ThumbnailImage::LAST_IMG;

    /**
     * Checks to see if the texture to draw on (sf::RenderTexture) and texture to render (sf::Sprite) for the  runnable application is set.
     * If not, it throws a runtime exception stating that these attributes were not set.
     */
    void checkIfRunnable() const
    {
        if (this->_textureToDrawOn == nullptr)
        {
            throw std::runtime_error("Error! Texture to draw on (sf::RenderTexture) not set!");
        }
        if (this->_textureToRender == nullptr)
        {
            throw std::runtime_error("Error! Texture to render (sf::Sprite) not set!");
        }
    }

public:
    virtual void run(sf::RenderWindow& mainWindow) = 0;

    void setRenderTexture(sf::RenderTexture* textureToDrawOn)
    {
        this->_textureToDrawOn = textureToDrawOn;
    }

    void setSprite(sf::Sprite* textureToRender)
    {
        this->_textureToRender = textureToRender;
    }

    ThumbnailImage getImageEnum() const
    {
        return this->_image;
    }
};

#endif //PORTFOLIO_PROJECT_RUNNABLE_H