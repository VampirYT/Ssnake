#pragma once

#include <iostream>
#include <Windows.h>
#include <string>
#include <fstream>
#include <vector>
#include <conio.h>
#include <cstdlib>

using namespace std;

const int x = 30, y = 20,kdbs = 60000,kdb = 10000;

struct Config
{
	int Wins=0, Lose=0, score=0, money=0,skincount=0;
	vector<string> Skins;
};

void GameStart();
void ReadConfig(Config& c);
void WriteConfig(Config& c);
void Menu();
void Statistic(Config& c);
//void Shop();
void Game();

void Map(int&, int&,int&, int&,char&,bool&,int&,vector<int>&, vector<int>&,int&, bool&,int&, int&,bool&);
void Move(char&);

void Yellow();
void Red();
void Blue();
void LightGreen(); 
void DarkGreen();

void Console();
void Help();
void CommandInfo(string text);

void Tab(int rows, int column);
void STab();