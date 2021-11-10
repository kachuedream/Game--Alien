#include "LeaderBoard.h"

LeaderBoard::LeaderBoard()
{
	font.loadFromFile("GAMERIA.ttf");
	
	for(int i=0;i<5;i++)
	{
		text_num[i].setFont(font);
		text_num[i].setCharacterSize(50);
		text_num[i].setPosition(Vector2f(300,200+i*100));
		text_num[i].setString(std::to_string(i+1));

		text_name[i].setFont(font);
		text_name[i].setCharacterSize(50);
		text_name[i].setPosition(Vector2f(400, 200 + i * 100));

		text_score[i].setFont(font);
		text_score[i].setCharacterSize(50);
		text_score[i].setPosition(Vector2f(900, 200 + i * 100));
	}
}

bool LeaderBoard::loadFromFile(string fileName)
{
	ifstream file(fileName);
	if (file.bad())
	{
		return false;
	}

	data.clear();

	for (int i = 0; i < 5; i++)
	{
		string strName;
		string strScore;
		if (!getline(file, strName))
		{
			break;
		}
		if (!getline(file, strScore))
		{
			break;
		}
		data.push_back(ScoreData{ strName , stoi(strScore) });
	}
	file.close();
	return true;
}

void LeaderBoard::sort()
{
	for (int d = 0; d < data.size(); d++)
	{
		for (int t = d + 1; t < data.size(); t++)
		{
			if (data[d].score < data[t].score)
			{
				ScoreData temp = data[d];
				data[d] = data[t];
				data[t] = temp;
			}
		}
	}
}

void LeaderBoard::addScore(string name, int score)
{
	data.push_back(ScoreData{ name,score });
	sort();
}

void LeaderBoard::saveToFile(string fileName)
{
	fstream file(fileName, ios::out);
	for (int i = 0; i < data.size() && i < 5; i++)
	{
		file << data[i].name << endl << data[i].score << endl;
	}
	file.close();
}

void LeaderBoard::update()
{
	loadFromFile("score.txt");
	sort();
	for (int i = 0; i < data.size(); i++)
	{
		text_name[i].setString(data[i].name);
		text_score[i].setString(std::to_string(data[i].score));
	}
	addScore("sf", 90);
	saveToFile("score.txt");
}

void LeaderBoard::render(RenderWindow& window)
{
	for (int i = 0; i < 5; i++)
	{
		window.draw(text_name[i]);
		window.draw(text_num[i]);
		window.draw(text_score[i]);
	}
}
