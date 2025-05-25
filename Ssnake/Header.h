#pragma once

#include <iostream>
#include <Windows.h>
#include <string>
#include <fstream>
#include <vector>
#include <conio.h>
#include <cstdlib>
#include <fcntl.h>
#include <io.h>

using namespace std;

const int x = 30, y = 20,kdbs = 60000,kdb = 10000;

struct Config
{
	int Wins = 0, Lose = 0, score = 0, money = 0;
	string language;
	vector<string> Skins;
};

struct game
{
	int TempBalance = 0;
	char move = 'n';
	bool dead = false, boost = false, boosts = true;
	int score = 0;
	vector<int>  xst, yst;
	int xh = x / 2, yh = y / 2;
	int xe = rand() % (x - 2 * 4) + 4;
	int ye = rand() % (y - 2 * 4) + 4;
	int kd = 0, xb = rand() % (x - 2 * 4) + 4, yb = rand() % (y - 2 * 4) + 4;
	string skin;
};

struct skins
{
	vector<string> Skins
	{
		"default","red", "blue", "skeleton" , "Ukraine"
	};
	vector<int> Price
	{
		0,100,200,300,500
	};
	vector<bool> AvaibleToBuy{false};
};

void GameStart();
void ReadConfig(Config& c,skins& s, game& g);
void WriteConfig(Config& c, game & g);
void FirstWriteConfig(Config& c, game& g);
void Menu();
void Inventory(Config& c, game& g);
void Statistic(Config& c, skins& s,game& g);
void Language(Config& c,game& g);
void Shop(Config& c, game& g,skins& s);
void Game(game& g,Config& c);

void Map(game& g,Config& c);
void Move(char&,Config& c,game& g);

void Yellow();
void Red();
void Blue();
void LightGreen(); 
void DarkGreen();
void White();
void Aqua();

void Console(Config& c,game& g);
void Help();
void CommandInfo(string text);

void Tab(int rows, int column);
void STab();