rps: play_game.o RPSGame.o Tool.o Paper.o Rock.o Scissors.o inputVerification.o
	g++ play_game.o RPSGame.o Tool.o Paper.o Rock.o Scissors.o inputVerification.o -o rps

play_game.o: play_game.cpp
	g++ -c -std=c++11 play_game.cpp

RPSGame.o: RPSGame.cpp
	g++ -c -std=c++11 RPSGame.cpp

Tool.o: Tool.cpp
	g++ -c -std=c++11 Tool.cpp

Paper.o: Paper.cpp
	g++ -c -std=c++11 Paper.cpp	

Rock.o: Rock.cpp
	g++ -c -std=c++11 Rock.cpp

Scissors.o: Scissors.cpp
	g++ -c -std=c++11 Scissors.cpp

inputVerification.o: inputVerification.cpp
	g++ -c -std=c++11 inputVerification.cpp

clean:
	rm *.o rps