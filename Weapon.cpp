//
// Created by martin on 18/04/26.
//

#include "Weapon.h"
// getters
int Weapon::getWeaponDamage() const
{
    return weaponDamage;
}

bool Weapon::isEnhanced() const
{
    return weaponEnhanced;
}

int Weapon::getEnhancedMultiplier() const
{
    return enhancedMultiplier;
};

// setters
void Weapon::setEnhanced(const bool enhanced)
{
    weaponEnhanced = enhanced;
}

void Weapon::setEnhancedMultiplier(const int multiplier)
{
    enhancedMultiplier = multiplier;
}