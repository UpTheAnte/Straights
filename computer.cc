#include <iostream>
#include <string>
#include "computer.h"

Computer::Computer() {}

Computer::Computer(Player &&p) {
    hand = p.hand;
    discarded = p.discarded;
}

void Computer::makeMove(Game &g, int i) {
    std::cout << "Player" << i << " ";
    for (std::vector<Card>::iterator it = hand.begin(); it != hand.end(); ++it) {
        if (g.isLegal(*it)) {
            g.play(*it);
            hand.erase(it);
            return;
        }
    }
    discard(hand[0]);   
}
