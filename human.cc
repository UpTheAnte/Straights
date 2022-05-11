#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "human.h"

Human::Human() {}

void Human::makeMove(Game &g, int i) {
    std::string command;
    while (true) {
        std::cin >> command;
        if (std::cin.eof()) { 
            throw QuitException{};
            return;
        }
        if (command == "play") {
            std::string c;
            std::cin >> c;
            Card choice{c};
            auto pos = std::find(hand.begin(), hand.end(), choice);
            if (g.isLegal(choice) && pos != hand.end()) {
                std::cout << "Player" << i << " ";
                g.play(choice);
                hand.erase(pos);
                return;
            } 
            std::cout << "This is not a legal play. \n";
        } else if (command == "discard") {
            std::string c;
            std::cin >> c;
            Card choice{c};
            bool hasLegal = false;
            bool hasCard = false;
            for (auto n : hand) {
                if (choice == n) {
                    hasCard = true;
                }
                if (g.isLegal(n)) {
                    hasLegal = true;
                    break;
                }
            }
            if (hasLegal) {
                std::cout << "You have a legal play. You may not discard. \n";
                continue;
            } 
            if (hasCard) {
                std::cout << "Player" << i << " ";
                discard(choice);
            }
        } else if (command == "deck") {
            g.printDeck();
        } else if (command == "quit") {
            throw QuitException{};
            return;
        } else if (command == "ragequit") {
            throw RageQuitException{};
            return;
        }
    }
}
