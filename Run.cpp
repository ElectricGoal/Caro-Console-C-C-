#include "Console.h"
#include "Menu.h"

using namespace std;

int main()
{
	SetConsoleTitle(L"Game Caro nhom 17");
	FixConsoleWindow();
	SetWindowSize(150, 40);
	ShowScrollbar(0);
	Run_Menu();

	return 0;
}