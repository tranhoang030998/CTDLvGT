#pragma once
#include "LopTinChi.h"
#include "Frame.h"


enum eShowSVDK { NIEMKHOA };
//danh sach dang ky
struct DangKy {
	char MASV[13];
	float DIEM;
};

struct ListDangKy {
	DangKy ThongTinDangKy;
	struct ListDangKy* pNext;
};


void Nhap_DSDK(ListDangKy *&ldk);
void ThemSinhVien_DSDK(ListLopTinChi &lltc);
void XoaSinhVien_DSDK(ListLopTinChi &lltc);
