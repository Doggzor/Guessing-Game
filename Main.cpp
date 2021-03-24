#pragma once
#include <iostream>
#include <string>
#include "Player.h"
#include "SecretWord.h"
#include "config.h"

int main()
{
	SecretWord movie("Secret Words.txt");
	Player player[2];
	std::string sPlayerName = "";
	std::string sAnswer;
	std::cout << "Welcome to the guessing game!\n\n";
	for (int i = 0; i < 2; ++i) {
		std::cout << "Player "<< i + 1 <<", enter your name: ";
		std::cin >> sPlayerName;
		player[i] = sPlayerName;
		std::cout << "\n";
	}
	std::cout << "Time to determine who goes first\n";
	do {
		config::Wait(0.75);
		player[0].DiceRoll();
		player[1].DiceRoll();
		config::Wait(0.75);
		if (player[0].nDice == player[1].nDice)
			std::cout << "Tie! Rolling again...\n";
	} while (player[0].nDice == player[1].nDice);

	std::cout << player[!(player[0].nDice > player[1].nDice)].sName << " goes first.\n\nGame starting\n\n";
	int nTurnCounter = !(player[0].nDice > player[1].nDice);
	const int nTurn = nTurnCounter % 2;
	int nPlayerIndex = nTurn;
	config::Wait(0.5);
	while (true) {
		nPlayerIndex = nTurnCounter % 2;
		if (nTurn == nPlayerIndex) movie.GetHint();
		std::cout << player[nPlayerIndex].sName << "'s turn.\n" << player[nPlayerIndex].sName << ", please type your answer:\n";
		std::cin >> sAnswer;
		if (movie.IsCorrectAnswer(sAnswer)) {
			std::cout << "\nCorrect!\n";
			break;
		}
		else {
			std::cout << "\nWrong!";
			if (nTurn != nPlayerIndex) std::cout << " Moving on...";
			std::cout << "\n\n\n";
			++nTurnCounter;
		}
		//Do stuff
	}
}