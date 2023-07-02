#ifndef SFML_TUTORIAL_EVENTHANDLEABLE_H
#define SFML_TUTORIAL_EVENTHANDLEABLE_H
#include "PhaserComponent.h"

class PhaserEventHandleable
{
public:
    virtual void eventHandler(sf::RenderWindow& window, sf::Event event) = 0;
};

#endif //SFML_TUTORIAL_EVENTHANDLEABLE_H
