#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <utility>
#include <algorithm>
#include <random>
#include "card.h"
#include "game.h"

bool Game::isLegal(Card c) {
	if (piles[3].first == 0 && piles[3].second == 0) {
		return c == Card{"7S"};
	} else if (piles[static_cast<std::size_t>(c.suit)].first == 0 && piles[static_cast<std::size_t>(c.suit)].second == 0) {
		return c.rank == 7;
	}
	return (c.rank == piles[static_cast<std::size_t>(c.suit)].first - 1 || c.rank == piles[static_cast<std::size_t>(c.suit)].second + 1);
}

void Game::play(Card c){
	if (piles[static_cast<std::size_t>(c.suit)].first == 0 && piles[static_cast<std::size_t>(c.suit)].second == 0) {
		piles[static_cast<std::size_t>(c.suit)].first = 7;
		piles[static_cast<std::size_t>(c.suit)].second = 7;
	} else if (c.rank == piles[static_cast<std::size_t>(c.suit)].first - 1) {
		piles[static_cast<std::size_t>(c.suit)].first--;
	} else {
		piles[static_cast<std::size_t>(c.suit)].second++;
	}
	std::cout << "plays " << c << "." << std::endl;
}

void Game::shuffle(unsigned int seed) {
	std::default_random_engine rng{seed};
	std::shuffle( deck.begin(), deck.end(), rng );
}

void Game::printDeck() {
	for (int i = 0; i < 52; i++) {
		std::cout << deck[i];
		if ((i + 1) % 13 == 0) {
			std::cout << std::endl;
		} else {
			std::cout << " ";
		}
	}
}

void Game::printPiles() {
	std::string suits[4] = {"Clubs", "Diamonds", "Hearts", "Spades"};
	std::cout << "Cards on the table:" << std::endl;
	for (int i = 0; i < 4; i++) {
		std::cout << suits[i] << ":";
		if (!(piles[i].first == 0 && piles[i].second == 0)) {
			for (int j = piles[i].first; j <= piles[i].second; j++) {
				if (j == 1) {
					std::cout << " " << "A";
				} else if (j == 10) {
					std::cout << " " << "T";
				} else if (j == 11) {
					std::cout << " " << "J";
				} else if (j == 12) {
					std::cout << " " << "Q";
				} else if (j == 13) {
					std::cout << " " << "K";
				} else {
					std::cout << " " << j ;
				}
			}
		}
		std::cout << std::endl;
	}
}
