#include "Menu.h"

#include <iostream>
#include <windows.h>

#pragma comment(lib, "user32")

int main()
{
	::SendMessage(::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);

	ListLopTinChi lltc;
	Initial_LLTC(lltc);
	///*Nhap_LLTC(lltc);

	//LuuFile_LLTC(lltc);*/

	DocFile_LLTC(lltc);

	//system("cls");
	////Xuat_LLTC(lltc);

	////system("cls");
	////Them_LLTC(lltc);
	////Xoa_LLTC(lltc);
	////Sua_LLTC(lltc);
	///*ListDangKy *ldk = NULL;
	//Nhap_DSDK(ldk);*/


	///*ThemSinhVien_DSDK(lltc);

	//ThemSinhVien_DSDK(lltc);

	//ThemSinhVien_DSDK(lltc);

	//LuuFile_DSDK(lltc);*/

	DocFile_DSDK(lltc);

	ListSinhVien lsv = NULL;
	///*Nhap_SV(lsv);

	//Xuat_SV(lsv);

	//LuuFile_LSV(lsv);*/

	DocFile_LSV(lsv);
	//
	////Xuat_SV(lsv);
	////ShowByClass_SV(lsv);

	ListMonHoc lmh = NULL;
	///*Nhap_LMH(lmh);
	//Xuat_LMH(lmh);*/

	////LuuFile_LMH(lmh);
	//system("cls");

	DocFile_LMH(lmh);
	////Xuat_LMH(lmh);

	///*_getch();
	//ShowByNameSubjects(lmh);*/

	DangKyHoc(lltc, lsv);
	//NhapDiem(lltc, lsv, lmh, true);
	XemBangDiemTBTheoLop(lltc, lsv, lmh);

	//menu_Show();
	
	gotoxy(40, 40);
	system("pause");
	return 0;
}