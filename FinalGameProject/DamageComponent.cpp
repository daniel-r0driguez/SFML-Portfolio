// Daniel Rodriguez : CS003A
// Super Mario but in SFML! | Final Game Project
#include "DamageComponent.h"

DamageComponent::DamageComponent()
: DamageComponent(0,0)
{

}

DamageComponent::DamageComponent(int baseDamage)
: DamageComponent(baseDamage, 0)
{

}

DamageComponent::DamageComponent(int baseDamage, int bonusDamage)
{
    this->_baseDamage = baseDamage;
    this->_bonusDamage = bonusDamage;
}

void DamageComponent::setBaseDamage(int baseDamageAmount)
{
    this->_baseDamage = baseDamageAmount;
}

void DamageComponent::setBonusDamage(int bonusDamageAmount)
{
    this->_bonusDamage = bonusDamageAmount;
}

int DamageComponent::getTotalDamage() const
{
    return this->_baseDamage + this->_bonusDamage;
}