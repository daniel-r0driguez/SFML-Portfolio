#ifndef SFML_TUTORIAL_COMPONENT_H
#define SFML_TUTORIAL_COMPONENT_H
// Make sure to include all helper classes for your component class.
// This way, all children of the class will be able to use these helper classes
class PhaserComponent : public sf::Drawable {
public:
    virtual void update(float dt) = 0;
    virtual void eventHandler(sf::RenderWindow& window, sf::Event event) = 0;
};
#endif //SFML_TUTORIAL_COMPONENT_H