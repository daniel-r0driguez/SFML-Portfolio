#ifndef PORTFOLIO_PROJECT_PORTFOLIOIMAGES_H
#define PORTFOLIO_PROJECT_PORTFOLIOIMAGES_H
#include "SFML/Graphics.hpp"
#include <unordered_map>
enum ThumbnailImage {GREEN_CIRCLE, BOUNCING_BALL, SFML2D_ARRAY, PLAYING_CARD,
        PHASER, POKER_ANALYSIS, FINAL_GAME, LAST_IMG};

class PortfolioImages {
private:
    static std::unordered_map<ThumbnailImage, sf::Texture> _images;

public:
    static const sf::Texture& getImage(ThumbnailImage image);

private:
    static void loadImage(ThumbnailImage image);
    static std::string getFilePath(ThumbnailImage image);
};


#endif //PORTFOLIO_PROJECT_PORTFOLIOIMAGES_H
