#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "config.h"
#include "rng.h"

class SecretWord
{
public:
	SecretWord() = default;
	SecretWord(std::string database) {
		sFileContents = config::GetFileContents(database);
		sName = config::GetNextText(sFileContents, "WORD:", "HINT", rng::rdm_int(1, config::CountWord(sFileContents, "WORD"))); //Initialize the word by random from all possible words in the file
		std::string sHints = config::GetNextText(sFileContents, sName, "NAME");
		for (int i = 0; i < nHINTS; ++i) {
			std::string startPos("HINT " + std::to_string(i + 1) + ':');
			vHint.push_back("");
			vHint[i] = config::GetNextText(sHints, startPos, "HINT");
		}
		if(vHint[nHINTS - 1].find("WORD") != std::string::npos) vHint[nHINTS - 1].resize(vHint[nHINTS - 1].find("WORD"));

	}

	bool IsCorrectAnswer(std::string answer) {
		return tolower(answer) == tolower(sName);
	}
	void GetHint() {
		if (nHintCounter >= nHINTS) std::cout << "No more hints\n\n";
		else std::cout <<"HINT: " << vHint[nHintCounter++] << "\n\n";
	}
	std::string tolower(const std::string& str) {
		std::string out = "";
		for (char c : str)
			out.push_back(std::tolower(c));
		return out;
	}

	std::string sFileContents;
	std::string sName;
	std::vector<std::string> vHint;
	static constexpr int nHINTS = 5;
	int nHintCounter = 0;

};

