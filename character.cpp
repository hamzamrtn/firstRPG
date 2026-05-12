//
// Created by martin on 18/04/26.
//

#include "character.h"

#include <cstdlib>
#include <stdexcept>

Character::Character(const int max_hp, const int defense, const int speed,
                     const WeaponType weapon_type)
    : hp_(max_hp),
      max_hp_(max_hp),
      defense_(defense),
      speed_(speed),
      weapon_(nullptr),
      state_(CharacterState::kIdle),
      critical_chance_(10),
      critical_multiplier_(2) {
    SetWeapon(weapon_type);
}

Character::Character(const Character& other)
    : hp_(other.hp_),
      max_hp_(other.max_hp_),
      defense_(other.defense_),
      speed_(other.speed_),
      state_(other.state_),
      critical_chance_(other.critical_chance_),
      critical_multiplier_(other.critical_multiplier_) {
    weapon_ = other.weapon_ ? other.weapon_->Clone() : nullptr;
}

Character& Character::operator=(const Character& other) {
    if (this != &other) {
        hp_ = other.hp_;
        max_hp_ = other.max_hp_;
        defense_ = other.defense_;
        speed_ = other.speed_;

        delete weapon_;
        weapon_ = other.weapon_ ? other.weapon_->Clone() : nullptr;

        state_ = other.state_;
        critical_chance_ = other.critical_chance_;
        critical_multiplier_ = other.critical_multiplier_;
    }
    return *this;
}

// getters
bool Character::IsAlive() const { return hp_ > 0; }

int Character::GetHp() const { return hp_; }

int Character::GetDefense() const { return defense_; }

int Character::GetSpeed() const { return speed_; }

const Weapon& Character::GetWeapon() const { return *weapon_; }

CharacterState Character::GetState() const { return state_; }

int Character::GetCriticalChance() const { return critical_chance_; }

int Character::GetCriticalMultiplier() const { return critical_multiplier_; }

// setters
void Character::SetSpeed(const int spd) { speed_ = spd; }

bool Character::SetWeapon(const WeaponType weapon_type, int damage,
                          const bool is_enhanced, int enhanced_multiplier) {
    bool is_input_valid = true;

    if (damage <= 0 || enhanced_multiplier < 1) {
        damage = kFistDamage;  // Usa la costante definita in weapon.h
        enhanced_multiplier = 1;
        is_input_valid = false;
    }

    Weapon* new_weapon = nullptr;
    switch (weapon_type) {
        case WeaponType::kSword:
            new_weapon = new Sword(damage, is_enhanced, enhanced_multiplier);
            break;
        case WeaponType::kMace:
            new_weapon = new Mace(damage, is_enhanced, enhanced_multiplier);
            break;
        case WeaponType::kBow:
            new_weapon = new Bow(damage, is_enhanced, enhanced_multiplier);
            break;
        case WeaponType::kFists:
        default:
            new_weapon = new Fists(damage, is_enhanced, enhanced_multiplier);
            break;
    }

    delete weapon_;
    weapon_ = new_weapon;
    return is_input_valid;
}

void Character::SetState(const CharacterState state) { state_ = state; }

void Character::SetDefense(const int defense) {
    if (defense < 0) {
        throw std::invalid_argument("Defense cannot be negative.");
    }

    defense_ = defense;
}

void Character::SetCriticalChance(const int chance) {
    if (chance < 0 || chance > 100) {
        throw std::out_of_range("Critical chance must be between 0 and 100.");
    }

    critical_chance_ = chance;
}

void Character::SetCriticalMultiplier(const int multiplier) {
    if (multiplier < 2) {
        throw std::invalid_argument("Critical multiplier must be at least 2.");
    }

    critical_multiplier_ = multiplier;
}

// mechanics
void Character::Attack(Character& other) const {
    other.TakeDamage(CalculateAttackDamage());
}

void Character::TakeDamage(const int dmg) {
    if (const auto final_damage = CalculateReceivedDamage(dmg);
        final_damage >= hp_) {
        hp_ = 0;
    } else {
        hp_ -= final_damage;
    }
}

int Character::CalculateAttackDamage() const {
    int damage = weapon_->GetWeaponDamage();

    if (IsCriticalHit()) {
        damage *= critical_multiplier_;
    }

    return damage;
}

int Character::CalculateReceivedDamage(const int dmg) const {
    if (dmg <= 0) {
        throw std::invalid_argument("Damage must be positive.");
    }

    int final_damage = dmg - defense_;

    if (final_damage <= 0) {
        final_damage = 1;
    }

    return final_damage;
}

bool Character::IsCriticalHit() const {
    return std::rand() % 100 < critical_chance_;
}

void Character::Heal(const int amount) {
    if (amount <= 0) {
        throw std::invalid_argument("Heal amount must be positive.");
    }

    if (amount >= max_hp_ - hp_) {
        hp_ = max_hp_;
    } else {
        hp_ += amount;
    }
}

void Character::HealToFull() { hp_ = max_hp_; }
