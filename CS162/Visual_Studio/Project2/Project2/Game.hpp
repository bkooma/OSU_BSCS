/*************************************************************************************
** Game.hpp is the game class specification file.
** Author:  Byron Kooima
** Date: 2017/07/14
** Description: CS162 Week3 Lab 3
** The Game class represents a game of war using dice. The Game class plays the game, 
** keeps track of the type of dice for each of the 2 players (regular/loaded), the 
** number of rounds to play, and maintains the scoring. The Game class creates the 
** necessary objects, plays the game, and displays the results to the user. The output
** from the Game class indicates the side and type (regular/loaded) of die used for 
** each player, the rolling numbers in each round and the final winner of the game.
***************************************************************************************/

#ifndef GAME_H
#define GAME_H

#include <cstdlib>
#include "Die.hpp"

class Game
{
private:
	// Die cast for player1/2
	Die* player1Die;
	Die* player2Die;

	// Variables for the Game
	int numRounds;
	int curRound;
	int p1NumSides;
	int p2NumSides;
	int player1Score;
	int player2Score;
	bool p1Loaded;
	bool p2Loaded;
	
	// Play a round of the Die Game
	void play_round();
	// Print the results
	void print();
public:
	// Contructor
	Game(int gameRounds);

	// Destructor
	~Game();

	// Play entire game for fun!
	void play_game(int p1DieSides, int p2DieSides, int dieLoaded);

};

#endif // !GAME_HPP
