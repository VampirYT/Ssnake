#include "Header.h"

void Map(game& g,Config& c)
{
	LightGreen();
	cout << "Your balance: " << c.money <<"(+" << g.TempBalance << ")" << endl;
	if (g.kd >= kdb)
	{
		g.boost = false;
	}
	if (!g.xst.empty()) {
		for (int i = g.xst.size() - 1; i > 0; i--) {
			g.xst[i] = g.xst[i - 1];
			g.yst[i] = g.yst[i - 1];
		}
		g.xst[0] = g.xh;
		g.yst[0] = g.yh;
	}
	if (g.move == 'u')
	{
		g.yh -= 1;
	}
	else if (g.move == 'd')
	{
		g.yh += 1;
	}
	else if (g.move == 'l')
	{
		g.xh -= 1;
	}
	else if (g.move == 'r')
	{
		g.xh += 1;
	}
	if ((g.yh >= y + 1 || g.yh <= 0) || (g.xh >= x + 1 || g.xh <= 0))
	{
		if (!g.boost)
		{
			g.dead = true;
		}
		else if(g.boost)
		{
			if (g.yh >= y + 1)
			{
				g.yh -= y;
			}
			else if (g.yh <= 0)
			{
				g.yh += y;
			}
			if (g.xh >= x + 1)
			{
				g.xh -= x;
			}
			else if (g.xh <= 0)
			{
				g.xh += x;
			}
		}
	}
	if(!g.boost)
	{
		for (int i = g.xst.size(); i--;)
		{
			if (g.xh == g.xst[i] && g.yh == g.yst[i])
			{
				g.dead = true;
				break;
			}
		}
	}
	if (g.xh == g.xe && g.yh == g.ye)
	{
		g.score++;
		g.TempBalance += 2;
		g.xst.push_back(g.xh);
		g.yst.push_back(g.yh);
		g.xe = rand() % (x - 2 * 4) + 4;
		g.ye = rand() % (y - 2 * 4) + 4;
	}
	if (g.xh == g.xb && g.yh == g.yb)
	{
		g.xb = rand() % (x - 2 * 4) + 4;
		g.yb = rand() % (x - 2 * 4) + 4;
		g.TempBalance += 10;
		g.boost = true;
		g.boosts = false;
	}
	for (int i = 0; i < y + 2; i++)
	{
		for (int j = 0; j < x + 2; j++)
		{
			bool printed = false;
			if (j == g.xh && i == g.yh)
			{
				if(g.skin == "default")
				{
					LightGreen();
				}
				else if (g.skin == "red")
				{
					Red();
				}
				else if (g.skin == "blue")
				{
					Blue();
				}
				else if (g.skin == "skeleton")
				{
					White();
				}
				else if (g.skin == "Ukraine")
				{
					Aqua();
				}
				cout << "8";
				printed = true;
			}
			else if (j == g.xe && i == g.ye)
			{
				Yellow();
				cout << "Y";
				printed = true;
			}
			else if (g.kd >= kdbs)
			{
				g.boosts = true;
				g.kd = 0;
			}
			if (i == g.yb && j == g.xb && g.boosts)
			{
				Blue();
				cout << "B";
				printed = true;
			}
			for (int k = 0; k < g.xst.size(); k++)
			{
				if (i == g.yst[k] && j == g.xst[k])
				{
					if(k== g.xst.size()-1)
					{
						if(g.skin == "default")
						{
							Red();
						}
						else if (g.skin == "red")
						{
							Red();
						}
						else if (g.skin == "blue")
						{
							Blue();
						}
						else if (g.skin == "skeleton")
						{
							White();
						}
						else if (g.skin == "Ukraine")
						{
							Yellow();
						}
						cout << "0";
					}
					else if(k< g.xst.size())
					{
						if (g.skin == "default")
						{
							DarkGreen();
						}
						else if (g.skin == "red")
						{
							Red();
						}
						else if (g.skin == "blue")
						{
							Blue();
						}
						else if (g.skin == "skeleton")
						{
							White();
						}
						else if (g.skin == "Ukraine")
						{
							if (k <= (g.xst.size() / 2))
							{
								Blue();
							}
							else if (k > (g.xst.size() / 2))
							{
								Yellow();
							}
						}
						cout << "0";
					}
					
					printed = true;
					break;
				}
			}
			if (!printed)
			{
				if ((i >= y + 1 || i == 0) || (j >= x + 1 || j == 0))
				{
					Red();
					cout << "#";
				}
				else if ((j < x + 1 || j != 0) || (i < y + 1 || i != 0))
				{
					cout << " ";
				}
			}	
		}
		cout << endl;
	}
	g.kd += 160;
	Move(g.move,c,g);
}