// Created by martin on 18/04/26.

#ifndef MYRPG_WEAPON_H
#define MYRPG_WEAPON_H

constexpr int kFistDamage = 5;
constexpr int kWeaponDamage = 10;

enum class WeaponType { kSword, kMace, kBow, kFists };

class Weapon {
public:
    // general constructor
    explicit Weapon(const int weapon_damage = kWeaponDamage,
                    const bool weapon_enhanced = false,
                    const int enhanced_multiplier = 1)
        : weapon_damage_(weapon_damage),
          weapon_enhanced_(weapon_enhanced),
          enhanced_multiplier_(enhanced_multiplier) {
        if (weapon_damage <= 0) {
            weapon_damage_ = kWeaponDamage;
        }

        if (enhanced_multiplier < 1) {
            enhanced_multiplier_ = 1;
        }
    }

    // virtual destructor
    virtual ~Weapon() = default;

    // getters
    [[nodiscard]] int GetWeaponDamage() const;

    [[nodiscard]] bool IsEnhanced() const;

    [[nodiscard]] int GetEnhancedMultiplier() const;

    // setters
    void SetEnhanced(bool enhanced);

    void SetEnhancedMultiplier(int multiplier);

    // methods
    virtual Weapon* Clone() const = 0;

private:
    // general weapon attributes
    int weapon_damage_;
    bool weapon_enhanced_;
    int enhanced_multiplier_;

    // TODO: attack range
};

class Fists final : public Weapon {
public:
    explicit Fists(const int weapon_damage = kFistDamage,
                   const bool weapon_enhanced = false,
                   const int enhanced_multiplier = 1)
        : Weapon(weapon_damage, weapon_enhanced, enhanced_multiplier) {}

    Weapon* Clone() const override { return new Fists(*this); }
};

class Sword final : public Weapon {
public:
    explicit Sword(const int weapon_damage = kWeaponDamage,
                   const bool weapon_enhanced = false,
                   const int enhanced_multiplier = 1)
        : Weapon(weapon_damage, weapon_enhanced, enhanced_multiplier) {}

    Weapon* Clone() const override { return new Sword(*this); }
};

class Mace final : public Weapon {
public:
    explicit Mace(const int weapon_damage = kWeaponDamage,
                  const bool weapon_enhanced = false,
                  const int enhanced_multiplier = 1)
        : Weapon(weapon_damage, weapon_enhanced, enhanced_multiplier) {}

    Weapon* Clone() const override { return new Mace(*this); }
};

class Bow final : public Weapon {
public:
    explicit Bow(const int weapon_damage = kWeaponDamage,
                 const bool weapon_enhanced = false,
                 const int enhanced_multiplier = 1)
        : Weapon(weapon_damage, weapon_enhanced, enhanced_multiplier) {}

    Weapon* Clone() const override { return new Bow(*this); }
};

#endif  // MYRPG_WEAPON_H