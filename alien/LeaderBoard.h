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
	sf::Font font;

	sf::Text text_num[5];
	sf::Text text_name[5];
	sf::Text text_score[5];

public:
	LeaderBoard();
	bool loadFromFile(string fileName);
	vector<ScoreData> data;

	void sort();
	void addScore(string name, int score);
	void saveToFile(string fileName);
	void update();
	void render(RenderWindow& window);


};

