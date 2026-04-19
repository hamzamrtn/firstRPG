//
// Created by martin on 18/04/26.
//

#ifndef MYRPG_CHARACTER_H
#define MYRPG_CHARACTER_H
#include <string>
#include "Weapon.h"

constexpr int PLR_DEFAULT_SPEED = 7;
constexpr int PLR_DEFAULT_HP = 100;
constexpr int ENE_DEFAULT_SPEED = 5;
constexpr int ENE_DEFAULT_HP = 50;

class Character {
public:
    // c'tors
    explicit Character(int hp, int speed) : hp(hp), speed(speed)
    {
    }

    // methods
    [[nodiscard]] bool isAlive() const;
    [[nodiscard]] int getHp() const;
    [[nodiscard]] int getSpeed() const;
    void attack(Character &other, int dmg);
    void takeDamage(int dmg);
    void changeSpeed(int spd);

private:
    int hp;
    int speed;
    Weapon weapon;
};

class Player : public Character {
public:
    explicit Player(int hp = PLR_DEFAULT_HP, int speed = PLR_DEFAULT_SPEED) : Character(hp, speed)
    {
    }
};

class Enemy : public Character {
public:
    explicit Enemy(int hp = ENE_DEFAULT_HP, int speed = ENE_DEFAULT_SPEED) : Character(hp, speed)
    {
    }
};

class Boss : public Enemy {
public:
    explicit Boss(int hp = 75, int speed = 10) : Enemy(hp, speed)
    {
    }
};

#endif //MYRPG_CHARACTER_H
