#include "Header.h"

void Move(char& move)
{
	int Time = 0;
	while (Time < 16)
	{
		if (_kbhit())
		{
			wchar_t ch = _getwch();
            if (ch == L'w' || ch == L'ö')
            {
                move = 'u';
                break;
            }
            else if (ch == L's' || ch == L'û' || ch == L'³')
            {
                move = 'd';
                break;
            }
            else if (ch == L'd' || ch == L'â')
            {
                move = 'r';
                break;
            }
            else if (ch == L'a' || ch == L'ô')
            {
                move = 'l';
                break;
            }
            else if (ch == L'`')
            {
                Console();
                break;
            }
		}
		Sleep(10);
		Time += 1;
	}
}