#include "Header.h"

void ReadConfig(Config& c,skins& s, game& g)
{
	c.Skins.clear();
	ifstream Config("config.txt");
	if (!Config.is_open())
	{
		Red();
		cout << "FAILED OPEN CONFIG!\n";
		cout << "ALL SAVE DATES LOST!";
		WriteConfig(c,g);
	}
	else
	{
		string line, key, count;
		int Count, i = 0;
		while (getline(Config, line))
		{
			size_t pos = line.find('=');
			if (pos != string::npos)
			{
				key = line.substr(0, pos);
				if (key == "Money")
				{
					count = line.substr(pos + 1);
					Count = stoi(count);
					c.money = Count;
				}
				else if (key == "Lose")
				{
					count = line.substr(pos + 1);
					Count = stoi(count);
					c.Lose = Count;
				}
				else if (key == "Score")
				{
					count = line.substr(pos + 1);
					Count = stoi(count);
					c.score = Count;
				}
				else if (key == "Wins")
				{
					count = line.substr(pos + 1);
					Count = stoi(count);
					c.Wins = Count;
				}
				else if (key == "UsesSkin")
				{
					g.skin = line.substr(pos + 1);
				}
				else if (key == ("Skin" + to_string(i)))
				{
					c.Skins.push_back(line.substr(pos + 1));
					i++;
				}
			}
		}
		s.AvaibleToBuy.clear();
		for (const auto& skin : s.Skins)
		{
			if (find(c.Skins.begin(), c.Skins.end(), skin) != c.Skins.end() || skin == g.skin)
				s.AvaibleToBuy.push_back(false);
			else
				s.AvaibleToBuy.push_back(true);
		}
		WriteConfig(c, g);
	}
}

void WriteConfig(Config& c,game& g)
{
	ofstream ConfigFile("config.txt");
	if (!ConfigFile.is_open())
	{
		Red();
		cout << "FAILED TO WRITE CONFIG!\n";
	}
	else
	{
		ConfigFile << "Money=" << c.money << endl;
		ConfigFile << "Lose=" << c.Lose << endl;
		ConfigFile << "Score=" << c.score << endl;
		ConfigFile << "Wins=" << c.Wins << endl;
		ConfigFile << "UsesSkin" << "=" << g.skin << endl;

		if (!c.Skins.empty())
		{
			for (int i = 0; i < c.Skins.size(); ++i)
			{
				ConfigFile << "Skin" << i << "=" << c.Skins[i] << endl;
			}
		}
	}
}