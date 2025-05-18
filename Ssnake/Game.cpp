#include "Header.h"

void Game(game& g, Config& c)
{
	while (!g.dead)
	{
		Map(g,c);
		system("cls");
	}
	Blue();
	cout << "Ur score - " << g.score;
	Sleep(3000);
	system("cls");
	c.money += g.TempBalance;
	g.TempBalance = 0;
	WriteConfig(c, g);
	Menu();
}

void GameStart()
{
	Red();
	STab();
	cout << "Welcome to our game - Ssmake";
	STab();
	Blue();
	cout << "Avtor - Oleksandr Bardin" << endl;
	for (int j = 0; j <= 40; j++)
	{
		cout << " ";
	}
	int timeWaited = 0;
	while (true)
	{
		if (_kbhit())
		{
			char ch = _getch();
			if (ch == ' ')
			{
				system("cls");
				Menu();
				break;
			}
		}
		Sleep(10);
		timeWaited += 10;
		if (timeWaited >= 3000)
		{
			system("cls");
			Menu();
			break;
		}
	}
}

void Language(Config& c)
{
	Tab(10, 47);
	cout << "Choose a language" << endl;
	Tab(1, 47);
	cout << "Press \"1\" to UA";
	Tab(1, 47);
	cout << "Press \"2\" to EN";
	while (true)
	{
		if (_kbhit())
		{
			char ch = _getch();
			if (ch == '1')
			{
				c.language = "ua";
				system("cls"); 
				Menu();
				break;
			}
			else if (ch == '2')
			{
				c.language = "en";
				system("cls");
				Menu();
				break;
			}
		}
	}
}