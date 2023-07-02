#ifndef POKERANALYSIS_APPLICATION_H
#define POKERANALYSIS_APPLICATION_H
#include "../PlayingCardProject/Component.h"
#include "../Runnable.h"
#include <vector>
#include "PokerScore.h"
#include "CardHandSFML.h"
#include "CardHandScorer.h"
#include "TextBox.h"
#include "SimulatePokerRounds.h"
#include "SetHand.h"

/**
 * This is an important utility class which handles running the entire part of the SFML portion of the program.
 */
class PokerAnalysisApplication : public Runnable {
private:
    std::vector<Component*>* _components = nullptr;

public:
    PokerAnalysisApplication();
    void run(sf::RenderWindow &mainWindow) override;

    /**
     * Adds a new component to the PokerAnalysisApplication.
     * @param component any object derived from the Component base class
     */
    void addComponent(Component& component);

private:
    static void configureHandForSFML(CardHandSFML& hand, float xPos, float yPos);
    static void configureTextBox(TextBox& textBox, const std::string& text, float xPos, float yPos);
    void run2(sf::RenderWindow &mainWindow);
    void clearComponents();
};


#endif //POKERANALYSIS_APPLICATION_H
