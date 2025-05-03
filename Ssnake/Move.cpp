#include "Header.h"

void Move(char& move)
{
	int Time = 0;
	while (Time < 16)
	{
		if (_kbhit())
		{
			char ch = _getch();
			if (ch == 'w')
			{
				move = 'u';
				break;
			}
			else if (ch == 's')
			{
				move = 'd';
				break;
			}
			else if (ch == 'd')
			{
				move = 'r';
				break;
			}
			else if (ch == 'a')
			{
				move = 'l';
				break;
			}
			else if (ch == '`')
			{
				Console();
				break;
			}
		}
		Sleep(10);
		Time += 1;
	}
}