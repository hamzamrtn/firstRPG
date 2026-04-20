//
// Created by martin on 18/04/26.
//

#ifndef MYRPG_CHARACTER_H
#define MYRPG_CHARACTER_H
#include <string>
#include "Weapon.h"

constexpr int PLR_SPEED = 7;
constexpr int PLR_HP = 100;
constexpr int ENE_SPEED = 5;
constexpr int ENE_HP = 50;

class Character {
public:
    // general constructor
    explicit Character(int hp, int speed, const std::string& weapon) : hp(hp), speed(speed)
    {
        if (weapon == "Sword")
            this->weapon = new Sword();
        else if (weapon == "Mace")
            this->weapon = new Mace();
        else if (weapon == "Bow")
            this->weapon = new Bow();
        else
            this->weapon = new Fists();
    }

    // copy constructor
    Character(const Character& other) : hp(other.hp), speed(other.speed)
    {
        weapon = other.weapon->clone();
    }

    // assignment operator
    Character& operator=(const Character& other)
    {
        if (this != &other)
        {
            hp = other.hp;
            speed = other.speed;
            delete weapon;
            weapon = other.weapon->clone();
        }
        return *this;
    }

    // destructor
    ~Character()
    {
        delete weapon;
    }

    // getters
    [[nodiscard]] bool isAlive() const;

    [[nodiscard]] int getHp() const;

    [[nodiscard]] int getSpeed() const;

    [[nodiscard]] Weapon& getWeapon() const;

    // setters
    void changeSpeed(int spd);

    bool setWeapon(const std::string& choice);

    // mechanics
    void attack(Character &other);

    void takeDamage(int dmg);

private:
    int hp;
    int speed;
    // TODO position / coordinates
    Weapon* weapon;
};

class Player : public Character {
public:
    // player constructor
    explicit Player(int hp = PLR_HP, int speed = PLR_SPEED, const std::string& weapon = "Fists") : Character(hp, speed, weapon)
    {}
};

class Enemy : public Character {
public:
    // enemy constructor
    explicit Enemy(int hp = ENE_HP, int speed = ENE_SPEED, const std::string& weapon = "Fists") : Character(hp, speed, weapon)
    {}
};

class Boss : public Enemy {
public:
    // boss constructor
    explicit Boss(int hp = 75, int speed = 10, const std::string& weapon = "Fists") : Enemy(hp, speed, weapon)
    {}
};

#endif //MYRPG_CHARACTER_H
