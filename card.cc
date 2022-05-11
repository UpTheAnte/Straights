#include <iostream>
#include <string>
#include "card.h"

Card::Card (const std::string &s) {
    switch (s[0]) {
        case 'A':
            rank = 1;
            break;
        case 'T':
            rank = 10;
            break;
        case 'J': 
            rank = 11;
            break;
        case 'Q':
            rank = 12;
            break;
        case 'K':
            rank = 13;
            break;
        default:
            rank =  s[0] - 48;
    }
    switch (s[1]) {
        case 'C':
            suit = Suit::C;
            break;
        case 'D':
            suit = Suit::D;
            break;
        case 'H':
            suit = Suit::H;
            break;
        case 'S':
            suit = Suit::S;
            break;
    }
}
    
std::ostream& operator<< (std::ostream& os, const Card &c) {
    switch (c.rank) {
        case 1:
            os << 'A';
            break;
        case 10:
            os << 'T';
            break;
        case 11:
            os << 'J';
            break;
        case 12:
            os <<   'Q';
            break;
        case 13:
            os << 'K';
            break;
        default:
            os << c.rank;
    }
    switch (c.suit) {
        case Suit::C: 
            os << "C";
            break;
        case Suit::D: 
            os << "D";
            break;
        case Suit::H: 
            os << "H";
            break;
        case Suit::S: 
            os << "S";
            break;
    }
    return os;
}

bool operator==(const Card &lhs, const Card &rhs) {
    return (lhs.rank == rhs.rank) && (lhs.suit == rhs.suit);
}
