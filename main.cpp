#include <iostream>
#include "character.h"
#include "weapon.h"

int main() {
    Player plr;
    Enemy enemy;

    std::cout << "=== Initial Status ===\n";
    std::cout << "Player HP: " << plr.getHp() << '\n';
    std::cout << "Enemy HP: " << enemy.getHp() << "\n\n";

    plr.setWeapon("Sword", 25, false, 1);
    enemy.setWeapon("Mace", 15, false, 1);

    std::cout << "=== Battle Start ===\n";

    int round = 1;
    while (plr.isAlive() && enemy.isAlive()) {
        std::cout << "Round " << round << '\n';

        plr.attack(enemy);
        std::cout << "Player attacks -> Enemy HP: " << enemy.getHp() << '\n';

        if (!enemy.isAlive())
            break;

        enemy.attack(plr);
        std::cout << "Enemy attacks -> Player HP: " << plr.getHp() << "\n\n";

        round++;
    }

    std::cout << "=== Result ===\n";
    if (plr.isAlive())
        std::cout << "Player wins\n";
    else
        std::cout << "Enemy wins\n";

    return 0;
}
