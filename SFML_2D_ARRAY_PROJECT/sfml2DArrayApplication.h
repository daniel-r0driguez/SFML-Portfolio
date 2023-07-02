#ifndef PORTFOLIO_PROJECT_SFML2DARRAYAPPLICATION_H
#define PORTFOLIO_PROJECT_SFML2DARRAYAPPLICATION_H
#include "../Runnable.h"
#include <SFML/Graphics.hpp>
#include "SFMLGrid.h"

class sfml2DArrayApplication : public Runnable {
public:
    sfml2DArrayApplication();
    void run(sf::RenderWindow &mainWindow) override;
};
#endif //PORTFOLIO_PROJECT_SFML2DARRAYAPPLICATION_H
