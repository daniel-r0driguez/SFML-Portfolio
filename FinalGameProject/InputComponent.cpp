// Daniel Rodriguez : CS003A
// Super Mario but in SFML! | Final Game Project
#include "InputComponent.h"

InputComponent::InputComponent() = default;

void InputComponent::update()
{
    this->_lastFrameKeys = this->_thisFrameKeys;
    this->_thisFrameKeys.setBit(Key::LEFT_KEY, sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A));
    this->_thisFrameKeys.setBit(Key::RIGHT_KEY, sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D));
    this->_thisFrameKeys.setBit(Key::DOWN_KEY, sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S));
    this->_thisFrameKeys.setBit(Key::UP_KEY, sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W));
    this->_thisFrameKeys.setBit(Key::ESC_KEY, sf::Keyboard::isKeyPressed(sf::Keyboard::Escape));
    this->_thisFrameKeys.setBit(Key::TAUNT_KEY, sf::Keyboard::isKeyPressed(sf::Keyboard::E));
}

bool InputComponent::isKeyPressed(Key keycode)
{
    return this->_thisFrameKeys.getBit(keycode);
}

bool InputComponent::wasKeyJustPressed(Key keycode)
{
    return !this->_lastFrameKeys.getBit(keycode) && this->_thisFrameKeys.getBit(keycode);
}

bool InputComponent::wasKeyReleased(Key keycode)
{
    return this->_lastFrameKeys.getBit(keycode) && !_thisFrameKeys.getBit(keycode);
}