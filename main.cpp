#include <iostream>

#include "battle.h"
#include "character.h"
#include "weapon.h"

int main() {
    Player plr;
    Enemy enemy;

    std::cout << "=== Initial Status ===" << std::endl;
    std::cout << "Player HP: " << plr.GetHp() << std::endl;
    std::cout << "Enemy HP: " << enemy.GetHp() << "\n\n";

    plr.SetWeapon(WeaponType::kSword, 25, false, 1);
    enemy.SetWeapon(WeaponType::kSword, 15, false, 1);

    std::cout << "=== Battle Start ===" << std::endl;

    int round = 1;
    while (plr.IsAlive() && enemy.IsAlive()) {
        std::cout << "Round " << round << std::endl;

        plr.Attack(enemy);
        std::cout << "Player attacks -> Enemy HP: " << enemy.GetHp() << std::endl;

        if (!enemy.IsAlive()) break;

        enemy.Attack(plr);
        std::cout << "Enemy attacks -> Player HP: " << plr.GetHp() << "\n\n";

        round++;
    }

    std::cout << "=== Result ===\n";
    if (plr.IsAlive())
        std::cout << "Player wins\n";
    else
        std::cout << "Enemy wins\n";

    return 0;
}
