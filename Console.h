#ifndef _CONSOLE_H
#define _CONSOLE_H
#include <windows.h>
#include <iostream>
using namespace std;

void FixConsoleWindow(); //hàm cố định console
void SetWindowSize(SHORT width, SHORT height); //hàm thay đổi kich thước console
void DisableResizeWindow(); //hàm vô hiệu hóa resize console
void ShowScrollbar(BOOL Show); //hàm ẩn thanh cuộn
void GotoXY(int x, int y); //hàm di chuyển chỗ nháy trên màn hình console
void txtColor(int color);

#endif
