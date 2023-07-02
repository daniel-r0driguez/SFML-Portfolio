// Daniel Rodriguez : CS003A
// Super Mario but in SFML! | Final Game Project
#ifndef FINALPROJECTGAME_APPLICATION_H
#define FINALPROJECTGAME_APPLICATION_H
#include "SFML/Graphics.hpp"
#include "GameObject.h"
#include "FinalGameImages.h"
#include <vector>
#include "CollisionDetector.h"
#include "CameraComponent.h"
#include "MusicManager.h"
#include "TiledMapReader.h"
#include "TiledMap.h"
#include "../Runnable.h"

class FinalGameApplication : public Runnable {
private:
    std::vector<GameObject*>* _gameObjects = nullptr;
    TiledMap* _map = nullptr;
    CameraComponent* _camera = nullptr;

public:
    FinalGameApplication();
    void run(sf::RenderWindow &mainWindow) override;
    void addComponent(GameObject& component);

private:
    void drawSceneObjects();
    void drawStaticObjects();

    void updateObjects(float dt);
    void onExit();
    void setCamera();
};


#endif //FINALPROJECTGAME_APPLICATION_H
