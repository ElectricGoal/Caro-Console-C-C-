
#include "Console.h"
#include "Effect.h";
using namespace std;




void  cheoTrai(int left, int top, int dai, int cao, int color)
{
	txtColor(color);
	int h = 0;
	for (int i = left; i <= dai + left; i++)
	{
		int k = 0;
		for (int j = cao + top; j >= top; j--)
		{
			if (h == k)
			{

				GotoXY(i, j);
				cout << "   ";
			}
			k++;
		}
		h++;
	}


}
void  cheoPhai(int left, int top, int dai, int cao, int color)
{
	txtColor(color);
	int h = 0;
	for (int i = left; i <= left + dai; i++)
	{
		int k = 0;
		for (int j = top; j <= top + cao; j++)
		{
			if (h == k)
			{

				GotoXY(i, j);
				cout << "   ";
			}
			k++;
		}
		h++;
	}
}
void  veNgang(int left, int top, int dai, int color)
{
	txtColor(color);
	for (int i = left; i <= left + dai; i++)
	{
		GotoXY(i, top);
		cout << "  ";
	}
}
void  veDoc(int left, int top, int dai, int color)
{
	txtColor(color);
	for (int i = top; i <= top + dai; i++)
	{

		GotoXY(left, i);
		cout << "   ";
	}
}
//Ham in ra X win

void P1Win()
{
	system("cls");
	int arr[4] = { 43,48,95,96 };
	int color;
	int index = 0;
	for (int i = 0; i < 28; i++)
	{
		Sleep(200);
		index = 0 + rand() % (4);
		color = arr[index];
		// X

		cheoPhai(45, 11, 10, 10, 112);
		cheoTrai(45, 11, 10, 10, 112);
		cheoTrai(40, 10, 10, 10, color);
		cheoPhai(40, 10, 10, 10, color);
		// W

		cheoPhai(60, 11, 10, 10, 112);
		cheoTrai(70, 16, 3, 3, 112);
		cheoPhai(73, 16, 3, 3, 112);
		cheoTrai(76, 11, 10, 10, 112);

		cheoPhai(55, 10, 10, 10, color);
		cheoTrai(65, 15, 3, 3, color);
		cheoPhai(68, 15, 3, 3, color);
		cheoTrai(71, 10, 10, 10, color);

		// I

		veNgang(91, 11, 10, 112);
		veDoc(96, 11, 10, 112);
		veNgang(91, 21, 10, 112);

		veNgang(86, 10, 10, color);
		veDoc(91, 10, 10, color);
		veNgang(86, 20, 10, color);

		//N

		veDoc(107, 11, 10, 112);
		cheoPhai(108, 11, 10, 10, 112);
		veDoc(119, 11, 10, 112);

		veDoc(102, 10, 10, color);
		cheoPhai(103, 10, 10, 10, color);
		veDoc(114, 10, 10, color);
	}
	txtColor(240);

}
void P2Win()
{
	system("cls");

	int arr[4] = { 43,48,95,96 };
	int color;
	int index = 0;
	for (int i = 0; i < 28; i++)
	{
		Sleep(200);
		index = 0 + rand() % (4);
		color = arr[index];
		// O
		veDoc(42, 13, 7, 112);
		veDoc(57, 13, 7, 112);
		veNgang(48, 11, 4, 112);
		veNgang(48, 22, 4, 112);
		GotoXY(45, 12); cout << "   ";
		GotoXY(54, 12); cout << "   ";
		GotoXY(45, 21); cout << "   ";
		GotoXY(54, 21); cout << "   ";

		veDoc(38, 12, 7, color);
		veDoc(53, 12, 7, color);
		veNgang(44, 10, 4, color);
		veNgang(44, 21, 4, color);
		GotoXY(41, 11); cout << "   ";
		GotoXY(50, 11); cout << "   ";
		GotoXY(41, 20); cout << "   ";
		GotoXY(50, 20); cout << "   ";

		// W

		cheoPhai(60, 11, 10, 10, 112);
		cheoTrai(70, 16, 3, 3, 112);
		cheoPhai(73, 16, 3, 3, 112);
		cheoTrai(76, 11, 10, 10, 112);

		cheoPhai(55, 10, 10, 10, color);
		cheoTrai(65, 15, 3, 3, color);
		cheoPhai(68, 15, 3, 3, color);
		cheoTrai(71, 10, 10, 10, color);

		// I

		veNgang(91, 11, 10, 112);
		veDoc(96, 11, 10, 112);
		veNgang(91, 21, 10, 112);

		veNgang(86, 10, 10, color);
		veDoc(91, 10, 10, color);
		veNgang(86, 20, 10, color);

		//N

		veDoc(107, 11, 10, 112);
		cheoPhai(108, 11, 10, 10, 112);
		veDoc(119, 11, 10, 112);

		veDoc(102, 10, 10, color);
		cheoPhai(103, 10, 10, 10, color);
		veDoc(114, 10, 10, color);
	}
	txtColor(240);

}
void Draw()
{
	system("cls");
	//system("cls");

	int arr[4] = { 43,48,95,96 };
	int color;
	int index = 0;
	for (int i = 0; i < 28; i++)
	{
		Sleep(200);
		index = 0 + rand() % (4);
		color = arr[index];
		// D

		veDoc(50, 8, 10, 112);
		veNgang(51, 8, 5, 112);
		veNgang(51, 18, 5, 112);
		cheoPhai(57, 8, 2, 2, 112);
		cheoTrai(57, 16, 2, 2, 112);
		veDoc(60, 10, 6, 112);

		veDoc(45, 7, 10, color);
		veNgang(46, 7, 5, color);
		veNgang(46, 17, 5, color);
		cheoPhai(52, 7, 2, 2, color);
		cheoTrai(52, 15, 2, 2, color);
		veDoc(55, 9, 6, color);
		//R

		veDoc(64, 8, 10, 112);
		veNgang(64, 8, 6, 112);
		veNgang(64, 13, 6, 112);
		veDoc(71, 10, 1, 112);
		cheoPhai(68, 13, 5, 5, 112);
		cheoPhai(70, 8, 2, 2, 112);
		cheoTrai(70, 11, 2, 2, 112);

		veDoc(59, 7, 10, color);
		veNgang(59, 7, 6, color);
		veNgang(59, 12, 6, color);
		veDoc(67, 9, 1, color);
		cheoPhai(63, 12, 5, 5, color);
		cheoPhai(65, 7, 2, 2, color);
		cheoTrai(65, 10, 2, 2, color);

		//A

		cheoPhai(85, 8, 10, 10, 112);
		cheoTrai(75, 8, 10, 10, 112);
		veNgang(80, 13, 8, 112);

		cheoPhai(80, 7, 10, 10, color);
		cheoTrai(70, 7, 10, 10, color);
		veNgang(75, 12, 8, color);
		//W

		cheoPhai(90, 8, 10, 10, 112);
		cheoTrai(100, 13, 3, 3, 112);
		cheoPhai(103, 13, 3, 3, 112);
		cheoTrai(106, 8, 10, 10, 112);

		cheoPhai(85, 7, 10, 10, color);
		cheoTrai(95, 12, 3, 3, color);
		cheoPhai(98, 12, 3, 3, color);
		cheoTrai(101, 7, 10, 10, color);
	}
	txtColor(240);

}