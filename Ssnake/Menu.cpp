#include "Header.h"

void Menu()
{
	Config c;
	game g;
	skins s; 
	ReadConfig(c, s, g);
	if(c.language == "en")
	{
		Tab(0, 6);
		cout << "Menu: ";
		Tab(2, 4);
		cout << "1. Play";
		Tab(2, 4);
		cout << "2. Shop";
		Tab(2, 4);
		cout << "3. Inventory";
		Tab(2, 4);
		cout << "4. Language";
		Tab(2, 4);
		cout << "5. Statistic";
		Tab(2, 4);
		cout << "ESC. Exit";
	}
	else if (c.language == "ua")
	{
		Tab(0, 6);
		cout << "Иеню: ";
		Tab(2, 4);
		cout << "1. Грати";
		Tab(2, 4);
		cout << "2. Магазин";
		Tab(2, 4);
		cout << "3. Інвентар";
		Tab(2, 4);
		cout << "4. Вибір мови";
		Tab(2, 4);
		cout << "5. Статистика";
		Tab(2, 4);
		cout << "ESC. Вихід";
	}
	ReadConfig(c,s,g);
	while (true)
	{
		if (_kbhit())
		{
			char ch = _getch();
			if (ch == '1')
			{
				system("cls");
				Game(g,c);
				break;
			}
			else if (ch == '2')
			{
				system("cls");
				Shop(c,g,s);
				break;
			}else if (ch == '3')
			{
				system("cls");
				Inventory(c, g);
				break;
			}
			else if (ch == '4')
			{
				system("cls");
				Language(c,g);
				break;
			}
			else if (ch == '5')
			{
				system("cls");
				Statistic(c,s,g);
				break;
			}
			else if (ch == VK_ESCAPE)
			{
				system("cls");
				exit(0);
				break;
			}
			else if (ch == '`')
			{
				system("cls");
				Console(c,g);
				break;
			}
			else
			{
				system("cls");
				Menu();
				break;
			}
		}
	}
}

void Inventory(Config&c, game& g)
{
	int index = 1;
	if(c.language == "en")
	{
		Tab(0, 6);
		cout << "Inventory: ";
		Tab(2, 4);
		cout << "Equipped - " << g.skin;
	}
	else if (c.language == "ua")
	{
		Tab(0, 6);
		cout << "Інвентар: ";
		Tab(2, 4);
		cout << "Використовується - " << g.skin;
	}
	for (int i = 0; i < c.Skins.size(); i++)
	{
		Tab(2, 4);
		cout << index << "." << c.Skins.at(i);
		index++;
	}
	while (true)
	{
		if (_kbhit())
		{
			char ch = _getch();
			int key = ch - '0';
			int index = key - 1;
			if (ch == VK_ESCAPE)
			{
				system("cls");
				Menu();
			}
			else if (key >= 1 && key <= c.Skins.size())
			{
				c.Skins.push_back(g.skin);
				g.skin = c.Skins.at(index);
				c.Skins.erase(c.Skins.begin() + index);
				WriteConfig(c, g);
				system("cls");
				Inventory(c, g);
			}
		}
	}
}

void Shop(Config& c, game& g,skins& s)
{
	if(c.language == "en")
	{
		Tab(0, 6);
		cout << "Shop: ";
		Tab(2, 4);
		cout << "Your balance: " << c.money;
		cout << endl;
	}
	else if (c.language == "ua")
	{
		Tab(0, 6);
		cout << "Магазин: ";
		Tab(2, 4);
		cout << "Ваш баланс: " << c.money;
		cout << endl;
	}
	for (int i = 0; i < s.AvaibleToBuy.size(); i++)
	{
		if (s.AvaibleToBuy.at(i))
		{
			if(c.language == "en")
			{
				cout << " true ";
			}
			else if(c.language == "ua")
			{
				cout << " так ";
			}
		}
		else if (!s.AvaibleToBuy.at(i))
		{
			if(c.language == "en")
			{
				cout << " false ";
			}
			else if(c.language == "ua")
			{
				cout << " ні ";
			}
		}
	}
	cout << endl;
	int index = 1;
	for(int i=0; i < s.Skins.size(); i++)
	{
		Tab(2, 4);
		if(s.AvaibleToBuy.at(i))
		{
			if(c.language == "en")
			{
				cout << index << "." << s.Skins.at(i) << " price - " << s.Price.at(i);
			}
			else if(c.language == "ua")
			{
				cout << index << "." << s.Skins.at(i) << " ціна - " << s.Price.at(i);
			}
		}
		else if (!s.AvaibleToBuy.at(i))
		{
			if(c.language == "en")
			{
				cout << index << "." << s.Skins.at(i) << " you already have this skin";
			}
			else if(c.language == "ua")
			{
				cout << index << "." << s.Skins.at(i) << " у вас вже є цей скін";
			}
		}
		index++;
	}
	Tab(2, 4);
	if (c.language == "en")
	{
		cout << "ESC. Exit";
	}
	else if (c.language == "ua")
	{
		cout << "ESC. Вихід";
	}
	while (true)
	{
		if (_kbhit())
		{
			char ch = _getch();
			int key = ch - '0';
			int index = key - 1;
			if (key >= 1 && key <= s.Skins.size())
			{
				if(s.AvaibleToBuy.at(index))
				{
					if (c.money >= s.Price.at(index))
					{
						system("cls");
						if(c.language == "en")
						{
							Tab(2, 4);
							cout << "Are yous sure to buy " << s.Skins.at(index) << " for " << s.Price.at(index) << "?";
							Tab(2, 4);
							cout << "1.Yes(spend " << s.Price.at(index) << " money)";
							Tab(2, 4);
							cout << "1.No";
						}
						else if (c.language == "ua")
						{
							Tab(2, 4);
							cout << "Ви впевнені що хочете придбати цей скін" << s.Skins.at(index) << " за " << s.Price.at(index) << "?";
							Tab(2, 4);
							cout << "1.Так(Витратити " << s.Price.at(index) << " грошей)";
							Tab(2, 4);
							cout << "1.Ні";
						}
						while(true)
						{
							if (_kbhit())
							{
								char ch = _getch();
								if (ch == '1')
								{
									c.money -= s.Price.at(index);
									c.Skins.push_back(s.Skins.at(index));
									s.AvaibleToBuy.at(index) = false;
									WriteConfig(c,g);
									system("cls");
									if(c.language == "en")
									{
										cout << "You spend " << s.Price.at(index) << " money for " << s.Skins.at(index);
									}
									else if(c.language == "ua")
									{
										cout << "Ви витратили " << s.Price.at(index) << " грошей за " << s.Skins.at(index);
									}
									Sleep(3000);
									system("cls");
									Shop(c, g, s);
								}
								else if (ch == '2')
								{
									system("cls");
									Tab(2, 4);
									if(c.language == "en")
									{
										cout << "You turn back to shop";
									}
									else if(c.language == "ua")
									{
										cout << "Вас поверне до меню магазина";
									}
									Sleep(3000);
									system("cls");
									Shop(c, g, s);
								}
							}
						}
					}
					else
					{
						system("cls");
						Tab(2, 4);
						if(c.language == "en")
						{
							cout << "You don't have money for this purchase";
						}
						else if(c.language == "ua")
						{
							cout << "У вас недостатньо грошей для покупки";
						}
						Sleep(3000);
						system("cls");
						Shop(c, g, s);
					}
				}
				else
				{
					Tab(2, 4);
					if(c.language == "en")
					{
						cout << "Skin not avaible to buy";
					}
					else if(c.language == "ua")
					{
						cout << "Скін не доступний для придбання";
					}
					Sleep(3000);
					system("cls");
					Shop(c, g, s);
				}
			}
			else if (ch == VK_ESCAPE)
			{
				system("cls");
				Menu();
			}
		}
	}
}

void Statistic(Config& c,skins& s,game& g)
{
	ReadConfig(c, s,g);
	if(c.language == "en")
	{
		cout << "Wins -" << c.Wins << endl;
		cout << "Lose -" << c.Lose << endl;
		cout << "Money -" << c.money << endl;
		cout << "Score -" << c.score << endl;
		cout << "Skincount - " << c.Skins.size() << endl;
		cout << "ESC.Exit" << endl;
	}
	else if(c.language == "ua")
	{
		cout << "Перемоги -" << c.Wins << endl;
		cout << "Поразки -" << c.Lose << endl;
		cout << "Гроші -" << c.money << endl;
		cout << "Очки -" << c.score << endl;
		cout << "Кількість скінів - " << c.Skins.size() << endl;
		cout << "ESC.Вихід" << endl;
	}
	while (true)
	{
		if (_kbhit())
		{
			char ch = _getch();
			if (ch == VK_ESCAPE)
			{
				system("cls");
				Menu();
			}
		}
	}
}