#ifndef PORTFOLIO_PROJECT_PORTFOLIOAPPLICATION_H
#define PORTFOLIO_PROJECT_PORTFOLIOAPPLICATION_H
#include "SFML/Graphics.hpp"
#include "SFMLObject.h"
#include <vector>
#include "Thumbnail.h"
#include "PortfolioImages.h"
#include "GreenCricleProject/GreenCircleApplication.h"
#include "PhaserProject/PhaserApplication.h"
#include "BouncingBallProject/BouncingBallApplication.h"
#include "SFML_2D_ARRAY_PROJECT/sfml2DArrayApplication.h"
#include "PlayingCardProject/PlayingCardApplication.h"
#include "PokerAnalysisProject/PokerAnalysisApplication.h"
#include "FinalGameProject/FinalGameApplication.h"
#include "PokerAnalysisProject/TextBox.h"

class PortfolioApplication {
private:
    static sf::RenderWindow _window;
    static sf::RenderTexture _drawableTexture;
    static sf::Sprite _renderedTexture;
    static std::vector<SFMLObject*> _objects;
    static std::vector<Runnable*> _projects;
    static Thumbnail _thumbnail;
    static int _curIndex;

public:
    static void run();
    static void addObject(SFMLObject& object);
    static void addProject(Runnable& runnable);

private:
    static void drawObjects();
};


#endif //PORTFOLIO_PROJECT_PORTFOLIOAPPLICATION_H
