#include "Header.h"

int main()
{
	_setmode(_fileno(stdin), _O_U16TEXT);
	srand(time(NULL));
	GameStart();
}