#pragma once
#include <string>
#include "rng.h"
#include "config.h"
class Player
{
public:
	Player() = default;
	Player(std::string name)
		:
		sName(name) {}

	void DiceRoll() {
		nDice = rng::rdm_int(1, 6);
		std::cout << sName << " is rolling a dice... ";
		config::Wait(1.5);
		std::cout << sName << " rolled " << nDice << "\n";
	}

	std::string sName;
	int nDice = 0;
};

