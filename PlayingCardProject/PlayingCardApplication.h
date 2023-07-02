#ifndef PORTFOLIO_PROJECT_PLAYINGCARDAPPLICATION_H
#define PORTFOLIO_PROJECT_PLAYINGCARDAPPLICATION_H
#include "../Runnable.h"
#include "CardSFML.h"

class PlayingCardApplication : public Runnable {
public:
    PlayingCardApplication();
    void run(sf::RenderWindow &mainWindow) override;
};


#endif //PORTFOLIO_PROJECT_PLAYINGCARDAPPLICATION_H
