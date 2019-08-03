#include "Mylib.h"
#include "Confirm.h"
#include "Frame.h"
#include "LopTinChi.h"
#include "DangKy.h"

int main()
{
	
	ListLopTinChi lltc;
	Initial_LLTC(lltc);
	/*Nhap_LLTC(lltc);

	LuuFile_LLTC(lltc);*/

	DocFile_LLTC(lltc);

	system("cls");
	Xuat_LLTC(lltc);

	system("cls");
	//Them_LLTC(lltc);
	//Xoa_LLTC(lltc);
	//Sua_LLTC(lltc);
	/*ListDangKy *ldk = NULL;
	Nhap_DSDK(ldk);*/
	ThemSinhVien_DSDK(lltc);

	system("cls");
	XoaSinhVien_DSDK(lltc);
	gotoxy(40, 40);
	system("pause");
	return 0;
}