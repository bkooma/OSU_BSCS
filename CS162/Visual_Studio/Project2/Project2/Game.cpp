/*************************************************************************************
** Game.cpp is the game class function implementation file.
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

#include<iostream>
#include<stdio.h>
#include "Game.hpp"
#include "Die.hpp"
#include "LoadedDie.hpp"
#include "userMenu.hpp"

/*********************************************************************
** Function: Game::Game(int)
** Description: Contructor to initialize the game parameters
** Parameters:	N/A
*********************************************************************/
Game::Game(int numRounds) {
	this->numRounds = numRounds;
	curRound = 1;
	player1Score = 0;
	player2Score = 0;

}

/*********************************************************************
** Function: Game::~Game()
** Description: Destructor to remove the new'd up Die memory.
** Parameters:	N/A
*********************************************************************/
Game::~Game() {
	// Remove dynamic memory allocation
	delete player1Die;
	delete player2Die;
}

/*********************************************************************
** Function: Game::play_round()
** Description: Plays one round to compare the rolls from player 1 and
**			player 2. Determines which value is greater and prints the
**			die values with the players' scores.
** Parameters:	N/A
*********************************************************************/
void Game::play_round()
{
	// Initialize players current die value to 0
	int player1Roll = 0;
	int player2Roll = 0;

	// Returning a random number for player1's roll
	player1Roll = player1Die->roll_die();
	
	// Returning a random number for player2's roll
	player2Roll = player2Die->roll_die();
	// Print players random die number
	std::cout << "\nRound: " << curRound << " with P1 Num Sides = " << p1NumSides << " vs. P2 Num Sides = " << p2NumSides;
	if (p1Loaded) {
		std::cout << "\nPlayer 1 Roll (Loaded): " << player1Roll;
	}
	else {
		std::cout << "\nPlayer 1 Roll (Legal): " << player1Roll;
	}

	if (p2Loaded) {
		std::cout << "\tPlayer 2: Roll (Loaded): " << player2Roll;
	}
	else {
		std::cout << "\tPlayer 2: Roll (Legal): " << player2Roll;
	}
	
	std::cout << "\n";

	// Determine who won the current round
	if (player1Roll > player2Roll)
		player1Score++;
	else if (player1Roll < player2Roll)
		player2Score++;

	// Output the player's score for the current round.
	std::cout << "Player 1 score: " << player1Score << "\t\t" << "Player 2 score: " << player2Score << "\n\n";
	
	// Increment the Round count
	curRound++;
}


/*********************************************************************
** Function: Game::play_game()
** Description: Plays a game by creating a new Die() object for each 
**		player. The menu option for which player has a loaded die is
**		used to determine what objects to new up. The game continues
**		until the numRounds is reached and then the game results are 
**		printed.
** Parameters:	player1Die      Die object for player 1
**				player2Die      Die object for player 2
**				dieLoaded		Menu value returned to determine which
								die is loaded
*********************************************************************/
void Game::play_game(int p1NumSides, int p2NumSides, int dieLoaded) {
	this->p1NumSides = p1NumSides;
	this->p2NumSides = p2NumSides;
	// Player1 Die is loaded
	if (dieLoaded == 2) {
		player1Die = new LoadedDie(p1NumSides);
		p1Loaded = true;
		player2Die = new Die(p2NumSides);
		p2Loaded = false;
	}
	// Player2 Die is loaded
	else if (dieLoaded == 3) {
		player1Die = new Die(p1NumSides);
		p1Loaded = false;
		player2Die = new LoadedDie(p2NumSides);
		p2Loaded = true;
	}
	// Both players' Die are loaded
	else if (dieLoaded == 4) {
		player1Die = new LoadedDie(p1NumSides);
		p1Loaded = true;
		player2Die = new LoadedDie(p2NumSides);
		p2Loaded = true;
	}
	// Both players' Die are not loaded
	else {
		player1Die = new Die(p1NumSides);
		p1Loaded = false;
		player2Die = new Die(p2NumSides);
		p2Loaded = false;
	}

	// Loop through the number of rounds (default:1)
	while (curRound <= numRounds)
		play_round();

	// Print the results of the game to the screen
	print();
}

/*********************************************************************
** Function: Game::print()
** Description: Prints the results for all the rounds of a game
** Parameters:	N/A
*********************************************************************/
void Game::print() {
	std::cout << "---------------------------------\nResult: ";
	// Check to see if player1 is the winner
	if (player1Score > player2Score)
		std::cout << "Player 1 wins\n";
	// Check to see if player2 is the winner
	else if (player1Score < player2Score)
		std::cout << "Player 2 wins\n";
	// Ends in a tie which is like...
	else
		std::cout << "Like kissing your sister\n";
}
