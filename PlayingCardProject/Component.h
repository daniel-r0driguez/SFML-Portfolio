#ifndef POKERANALYSIS_COMPONENT_H
#define POKERANALYSIS_COMPONENT_H
#include <SFML/Graphics.hpp>
/**
 * Parent Base class for all objects which are expected to displayed during an SFML program.
 * These objects MUST derive from this Base class in order to be added to the PokerAnalysisApplication.
 */
class Component : public sf::Drawable {};
#endif //POKERANALYSIS_COMPONENT_H
