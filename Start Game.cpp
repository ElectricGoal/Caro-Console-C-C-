#include "Start game.h"
#include "Console.h"


void KhungGiaoDien() {
    txtColor(245);
    for (int i = 0; i <= 28; i++)
    {
        GotoXY(60, i);
        cout << char(186);
    }
    for (int i = 0; i <= 58; i++)
    {
        GotoXY(61 + i, 1);
        cout << char(205);
    }
    for (int i = 0; i <= 28; i++)
    {
        GotoXY(120, i);
        cout << char(186);
    }
    GotoXY(87, 1);
    txtColor(246);
    cout << " TI SO ";
    GotoXY(70, 3);
    txtColor(240);
    cout << "PLAYER X                         PLAYER O";
    txtColor(245);
    for (int i = 0; i <= 8; i++)
    {
        GotoXY(90, 2 + i);
        cout << char(186);
    }
    for (int i = 0; i <= 58; i++)
    {
        GotoXY(61 + i, 10);
        cout << char(205);
    }
    txtColor(246);
    GotoXY(86, 10);
    cout << " LUOT DI ";
    txtColor(245);
    for (int i = 0; i <= 58; i++)
    {
        GotoXY(61 + i, 20);
        cout << char(205);
    }
    for (int i = 0; i <= 120; i++)
    {
        GotoXY(0 + i, 29);
        cout << char(205);
    }
    GotoXY(85, 20);
    txtColor(246);
    cout << " HUONG DAN ";
    txtColor(241);
    GotoXY(74, 23); cout << "W : " << char(30) << "    S : " << char(31) << "    D : " << char(16) << "    A : " << char(17);

    txtColor(240);
    GotoXY(74, 25); cout << "Enter : Chon vi tri danh X hoac O";
    GotoXY(74, 27); cout << "ESC : Nhan de thoat";
}

void TrangTri()
{
    txtColor(252);
    GotoXY(127, 1);  cout << "xxx         xxx     " << endl;
    GotoXY(127, 2);  cout << "  xxx     xxx       " << endl;
    GotoXY(127, 3);  cout << "    xxx xxx         " << endl;
    GotoXY(127, 4);  cout << "      xxx           " << endl;
    GotoXY(127, 5);  cout << "    xxx xxx         " << endl;
    GotoXY(127, 6);  cout << "  xxx     xxx       " << endl;
    GotoXY(127, 7);  cout << "xxx         xxx     " << endl;
    GotoXY(127, 8);  cout << endl;
    GotoXY(127, 9);  cout << endl;
    txtColor(249);
    GotoXY(127, 10); cout << "   000000000    " << endl;
    GotoXY(127, 11); cout << " 000       000   " << endl;
    GotoXY(127, 12); cout << "000         000  " << endl;
    GotoXY(127, 13); cout << "000         000  " << endl;
    GotoXY(127, 14); cout << "000         000  " << endl;
    GotoXY(127, 15); cout << " 000       000  " << endl;
    GotoXY(127, 16); cout << "   000000000   " << endl;
    GotoXY(127, 17); cout << endl;
    GotoXY(127, 18); cout << endl;
    txtColor(252);
    GotoXY(127, 19);  cout << "xxx         xxx     " << endl;
    GotoXY(127, 20);  cout << "  xxx     xxx       " << endl;
    GotoXY(127, 21);  cout << "    xxx xxx         " << endl;
    GotoXY(127, 22);  cout << "      xxx           " << endl;
    GotoXY(127, 23);  cout << "    xxx xxx         " << endl;
    GotoXY(127, 24);  cout << "  xxx     xxx       " << endl;
    GotoXY(127, 25);  cout << "xxx         xxx     " << endl;
    GotoXY(127, 26); cout << endl;
    GotoXY(127, 27); cout << endl;
    txtColor(249);
    GotoXY(127, 28); cout << "   000000000    " << endl;
    GotoXY(127, 29); cout << " 000       000   " << endl;
    GotoXY(127, 30); cout << "000         000  " << endl;
    GotoXY(127, 31); cout << "000         000  " << endl;
    GotoXY(127, 32); cout << "000         000  " << endl;
    GotoXY(127, 33); cout << " 000       000  " << endl;
    GotoXY(127, 34); cout << "   000000000   " << endl;
}

void Xturn()
{
    txtColor(252);
    GotoXY(83, 12);  cout << "xxx         xxx        " << endl;
    GotoXY(83, 13);  cout << "  xxx     xxx          " << endl;
    GotoXY(83, 14);  cout << "    xxx xxx            " << endl;
    GotoXY(83, 15);  cout << "      xxx              " << endl;
    GotoXY(83, 16);  cout << "    xxx xxx            " << endl;
    GotoXY(83, 17);  cout << "  xxx     xxx          " << endl;
    GotoXY(83, 18);  cout << "xxx         xxx        " << endl;
}

void Oturn()
{
    txtColor(249);
    GotoXY(83, 12); cout << "   000000000            " << endl;
    GotoXY(83, 13); cout << " 000       000          " << endl;
    GotoXY(83, 14); cout << "000         000         " << endl;
    GotoXY(83, 15); cout << "000         000         " << endl;
    GotoXY(83, 16); cout << "000         000         " << endl;
    GotoXY(83, 17); cout << " 000       000          " << endl;
    GotoXY(83, 18); cout << "   000000000            " << endl;
}





