//
// Created by martin on 18/04/26.
//

#include "character.h"

// getters
bool Character::isAlive() const {
    return hp > 0;
}

int Character::getHp() const {
    return hp;
}

int Character::getSpeed() const {
    return speed;
}

const Weapon &Character::getWeapon() const {
    return *weapon;
}

void Character::setHp(int hp) {
    this->hp = hp;
}

// setters
void Character::changeSpeed(const int spd) {
    speed = spd;
}

bool Character::setWeapon(const std::string &choice = "Fists", const int weapon_damage = WEAPON_DAMAGE, const bool weapon_enhanced = false,
                          const int enhanced_multiplier = 1) {
    delete weapon;
    weapon = nullptr;
    if (choice == "Sword")
        weapon = new Sword(weapon_damage, weapon_enhanced, enhanced_multiplier);
    else if (choice == "Mace")
        weapon = new Mace(weapon_damage, weapon_enhanced, enhanced_multiplier);
    else if (choice == "Bow")
        weapon = new Bow(weapon_damage, weapon_enhanced, enhanced_multiplier);
    else
        weapon = new Fists(weapon_damage, weapon_enhanced, enhanced_multiplier);
    return true;
}

// mechanics
void Character::attack(Character &other) {
    other.takeDamage(this->getWeapon().getWeaponDamage());
}

void Character::takeDamage(const int dmg) {
    hp -= dmg;
    if (hp < 0)
        hp = 0;
}
