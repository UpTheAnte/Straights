#ifndef _GAME_H
#define _GAME_H
#include <string>
#include <vector>
#include <utility>
#include <memory>
#include <iostream>
#include "card.h"
#include "player.h"

class Game {
    public:
    std::vector<Card> deck = {Card{"AC"}, Card{"2C"}, Card{"3C"}, Card{"4C"}, Card{"5C"}, Card{"6C"}, Card{"7C"}, Card{"8C"}, Card{"9C"}, Card{"TC"}, Card{"JC"}, Card{"QC"}, Card{"KC"}, 
                 	          Card{"AD"}, Card{"2D"}, Card{"3D"}, Card{"4D"}, Card{"5D"}, Card{"6D"}, Card{"7D"}, Card{"8D"}, Card{"9D"}, Card{"TD"}, Card{"JD"}, Card{"QD"}, Card{"KD"}, 
                 	          Card{"AH"}, Card{"2H"}, Card{"3H"}, Card{"4H"}, Card{"5H"}, Card{"6H"}, Card{"7H"}, Card{"8H"}, Card{"9H"}, Card{"TH"}, Card{"JH"}, Card{"QH"}, Card{"KH"}, 
                 	          Card{"AS"}, Card{"2S"}, Card{"3S"}, Card{"4S"}, Card{"5S"}, Card{"6S"}, Card{"7S"}, Card{"8S"}, Card{"9S"}, Card{"TS"}, Card{"JS"}, Card{"QS"}, Card{"KS"}};
    std::vector<std::pair<int, int>> piles = {std::make_pair(0,0), std::make_pair(0,0), std::make_pair(0,0), std::make_pair(0,0)};
    //order of piles: Clubs, Diamonds, Hearts, Spades
    std::vector<std::unique_ptr<Player>> players;
    std::vector<int> scores = {0, 0, 0, 0};
    bool isLegal(Card c);
    void play(Card c);
    void printDeck();
    void printPiles();
    void shuffle(unsigned int seed);
};

#endif