#include "Frame.h"


void EnterLTCFrame( POINT p, bool isDone)//x = 14
{
	gotoxy(p.x, p.y + 1); cout <<  "|-----------------------------------------------|\n";
	gotoxy(p.x, p.y + 2); cout <<  "|                 Mo Lop Tin Chi                |\n";
	gotoxy(p.x, p.y + 3); cout <<  "|-----------------------------------------------|\n";
	gotoxy(p.x, p.y + 4); cout <<  "|             ___________________________       |\n";
	gotoxy(p.x, p.y + 5); cout <<  "| Ma Lop     |                           |      |\n";
	gotoxy(p.x, p.y + 6); cout <<  "|             ___________________________       |\n";
	gotoxy(p.x, p.y + 7); cout <<  "| Ma Mon Hoc |                           |      |\n";
	gotoxy(p.x, p.y + 8); cout <<  "|             ___________________________       |\n";
	gotoxy(p.x, p.y + 9); cout <<  "| Nien Khoa  |                           |      |\n";
	gotoxy(p.x, p.y + 10); cout << "|             ___________________________       |\n";
	gotoxy(p.x, p.y + 11); cout << "| Hoc Ky     |                           |      |\n";
	gotoxy(p.x, p.y + 12); cout << "|             ___________________________       |\n";
	gotoxy(p.x, p.y + 13); cout << "| Nhom       |                           |      |\n";
	gotoxy(p.x, p.y + 14); cout << "|             ___________________________       |\n";
	gotoxy(p.x, p.y + 15); cout << "| SV Max     |                           |      |\n";
	gotoxy(p.x, p.y + 16); cout << "|             ___________________________       |\n";
	gotoxy(p.x, p.y + 17); cout << "| SV Min     |                           |      |\n";
	gotoxy(p.x, p.y + 18); cout << "|-----------------------------------------------|\n";
	gotoxy(p.x, p.y + 19); cout << "|                                               |\n";
	gotoxy(p.x, p.y + 20); cout << "|                                               |\n";
	gotoxy(p.x, p.y + 21); cout << "|                                               |\n";
	gotoxy(p.x, p.y + 22); cout << "|-----------------------------------------------|\n";
	Button(isDone, "XONG", { p.x + 23, p.y + 19 }, { 8, 3 }, ColorCode_Blue, ColorCode_Black);
}

void ShowListLTCFrame(POINT p)
{
	gotoxy(p.x, p.y + 1); cout << "|------------------------------------------------------------------|\n";
	gotoxy(p.x, p.y + 2); cout << "|                      Danh Sach Lop Tin Chi                       |\n";
	gotoxy(p.x, p.y + 3); cout << "|------------------------------------------------------------------|\n";
	gotoxy(p.x, p.y + 4); cout << "| Ma Lop | M Mon Hoc | Niem Khoa | Hoc Ky | Nhom | SV Max | Sv Min |\n";
	gotoxy(p.x, p.y + 5); cout << "|------------------------------------------------------------------|";
}

void EnterCodeLTCFrame(POINT p) //x = 14
{
	gotoxy(p.x, p.y + 1); cout << "|-----------------------------------------------|\n";
	gotoxy(p.x, p.y + 2); cout << "|                Nhap Ma Lop Tin Chi            |\n";
	gotoxy(p.x, p.y + 3); cout << "|-----------------------------------------------|\n";
	gotoxy(p.x, p.y + 4); cout << "|             ___________________________       |";
	gotoxy(p.x, p.y + 5); cout << "| Ma Lop     |                           |      |\n";
	gotoxy(p.x, p.y + 6); cout << "|-----------------------------------------------|";
}

void ShowListToDeleteLTCFrame(POINT p)
{
	ShowListLTCFrame(p);

	gotoxy(p.x, p.y + 7); cout <<  "|------------------------------------------------------------------|\n";
	gotoxy(p.x, p.y + 8); cout <<  "|                Ban co muon xoa lop tin chi nay khong?            |\n";
	gotoxy(p.x, p.y + 9); cout <<  "|                                                                  |\n";
	gotoxy(p.x, p.y + 10); cout << "|                                                                  |\n";
	gotoxy(p.x, p.y + 11); cout << "|                                                                  |\n";
	gotoxy(p.x, p.y + 12); cout << "|                                                                  |\n";
	gotoxy(p.x, p.y + 13); cout << "|                                                                  |\n";
	gotoxy(p.x, p.y + 14); cout << "|------------------------------------------------------------------|\n";
}

void EnterMaSVFrame(POINT p) // x = 14
{
	gotoxy(p.x, p.y + 1); cout << "|-----------------------------------------------|\n";
	gotoxy(p.x, p.y + 2); cout << "|                Nhap Ma Sinh Vien              |\n";
	gotoxy(p.x, p.y + 3); cout << "|-----------------------------------------------|\n";
	gotoxy(p.x, p.y + 4); cout << "|             ___________________________       |";
	gotoxy(p.x, p.y + 5); cout << "| Ma SV      |                           |      |\n";
	gotoxy(p.x, p.y + 6); cout << "|-----------------------------------------------|";
}