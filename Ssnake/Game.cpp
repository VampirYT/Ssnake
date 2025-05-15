#include "Header.h"


void Game()
{
	char move;
	bool dead = false, boost = false, boosts = true;
	int score = 0;
	vector<int>  xst, yst;
	int xh = x / 2, yh = y / 2;
	int xe = rand() % (x - 2 * 4) + 4;
	int ye = rand() % (y - 2 * 4) + 4; 
	int kd = 0, xb = rand() % (x - 2 * 4) + 4, yb = rand() % (y - 2 * 4) + 4;
	while (!dead)
	{
		Map(xe, ye, xh, yh, move, dead, score, xst, yst, kd, boost, xb, yb, boosts);
		system("cls");
	}
	Blue();
	cout << "Ur score - " << score;
	exit(0);
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





//							Im progress





//void Next()
//{
//	Blue();
//	system("cls");
//	STab();
//	if (game.Language == "ua")
//		cout << "Натисніть пробіл, щоб продовжити" << endl;
//	else if (game.Language == "en")
//		cout << "Press SpaceBar to continue" << endl;
//	while (true)
//	{
//		if (_kbhit())
//		{
//			char ch = _getch();
//			if (ch == ' ')
//			{
//				system("cls");
//				Game();
//			}
//		}
//	}
//}
// 
//void language(Settings& game, ConsoleCommand& command, login& Login)
//{
//	system("cls");
//	Tab(10, 47);
//	cout << "Choose a language" << endl;
//	Tab(1, 47);
//	cout << "Press \"1\" to UA";
//	Tab(1, 47);
//	cout << "Press \"2\" to EN";
//	while (true)
//	{
//		if (_kbhit())
//		{
//			char ch = _getch();
//			if (ch == '1')
//			{
//				game.Language = "ua";
//				Next(game, command, Login);
//				break;
//			}
//			else if (ch == '2')
//			{
//				game.Language = "en";
//				Next(game, command, Login);
//				break;
//			}
//		}
//	}
//}