#include "PhaserAnimatedSprite.h"
#include "iostream"

PhaserAnimatedSprite::PhaserAnimatedSprite()
: sprite()
{
    this->velocity = {0.f, 0.f};
    this->acceleration = 4000.f;
    this->friction = 2000.f;
    this->maxSpeed = 350.f;
    this->direction = Direction::DOWN;
}

PhaserAnimatedSprite::PhaserAnimatedSprite(const sf::Texture &texture, int rows, int columns)
{
    this->velocity = {0.f, 0.f};
    this->acceleration = 4000.f;
    this->friction = 2000.f;
    this->maxSpeed = 350.f;
    this->direction = Direction::DOWN;
    setup(texture, rows, columns);
}

void PhaserAnimatedSprite::animate()
{
    this->textureRect.top = this->direction * this->textureRect.height;
    if (this->clock.getElapsedTime().asMilliseconds() > this->_timeInterval)
    {
        (this->textureRect.left + this->textureRect.width >= this->sprite.getTexture()->getSize().x) ?
        this->textureRect.left = 0 : this->textureRect.left += this->textureRect.width;
        clock.restart();
    }
    this->sprite.setTextureRect(this->textureRect);
}

void PhaserAnimatedSprite::setup(const sf::Texture &texture, int rows, int columns)
{
    this->sprite.setTexture(texture);
    this->setupIntRect(texture.getSize(), rows, columns);
    this->sprite.setTextureRect(this->textureRect);
}

void PhaserAnimatedSprite::setupIntRect(const sf::Vector2u &size, int rows, int columns)
{
    this->textureRect.width = static_cast<int> (floor(static_cast<float>(size.x) / static_cast<float>(columns) + 0.5));
    this->textureRect.height = int(size.y) / rows;
    this->textureRect.left = 0;
    this->textureRect.top = 0;
}

int PhaserAnimatedSprite::getTimeInterval() const
{
    return _timeInterval;
}

void PhaserAnimatedSprite::setTimeInterval(int timeInterval)
{
    this->_timeInterval = timeInterval;
}

void PhaserAnimatedSprite::applyFriction(float dt)
{
    // Going left
    if (this->velocity.x < 0)
    {
        this->velocity.x = std::min(this->velocity.x + this->friction * dt, 0.f);
    }
    // Going right
    if (this->velocity.x > 0)
    {
        this->velocity.x = std::max(this->velocity.x - this->friction * dt, 0.f);
    }
    // Going up
    if (this->velocity.y < 0)
    {
        this->velocity.y = std::min(this->velocity.y + this->friction * dt, 0.f);
    }
    // Going down
    if (this->velocity.y > 0)
    {
        this->velocity.y = std::max(this->velocity.y - this->friction * dt, 0.f);
    }
}

void PhaserAnimatedSprite::move(float dt)
{
    if (sf::Keyboard::isKeyPressed(this->_leftKey))
    {
        this->velocity.x += -this->acceleration * dt;
        this->direction = LEFT;
    }
    if (sf::Keyboard::isKeyPressed(this->_rightKey))
    {
        this->velocity.x += this->acceleration * dt;
        this->direction = RIGHT;
    }
    if (sf::Keyboard::isKeyPressed(this->_upKey))
    {
        this->velocity.y += -this->acceleration * dt;
        this->direction = UP;
    }
    if (sf::Keyboard::isKeyPressed(this->_downKey))
    {
        this->velocity.y += this->acceleration * dt;
        this->direction = DOWN;
    }
    if (std::abs(this->velocity.x) > this->maxSpeed)
    {
        this->velocity.x = (this->velocity.x > 0) ? this->maxSpeed : -this->maxSpeed;
    }
    if (std::abs(this->velocity.y) > this->maxSpeed)
    {
        this->velocity.y = (this->velocity.y > 0) ? this->maxSpeed : -this->maxSpeed;
    }
    this->sprite.move(this->velocity * dt);
    applyFriction(dt);
}

void PhaserAnimatedSprite::eventHandler(sf::RenderWindow &window, sf::Event event)
{

}

void PhaserAnimatedSprite::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(this->sprite);
}

void PhaserAnimatedSprite::update(float dt)
{
    animate();
    move(dt);
}

void PhaserAnimatedSprite::setUpKey(sf::Keyboard::Key upKey)
{
    this->_upKey = upKey;
}

void PhaserAnimatedSprite::setDownKey(sf::Keyboard::Key downKey)
{
    this->_downKey = downKey;
}

void PhaserAnimatedSprite::setLeftKey(sf::Keyboard::Key leftKey)
{
    this->_leftKey = leftKey;
}

void PhaserAnimatedSprite::setRightKey(sf::Keyboard::Key rightKey)
{
    this->_rightKey = rightKey;
}
