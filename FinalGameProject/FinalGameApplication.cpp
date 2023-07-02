// Daniel Rodriguez : CS003A
// Super Mario but in SFML! | Final Game Project
#include "FinalGameApplication.h"

FinalGameApplication::FinalGameApplication()
{
    this->_image = ThumbnailImage::FINAL_GAME;
}

void FinalGameApplication::run(sf::RenderWindow &mainWindow)
{
    checkIfRunnable();
    this->_gameObjects = new std::vector<GameObject*>();
    this->_map = new TiledMap(30, 30);
    this->_camera = new CameraComponent;

    // Original size of the window.
    sf::Vector2u originalWindowSize = mainWindow.getSize();
    // The original size of the texture. Usually from the main SFML loop.
    sf::Vector2u originalTextureSize = this->_textureToDrawOn->getSize();

    // The new size of the texture for this particular project.
    sf::Vector2u newTextureSize = {1000, 800};

    // Set the size of the window to fit the contents.
    mainWindow.setSize(newTextureSize);

    // Clear the contents from before.
    this->_textureToDrawOn->clear();
    // Set the new size of the sf::RenderTexture.
    this->_textureToDrawOn->create(newTextureSize.x, newTextureSize.y);

    // Update the texture rect of the sf::Sprite, which is our textureToRender.
    // This way, the drawing does not look stretched out or messed up.
    this->_textureToRender->setTextureRect({0, 0, static_cast<int>(newTextureSize.x), static_cast<int>(newTextureSize.y)});

    bool isRunning = true;
    sf::Event event;
    sf::Clock deltaClock;
    sf::Time dt;

    TiledMapReader::loadMap(*this->_gameObjects, "FinalGameProject/lvl1-1.tmx", *this->_map);
    setCamera();
    this->_map->setTexture(FinalGameImages::getImage(Image_Enum::MARIO_TILE_SHEET));
    MusicManager::playMusic(OVERWORLD_THEME, true);
    this->_camera->zoom(0.3f);

    while (isRunning)
    {
        dt = deltaClock.restart();
        while (mainWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                isRunning = false;
                mainWindow.close();
                break;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                isRunning = false;
                break;
            }
            // Allow for zooming. Usually used for testing the camera.
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
            {
                this->_camera->zoom(1.1);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
            {
                this->_camera->zoom(0.9);
            }
            if (event.type == sf::Event::Resized)
            {
                this->_camera->setSize({static_cast<float>(event.size.width), static_cast<float>(event.size.height)});
                this->_camera->zoom(0.3f);
            }
        }

        // Check for collisions between components. This is a brute force method.
        // Unfortunately I didn't have enough time to study and implement a better way.
        // However, in the future I will most definitely use this project as way to study and implement optimization algorithms.
        for (GameObject *component: *this->_gameObjects)
        {
            for (GameObject *otherComponenet: *this->_gameObjects)
            {
                if (component != otherComponenet)
                {
                    CollisionDetector::isColliding(*component, *otherComponenet);
                }
            }
        }
        // Set the color to the original sky color in super mario.
        this->_textureToDrawOn->clear(sf::Color(107, 140, 255));
        // Update all objects.
        updateObjects(dt.asSeconds());
        // Update the camera's center position to follow the desired object.
        this->_camera->update({20.f, 0.f});
        // Draw all objects in the bounds of the scene (sf::View)
        drawSceneObjects();
        // Draw any static objects to the window screen (window's default view)
        drawStaticObjects();
        this->_textureToDrawOn->display();

        mainWindow.clear(sf::Color::Black);
        mainWindow.draw(*this->_textureToRender);
        mainWindow.display();
    }
    onExit();
    // We have to reset to the previous  state that the sf::RenderTexture and sf::Sprite came in with.

    // Reset the windows size.
    mainWindow.setSize(originalWindowSize);
    // Set the sf::RenderTexture to its previous size.
    this->_textureToDrawOn->create(originalTextureSize.x, originalTextureSize.y);
    // Set the textureRect to fit this original size.
    this->_textureToRender->setTextureRect({0, 0, static_cast<int>(originalTextureSize.x), static_cast<int>(originalTextureSize.y)});
    // Clear the contents drawn from this project, just in case any was left.
    this->_textureToDrawOn->clear();
}

void FinalGameApplication::addComponent(GameObject &component)
{
    this->_gameObjects->push_back(&component);
}

void FinalGameApplication::drawSceneObjects()
{
    this->_textureToDrawOn->setView(this->_camera->getView());
    // Draw the map onto the view.
    this->_textureToDrawOn->draw(*this->_map);
    // Draw all components onto the window view.
    for (GameObject* component : *this->_gameObjects)
    {
        this->_textureToDrawOn->draw(*component);
    }
}

void FinalGameApplication::drawStaticObjects()
{
    this->_textureToDrawOn->setView(this->_textureToDrawOn->getDefaultView());
    // Draw static items here...
}

void FinalGameApplication::updateObjects(float dt)
{
    for (auto& gameObject : *this->_gameObjects)
    {
        gameObject->update(dt);
    }
}

void FinalGameApplication::onExit()
{
    for (auto& gameObject : *this->_gameObjects)
    {
        delete gameObject;
    }
    delete this->_gameObjects;
    delete this->_map;
    delete this->_camera;
    MusicManager::stop();
}

void FinalGameApplication::setCamera()
{
    for (GameObject* object : *this->_gameObjects)
    {
        if (auto* player = dynamic_cast<Player*>(object))
        {
            this->_camera->followObject(player);
        }
    }
}
