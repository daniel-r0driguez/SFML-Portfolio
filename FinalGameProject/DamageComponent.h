// Daniel Rodriguez : CS003A
// Super Mario but in SFML! | Final Game Project
#ifndef FINALPROJECTGAME_DAMAGECOMPONENT_H
#define FINALPROJECTGAME_DAMAGECOMPONENT_H

class DamageComponent {
private:
    int _baseDamage;
    int _bonusDamage;

public:
    DamageComponent();
    explicit DamageComponent(int baseDamage);
    DamageComponent(int baseDamage, int bonusDamage);
    void setBaseDamage(int baseDamageAmount);
    void setBonusDamage(int bonusDamageAmount);

    int getTotalDamage() const;
};


#endif //FINALPROJECTGAME_DAMAGECOMPONENT_H
