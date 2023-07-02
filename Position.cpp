#ifndef SFML_TEMPLATE_POSITION_CPP
#define SFML_TEMPLATE_POSITION_CPP
#include "Position.h"

template<typename T, typename S>
void Position::center(const T& constObj, S& obj)
{
    sf::FloatRect bounds = constObj.getGlobalBounds();
    obj.setPosition({
        (bounds.left + bounds.width / 2) - (obj.getGlobalBounds().width  / 2),
        (bounds.top + bounds.height / 2) - (obj.getGlobalBounds().height  / 2)
    });
}

template<typename T, typename S>
void Position::topLeft(const T& constObj, S& obj, float xMargin, float yMargin)
{
    sf::FloatRect bounds = constObj.getGlobalBounds();
    obj.setPosition({
        bounds.left + xMargin,
        bounds.top + yMargin
    });
}

template<typename T, typename S>
void Position::bottomRight(const T& constObj, S& obj, float xMargin, float yMargin)
{
    sf::FloatRect bounds = constObj.getGlobalBounds();
    obj.setPosition({
        bounds.left + bounds.width - xMargin,
        bounds.top + bounds.height - yMargin
    });
}

#endif