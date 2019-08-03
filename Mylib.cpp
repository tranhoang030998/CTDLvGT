#include "Mylib.h"

char* Pwd() {
	char S[40]; int i = 0;
	while ((S[i] = _getch()) != Enter) {
		printf("%c", '*'); i++;
	}
	S[i] = '\0';
	return S;
}

int CheckPwd() {
	int dem = 0;
	for (dem = 1; dem <= 3; dem++) {
		printf("Password :");
		if (strcmp(Pwd(), PASSWORD) == 0)   return 1;
		else printf("\nPassword sai. Hay nhap lai\n");
	}
	return 0;
}

void gotoxy(short x, short y) {
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x,y };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}

int wherex(void) {
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
	return screen_buffer_info.dwCursorPosition.X;
}

int wherey(void) {
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
	return screen_buffer_info.dwCursorPosition.Y;
}
void clreol() {
	COORD coord;
	DWORD written;
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
	coord.X = info.dwCursorPosition.X;
	coord.Y = info.dwCursorPosition.Y;
	FillConsoleOutputCharacter(GetStdHandle(STD_OUTPUT_HANDLE), ' ',
		info.dwSize.X - info.dwCursorPosition.X * info.dwCursorPosition.Y, coord, &written);
	gotoxy(info.dwCursorPosition.X, info.dwCursorPosition.Y);
}

void SetColor(WORD color) {
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	wAttributes &= 0xfff0;
	wAttributes |= color;

	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}

void SetBGColor(WORD color) {
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	color <<= 4;
	wAttributes &= 0xff0f;
	wAttributes |= color;

	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
void clrscr() {
	system("cls");
}

//Lay thong tin phim nhan
int GetKey() {
	char key;
	key = _getch();
	if (key == -32 || key == 0)
		return -_getch();
	else return key;
}

int Alert(string str, POINT p)
{
	gotoxy(p.x, p.y);
	SetBGColor(ColorCode_White);
	cout << "                                                                                ";
	gotoxy(p.x, p.y + 2);
	cout << "                                                                                ";
	gotoxy(p.x, p.y + 1);
	SetColor(ColorCode_Red);
	std::cout << "   " << str << ":  ";

	SetBGColor(ColorCode_Black);
	SetColor(ColorCode_White);

	if (GetKey() == (int)'Y' || GetKey() == (int)'y')
		return 1;
	return 0;
}

//Pop up canh bao
void Alert(string str, POINT p, int color, int sleep, int bgColor)
{
	SetColor(color);
	SetBGColor(bgColor);
	gotoxy(p.x, p.y);
	std::cout << "                                        ";
	gotoxy(p.x, p.y + 1);
	std::cout << "                                        ";
	gotoxy(p.x, p.y + 1);
	std::cout << str;
	
	gotoxy(p.x, p.y + 2);
	std::cout << "                                        ";
	Sleep(sleep);
	SetBGColor(ColorCode_Black);
	SetColor(ColorCode_White);

	gotoxy(p.x, p.y);
	std::cout << "                                        ";
	gotoxy(p.x, p.y + 1);
	std::cout << "                                        ";
	gotoxy(p.x, p.y + 2);
	std::cout << "                                        ";
}

void drawRectangle(POINT &result, POINT lc, SIZE s, int colorBG, int colorBorder)
{
	POINT LCtemp = lc;
	for (int i = 0; i < s.cy; i++)
	{
		for (int j = 0; j < s.cx; j++)
		{
			SetColor(colorBorder); // set color border
			if (i == 0 || j == 0 || i == s.cy - 1 || j == s.cx - 1)
			{
				gotoxy(lc.x, lc.y);
				if (i == 0 && j == 0)
				{
					std::cout << (char)201;  // ╔
				}
				else if (i == 0 && j == s.cx - 1)
				{
					std::cout << (char)187; // ╗
				}
				else if (i == s.cy - 1 && j == 0)
				{
					std::cout << (char)200; // ╚
				}
				else if (i == s.cy - 1 && j == s.cx - 1)
				{
					std::cout << (char)188; // ╝
				}
				else if (i == 0 || i == s.cy - 1)
				{
					std::cout << (char)205; // ═
				}
				else if (j == 0 || j == s.cx - 1)
				{
					std::cout << (char)186;  // ║
				}
			}
			else
			{
				BGColorText(" ", ColorCode_DarkWhite, colorBG); // set color bg
			}
			lc.x++;
		}
		lc.x = LCtemp.x;
		lc.y++;
	}

	SetColor(ColorCode_DarkWhite); // reset color text;

	result.y = LCtemp.y + (s.cy / 2);
	result.x = LCtemp.x + 2;
}

void Button(bool isFocus, char *text, POINT lc, SIZE sizeBTN, int colorFocus, int colornFocus)
{
	POINT l;
	int padding = 4;

	POINT result;
	result.x = lc.x + (sizeBTN.cx / 2) - (strlen(text) / 2);
	result.y = lc.y + (sizeBTN.cy / 2);

	if (isFocus) //Focusing
	{
		drawRectangle(l, lc, sizeBTN, colorFocus, colorFocus);


		gotoxy(result.x, result.y);
		BGColorText(text, ColorCode_DarkWhite, colorFocus);

	}
	else
	{
		drawRectangle(l, lc, sizeBTN, colornFocus, ColorCode_DarkWhite);

		
			gotoxy(result.x, result.y);
			BGColorText(text, ColorCode_DarkWhite, colornFocus);

	}
	SetBGColor(ColorCode_Black); // reset;
}

int TwoOptionYN(POINT p)
{
	POINT pY = {p.x, p.y};
	POINT pN = {p.x + 40, p.y};
	Button(true, "YES", pY, { 7, 5 }, ColorCode_Blue, ColorCode_Black);
	Button(false, "NO", pN, { 7, 5 }, ColorCode_Blue, ColorCode_Black);
	int index = 0;
	while (true)
	{
		if (_kbhit())
		{
			char key = _getch();
			if (key == 75)//cout << "LEFT";
			{
				if (index == 0)
				{
					index = 1;
					Button(false, "YES", pY, { 7, 5 }, ColorCode_Blue, ColorCode_Black);
					Button(true, "NO", pN, { 7, 5 }, ColorCode_Blue, ColorCode_Black);
				}
				else if (index == 1)
				{
					index = 0;
					Button(true, "YES", pY, { 7, 5 }, ColorCode_Blue, ColorCode_Black);
					Button(false, "NO", pN, { 7, 5 }, ColorCode_Blue, ColorCode_Black);
				}
			}
			else if (key == 77)//cout << "RIGHT";
			{
				if (index == 0)
				{
					index = 1;
					Button(false, "YES", pY, { 7, 5 }, ColorCode_Blue, ColorCode_Black);
					Button(true, "NO", pN, { 7, 5 }, ColorCode_Blue, ColorCode_Black);
				}
				else if (index == 1)
				{
					index = 0;
					Button(true, "YES", pY, { 7, 5 }, ColorCode_Blue, ColorCode_Black);
					Button(false, "NO", pN, { 7, 5 }, ColorCode_Blue, ColorCode_Black);
				}
			}
			else if (key == 13)//cout << "ENTER";
			{
				return index;
			}
		}
	}
}

void ColorText(int number, int Color)
{
	SetColor(Color);
	cout << number;
	SetColor(7);
}
void ColorText(char Text, int Color)
{
	SetColor(Color);
	cout << Text;
	SetColor(7);
}
void ColorText(string Text, int Color)
{
	SetColor(Color);
	cout << Text;
	SetColor(7);
}

void BGColorText(char *text, int colorText, int colorBG)
{
	SetBGColor(colorBG);
	SetColor(colorText);
	cout << text;
	SetColor(7);
	SetBGColor(0);
}

void BGColorText(const char *text, int colorText, int colorBG)
{
	SetBGColor(colorBG);
	SetColor(colorText);
	cout << text;
	SetColor(7);
	SetBGColor(0);
}

