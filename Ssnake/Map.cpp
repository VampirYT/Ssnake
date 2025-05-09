#include "Header.h"

void Map(int& xe, int& ye, int& xh, int& yh,char& move, bool& dead, int& score,vector<int>& xst, vector<int>&yst,int& kd,bool& boost,int& xb,int&yb,bool& boosts)
{
	if (kd >= kdb)
	{
		boost = false;
	}
	if (!xst.empty()) {
		for (int i = xst.size() - 1; i > 0; i--) {
			xst[i] = xst[i - 1];
			yst[i] = yst[i - 1];
		}
		xst[0] = xh;
		yst[0] = yh;
	}
	if (move == 'u')
	{
		yh -= 1;
	}
	else if (move == 'd')
	{
		yh += 1;
	}
	else if (move == 'l')
	{
		xh -= 1;
	}
	else if (move == 'r')
	{
		xh += 1;
	}
	if ((yh >= y + 1 || yh <= 0) || (xh >= x + 1 || xh <= 0))
	{
		if (!boost)
		{
			dead = true;
		}
		else if(boost)
		{
			if (yh >= y + 1)
			{
				yh -= y;
			}
			else if (yh <= 0)
			{
				yh += y;
			}
			if (xh >= x + 1)
			{
				xh -= x;
			}
			else if (xh <= 0)
			{
				xh += x;
			}
		}
	}
	if(!boost)
	{
		for (int i = xst.size(); i--;)
		{
			if (xh == xst[i] && yh == yst[i])
			{
				dead = true;
				break;
			}
		}
	}
	if (xh == xe && yh == ye)
	{
		score++;
		xst.push_back(xh);
		yst.push_back(yh);
		xe = rand() % (x - 2 * 4) + 4;
		ye = rand() % (y - 2 * 4) + 4;
	}
	if (xh == xb && yh == yb)
	{
		xb = rand() % (x - 2 * 4) + 4;
		yb = rand() % (x - 2 * 4) + 4;
		boost = true;
		boosts = false;
	}
	for (int i = 0; i < y + 2; i++)
	{
		for (int j = 0; j < x + 2; j++)
		{
			bool printed = false;
			if (j == xh && i == yh)
			{
				LightGreen();
				cout << "8";
				printed = true;
			}
			else if (j == xe && i == ye)
			{
				Yellow();
				cout << "Y";
				printed = true;
			}
			else if (kd >= kdbs)
			{
				boosts = true;
				kd = 0;
			}
			if (i == yb && j == xb && boosts)
			{
				Blue();
				cout << "B";
				printed = true;
			}
			for (int k = 0; k < xst.size(); k++)
			{
				if (i == yst[k] && j == xst[k])
				{
					if(k==xst.size()-1)
					{
						Red();
						cout << "0";
					}
					else if(k<xst.size())
					{
						DarkGreen();
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
	kd += 160;
	Move(move);
}