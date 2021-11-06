#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include "AllHeader.h"

class LeaderBoard
{
private:
	struct ScoreData
	{
		string name;
		int score;
	};


public:
	LeaderBoard();
	bool loadFromFile(string fileName);
	vector<ScoreData> data;

	void sort();
	void addScore(string name, int score);
	void saveToFile(string fileName);
};

