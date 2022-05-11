#ifndef _PLAYER_H
#define _PLAYER_H
#include <vector>
#include "card.h"

class Human;
class Computer;
class Game;

class Player {
    public: 
    std::vector<Card> hand;
    std::vector<Card> discarded;
    virtual void makeMove(Game &g, int i) = 0;
    void printHand();
    void discard(Card c);
    virtual ~Player() = 0;
};

#endif