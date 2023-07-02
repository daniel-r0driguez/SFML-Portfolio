// Daniel Rodriguez : CS003A
#ifndef PORTFOLIO_PROJECT_BOUNCINGBALLAPPLICATION_H
#define PORTFOLIO_PROJECT_BOUNCINGBALLAPPLICATION_H
#include "../Runnable.h"
#include "Ball.h"

class BouncingBallApplication : public Runnable {
public:
    BouncingBallApplication();
    static void bounce(const sf::Vector2u &window, Ball& ball);
    void run(sf::RenderWindow& mainWindow) override;
};

#endif //PORTFOLIO_PROJECT_BOUNCINGBALLAPPLICATION_H
