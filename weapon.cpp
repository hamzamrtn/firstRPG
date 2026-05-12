//
// Created by martin on 18/04/26.
//

#include "weapon.h"

// getters
int Weapon::GetWeaponDamage() const {
    if (weapon_enhanced_) {
        return weapon_damage_ * enhanced_multiplier_;
    }
    return weapon_damage_;
}

bool Weapon::IsEnhanced() const { return weapon_enhanced_; }

int Weapon::GetEnhancedMultiplier() const { return enhanced_multiplier_; };

// setters
void Weapon::SetEnhanced(const bool enhanced) { weapon_enhanced_ = enhanced; }

void Weapon::SetEnhancedMultiplier(const int multiplier) {
    enhanced_multiplier_ = multiplier;
}
