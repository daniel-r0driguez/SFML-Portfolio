// Daniel Rodriguez : CS003A
// Super Mario but in SFML! | Final Game Project
#include "TiledMap.h"
#include "iostream"

TiledMap::TiledMap()
: TiledMap(0, 0)
{

}

TiledMap::TiledMap(int chunkWidth, int chunkHeight)
: _chunksInMap(),
_height(0),
_width(0)
{
    this->_currentChunk = nullptr;
    this->_chunkWidth = chunkWidth;
    this->_chunkHeight = chunkHeight;
}

TiledMap::~TiledMap()
{
    clearMap();
}

int TiledMap::getMapHeight() const
{
    return this->_height;
}

int TiledMap::getChunkHeight() const
{
    return this->_chunkHeight;
}

void TiledMap::setMapHeight(int mapHeight)
{
    this->_height = mapHeight;
}

int TiledMap::getMapWidth() const
{
    return this->_width;
}

int TiledMap::getChunkWidth() const
{
    return this->_chunkWidth;
}

void TiledMap::setMapWidth(int mapWidth)
{
    this->_width = mapWidth;
}

void TiledMap::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for (const auto& chunkPair : this->_chunksInMap)
    {
        chunkPair.second->draw(target, this->_renderStates);
    }
}

const sf::RenderStates& TiledMap::getRenderStates() const
{
    return this->_renderStates;
}

void TiledMap::addTile(const std::vector<sf::Vertex>& vertexes)
{
    if (this->_currentChunk == nullptr || !(this->_currentChunk->canAddTile()))
    {
        createNewChunk(vertexes.at(0));
    }
    if (this->_currentChunk->canAddTile())
    {
        this->_currentChunk->addTile(vertexes);
    }
}

void TiledMap::setTexture(const sf::Texture& tileSet)
{
    this->_renderStates.texture = &tileSet;
}

void TiledMap::createNewChunk(const sf::Vertex& positionOfChunk)
{
    int xPos = static_cast<int>(positionOfChunk.position.x);
    int yPos = static_cast<int>(positionOfChunk.position.y);
    this->_chunksInMap[std::pair<int, int>(xPos, yPos)] = new Chunk({this->_chunkWidth, this->_chunkHeight}, {xPos, yPos});
    this->_currentChunk = this->_chunksInMap[std::pair<int, int>(xPos, yPos)];
}

void TiledMap::clearMap()
{
    for (auto& chunk : this->_chunksInMap)
    {
        delete chunk.second;
    }
    this->_chunksInMap.clear();
    this->_currentChunk = nullptr;
    this->_width = 0;
    this->_height = 0;
    this->_renderStates.texture = nullptr;
}