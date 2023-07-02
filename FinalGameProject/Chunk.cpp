// Daniel Rodriguez : CS003A
// Super Mario but in SFML! | Final Game Project
#include "Chunk.h"
#include "iostream"

Chunk::Chunk()
: Chunk({0, 0}, {0, 0})
{

}

Chunk::Chunk(const sf::Vector2i& dimensions, const sf::Vector2i& position)
: _tilesInChunk(sf::Quads, sf::VertexBuffer::Static)
{
    this->_tileWidth = dimensions.x;
    this->_tileHeight = dimensions.y;
    this->_position = position;
    this->_size = 0;
    this->_tilesInChunk.create(this->_tileWidth * this->_tileHeight * 4);
}

sf::Vector2i Chunk::getPosition() const
{
    return this->_position;
}

bool Chunk::addTile(const std::vector<sf::Vertex>& vertexes)
{
    if (canAddTile())
    {
        this->_tilesInChunk.update(vertexes.data(), vertexes.size(), _size);
        this->_size += static_cast<int>(vertexes.size());
        return true;
    }
    return false;
}

bool Chunk::canAddTile() const
{
    return this->_size + 4 <= this->_tilesInChunk.getVertexCount();
}

void Chunk::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(this->_tilesInChunk, states);
}