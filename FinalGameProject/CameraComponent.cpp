// Daniel Rodriguez : CS003A
// Super Mario but in SFML! | Final Game Project
#include "CameraComponent.h"

const sf::View& CameraComponent::getView()
{
    return this->_camera;
}

void CameraComponent::followObject(GameObject *objectToFollow)
{
    this->_objectToFollow = objectToFollow;
}

void CameraComponent::setCenter(const sf::Vector2f& centerPosition)
{
    this->_camera.setCenter(centerPosition);
}

void CameraComponent::rotate(float angle)
{
    this->_camera.rotate(angle);
}

void CameraComponent::setSize(const sf::Vector2f& size)
{
    sf::Vector2f oldCenter = this->_camera.getCenter();

    this->_camera.setSize(size);

    sf::Vector2f newCenter = this->_camera.getCenter();

    sf::Vector2f centerDiff = newCenter - oldCenter;

    this->_objectToFollow->setPosition(this->_objectToFollow->getPosition() + centerDiff);
}

void CameraComponent::move(const sf::Vector2f &offset)
{
    this->_camera.move(offset);
}


void CameraComponent::setRotation(float angle)
{
    this->_camera.setRotation(angle);
}

void CameraComponent::update(const sf::Vector2f& offset)
{
    if (this->_objectToFollow)
    {
        sf::FloatRect bounds = _objectToFollow->getBounds();
        this->_camera.setCenter((bounds.left + bounds.width / 2.f) + offset.x, (bounds.top + bounds.height / 2.f) + offset.y);
    }
}

void CameraComponent::zoom(float factor)
{
    this->_camera.zoom(factor);
}