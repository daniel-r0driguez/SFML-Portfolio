#include "PortfolioImages.h"
#include "iostream"

std::unordered_map<ThumbnailImage, sf::Texture> PortfolioImages::_images;

const sf::Texture& PortfolioImages::getImage(ThumbnailImage image)
{
    loadImage(image);
    return _images[image];
}

void PortfolioImages::loadImage(ThumbnailImage image)
{
    if(!_images[image].loadFromFile(getFilePath(image)))
    {
        std::cout << "Failed to load image!\n";
    }
}

std::string PortfolioImages::getFilePath(ThumbnailImage image)
{
    switch (image)
    {
        case GREEN_CIRCLE:
            return "greenCircleThumbnail.png";
        case BOUNCING_BALL:
            return "bouncingBallThumbnail.jpg";
        case SFML2D_ARRAY:
            return "sfml2DArrayThumbnail.png";
        case PLAYING_CARD:
            return "playingCardThumbnail.png";
        case PHASER:
            return "phaserThumbnail.png";
        case POKER_ANALYSIS:
            return "pokerAnalysisThumbnail.png";
        case FINAL_GAME:
            return "finalGameThumbnail.png";
        case LAST_IMG:
            return "missingTexture.jpg";
    }
}