// Daniel Rodriguez : CS003A
// Super Mario but in SFML! | Final Game Project
#ifndef FINALPROJECTGAME_TILEDMAP_H
#define FINALPROJECTGAME_TILEDMAP_H
#include "SFML/Graphics.hpp"
#include "GameObject.h"
#include "Chunk.h"
#include "map"

class TiledMap : public sf::Drawable {
private:
    sf::RenderStates _renderStates;
    std::map<std::pair<int, int>, Chunk*> _chunksInMap;
    Chunk* _currentChunk;
    int _width;
    int _height;
    int _chunkWidth;
    int _chunkHeight;

public:
    TiledMap(int chunkWidth, int chunkHeight);
    ~TiledMap() override;
    void setTexture(const sf::Texture& tileSet);
    int getMapHeight() const;
    int getChunkHeight() const;
    int getMapWidth() const;
    int getChunkWidth() const;
    void setMapHeight(int mapHeight);
    void setMapWidth(int mapWidth);
    const sf::RenderStates& getRenderStates() const;
    void addTile(const std::vector<sf::Vertex>& vertexes);
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    void clearMap();

private:
    TiledMap();
    void createNewChunk(const sf::Vertex& positionOfChunk);
};


#endif //FINALPROJECTGAME_TILEDMAP_H
