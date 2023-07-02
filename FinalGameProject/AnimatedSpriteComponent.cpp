// Daniel Rodriguez : CS003A
// Super Mario but in SFML! | Final Game Project
#include "AnimatedSpriteComponent.h"

AnimatedSpriteComponent::AnimatedSpriteComponent()
: _animatedSprite(),
  _clock(),
  _textureRect()
{
    this->_timeInterval = 100;
}

AnimatedSpriteComponent::AnimatedSpriteComponent(const sf::Texture& texture, int rows, int columns)
{
    this->_timeInterval = 200;
    setup(texture, rows, columns);
}

void AnimatedSpriteComponent::setRow(int state)
{
    this->_textureRect.top = this->_textureRect.height * state;
}

void AnimatedSpriteComponent::setTexture(const sf::Texture& texture, int rows, int columns)
{
    setup(texture, rows, columns);
}

const sf::Texture& AnimatedSpriteComponent::getTexture() const
{
    return *this->_animatedSprite.getTexture();
}

void AnimatedSpriteComponent::setPosition(const sf::Vector2f& position, bool center)
{
    float x = position.x;
    float y = position.y;
    if (center)
    {
        x += (static_cast<float>(this->_textureRect.width) / 2.f);
        y += (static_cast<float>(this->_textureRect.height) / 2.f);
    }
    this->_animatedSprite.setPosition(x, y);
}

sf::Vector2f AnimatedSpriteComponent::getPosition() const
{
    return this->_animatedSprite.getPosition();
}

void AnimatedSpriteComponent::setup(const sf::Texture &texture, int rows, int columns)
{
    this->_animatedSprite.setTexture(texture);
    setupIntRect(texture.getSize(), rows, columns);
    this->_animatedSprite.setTextureRect(this->_textureRect);
    this->_animatedSprite.setOrigin(static_cast<float>(this->_textureRect.width) / 2.f,
                                    static_cast<float>(this->_textureRect.height) / 2.f);
}

void AnimatedSpriteComponent::setupIntRect(const sf::Vector2u &size, int rows, int columns)
{
    this->_textureRect.width = static_cast<int> (floor(static_cast<float>(size.x) / static_cast<float>(columns) + 0.5));
    this->_textureRect.height = int(size.y) / rows;
    this->_textureRect.left = 0;
    this->_textureRect.top = 0;
}

void AnimatedSpriteComponent::animate(int state)
{
    this->setRow(state);
    if (this->_clock.getElapsedTime().asMilliseconds() > this->_timeInterval)
    {
        (this->_textureRect.left + this->_textureRect.width >= this->_animatedSprite.getTexture()->getSize().x) ?
                this->_textureRect.left = 0 : this->_textureRect.left += this->_textureRect.width;
        _clock.restart();
    }
    this->_animatedSprite.setTextureRect(this->_textureRect);
}

void AnimatedSpriteComponent::setTimeInterval(int timeInterval)
{
    this->_timeInterval = timeInterval;
}

int AnimatedSpriteComponent::getTimeInterval() const
{
    return this->_timeInterval;
}

sf::Vector2i AnimatedSpriteComponent::getFramedSize() const
{
    return {this->_textureRect.width, this->_textureRect.height};
}

void AnimatedSpriteComponent::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(this->_animatedSprite);
}

void AnimatedSpriteComponent::setScale(const sf::Vector2f& scale)
{
    this->_animatedSprite.setScale(scale.x , scale.y);
}

void AnimatedSpriteComponent::scaleToSize(const sf::Vector2f& size)
{
    float scaleX = size.x / static_cast<float>(this->_textureRect.width);
    float scaleY = size.y / static_cast<float>(this->_textureRect.height);
    this->_animatedSprite.scale(scaleX, scaleY);
}
