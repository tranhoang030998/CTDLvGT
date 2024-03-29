#pragma once
#include "LopTinChi.h"
#include "Frame.h"
#include  "SinhVien.h"
#include "MonHoc.h"


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
void DangKyHoc(ListLopTinChi &lltc, ListSinhVien lsv);
void NhapDiem(ListLopTinChi &lltc, ListSinhVien lsv, ListMonHoc lmh, bool isShow);
void XemBangDiemTBTheoLop(ListLopTinChi lltc, ListSinhVien lsv, ListMonHoc lmh);

void ThemSinhVien_DSDK(ListLopTinChi &lltc);
void SuaSinhVien_DSDK(ListLopTinChi &lltc);
void XoaSinhVien_DSDK(ListLopTinChi &lltc);

void LuuFile_DSDK(ListLopTinChi lltc);
void DocFile_DSDK(ListLopTinChi &lltc);
