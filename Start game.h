#pragma once

#include <windows.h>
#include <conio.h>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void txtColor(int color);
void KhungGiaoDien();
void TrangTri();

void FixConsoleWindow();
void GotoXY(int x, int y);
void DrawBoard(int pSize);
void ResetData();
void StartGame();
void ExitGame();
int ProcessFinish(int pWhoWin);
int AskContinue();
int isWin(int x);
int isDraw();
int TestBoard();
int CheckBoard(int pX, int pY);
void MoveRight();
void MoveLeft();
void MoveDown();
void MoveUp();
void NewGame();
void Xturn();
void Oturn();
void SaveGame_ESC();
void SaveGame_N();
void LoadGame(string taptin);