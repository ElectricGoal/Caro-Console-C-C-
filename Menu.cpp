#include "Menu.h"
#include "Console.h"
#include "Start game.h"

int X = 70, Y = 30, command;

void team17()
{
	txtColor(243);
	GotoXY(6, 30); cout << "   ******       ***************          ";
	GotoXY(6, 31); cout << "  ********       ***************         ";
	GotoXY(6, 32); cout << " ****  ****                  ****        ";
	GotoXY(6, 33); cout << "****    ****            **************   ";
	GotoXY(6, 34); cout << "         ****            **************  ";
	GotoXY(6, 35); cout << "          ****                  ****     ";
	GotoXY(6, 36); cout << "           ****                  ****    ";
	GotoXY(6, 37); cout << "            ****                  ****   ";
}

void hinh_menu()
{
	cout << endl;
	cout << endl;
	txtColor(241);
	cout << "          000000        xxxx       0000000       xxxxx          000000   xx  000000000  xx      xx       000000        xxxx       0000000    " << endl;
	cout << "        000   0000     xx  xx     00     00    xx     xx       00    00  xx  00         xx      xx     000   0000     xx  xx      00     00  " << endl;
	cout << "        00            xx    xx    00    000  xx         xx      000      xx  000000000  xx      xx     00            xx    xx     00     00  " << endl;
	cout << "        00           xxxxxxxxxx   00  000    xx         xx        000    xx  000000000  xx      xx     00           xxxxxxxxxx    0000000    " << endl;
	cout << "        00    0000  xx        xx  00     00    xx     xx      00    00   xx  00         xxx    xxx     00    0000  xx        xx   00         " << endl;
	cout << "          000000   xx          xx 00      00     xxxxx         000000    xx  000000000    xxxxxx         000000   xx          xx  00         " << endl;
	cout << endl;
	cout << endl;
	txtColor(246);
	cout << "                                            VIP      "<<endl;
	cout << "                                            VIP      "<<endl;
	cout << "                  xxx               xxx              xxxxxxx                 000000000        xxxxxxxxxx           0000000000           xxx         " << endl;
	cout << "                   xxx             xxx      000    xxxx    xxxx            0000     0000     xxx      xxxxx      000        000         xxx         " << endl;
	cout << "                    xxx           xxx       000    xxx        xxx          000         000   xxx          xxx   000          000        xxx         " << endl;
	cout << "                     xxx         xxx        000    xxx        xxx          000         000   xxx          xxx   000          000        xxx         " << endl;
	cout << "                      xxx       xxx         000    xxx     xxxx            000      0000     xxx      xxxxx     000          000        xxx         " << endl;
	cout << "                       xxx     xxx          000    xxxxxxxxx               00000000000       xxx   xxxxx        000          000        xxx         " << endl;
	cout << "                        xxx   xxx    00     000    xxx                     000               xxx      xxx       000          000                    " << endl;
	cout << "                         xxx xxx     000   0000    xxx                     000               xxx        xxx      000        000         xxx         " << endl;
	cout << "                          xxxxx        000000      xxx                     000               xxx          xxx      0000000000           xxx         " << endl;
	cout << endl;
	cout << endl;
	team17();
	txtColor(252);
	for (int i = 0; i < 20; i = i + 2)
	{
		GotoXY(65 + i, 23);
		cout << char(3);

		GotoXY(65 + i, 31);
		cout << char(3);
	}

	for (int i = 0; i < 9; i++)
	{
		GotoXY(65, 23 + i);
		cout << char(3);

		GotoXY(85, 23 + i);
		cout << char(3);
	}
	txtColor(243);
	GotoXY(130, 36); cout << "W : " << char(30) << "    S : " << char(31);
}

void Run_Menu()
{
	string Menu[4] = { "New Game", "Load Game", "Team Profile", "Exit" };
	int pointer = 0;

	while (true)
	{
		system("cls");
		hinh_menu();
		for (int i = 0; i < 4; ++i)
		{
			if (i == pointer)
			{
				GotoXY(70, 25 + i);
				txtColor(243);
				cout << Menu[i] << endl;
			}
			else
			{
				GotoXY(70, 25 + i);
				txtColor(240);
				cout << Menu[i] << endl;
			}
		}

		while (true)
		{
			command = toupper(_getch());
			if (command == 'W')
			{
				pointer -= 1;
				if (pointer == -1)
				{
					pointer = 3;
				}
				break;
			}
			else if (command == 'S')
			{
				pointer += 1;
				if (pointer == 4)
				{
					pointer = 0;
				}
				break;
			}
			else if (command == 13)
			{
				switch (pointer)
				{
				case 0:
				{
					NewGame();
				} break;
				case 1:
				{
					string taptin;
					bool ktra;
					do {
						system("cls");
						ktra = true;
						team17();
						txtColor(240);
						GotoXY(65, 10); cout << "Nhap ten file da luu :";
						getline(cin, taptin);
						ifstream L;
						L.open(taptin, ios::in);
						if (L.fail() == 1)
						{
							ktra = false;
							GotoXY(65, 12); cout << "File khong ton tai !";
							GotoXY(65, 14); cout << "Nhan phim bat ki de nhap lai!";
							GotoXY(65, 15); cout << "Nhan ESC de thoat";
							if (_getch() == 27)
							{
								Run_Menu();
							}
						}
					} while(ktra == false);
					LoadGame(taptin);
				}break;
				case 2:
				{
					system("cls");
					team17();
					txtColor(241);
					GotoXY(68, 8); cout << "20CTT3A    NHOM 17";
					txtColor(240);
					GotoXY(65, 10); cout << "20120353" << " HUYNH HUU PHUOC";
					GotoXY(65, 12); cout << "20120393" << " HUYNH MINH TU";
					GotoXY(65, 14); cout << "20120435" << " LE THI NGOC BICH";
					GotoXY(65, 16); cout << "20120470" << " NGUYEN VAN HAO";
					GotoXY(65, 18); cout << "20120474" << " LE KIM HIEU";
					txtColor(240);
					GotoXY(1, 1); cout << "Press any key to go back";
					system("pause > nul");
				} break;
				case 3:
					exit(0);
				}
				break;
			}
		}
	}

}
		
