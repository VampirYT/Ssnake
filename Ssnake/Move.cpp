#include "Header.h"

void Move(char& move)
{
	int Time = 0;
	while (Time < 16)
	{
		if (_kbhit())
		{
			wchar_t ch = _getwch();
            if (ch == L'w' || ch == L'�')
            {
                move = 'u';
                break;
            }
            else if (ch == L's' || ch == L'�' || ch == L'�')
            {
                move = 'd';
                break;
            }
            else if (ch == L'd' || ch == L'�')
            {
                move = 'r';
                break;
            }
            else if (ch == L'a' || ch == L'�')
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