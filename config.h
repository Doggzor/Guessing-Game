#pragma once
#include <string>
#include <fstream>
#include <chrono>
class config
{
public:
	//Loads the contents of a file into a string
	static std::string GetFileContents(std::string fileName) {
		std::ifstream in(fileName);
		std::string out;
		while (in.good()) {
			std::string temp;
			in >> temp;
			out += temp += " ";
		}
		return out;
	}	
	//Counts how many times string *word* appears in string *str*
	static int CountWord(std::string str, std::string word) {
		int out = 0;
		while (str.find(word) != std::string::npos) {
			str.erase(str.find(word), (int)word.size());
			++out;
		}
		return out;
	}
	//Gets the text that comes between the Nth occurence of string *readAfterThis* and the next occurence of string *readUntilThis* in string *str*
	static std::string GetNextText(std::string str, std::string readAfterThis, std::string readUntilThis, int occurence = 1) {
		size_t startPos = 0;
		std::string out = "";
		do {
			startPos = str.find(readAfterThis);
			if(startPos == std::string::npos) return "There is no " + readAfterThis + " appearing that many times\n";
			str.erase(startPos, readAfterThis.size());
		} while (--occurence);
		size_t endPos = str.find(readUntilThis, startPos) != std::string::npos ? str.find(readUntilThis, startPos) : str.size();
		out = str.substr(startPos, endPos - startPos);
		for (size_t i = 0; i < out.size(); ++i) { //Trim the front
			if (out[i] != ' ') break;
			else out.erase(out.begin() + i);
		}
		for (size_t i = out.size() - 1; i; --i) { //Trim the back
			if (out[i] != ' ') break;
			else out.erase(out.begin() + i);
		}
		return out;
	}
	static void Wait(double seconds) {
		double timePassed = 0;
		auto start = std::chrono::steady_clock::now();
		do {
			auto current = std::chrono::steady_clock::now();
			std::chrono::duration<double> timeDiff = current - start;
			timePassed = timeDiff.count();
		} while (timePassed < seconds);
	}
};
