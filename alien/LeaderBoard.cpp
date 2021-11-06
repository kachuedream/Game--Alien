#include "LeaderBoard.h"

LeaderBoard::LeaderBoard()
{

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