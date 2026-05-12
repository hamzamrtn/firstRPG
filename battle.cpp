//
// Created by martin on 12/05/26.
//

#include "battle.h"
bool Battle::IsOver() const {
    return player_.GetHp() <= 0 || enemy_.GetHp() <= 0;
}

void Battle::Start() {}
void Battle::PlayerTurn() {}
void Battle::EnemyTurn() {}