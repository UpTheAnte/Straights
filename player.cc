#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include "player.h"

void Player::printHand() {
    std::cout << "Your hand:";
    for (auto c : hand) {
        std::cout << " "<< c;
    }
    std::cout << std::endl;
}

void Player::discard(Card c) {
    auto pos = std::find(hand.begin(), hand.end(), c);
    hand.erase(pos);
    discarded.push_back(c);
    std::cout << "discards " << c << "." << std::endl;
    return;
}
Player::~Player() {}