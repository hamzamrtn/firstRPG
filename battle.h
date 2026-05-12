//
// Created by martin on 12/05/26.
//

#ifndef MYRPG_BATTLE_H
#define MYRPG_BATTLE_H

#include "character.h"

class Battle {
public:
    Battle(Character& player, Character& enemy)
        : player_(player), enemy_(enemy) {};

    // getter setter
    bool IsOver() const;

    // mechanics
    void Start();
    void PlayerTurn();
    void EnemyTurn();

private:
    Character& player_;
    Character& enemy_;
};

#endif  // MYRPG_BATTLE_H
