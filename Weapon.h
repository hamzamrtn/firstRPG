//
// Created by martin on 18/04/26.
//

#ifndef MYRPG_WEAPON_H
#define MYRPG_WEAPON_H

constexpr int FIST_DAMAGE = 5;
constexpr int WEAPON_DAMAGE = 10;

class Weapon {
public:
    // general constructor
    explicit Weapon(int weaponDamage = WEAPON_DAMAGE, bool weaponEnhanced = false, int enhancedMultiplier = 1)
        : weaponDamage(weaponDamage), weaponEnhanced(weaponEnhanced), enhancedMultiplier(enhancedMultiplier)
    {
        if (weaponDamage <= 0) this->weaponDamage = WEAPON_DAMAGE;
        if (enhancedMultiplier < 1) this->enhancedMultiplier = 1;
    }

    // virtual destructor
    virtual ~Weapon() = default;

    // getters
    [[nodiscard]] int getWeaponDamage() const;
    [[nodiscard]] bool isEnhanced() const;
    [[nodiscard]] int getEnhancedMultiplier() const;

    // setters
    void setEnhanced(bool enhanced);
    void setEnhancedMultiplier(int multiplier);

    // methods
    virtual Weapon* clone() const = 0;

private:
    // general weapon attributes
    int weaponDamage;
    bool weaponEnhanced = false;
    int enhancedMultiplier;
    // TODO attack range
};

class Fists : public Weapon {
public:
    explicit Fists(int weaponDamage = FIST_DAMAGE, bool weaponEnhanced = false, int enhancedMultiplier = 1)
    : Weapon(weaponDamage, weaponEnhanced, enhancedMultiplier)
    {}

    Weapon* clone() const override
    {
        return new Fists(*this);
    }
};

class Sword : public Weapon {
public:
    explicit Sword(int weaponDamage = WEAPON_DAMAGE, bool weaponEnhanced = false, int enhancedMultiplier = 1)
    : Weapon(weaponDamage, weaponEnhanced, enhancedMultiplier)
    {}

    Weapon* clone() const override
    {
        return new Sword(*this);
    }
};

class Mace : public Weapon {
public:
    explicit Mace(int weaponDamage = WEAPON_DAMAGE, bool weaponEnhanced = false, int enhancedMultiplier = 1)
    : Weapon(weaponDamage, weaponEnhanced, enhancedMultiplier)
    {}

    Weapon* clone() const override
    {
        return new Mace(*this);
    }
};

class Bow : public Weapon {
public:
    explicit Bow(int weaponDamage = WEAPON_DAMAGE, bool weaponEnhanced = false, int enhancedMultiplier = 1)
    : Weapon(weaponDamage, weaponEnhanced, enhancedMultiplier)
    {}

    Weapon* clone() const override
    {
        return new Bow(*this);
    }
};

#endif //MYRPG_WEAPON_H
