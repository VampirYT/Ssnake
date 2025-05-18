#include "Header.h"

void Move(char& move,Config& c,game& g)
{
    _setmode(_fileno(stdin), _O_U16TEXT);
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
                system("cls");
                Console(c,g);
                break;
            }
            else if (ch == VK_ESCAPE)
            {
                system("cls");
                Blue();
                cout << "Ur score - " << g.score;
                Sleep(3000);
                system("cls");
                c.money += g.TempBalance;
                g.TempBalance = 0;
                WriteConfig(c, g);
                Menu();
                break;
            }
		}
		Sleep(10);
		Time += 1;
	}
}