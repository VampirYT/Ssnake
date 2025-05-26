#include "Header.h"

int main()
{
	_setmode(_fileno(stdin), _O_U16TEXT);
	SetConsoleOutputCP(65001);
	SetConsoleCP(1251);
	srand(time(NULL));
	GameStart();
}