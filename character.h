//
// Created by martin on 18/04/26.
//

#ifndef MYRPG_CHARACTER_H_H
#define MYRPG_CHARACTER_H_H

#include "weapon.h"

constexpr int kPlrMaxHp = 100;
constexpr int kPlrSpeed = 7;
constexpr int kEneMaxHp = 100;
constexpr int kEneSpeed = 5;
constexpr int kBossMaxHp = 250;
constexpr int kBossSpeed = 10;

enum class CharacterState { kIdle, kAttacking, kDefending, kDead };

class Character {
public:
    // general constructor
    explicit Character(const int max_hp, const int defense, const int speed,
                       const WeaponType weapon_type);

    // COPY constructor
    Character(const Character& other);

    // ASSIGNMENT operator
    Character& operator=(const Character& other);

    // destructor
    virtual ~Character() { delete weapon_; }

    // getters
    [[nodiscard]] bool IsAlive() const;
    [[nodiscard]] int GetHp() const;
    [[nodiscard]] int GetDefense() const;
    [[nodiscard]] int GetSpeed() const;
    [[nodiscard]] const Weapon& GetWeapon() const;
    [[nodiscard]] CharacterState GetState() const;
    [[nodiscard]] int GetCriticalChance() const;
    [[nodiscard]] int GetCriticalMultiplier() const;

    // setters
    void SetSpeed(int spd);
    bool SetWeapon(WeaponType weapon_type, int damage = kWeaponDamage,
                   bool is_enhanced = false, int enhanced_multiplier = 1);
    void SetState(CharacterState state);
    void SetDefense(int defense);
    void SetCriticalChance(int chance);
    void SetCriticalMultiplier(int multiplier);

    // mechanics
    void Attack(Character& other) const;
    void TakeDamage(int dmg);
    [[nodiscard]] int CalculateAttackDamage() const;
    [[nodiscard]] int CalculateReceivedDamage(int dmg) const;
    [[nodiscard]] bool IsCriticalHit() const;
    void Heal(int amount);
    void HealToFull();

    virtual void SpecialAbility() = 0;

private:
    int hp_;
    int max_hp_;
    int defense_;
    int speed_;
    Weapon* weapon_;
    CharacterState state_;
    int critical_chance_;
    int critical_multiplier_;
    // TODO position / coordinates
};

class Player final : public Character {
public:
    // player constructor
    explicit Player(const int max_hp = kPlrMaxHp, const int defense = 0,
                    const int speed = kPlrSpeed,
                    const WeaponType weapon_type = WeaponType::kFists)
        : Character(max_hp, defense, speed, weapon_type) {}

    void SpecialAbility() override { HealToFull(); };
};

class Enemy : public Character {
public:
    // enemy constructor
    explicit Enemy(const int max_hp = kEneMaxHp, const int defense = 0,
                   const int speed = kEneSpeed,
                   const WeaponType weapon_type = WeaponType::kFists)
        : Character(max_hp, defense, speed, weapon_type) {}

    void SpecialAbility() override { HealToFull(); };
};

class Boss final : public Enemy {
public:
    // boss constructor
    explicit Boss(const int max_hp = kBossMaxHp, const int defense = 0,
                  const int speed = kBossSpeed,
                  const WeaponType weapon_type = WeaponType::kFists)
        : Enemy(max_hp, defense, speed, weapon_type) {}

    void SpecialAbility() override { HealToFull(); };
};

#endif  // MYRPG_CHARACTER_H_H
