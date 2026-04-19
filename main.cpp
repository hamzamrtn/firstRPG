#include <iostream>
#include <unistd.h>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "Character.h"
#include "Weapon.h"


int main() {
    std::cout << "Starting Game..." << std::endl;

    Player plr;
    Enemy enemy;
    constexpr int dmg = 25;

    int i = 0;
    while (plr.isAlive())
    {
        enemy.attack(plr, dmg);
        std::cout << "Round " << ++i << " | Took " << dmg << " damage | HP: " << plr.getHp() << std::endl;
        sleep(1);
        if (!plr.isAlive())
        {
            std::cout << "Player is dead" << std::endl;
        }
    }

    return 0;
}
