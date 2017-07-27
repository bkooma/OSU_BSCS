/*************************************************************************************
** TicTacToe.hpp is the TicTacToe class specification file.
** Author:  Byron Kooima
** Date: 2017/03/08
** Description: CS161 Week9 Assignment 9 Project
** The TicTacToe class has two fields - a Board object and current player character. It
** has a constructor that takes a char parameter that determines whether 'x' or 'o' 
** should have the first move. It has a method called play that starts a game. The play
** method keeps looping until someone has won or it's a draw and then declares outcome.
***************************************************************************************/

#ifndef TICTACTOE_HPP
#define TICTACTOE_HPP

#include "Board.hpp"
#include <string>

class TicTacToe
{
private:
	Board board1;
	char playerTurn;

public:
	// default constructor
	TicTacToe();

	// constructor with parameters
	TicTacToe(char);

	// Metod for play
	void play();

	//destructor
	~TicTacToe();
};

#endif // !TICTACTOE_HPP

