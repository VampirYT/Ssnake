#include "Header.h"

void Menu()
{
	Config c;
	Tab(0, 6);
	cout << "Menu: ";
	Tab(2, 4);
	cout << "1. Play";
	Tab(2, 4);
	cout << "2. Shop";
	Tab(2, 4);
	cout << "3. Statistic";
	ReadConfig(c);
	while (true)
	{
		if (_kbhit())
		{
			char ch = _getch();
			if (ch == '1')
			{
				system("cls");
				Game();
			}
			else if (ch == '2')
			{
				//Shop();
			}
			else if (ch == '3')
			{
				system("cls");
				Statistic(c);
			}
			else
			{

			}
		}
	}
}

/*void Shop()
{


}*/

void Statistic(Config& c)
{
	string temp;
	cout << "Wins -" << c.Wins << endl;
	cout << "Lose -" << c.Lose << endl;
	cout << "Money -" << c.money << endl;
	cout << "Score -" << c.score << endl;
	cout << "Skincount - " << c.skincount << endl;
	for(int i = 0; i < c.skincount;i++)
	{
		cout << "Skin" << i << " - " << c.Skins[i] << endl;
	}
}

void ReadConfig(Config& c)
{
	c.Skins.clear();
	ifstream Config("config.txt");
	if (!Config.is_open())
	{
		Red();
		cout << "FAILED OPEN CONFIG!\n";
		cout << "ALL SAVE DATES LOST!";
		WriteConfig(c);
	}
	else
	{
		string line,key,count;
		int Count,i=0;
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
				else if (key == "SkinCount")
				{
					count = line.substr(pos + 1);
					Count = stoi(count); 
					c.skincount = Count;
				}
				else if(key == ("Skin"+ to_string(i)))
				{
					if (i < c.skincount)
					{
						c.Skins.push_back(line.substr(pos + 1));
						i++;
					}
				}
			}
		}
	}
}

void WriteConfig(Config& c)
{
	ofstream ConfigFile("config.txt");
	if (!ConfigFile.is_open())
	{
		Red();
		cout << "FAILED TO WRITE CONFIG!\n";
	}

	ConfigFile << "Money=" << c.money << endl;
	ConfigFile << "Lose=" << c.Lose << endl;
	ConfigFile << "Score=" << c.score << endl;
	ConfigFile << "Wins=" << c.Wins << endl;
	ConfigFile << "SkinCount=" << c.skincount << endl;

	for (int i = 0; i < c.Skins.size(); ++i)
	{
		ConfigFile << "Skin" << i << "=" << c.Skins[i] << endl;
	}
}