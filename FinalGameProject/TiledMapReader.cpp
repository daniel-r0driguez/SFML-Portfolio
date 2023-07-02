// Daniel Rodriguez : CS003A
// Super Mario but in SFML! | Final Game Project
#include "TiledMapReader.h"
#include "CameraComponent.h"
#include <iostream>

void TiledMapReader::loadMap(std::vector<GameObject*>& objects, const char* tmxFilePath, TiledMap& tiledMap)
{
    pugi::xml_document xmlDocument;
    xmlDocument.load_file(tmxFilePath);

    if (!xmlDocument)
    {
        std::cout << "error loading file.\n";
    }
    // get the root node of the document
    pugi::xml_node root = xmlDocument.child("map");

    // Spawn the tile map. This function will store it in the TiledMap object, which is passed by reference.
    spawnTiledLayers(root, tiledMap);

    // Outer for-loop will loop through the "objectgroup" nodes.
    // Each "objectgroup" is essentially like a layer which contains a collection of objects located in different locations.
    for (pugi::xml_node objectGroup = root.child("objectgroup"); objectGroup; objectGroup = objectGroup.next_sibling("objectgroup"))
    {
        // Check if the current "objectgroup" contains "solid" objects.
        if (strcmp(objectGroup.attribute("name").as_string(), "solid") == 0)
        {
            // If so, then spawn in the all the solid "objects" (child nodes) stored in this "objectgroup".
            for (pugi::xml_node solidObject = objectGroup.child("object"); solidObject; solidObject = solidObject.next_sibling("object"))
            {
                float xPos = solidObject.attribute("x").as_float();
                float yPos = solidObject.attribute("y").as_float();
                float width = solidObject.attribute("width").as_float();
                float height = solidObject.attribute("height").as_float();
                auto* newObstacle = new Solid({width, height}, {xPos, yPos}, sf::Color::Transparent);
                newObstacle->setCollidable(true);
                objects.push_back(newObstacle);
            }
        }
        // Check if the current "objectgroup" contains "entity" objects.
        // For example, coins, enemies, players, etc...
        if (strcmp(objectGroup.attribute("name").as_string(), "entity") == 0)
        {
            // If it is entity layer, then spawn in the entity "objects" (child nodes) in this "objectgroup".
            // However, we need to decide which type of entity object it is.
            for (pugi::xml_node entityObject = objectGroup.child("object"); entityObject; entityObject = entityObject.next_sibling("object"))
            {
                // Get the class name of the object.
                const char* className = entityObject.attribute("class").as_string();

                // Get the associated coordinates and size of the object.
                sf::Vector2f position = {entityObject.attribute("x").as_float(), entityObject.attribute("y").as_float()};
                sf::Vector2f size = {entityObject.attribute("width").as_float(), entityObject.attribute("height").as_float()};
                // Check if the entity is a player
                if (strcmp(className, "player") == 0)
                {
                    // If so, spawn the player.
                    auto* player = new Player(size, position);
                    player->setCollidable(true);
                    objects.push_back(player);
                }
                // Check if the entity is a coin. [not implemented :( ]
                if (strcmp(className, "coin") == 0)
                {
                    // If so spawn the coin.
                    auto* newCoin = new Solid({10, 10}, position, sf::Color::Yellow);
                    newCoin->setCollidable(true);
                    objects.push_back(newCoin);
                }
                // Check if the entity is an Goomba.
                if (strcmp(className, "goomba") == 0)
                {
                    // If so, spawn the Goomba.
                    auto* newGoomba = new Goomba(size, position);
                    newGoomba->setCollidable(true);
                    objects.push_back(newGoomba);
                }
                if (strcmp(className, "koopa") == 0)
                {
                    auto* newKoopa = new Koopa(size, position);
                    newKoopa->setCollidable(true);
                    objects.push_back(newKoopa);
                }
            }
        }
    }
}

sf::IntRect TiledMapReader::calculateTextureRect(int tileID, int tileWidth, int tileHeight, int numOfColumns)
{
    // Must subtract tileID - 1.
    // This is because in Tiled, IDs start from 0, however, in the csv data, the IDs are incremented by 1.
    const int TILE_ROW = (tileID - 1) / numOfColumns;
    const int TILE_COLUMN = (tileID - 1) % numOfColumns;

    const int TEXTURE_RECT_XPOS = TILE_COLUMN * tileWidth;
    const int TEXTURE_RECT_YPOS = TILE_ROW * tileHeight;

   return {TEXTURE_RECT_XPOS, TEXTURE_RECT_YPOS, tileWidth, tileHeight};
}

void TiledMapReader::spawnTiledLayers(const pugi::xml_node& rootNode, TiledMap& tiledMap)
{
    pugi::xml_node tileset = rootNode.child("tileset");

    float currentXPos;
    float currentYPos;
    // Total tile width of the map.
    const int MAP_WIDTH = rootNode.attribute("width").as_int();
    // Total tile height of the map.
    const int MAP_HEIGHT = rootNode.attribute("height").as_int();
     tiledMap.setMapHeight(MAP_HEIGHT);
     tiledMap.setMapWidth(MAP_WIDTH);

    // TILE_WIDTH and TILE_HEIGHT are made floats in order to minimize the potential static_cast<T> calls.
    // Width of each tile.
    const float TILE_WIDTH = tileset.attribute("tilewidth").as_float();
    // Height of each tile.
    const float TILE_HEIGHT = tileset.attribute("tileheight").as_float();
    // Total amount of tile columns present in the map (can also be calculated by MAP_WIDTH / TILE_WIDTH);
    const int TOTAL_TILE_COLUMNS = tileset.attribute("columns").as_int();

    // Stream which will hold the csv formatted tile data.
    std::istringstream csvStream;
    // Parser which will parse the csvStream.
    rapidcsv::Document csvDoc;

    // An array which will help for pushing Vertexes to a sf::VertexBuffer later on.
    std::vector<sf::Vertex> vertexes(4);

    // Each "layer" node represents a collection of tiles to be drawn.
    for (pugi::xml_node layer = rootNode.child("layer"); layer; layer = layer.next_sibling("layer"))
    {
        // Reset the x and y positions for the next "layer" of tiles.
        currentXPos = 0;
        currentYPos = 0;

        // Gather and update the csvStream to the csv data of the current layer.
        csvStream.str(layer.child("data").text().as_string());

        // Load the csv data into the csv parser.
        csvDoc.Load(csvStream, rapidcsv::LabelParams(-1, -1), rapidcsv::SeparatorParams(',', true),
                    rapidcsv::ConverterParams(true, -1.f, -1), rapidcsv::LineReaderParams(true, '#',true));

        // Each "layer" node contains rows and columns of tiles (like a 2D array).
        // In this case we will deal with each row of tiles first.
        // So, for the current "layer" of tiles we are dealing with...
        for (int i = 0; i < csvDoc.GetRowCount(); ++i)
        {
            // ...grab the row of tile IDs.
            std::vector<int> tileRow = csvDoc.GetRow<int>(i);

            // And for each tileID in the current row...
            for (int tileID : tileRow)
            {
                // ...if it is greater than 0, indicating a valid tile texture is needed...
                if (tileID > 0)
                {
                    // Since a tile is a rectangle/square shape, it has four vertexes. Set up each vertex accordingly.
                    // First, set up its position.
                    vertexes[0].position = {currentXPos, currentYPos};
                    vertexes[1].position = {currentXPos + TILE_WIDTH, currentYPos};
                    vertexes[2].position = {currentXPos + TILE_WIDTH, currentYPos + TILE_HEIGHT};
                    vertexes[3].position = {currentXPos, currentYPos + TILE_HEIGHT};

                    // Second, calculate the texture rect and apply the correct texture coordinates to the vertexes.
                    sf::FloatRect textureRect = static_cast<sf::FloatRect>(calculateTextureRect(tileID, static_cast<int>(TILE_WIDTH),
                                                                                                static_cast<int>(TILE_WIDTH), TOTAL_TILE_COLUMNS));
                    vertexes[0].texCoords = {textureRect.left, textureRect.top};
                    vertexes[1].texCoords = {textureRect.left + textureRect.width, textureRect.top};
                    vertexes[2].texCoords = {textureRect.left + textureRect.width, textureRect.top + textureRect.height};
                    vertexes[3].texCoords = {textureRect.left, textureRect.top + textureRect.height};

                    // These four vertexes represent one tile in the map.
                    // Update the TiledMap by pushing these vertexes into it.
                    tiledMap.addTile(vertexes);
                }
                // Update the horizontal position for the next tile (column) in the current row.
                currentXPos += TILE_WIDTH;
            }
            // Reset the x-position to 0 since a new row will be processed
            currentXPos = 0;
            // Update the y-position for the next row of tiles.
            currentYPos += TILE_HEIGHT;
        }
        // Once we reach here, we move onto the next layer of tiles, if any are _goLeft.
    }
}