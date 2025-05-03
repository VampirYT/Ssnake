#include "Header.h"

void Console()
{
	LightGreen();
	system("cls");
	cout << "It's a developer console here you can print some admin command if you want return to game press \"ESC\""
		<< endl << "For take all commands list write \"help\"" << endl;
	string Command;
	while (true)
	{
		cout << "BlackJack/User:";
		cin >> Command;
		if (Command == "exit")
		{
			system("cls");
			exit(0);
		}
		else if (Command == "help")
		{
			Help();
		}
		else if (Command == "Start")
		{
			int j = 5;
			for (int i = 0; i < 5; i++)
			{
				system("cls");
				STab();
				cout << "The game will start in - " << j;
				j--;
				Sleep(1000);
			}
			system("cls");
			GameStart();
		}
		else if (Command == "GitHub")
			cout << "Avtor GitHub - https://github.com/VampirYT/BlackJack-CPP-" << endl;
		else
		{
			Red();
			cout << "\"" << Command << "\"" << " unknown command use \"help\" for show command list" << endl;
			LightGreen();
		}
	}
}
	void Help()
	{
		system("cls");
		cout << "Command list: ";
		CommandInfo("exit - close the game");
		CommandInfo("help - this commands list");
		CommandInfo("Start - start the game");
		CommandInfo("GitHub - take link to avtor GitHub");
	}
	void CommandInfo(string text)
	{
		Tab(1, 1);
		cout << text << endl;
	}

	void Tab(int rows, int column)
	{
		for (int i = 0; i <= rows; i++)
		{
			if (i < rows)
				cout << " " << endl;
			if (i == rows)
				cout << " ";
		}
		for (int j = 0; j <= column; j++)
		{
			cout << " ";
		}
	}
	void STab()
	{
		for (int i = 0; i <= 10; i++)
		{
			cout << " " << endl;
		}
		for (int j = 0; j <= 40; j++)
		{
			cout << " ";
		}
	}