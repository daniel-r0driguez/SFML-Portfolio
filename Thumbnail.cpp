#include "Thumbnail.h"
#include "iostream"

Thumbnail::Thumbnail()
: Thumbnail(nullptr, {0.f, 0.f},{0.f, 0.f})
{

}

Thumbnail::Thumbnail(const sf::Texture *texture, const sf::Vector2f& size, const sf::Vector2f& position)
{
    this->_project = nullptr;
    this->_texture = texture;
    if (this->_texture != nullptr)
    {
        this->_thumbnail.setTexture(*this->_texture);
        scaleToSize(this->_texture, size);
    }
    this->_thumbnail.setPosition(position);
}

const Runnable* Thumbnail::getProject()
{
    return this->_project;
}

void Thumbnail::setTexture(const sf::Texture* texture, const sf::Vector2f& size)
{
    this->_texture = texture;
    if (this->_texture != nullptr)
    {
        this->_thumbnail.setTexture(*texture);
        scaleToSize(this->_texture, size);
    }
}

void Thumbnail::scaleToSize(const sf::Texture *texture, const sf::Vector2f& size)
{
    sf::Vector2f textureSize = static_cast<sf::Vector2f>(texture->getSize());
    float xScale = size.x / textureSize.x;
    float yScale = size.y / textureSize.y;
    this->_thumbnail.setScale(xScale, yScale);
}


sf::Vector2f Thumbnail::getPosition() const
{
    return this->_thumbnail.getPosition();
}

void Thumbnail::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(this->_thumbnail);
}

void Thumbnail::update(float dt) const
{

}

void Thumbnail::eventHandler(sf::RenderWindow& target, sf::Event event) const
{
    if (MouseEvents::isClicked(*this, target) || sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
    {
        if (this->_project)
        {
            _project->run(target);
        }
    }
}

sf::FloatRect Thumbnail::getGlobalBounds() const
{
    return this->_thumbnail.getGlobalBounds();
}

void Thumbnail::setPosition(const sf::Vector2f& position)
{
    this->_thumbnail.setPosition(position);
}

void Thumbnail::setRunnable(Runnable *runnable)
{
    this->_project = runnable;
}

sf::FloatRect Thumbnail::getLocalBounds() const
{
    return this->_thumbnail.getLocalBounds();
}
