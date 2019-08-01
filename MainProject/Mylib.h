#pragma once
#include <conio.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#include <string>
#include <windows.h>
using namespace std;


#define Enter 13
//const int WHITE=15;
#define PASSWORD "abcdef"
//const int WHITE=15;

#define ColorCode_Black			0
#define ColorCode_DarkBlue		1
#define ColorCode_DarkGreen		2
#define ColorCode_DarkCyan		3
#define ColorCode_DarkRed		4
#define ColorCode_DarkPink		5
#define ColorCode_DarkYellow	6
#define ColorCode_DarkWhite		7
#define ColorCode_Grey			8
#define ColorCode_Blue			9
#define ColorCode_Green			10
#define ColorCode_Cyan			11
#define ColorCode_Red			12
#define ColorCode_Pink			13
#define ColorCode_Yellow		14
#define ColorCode_White			15

char* Pwd();
int CheckPwd();
void gotoxy(short x, short y);
int wherex(void);
int wherey(void);
void clreol();
void SetColor(WORD color);
void SetBGColor(WORD color);
void clrscr();
int Alert(string str, POINT p);
void Alert(string str, POINT p, int color, int sleep, int bgColor);
void Button(bool isFocus, char *text, POINT lc, SIZE sizeBTN, int colorFocus, int colornFocus);
int TwoOptionYN(POINT p);
void BGColorText(const char *text, int colorText, int colorBG);

//-----------------------------------------------------------NEW ADD----------------------------------------------------------

////Resize Console
//void resizeConsole(int width, int height) {
//	HWND console = GetConsoleWindow();
//	RECT r;
//	GetWindowRect(console, &r);
//	MoveWindow(console, r.left, r.top, width, height, TRUE);
//}

//
////Lay thong tin phim nhan
//int GetKey() {
//	char key;
//	key = _getch();
//	if (key == -32 || key == 0)
//		return -_getch();
//	else return key;
//}
//
////Turn off buttom cua Them Lop