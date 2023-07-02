// Daniel Rodriguez : CS003A
// Super Mario but in SFML! | Final Game Project
#ifndef FINALPROJECTGAME_TILEDMAPREADER_H
#define FINALPROJECTGAME_TILEDMAPREADER_H
#include "SFML/Graphics.hpp"
#include "GameObject.h"
#include "Solid.h"
#include "Player.h"
#include "Goomba.h"
#include "Koopa.h"
#include "pugixml.hpp"
#include "radpidcsv.h"
#include "TiledMap.h"
#include <vector>
#include <sstream>
#include <cctype>
#include <cstring>

// This way the TiledMapReader can then access those ObjectPools and grab the necessary objects to return to the...
// ...FinalGameApplication's std::vector<GameObject*> to update and draw.
class TiledMapReader {
public:
    /**
     * This function loads a Tiled map using the pugixml library.
     * Parses the tmx/xml file and dynamically creates the necessary GameObjects for the current Tiled map.
     * @param  objects an std::vector to add the game objects and tiles to. Usually this is the FinalGameApplication's _gameObject's vector.
     * @param tmxFilePath the file path of the tmx/xml file
     * @param gameObjects a reference to the vector of GameObject pointers to push the dynamically created GameObject
     */
    static void loadMap(std::vector<GameObject*>& objects, const char* tmxFilePath, TiledMap& tiledMap);

private:
    static sf::IntRect calculateTextureRect(int tileID, int tileWidth, int tileHeight, int numOfColumns);
    static void spawnTiledLayers(const pugi::xml_node& rootNode, TiledMap& tiledMap);
};

#endif //FINALPROJECTGAME_TILEDMAPREADER_H