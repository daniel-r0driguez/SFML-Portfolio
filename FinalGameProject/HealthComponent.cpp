// Daniel Rodriguez : CS003A
// Super Mario but in SFML! | Final Game Project
#include "HealthComponent.h"

HealthComponent::HealthComponent()
: HealthComponent(1, 1)
{

}

HealthComponent::HealthComponent(int initialHealth, int maxHealth)
{
    this->_hitpoints = initialHealth;
    this->_maxHitpoints = maxHealth;
}

int HealthComponent::getMaxHealth() const
{
    return this->_maxHitpoints;
}

void HealthComponent::setMaxHealth(int maxHealthAmount)
{
    this->_hitpoints = (this->_hitpoints > maxHealthAmount) ? maxHealthAmount : this->_hitpoints;
    this->_maxHitpoints = maxHealthAmount;
}

int HealthComponent::getCurrentHealth() const
{
    return this->_hitpoints;
}

void HealthComponent::setCurrentHealth(int healthAmount)
{
    this->_hitpoints = healthAmount;
}

void HealthComponent::takeDamage(int damageAmount)
{
    this->_hitpoints -= damageAmount;
}

void HealthComponent::heal(int healAmount)
{
    this->_hitpoints = (this->_hitpoints + healAmount <= this->_maxHitpoints) ?
            this->_hitpoints + healAmount : this->_maxHitpoints;
}

bool HealthComponent::isAlive() const
{
    return this->_hitpoints > 0;
}
