// Daniel Rodriguez : CS003A
// Super Mario but in SFML! | Final Game Project
#ifndef FINALPROJECTGAME_CHUNK_H
#define FINALPROJECTGAME_CHUNK_H
#include "SFML/Graphics.hpp"

class Chunk : public sf::Drawable {
private:
    sf::Vector2i _position; // mutable
    int _tileHeight; // immutable after construction
    int _tileWidth; // immutable after construction
    sf::VertexBuffer _tilesInChunk; // can only add tiles.
    int _size;

public:
    Chunk();
    Chunk(const sf::Vector2i& dimensions, const sf::Vector2i& position);
    sf::Vector2i getPosition() const;
    bool addTile(const std::vector<sf::Vertex>& vertexes);
    bool canAddTile() const;
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

};


#endif //FINALPROJECTGAME_CHUNK_H
