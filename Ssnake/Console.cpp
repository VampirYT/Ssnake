#include "Header.h"

void Console(Config& c,game& g)
{
	LightGreen();
	wcout << "It's a developer console here you can print some admin command if you want return to game press \"ESC\""
		<< endl << "For take all commands list write \"help\"" << endl;
	wstring Command;
	while (true)
	{
		wcout << L"Ssnake/User:";
		getline(wcin,Command);
		if (Command == L"exit" || Command == L"Exit")
		{
			system("cls");
			exit(0);
		}
		else if (Command == L"clear" || Command == L"Clear" || Command == L"cls")
		{
			system("cls");
		}
		else if (Command == L"help" || Command == L"Help")
		{
			Help();
		}
		else if (Command == L"SetMoney" || Command == L"Setmoney" || Command == L"setmoney")
		{
			wcout << "Enter how much money you want set" << endl;
			wcin >> c.money;
			WriteConfig(c, g);
			cout << "Money set to " << c.money;
		}
		else if (Command == L"List" || Command == L"list")
		{
			int index = 1;
			cout << "List: " << endl;
			cout << "Language - " << c.language << endl;
			cout << "Wins - " << c.Wins << endl;
			cout << "Loses - " << c.Lose << endl;
			cout << "Money - " << c.money << endl;
			cout << "Score - " << c.score << endl;
			cout << "Skins - " << c.Skins.size() << endl;
			for (int i = 0; i < c.Skins.size(); i++)
			{
				cout << index << ".Skin - " << c.Skins.at(i) << endl;
				index++;
			}
		}
		else if (Command == L"Delete skin" || Command == L"delete skin")
		{
			int index;
			cout << "Enter skin position" << endl;
			cin >> index;
			index--;
			if (index >= 0 && index < c.Skins.size())
			{
				cout << c.Skins.at(index) << " deleted";
				c.Skins.erase(c.Skins.begin() + index);
			}
			else
			{
				cout << "Error: invalid index" << endl;
			}
			WriteConfig(c, g);
		}
		else if (Command == L"Start" || Command == L"start")
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
		else if (Command == L"GitHub" || Command == L"github")
			cout << "Avtor GitHub - https://github.com/VampirYT/BlackJack-CPP-" << endl;
		else
		{
			Red();
			wcout << "\"" << Command << "\"" << " unknown command use \"help\" for show command list" << endl;
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
	CommandInfo("SetMoney - enter how many money you want");
	CommandInfo("List - show your statistic");
	CommandInfo("Delete skin - delete skin on position");
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