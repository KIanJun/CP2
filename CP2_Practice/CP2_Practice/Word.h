#pragma once
#include <iostream>
#include <string>
#include <map>
#include <list>

using namespace std;

class Word {
private:
	string word;

public:
	Word(string word) { this->word = word; }
	string getWord() { return this->word; }
};
