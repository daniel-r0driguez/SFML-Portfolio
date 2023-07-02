#ifndef SFML_TEMPLATE_SFMLGRID_CPP
#define SFML_TEMPLATE_SFMLGRID_CPP
#include "SFMLGrid.h"

template<typename T>
sf::Vector2f SFMLGrid<T>::getPosition()
{
    if (this->ptrToPtrs != nullptr)
    {
        return (*(this->ptrToPtrs + 0) + 0)->getPosition();
    }
    else
    {
        return {0,0};
    }
}

template<typename T>
void SFMLGrid<T>::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
    if (this->ptrToPtrs != nullptr)
    {
        for (int row = 0; row < this->_rowSize; ++row)
        {
            for (int column = 0; column < this->_columnSize; ++column)
            {
                window.draw(*(*(this->ptrToPtrs + row) + column));
            }
        }
    }
}

template<typename T>
void SFMLGrid<T>::setPosition(float xPos, float yPos)
{
    if (this->ptrToPtrs != nullptr)
    {
        (*(this->ptrToPtrs + 0) + 0)->setPosition(sf::Vector2f(xPos, yPos));
    }
    setSpacingBetween();
}

template<typename T>
void SFMLGrid<T>::setSpacingBetween()
{
    if (this->ptrToPtrs != nullptr)
    {
        sf::FloatRect bounds = (*(this->ptrToPtrs + 0) + 0)->getGlobalBounds();
        float xPos = bounds.left;
        float yPos = bounds.top;
        float width = bounds.width;
        float height = bounds.height;
        for (int row = 0; row < this->_rowSize; ++row)
        {
            float xPosTemp = xPos;
            for (int column = 0; column < this->_columnSize; ++column)
            {
                (*(this->ptrToPtrs + row) + column)->setPosition(xPosTemp, yPos);
                xPosTemp += width;
            }
            yPos += height;
        }
    }
}

template<typename T>
void SFMLGrid<T>::setSpacingBetween(float xSpacing, float ySpacing)
{
    if (this->ptrToPtrs != nullptr)
    {
        sf::FloatRect bounds = (*(this->ptrToPtrs + 0) + 0)->getGlobalBounds();
        float xPos = bounds.left;
        float yPos = bounds.top;
        for (int row = 0; row < this->_rowSize; ++row)
        {
            float xPosTemp = xPos;
            for (int column = 0; column < this->_columnSize; ++column)
            {
                (*(this->ptrToPtrs + row) + column)->setPosition(xPosTemp, yPos);
                xPosTemp += xSpacing;
            }
            yPos += ySpacing;
        }
    }
}

template<typename T>
void SFMLGrid<T>::setGridElementSize(const sf::Vector2f& size)
{
    if (this->ptrToPtrs != nullptr)
    {
        for (int row  = 0; row < this->_rowSize; ++row)
        {
            for (int column = 0; column < this->_columnSize; ++column)
            {
                (*(this->ptrToPtrs + row) + column)->setSize(size);
            }
        }
        setSpacingBetween();
    }
}

template<typename T>
void SFMLGrid<T>::randomColors()
{
    if (this->ptrToPtrs != nullptr)
    {
        int red;
        int green;
        int blue;
        for (int row = 0; row < this->_rowSize; ++row)
        {
            for (int column = 0; column < this->_columnSize; ++column)
            {
                red = rand() % 256;
                green = rand() % 256;
                blue = rand() % 256;
                (*(this->ptrToPtrs + row) + column)->setFillColor(sf::Color(red, green, blue));
            }
        }
    }
}

template<typename T>
void SFMLGrid<T>::eventHandler(sf::RenderWindow& window, sf::Event event)
{
    // Pushing more rows to the bottom.
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        Grid<T>::push_back_row();
        setSpacingBetween();
    }
    // Popping rows from the bottom.
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && this->_rowSize > 1)
    {
        Grid<T>::pop_back_row();
    }
    // Pushing more columns on the left.
    if (sf::Keyboard::isKeyPressed((sf::Keyboard::Right)))
    {
        Grid<T>::push_back_column();
        setSpacingBetween();
    }
    // Popping columns on the left.
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && this->_columnSize > 1)
    {
        Grid<T>::pop_back_column();
    }

    // Up movement
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        setPosition(getPosition().x, getPosition().y - this->_velocity);
    }
    // Down movement
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        setPosition(getPosition().x, getPosition().y + this->_velocity);
    }
    // Left movement
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        setPosition(getPosition().x - this->_velocity, getPosition().y);
    }
    // Right movement
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        setPosition(getPosition().x + this->_velocity, getPosition().y);
    }
}
#endif //SFML_TEMPLATE_SFMLGRID_CPP