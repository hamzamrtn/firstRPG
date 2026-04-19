//
// Created by martin on 18/04/26.
//

#include "Character.h"

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

void Character::attack(Character &other, const int dmg)
{
    other.takeDamage(dmg);
}

void Character::takeDamage(const int dmg)
{
    hp -= dmg;
    if (hp < 0)
        hp = 0;
}

void Character::changeSpeed(const int spd)
{
    speed = spd;
}
