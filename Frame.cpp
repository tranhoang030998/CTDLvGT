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

void EnterSVFrame(POINT p) // x = 20
{
	gotoxy(p.x, p.y + 1); cout <<  "|----------------------------------------------------|\n";
	gotoxy(p.x, p.y + 2); cout <<  "|                 Thong Tin Sinh Vien                |\n";
	gotoxy(p.x, p.y + 3); cout <<  "|----------------------------------------------------|\n";
	gotoxy(p.x, p.y + 4); cout <<  "|                  ___________________________       |\n";
	gotoxy(p.x, p.y + 5); cout <<  "| Ma SV           |                           |      |\n";
	gotoxy(p.x, p.y + 6); cout <<  "|                  ___________________________       |\n";
	gotoxy(p.x, p.y + 7); cout <<  "| Ma Lop          |                           |      |\n";
	gotoxy(p.x, p.y + 8); cout <<  "|                  ___________________________       |\n";
	gotoxy(p.x, p.y + 9); cout <<  "| Ho              |                           |      |\n";
	gotoxy(p.x, p.y + 10); cout << "|                  ___________________________       |\n";
	gotoxy(p.x, p.y + 11); cout << "| Ten             |                           |      |\n";
	gotoxy(p.x, p.y + 12); cout << "|                  ___________________________       |\n";
	gotoxy(p.x, p.y + 13); cout << "| Gioi Tinh       |                           |      |\n";
	gotoxy(p.x, p.y + 14); cout << "|                  ___________________________       |\n";
	gotoxy(p.x, p.y + 15); cout << "| SDT             |                           |      |\n";
	gotoxy(p.x, p.y + 16); cout << "|                  ___________________________       |\n";
	gotoxy(p.x, p.y + 17); cout << "| Nam Nhap Hoc    |                           |      |\n";
	gotoxy(p.x, p.y + 18); cout << "|----------------------------------------------------|\n";
	gotoxy(p.x, p.y + 19); cout << "|               Ban co muon nhap tiep khong?         |\n";
	gotoxy(p.x, p.y + 20); cout << "|                                                    |\n";
	gotoxy(p.x, p.y + 21); cout << "|                                                    |\n";
	gotoxy(p.x, p.y + 22); cout << "|                                                    |\n";
	gotoxy(p.x, p.y + 23); cout << "|                                                    |\n";
	gotoxy(p.x, p.y + 24); cout << "|                                                    |\n";
	gotoxy(p.x, p.y + 25); cout << "|                                                    |\n";
	gotoxy(p.x, p.y + 26); cout << "|----------------------------------------------------|\n";

	Button(false, "YES", {p.x + 4, p.y + 19}, { 7, 5 }, ColorCode_Blue, ColorCode_Black);
	Button(false, "NO", {p.x + 44, p.y + 19}, { 7, 5 }, ColorCode_Blue, ColorCode_Black);

}

void ShowListSVFrame(POINT p)
{
	gotoxy(p.x, p.y + 1); cout << "|----------------------------------------------------------------------------------------------|\n";
	gotoxy(p.x, p.y + 2); cout << "|                                       Danh Sach Sinh Vien                                    |\n";
	gotoxy(p.x, p.y + 3); cout << "|----------------------------------------------------------------------------------------------|\n";
	gotoxy(p.x, p.y + 4); cout << "|   Ma SV    |       Ho      |    Ten    |  Ma Lop   | Gioi Tinh |         SDT       |  Nam NH |\n";
	gotoxy(p.x, p.y + 5); cout << "|----------------------------------------------------------------------------------------------|";
}

void EnterClassCodeFrame(POINT p) // x = 14
{
	gotoxy(p.x, p.y + 1); cout << "|-----------------------------------------------|\n";
	gotoxy(p.x, p.y + 2); cout << "|                    Nhap Ma Lop                |\n";
	gotoxy(p.x, p.y + 3); cout << "|-----------------------------------------------|\n";
	gotoxy(p.x, p.y + 4); cout << "|             ___________________________       |";
	gotoxy(p.x, p.y + 5); cout << "| Ma Lop     |                           |      |\n";
	gotoxy(p.x, p.y + 6); cout << "|-----------------------------------------------|";
}

void EnterSubjectsFrame(POINT p)
{
	gotoxy(p.x, p.y + 1); cout <<  "|----------------------------------------------------|\n";
	gotoxy(p.x, p.y + 2); cout <<  "|                    Thong Tin Mon Hoc               |\n";
	gotoxy(p.x, p.y + 3); cout <<  "|----------------------------------------------------|\n";
	gotoxy(p.x, p.y + 4); cout <<  "|                  ___________________________       |\n";
	gotoxy(p.x, p.y + 5); cout <<  "| Ma Mon Hoc      |                           |      |\n";
	gotoxy(p.x, p.y + 6); cout <<  "|                  ___________________________       |\n";
	gotoxy(p.x, p.y + 7); cout <<  "| Ten Mon Hoc     |                           |      |\n";
	gotoxy(p.x, p.y + 8); cout <<  "|                  ___________________________       |\n";
	gotoxy(p.x, p.y + 9); cout <<  "| So Tin Chi LT   |                           |      |\n";
	gotoxy(p.x, p.y + 10); cout << "|                  ___________________________       |\n";
	gotoxy(p.x, p.y + 11); cout << "| So Tin Chi TH   |                           |      |\n";
	gotoxy(p.x, p.y + 12); cout << "|----------------------------------------------------|\n";
	gotoxy(p.x, p.y + 13); cout << "|              Ban co muon nhap tiep khong?          |\n";
	gotoxy(p.x, p.y + 14); cout << "|                                                    |\n";
	gotoxy(p.x, p.y + 15); cout << "|                                                    |\n";
	gotoxy(p.x, p.y + 16); cout << "|                                                    |\n";
	gotoxy(p.x, p.y + 17); cout << "|                                                    |\n";
	gotoxy(p.x, p.y + 18); cout << "|                                                    |\n";
	gotoxy(p.x, p.y + 19); cout << "|                                                    |\n";
	gotoxy(p.x, p.y + 20); cout << "|----------------------------------------------------|\n";
}

void ShowListSubjectFrame(POINT p)
{
	gotoxy(p.x, p.y + 1); cout << "|---------------------------------------------------------------|\n";
	gotoxy(p.x, p.y + 2); cout << "|                      Danh Sach Mon Hoc                        |\n";
	gotoxy(p.x, p.y + 3); cout << "|---------------------------------------------------------------|\n";
	gotoxy(p.x, p.y + 4); cout << "| Ma Mon Hoc |    Ten Mon Hoc   | STC Thuc Hanh | STC Ly Thuyet |\n";
	gotoxy(p.x, p.y + 5); cout << "|---------------------------------------------------------------|";
}

void EnterSubjectCodeFrame(POINT p) // x = 14
{
	gotoxy(p.x, p.y + 1); cout << "|-----------------------------------------------|\n";
	gotoxy(p.x, p.y + 2); cout << "|                  Nhap Ma Mon Hoc              |\n";
	gotoxy(p.x, p.y + 3); cout << "|-----------------------------------------------|\n";
	gotoxy(p.x, p.y + 4); cout << "|             ___________________________       |";
	gotoxy(p.x, p.y + 5); cout << "| Ma Mon Hoc |                           |      |\n";
	gotoxy(p.x, p.y + 6); cout << "|-----------------------------------------------|";
}

void EnterToRegSubjects(POINT p)
{
	gotoxy(p.x, p.y + 1); cout <<  "|----------------------------------------------------|\n";
	gotoxy(p.x, p.y + 2); cout <<  "|                     Thong Tin SV DK                |\n";
	gotoxy(p.x, p.y + 3); cout <<  "|----------------------------------------------------|\n";
	gotoxy(p.x, p.y + 4); cout <<  "|                  ___________________________       |\n";
	gotoxy(p.x, p.y + 5); cout <<  "| Ma sinh Vien    |                           |      |\n";
	gotoxy(p.x, p.y + 6); cout <<  "|                  ___________________________       |\n";
	gotoxy(p.x, p.y + 7); cout <<  "| Niem Khoa       |                           |      |\n";
	gotoxy(p.x, p.y + 8); cout <<  "|                  ___________________________       |\n";
	gotoxy(p.x, p.y + 9); cout <<  "| Hoc Ky          |                           |      |\n";
	gotoxy(p.x, p.y + 10); cout << "|----------------------------------------------------|\n";
}

void EnterScoreFrame(POINT p)
{
	gotoxy(p.x, p.y + 1); cout <<  "|----------------------------------------------------|\n";
	gotoxy(p.x, p.y + 2); cout <<  "|                        Thong Tin                   |\n";
	gotoxy(p.x, p.y + 3); cout <<  "|----------------------------------------------------|\n";
	gotoxy(p.x, p.y + 4); cout <<  "|                  ___________________________       |\n";
	gotoxy(p.x, p.y + 5); cout <<  "| Ma Mon Hoc      |                           |      |\n";
	gotoxy(p.x, p.y + 6); cout <<  "|                  ___________________________       |\n";
	gotoxy(p.x, p.y + 7); cout <<  "| Niem Khoa       |                           |      |\n";
	gotoxy(p.x, p.y + 8); cout <<  "|                  ___________________________       |\n";
	gotoxy(p.x, p.y + 9); cout <<  "| Hoc Ky          |                           |      |\n";
	gotoxy(p.x, p.y + 10); cout << "|                  ___________________________       |\n";
	gotoxy(p.x, p.y + 11); cout << "| Nhom            |                           |      |\n";
	gotoxy(p.x, p.y + 12); cout << "|----------------------------------------------------|\n";
}

void EnterInfoScoreFrame(POINT p)
{
	gotoxy(p.x, p.y + 1); cout << "|---------------------------------------------------------------|\n";
	gotoxy(p.x, p.y + 2); cout << "|                           Danh Sach                           |\n";
	gotoxy(p.x, p.y + 3); cout << "|---------------------------------------------------------------|\n";
	gotoxy(p.x, p.y + 4); cout << "|  STT |     Ma SV    |      HO      |    Ten    |   Diem       |\n";
	gotoxy(p.x, p.y + 5); cout << "|---------------------------------------------------------------|";
}

void TitleShowScore(POINT p)
{
	gotoxy(p.x, p.y); cout <<     "_________________________________________________________________";
	gotoxy(p.x, p.y + 1); cout << "|---------------------------------------------------------------|\n";
	gotoxy(p.x, p.y + 2); cout << "|                     BANG DIEM MON:                            |";
	gotoxy(p.x, p.y + 3); cout << "|      Niem Khoa:            Hoc Ky:           Nhom:            |";
}