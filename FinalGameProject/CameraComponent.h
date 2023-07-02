// Daniel Rodriguez : CS003A
// Super Mario but in SFML! | Final Game Project
#ifndef FINALPROJECTGAME_CAMERACOMPONENTSTATIC_H
#define FINALPROJECTGAME_CAMERACOMPONENTSTATIC_H
#include "SFML/Graphics/View.hpp"
#include "GameObject.h"

class CameraComponent {
private:
    sf::View _camera;
    GameObject* _objectToFollow = nullptr;

public:
    const sf::View& getView();
    void followObject(GameObject* objectToFollow);
    void setCenter(const sf::Vector2f& centerPosition);
    void rotate(float angle);
    void zoom(float factor);
    void setSize(const sf::Vector2f& size);
    void move(const sf::Vector2f& offset);
    void setRotation(float angle);
    void update(const sf::Vector2f& offset);
};

#endif //FINALPROJECTGAME_CAMERACOMPONENTSTATIC_H