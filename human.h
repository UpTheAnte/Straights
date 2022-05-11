#ifndef _HUMAN_H
#define _HUMAN_H
#include "player.h"
#include "game.h"

struct QuitException {};
struct RageQuitException {};

class Human : public Player {
    public:
    Human();
    void makeMove(Game &g, int i) override;
};

#endif