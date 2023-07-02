// Daniel Rodriguez : CS003A
// Super Mario but in SFML! | Final Game Project
#include "Bitmask.h"

Bitmask::Bitmask()
{
    this->_mask = 0;
}

Bitmask::Bitmask(const Bitmask& otherBitmask)
{
    this->_mask = otherBitmask._mask;
}

void Bitmask::setBitmask(const Bitmask& otherBitmask)
{
    this->_mask = otherBitmask._mask;
}

void Bitmask::setBitOn(int index)
{
    this->_mask |= (1 << index);
}

bool Bitmask::getBit(int index) const
{
    return (this->_mask & (1 << index)) != 0;
}

void Bitmask::setBitOff(int index)
{
    this->_mask &= ~(1 << index);
}

void Bitmask::setBit(int index, bool on)
{
    if (on)
    {
        this->setBitOn(index);
    }
    else
    {
        this->setBitOff(index);
    }
}

Bitmask& Bitmask::operator=(const Bitmask &otherBitmask)
= default;

Bitmask Bitmask::operator&(const Bitmask &otherBitmask) const
{
    Bitmask result;
    result._mask = this->_mask & otherBitmask._mask;
    return result;
}

Bitmask Bitmask::operator^(const Bitmask &otherBitmask) const
{
    Bitmask result;
    result._mask = this->_mask ^ otherBitmask._mask;
    return result;
}

Bitmask Bitmask::operator|(const Bitmask &otherBitmask) const
{
    Bitmask result;
    result._mask = this->_mask | otherBitmask._mask;
    return result;
}

Bitmask Bitmask::operator~() const
{
    Bitmask result;
    result._mask = ~this->_mask;
    return result;
}