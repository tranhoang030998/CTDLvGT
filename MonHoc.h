#pragma once
#include "Frame.h"
#include <fstream>

//khai bao danh sach mon hoc la cay nhi phan tim kiem
typedef struct MonHoc {
	char MAMH[11];
	char TenMH[21];
	int STCTH;
	int STCLT;
};
struct NoteMH {
	MonHoc monHoc;
	struct NoteMH* pLeft, * pRight;
};
typedef struct NoteMH* ListMonHoc;


void DocFile_LMH(ListMonHoc &lmh);
void LuuFile_LMH(ListMonHoc lmh);

void Nhap_LMH(ListMonHoc &lmh);
void Xuat_LMH(ListMonHoc lmh);

void Them_MH(ListMonHoc &lmh);
void Xoa_MH(ListMonHoc &lmh);
void Sua_MH(ListMonHoc &lmh);

void ShowByNameSubjects(ListMonHoc lmh);
