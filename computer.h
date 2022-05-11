#ifndef _COMPUTER_H
#define _COMPUTER_H
#include "player.h"
#include "game.h"

class Computer : public Player {
    public:
    Computer();
    Computer(Player &&p);
    void makeMove(Game &g, int i) override;
};

#endif