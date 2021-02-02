#include "Start game.h"
#include "Console.h"
#include "Menu.h"
#include "Effect.h"
#include <iostream>

#define BOARD_SIZE 12 // Kích thức ma trận bàn cờ
#define LEFT 3 // Tọa độ trái màn hình bàn cờ
#define TOP 1 // Tọa độ trên màn hình bàn cờ
// Khai báo kiểu dữ liệu
struct _POINT { int x, y, c; }; // x: tọa độ dòng, y: tọa độ cột, c: đánh dấu
_POINT _A[BOARD_SIZE + 1][BOARD_SIZE + 1]; //Ma trận bàn cờ
bool _TURN; //true là lượt người thứ nhất và false là lượt người thứ hai
int _COMMAND; // Biến nhận giá trị phím người dùng nhập
int _X, _Y; //Tọa độ hiện hành trên màn hình bàn cờ
int ScoreX = 0, ScoreO = 0; //Số điểm của 2 người chơi X và O
bool TheLastValue; //Giá trị cuối cùng để đánh X hoặc O


void DrawBoard(int pSize) {
	txtColor(242);
	for (int i = 0; i <= pSize; i++) {
		for (int j = 0; j <= pSize; j++) {
			GotoXY(LEFT + 4 * i, TOP + 2 * j);
			cout << " . ";
			GotoXY(6, 2);
		}
	}
}



//Hàm khởi tạo dữ liệu mặc định ban đầu cho ma trận bàn cờ (hàm nhóm Model)
void ResetData() {
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			_A[i][j].x = 4 * j + LEFT + 3; // Trùng với hoành độ màn hình bàn cờ
			_A[i][j].y = 2 * i + TOP + 1; // Trùng với tung độ màn hình bàn cờ
			_A[i][j].c = 0; // 0 nghĩa là chưa ai đánh dấu, nếu đánh dấu phải theo quy
			//định như sau: -1 là lượt true đánh, 1 là lượt false đánh
		}
	}
	_TURN = true; _COMMAND = -1; // Gán lượt và phím mặc định
	_X = _A[0][0].x; _Y = _A[0][0].y; // Thiết lập lại tọa độ hiện hành ban đầu
}



void StartGame() {
	system("cls");
	ResetData(); // Khởi tạo dữ liệu gốc
	KhungGiaoDien();
	Xturn();
	GotoXY(73, 5);
	txtColor(240);
	cout << ScoreX;
	GotoXY(106, 5);
	txtColor(240);
	cout << ScoreO;
	TrangTri();
	DrawBoard(BOARD_SIZE); // Vẽ màn hình game
}



//Hàm thoát game (hàm nhóm Control)
void ExitGame() {
	system("cls");

}



//Hàm xử lý khi người chơi thua
int ProcessFinish(int pWhoWin) {
	GotoXY(0, _A[BOARD_SIZE - 1][BOARD_SIZE - 1].y + 2); // Nhảy tới vị trí
		 // thích hợp để in chuỗi thắng/thua/hòa
	switch (pWhoWin) {
	case -1:
		P1Win();
		ScoreX += 1;
		break;
	case 1:
		P2Win();
		ScoreO += 1;
		break;
	case 0:
		Draw();
		break;
	case 2:
		_TURN = !_TURN; // Đổi lượt nếu không có gì xảy ra

	}
	GotoXY(_X, _Y); // Trả về vị trí hiện hành của con trỏ màn hình bàn cờ
	return pWhoWin;
}


int AskContinue() {
	txtColor(240);
	GotoXY(5, 32); cout<< "Ban co muon choi tiep khong! Nhan Y de tiep tuc hoac N de dung...";
	return toupper(_getch());
}

int isWin(int x)
{
	int X, Y;
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			if (_A[i][j].x == _X && _A[i][j].y == _Y)
			{
				X = i;
				Y = j;
				break;
			}
		}
	}
	//ngang
	int startx = X - 4, endx = X + 4;
	if (X < 0) startx = 0;
	if (X > 11) endx = 11;
	for (short i = startx; i + 4 <= endx; i++)
		if (_A[i][Y].c == x && _A[i + 1][Y].c == x && _A[i + 2][Y].c == x && _A[i + 3][Y].c == x && _A[i + 4][Y].c == x)
			return 1;
	//doc
	int starty = Y - 4, endy = Y + 4;
	if (Y < 0) starty = 0;
	if (Y > 11) endy = 11;
	for (short i = starty; i + 4 <= endy; i++)
		if (_A[X][i].c == x && _A[X][i + 1].c == x && _A[X][i + 2].c == x && _A[X][i + 3].c == x && _A[X][i + 4].c == x)
			return 1;
	//cheo

	int max, min;
	max = (X >= Y) ? X : Y;
	min = (X >= Y) ? Y : X;
	startx = X - 4;
	starty = Y - 4;
	endx = X + 4;
	endy = Y + 4;
	if (min < 4)
	{
		if (min == X)
		{
			startx = 0;
			starty = Y - X;
		}
		else
		{
			startx = X - Y;
			starty = 0;
		}
	}
	if (max > 7)
	{
		if (max == X)
		{
			endx = 11;
			endy = Y + (11 - X);
		}
		else
		{
			endx = X + (11 - Y);
			endy = 11;
		}
	}
	for (short i = 0; startx + 4 + i <= endx && starty + 4 + i <= endy; i++)
	{
		if (_A[startx + i][starty + i].c == x && _A[startx + i + 1][starty + i + 1].c == x && _A[startx + i + 2][starty + i + 2].c == x && _A[startx + i + 3][starty + i + 3].c == x && _A[startx + i + 4][starty + i + 4].c == x)
			return 1;
	}
	//cheophu
	max = (11 - X >= Y) ? (11 - X) : Y;
	min = (11 - X >= Y) ? Y : (11 - X);
	startx = X + 4;
	starty = Y - 4;
	endx = X - 4;
	endy = Y + 4;
	if (min < 4)
	{
		if (min == 11 - X)
		{
			startx = 11;
			starty = Y -(11 - X);
		}
		else
		{
			startx = X + Y;
			starty = 0;
		}
	}
	if (max > 7)
	{
		if (max == 11 - X)
		{
			endx = 0;
			endy = Y + X;
		}
		else
		{
			endx = X - (11 - Y);
			endy = 11;
		}
	}
	for (short i = 0; startx - 4 - i >= endx && starty + 4 + i <= endy; i++)
	{
		if (_A[startx - i][starty + i].c == x && _A[startx - i - 1][starty + i + 1].c == x && _A[startx - i - 2][starty + i + 2].c == x && _A[startx - i - 3][starty + i + 3].c == x && _A[startx - i - 4][starty + i + 4].c == x)
			return 1;
	}
	return 0;
}
int isDraw()
{
	int sum = 0;
	for (int i = 0; i <= 11; i++)
	{
		for (int j = 0; j <= 11; j++)
		{
			if ((_A[i][j].c == 1) || (_A[i][j].c == -1))
				sum = sum + 1;
		}

		if (sum == 144)
		{
			return 1;
		}
	}
	return 0;
}



//Hàm kiểm tra xem có người thắng/thua hay hòa
int TestBoard()
{
	if (isWin(-1)) return -1;
	else if (isWin(1)) return 1;
	else if (isDraw() == 1) return 0;
	else return 2;
}



int CheckBoard(int pX, int pY)
{
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			if (_A[i][j].x == pX && _A[i][j].y == pY && _A[i][j].c == 0) {
				if (_TURN == true) _A[i][j].c = -1; // Nếu lượt hiện hành là true thì c = -1
				else _A[i][j].c = 1; // Nếu lượt hiện hành là false thì c = 1
				return _A[i][j].c;
			}
		}
	}
	return 0;
}




void MoveRight()
{
	if (_X < _A[BOARD_SIZE - 1][BOARD_SIZE - 1].x)
	{
		_X += 4;
		GotoXY(_X, _Y);

	}
}
void MoveLeft() {
	if (_X > _A[0][0].x) {
		_X -= 4;
		GotoXY(_X, _Y);
	}
}
void MoveDown() {
	if (_Y < _A[BOARD_SIZE - 1][BOARD_SIZE - 1].y)
	{
		_Y += 2;
		GotoXY(_X, _Y);
	}
}
void MoveUp() {
	if (_Y > _A[0][0].y) {
		_Y -= 2;
		GotoXY(_X, _Y);
	}
}



void NewGame()
{
	FixConsoleWindow();
	ScoreX = 0;
	ScoreO = 0;
	
	StartGame();
	GotoXY(6, 2);
	bool validEnter = true;
	while (1)
	{
		_COMMAND = toupper(_getch());

		if (_COMMAND == 27)
		{
			TheLastValue = _TURN;
			SaveGame_ESC();
			ExitGame();
			return;
		}
		else {
			if (_COMMAND == 'A') MoveLeft();
			else if (_COMMAND == 'W') MoveUp();
			else if (_COMMAND == 'S') MoveDown();
			else if (_COMMAND == 'D') MoveRight();
			else if (_COMMAND == 13) {// Người dùng đánh dấu trên màn hình bàn cờ
				switch (CheckBoard(_X, _Y)) {
				case -1:
					txtColor(252);
					cout << 'X';
					Oturn();
					break;
				case 1:
					txtColor(249);
					cout << 'O';
					Xturn();
					break;
				case 0: validEnter = false; // Khi đánh vào ô đã đánh rồi
				}
				// Tiếp theo là kiểm tra và xử lý thắng/thua/hòa/tiếp tục
				if (validEnter == true) {
					switch (ProcessFinish(TestBoard())) {
					case -1: case 1: case 0:
						if (AskContinue() != 'Y') {
							SaveGame_N();
							ExitGame();
							Run_Menu();
						}
						else StartGame();
					}

				}
				validEnter = true; // Mở khóa

			}
		}
		continue;
	}
}

void SaveGame_ESC() //Ham xu ly save game sau khi nhan ESC
{
	int command;
	txtColor(240);
	GotoXY(5, 32); cout << "Ban co muon luu tro choi khong ?                                       ";
	GotoXY(5, 33); cout << "   Co : Nhan phim Y de luu";
	GotoXY(5, 34); cout << "   Khong : Nhan cac phim con lai de thoat";
	command = toupper(_getch());
	if (command == 'Y')
	{
		GotoXY(5, 32); cout << "                                                                    ";
		GotoXY(5, 34); cout << "                                         ";
		GotoXY(5, 33); cout << "Nhap ten file de luu...    " << endl;
		GotoXY(5, 34); cout << "Ten file: ";
		string taptin;
		getline(cin, taptin);
		ofstream S;
		S.open(taptin, ios::out);
		S << TheLastValue << endl;
		S << ScoreX << endl;
		S << ScoreO << endl;
		for (int i = 0; i < BOARD_SIZE; i++)
			for (int j = 0; j < BOARD_SIZE; j++)
			{
				if (_A[i][j].c == -1)
					S << 2;
				else
					S << _A[i][j].c;
			}
		S.close();
	}
}

void SaveGame_N() //Ham xu ly save game khi nhan N
{
	int command;
	txtColor(240);
	GotoXY(5, 32); cout << "Ban co muon luu tro choi khong ?                                      ";
	GotoXY(5, 33); cout << "  Co : Nhan phim Y de luu";
	GotoXY(5, 34); cout << "  Khong : Nhan cac phim con lai de thoat";
	command = toupper(_getch());
	if (command == 'Y')
	{
		GotoXY(5, 32); cout << "                                                                    ";
		GotoXY(5, 34); cout << "                                         ";
		GotoXY(5, 33); cout << "Nhap ten file de luu...    " << endl;
		GotoXY(5, 34); cout << "Ten file: ";
		string taptin;
		getline(cin, taptin);
		ofstream S;
		S.open(taptin, ios::out);
		S << 1 << endl;
		S << ScoreX << endl;
		S << ScoreO << endl;
		S.close();
	}
}

void LoadGame(string taptin) //Ham xu ly load game
{
	char t;
	
	ifstream L;
	L.open(taptin, ios::in);
	L >> TheLastValue;
	L >> ScoreX;
	L >> ScoreO;
	FixConsoleWindow();
	StartGame();
	
	for (int i = 0; i < BOARD_SIZE; i++)
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			L >> t;
			if (t == '2')
			{
				_A[i][j].c = -1;
				GotoXY(_A[i][j].x, _A[i][j].y);
				txtColor(252);
				cout << 'X';
			}
			else if (t == '1')
			{
				_A[i][j].c = 1;
				GotoXY(_A[i][j].x, _A[i][j].y);
				txtColor(249);
				cout << 'O';
			}
		}
	L.close();
	if (TheLastValue == true)
		Xturn();
	else
		Oturn();
	GotoXY(6, 2);
	_TURN = TheLastValue;
	bool validEnter = true;
	while (1)
	{
		
		_COMMAND = toupper(_getch());

		if (_COMMAND == 27)

		{
			TheLastValue = _TURN;
			SaveGame_ESC();
			ExitGame();
			return;
		}
		else {
			if (_COMMAND == 'A') MoveLeft();
			else if (_COMMAND == 'W') MoveUp();
			else if (_COMMAND == 'S') MoveDown();
			else if (_COMMAND == 'D') MoveRight();
			else if (_COMMAND == 13) {// Người dùng đánh dấu trên màn hình bàn cờ
				switch (CheckBoard(_X, _Y)) {
				case -1:
					txtColor(252);
					cout << 'X';
					Oturn();
					break;
				case 1:
					txtColor(249);
					cout << 'O';
					Xturn();
					break;
				case 0: validEnter = false; // Khi đánh vào ô đã đánh rồi
				}
				// Tiếp theo là kiểm tra và xử lý thắng/thua/hòa/tiếp tục
				if (validEnter == true) {
					switch (ProcessFinish(TestBoard())) {
					case -1: case 1: case 0:
						if (AskContinue() != 'Y') {
							SaveGame_N();
							ExitGame();
							Run_Menu();
						}
						else StartGame();
					}
				}
				validEnter = true; // Mở khóa
			}
		}
		continue;
	}

}