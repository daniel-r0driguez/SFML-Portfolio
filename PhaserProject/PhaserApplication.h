#ifndef SFML_TUTORIAL_APPLICATION_H
#define SFML_TUTORIAL_APPLICATION_H
#include "SFML/Graphics.hpp"
#include "../Runnable.h"
#include "PhaserAnimatedSprite.h"
#include <vector>

class PhaserApplication : public Runnable {
public:
    PhaserApplication();
    void run(sf::RenderWindow &mainWindow) override;
};
#endif //SFML_TUTORIAL_APPLICATION_H