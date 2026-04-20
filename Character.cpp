//
// Created by martin on 18/04/26.
//

#include "Character.h"

// getters
bool Character::isAlive() const
{
    return hp > 0;
}

int Character::getHp() const
{
    return hp;
}

int Character::getSpeed() const
{
    return speed;
}

Weapon& Character::getWeapon() const
{
    return *weapon;
}

// setters
void Character::changeSpeed(const int spd)
{
    speed = spd;
}

bool Character::setWeapon(const std::string& choice)
{
    delete weapon;
    weapon = nullptr;
    if (choice == "Sword")
        weapon = new Sword;
    else if (choice == "Mace")
        weapon = new Mace;
    else if (choice == "Bow")
        weapon = new Bow;
    else
        return false;
    return true;
}

// mechanics
void Character::attack(Character &other)
{
    other.takeDamage(this->getWeapon().getWeaponDamage());
}

void Character::takeDamage(const int dmg)
{
    hp -= dmg;
    if (hp < 0)
        hp = 0;
}
