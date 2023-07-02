// Daniel Rodriguez : CS003A
// Super Mario but in SFML! | Final Game Project
#ifndef FINALPROJECTGAME_HEALTHCOMPONENT_H
#define FINALPROJECTGAME_HEALTHCOMPONENT_H

class HealthComponent {
private:
    int _maxHitpoints;
    int _hitpoints;

public:
    HealthComponent();
    HealthComponent(int initialHealth, int maxHealth);
    int getMaxHealth() const;
    void setMaxHealth(int maxHealthAmount);
    int getCurrentHealth() const;
    void setCurrentHealth(int healthAmount);
    void takeDamage(int damageAmount);
    void heal(int healAmount);
    bool isAlive() const;
};


#endif //FINALPROJECTGAME_HEALTHCOMPONENT_H
