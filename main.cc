#include <iostream>
#include <string>
#include <chrono>
#include <memory>
#include "card.h"
#include "player.h"
#include "human.h"
#include "computer.h"
#include "game.h"

int main( int argc, char * argv[] ) {
	// use a time-based seed for the default seed value
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	
	if ( argc > 1 ) {
		try {
			seed = std::stoi( std::string{ argv[1] } );
		} catch( std::invalid_argument & e ) {
			std::cerr << e.what() << std::endl;
			return 1;
		} catch( std::out_of_range & e ) {
			std::cerr << e.what() << std::endl;
			return -1;
		} // catch
	} // if

	Game g;
	// creates players
	for (int i = 0; i < 4; i++) {
		std::string s;
		std::cout << "Is Player" << i + 1 << " a human (h) or a computer (c)?" << std::endl;
		std::cin >> s;
		if (s == "h") {
			g.players.push_back(std::make_unique<Human>());
		} else if (s == "c") {
			g.players.push_back(std::make_unique<Computer>());
		}
	}

	//GAME LOOP
	while (g.scores[0] < 80 && g.scores[1] < 80 && g.scores[2] < 80 && g.scores[3] < 80) {
		g.shuffle(seed);
		int p = 0; //starting player
		for (int i = 0; i < 4; i++) {
			g.players[i]->hand.clear();
			g.players[i]->discarded.clear();
			g.piles[i].first = 0;
			g.piles[i].second = 0;
			for (int j = 0; j < 13; j++) {
				g.players[i]->hand.push_back(g.deck[j + i * 13]);
				//finds who has 7S
				if (g.deck[j + i * 13] == Card{"7S"}) {
					p = i;
				}
			}
		}
		std::cout << "A new round begins. It's Player" << p + 1 << "'s turn to play." << std::endl;
		for (int i = 0; i < 13; i++) { // 13 rotations per round
			for (int j = 0; j < 4; j++) { // loop of players for each rotation
				if (p == 4) { // loop back to first player
					p = 0;
				}
				//game stuff
				g.printPiles();
				g.players[p]->printHand();
				std::cout << "Legal plays:";
				std::vector<Card> legalPlays;
				for (auto n : g.players[p]->hand) {
					if (g.isLegal(n)) {
						legalPlays.push_back(n);
						std::cout << " " << n;
					}
				}
				std::cout << std::endl;
				try {
					g.players[p]->makeMove(g, p + 1);
				} catch (const QuitException &) {
					return 0;
				} catch(const RageQuitException&) {
					g.players[p] = std::make_unique<Computer>(std::move(*g.players[p]));
					std::cout << "Player" << p + 1 << " ragequits. A computer will now take over." << std::endl;
					g.players[p]->makeMove(g, p + 1);
				}
				// next player's turn
				p++;
			}
		}

		// calculate scores at the end of each round
		for (int i = 0; i < 4; i++) {
			std::cout << "Player" << i + 1 << "'s discards:";
			int oldScore = g.scores[i];
			for (auto n : g.players[i]->discarded) {
				std::cout << " " << n;
				g.scores[i] += n.rank;
			}
			std::cout << std::endl;
			std::cout << "Player" << i + 1 << "'s score: " << oldScore << " + " << g.scores[i] - oldScore << " = " << g.scores[i] << std::endl;
		}
	}

	//find who won
	int min = g.scores[0];
	for (int i = 1; i < 4; i++) {
		if (g.scores[i] < min) {
			min = g.scores[i];
		}
	}
	for (int i = 0; i < 4; i++) {
		if (g.scores[i] == min) {
			std::cout << "Player" << i + 1 << " wins!" << std::endl;
		}
	}
}