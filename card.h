#ifndef _CARD_H
#define _CARD_H
#include <iostream>
#include <string>

enum class Suit {
    C = 0, D, H, S
};

class Card {
    public:
    Suit suit;
    int rank;
    Card (const std::string &s);
    //std::istream& operator>> (std::istream& is);
};

std::ostream& operator<< (std::ostream& os, const Card &c);
bool operator==(const Card &lhs, const Card &rhs);

#endif