#ifndef PORTFOLIO_PROJECT_GREENCIRCLEAPPLICATION_H
#define PORTFOLIO_PROJECT_GREENCIRCLEAPPLICATION_H
#include "../Runnable.h"
#include "GreenCircle.h"
#include "../Position.h"

class GreenCircleApplication : public Runnable {
public:
    GreenCircleApplication();
    void run(sf::RenderWindow& mainWindow) override;
};

#endif //PORTFOLIO_PROJECT_GREENCIRCLEAPPLICATION_H