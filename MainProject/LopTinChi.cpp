#include "LopTinChi.h"
#include <iostream>

using namespace std;

int ChonMaLopTinChi()
// chon ma lop tu 5000ptu
{
	for (int i = 0; i < DSDKMAX; i++)
	{

		if (arrMaLop[i] != 0)
		{
			int maLop = arrMaLop[i];
			// lay ma lop roi tra ve gia tri 0
			arrMaLop[i] = 0;
			return maLop;
		}
	}
	return -1;
}
// tao 1 mang tu 1 den 5000
void LTC_Initial()
{
	for (int i = 0; i < DSDKMAX; i++)
	{
		arrMaLop[i] = i + 1;
	}
}

void Nhap(LopTinChi *ltc)
{
	ltc->MALOPTC = ChonMaLopTinChi();

	cout << "Nhap Ma Mon Hoc: ";
	cin >> ltc->MAMH;
	//fflush(stdin);
	cout << "Nhap nien khoa: ";
	cin >> ltc->NienKhoa;
	cout << "Nhap Hoc Ky: ";
	cin >> ltc->HocKy;
	//fflush(stdin);
	cout << "Nhap Nhom: ";
	cin >> ltc->Nhom;
	//fflush(stdin);
	cout << "Nhap Sinh Vien Min: ";
	cin >> ltc->SvMin;
	//fflush(stdin);
	cout << "Nhap Sinh Vien Max: ";
	cin >> ltc->SvMax;
}

void Xuat(LopTinChi *ltc)
{
	cout << "\nMa Lop: " << ltc->MALOPTC;
	cout << "\nMa Mon Hoc: " << ltc->MAMH;
	cout << "\nNien khoa: " << ltc->NienKhoa;
	cout << "\nHoc Ky: " << ltc->HocKy;
	cout << "\nSinh Vien Min: " << ltc->SvMin;
	cout << "\nSinh Vien Max: " << ltc->SvMax;
}

void Nhap_LLTC(ListLopTinChi& lltc)
{
	int choice = 0;
	do {
		LopTinChi ltc;
		//nhap vao 1 nut

		lltc.ds[lltc.SoLuong] = new LopTinChi;
		Nhap(lltc.ds[lltc.SoLuong]);

		// dua nut ltc vao lltc
		lltc.SoLuong += 1;
		//fflush(stdin);
		cout << "\n\nBan Muon Mo Them Lop Tin Chi Khong(1=YES/0=NO): ";
		cin >> choice;
	} while (choice == 1);
}

void Xuat_LLTC(ListLopTinChi lltc)
{
	for (int i = 0; i < lltc.SoLuong; i++)
	{
		Xuat(lltc.ds[i]);
		cout << std::endl;
	}
}

void Them_LLTC(ListLopTinChi& lltc)
{
	if (IsFull(lltc))
		return;
	LopTinChi ltc;
	//nhap vao 1 nut
	lltc.ds[lltc.SoLuong] = new LopTinChi;
	Nhap(lltc.ds[lltc.SoLuong++]);
}

void Xoa_LLTC(ListLopTinChi &lltc)
{
	if (lltc.SoLuong <= 0)
		return;

	int choice = 0;
	do
	{
		int mltc;
		cout << "Nhap vao ma lop tin chi muon xoa: ";
		cin >> mltc;

		for (int i = 0; i < lltc.SoLuong; i++)
		{
			if (lltc.ds[i]->MALOPTC == mltc)
			{
				arrMaLop[mltc - 1] = mltc;
				for (int j = i; j < lltc.SoLuong - 1; j++)
				{
					strcpy_s(lltc.ds[j]->MAMH, lltc.ds[j + 1]->MAMH);
					lltc.ds[j]->MALOPTC = lltc.ds[j + 1]->MALOPTC;
					lltc.ds[j]->Nhom = lltc.ds[j + 1]->Nhom;
					lltc.ds[j]->NienKhoa = lltc.ds[j + 1]->HocKy;
					lltc.ds[j]->SvMin = lltc.ds[j + 1]->SvMin;
					lltc.ds[j]->SvMax = lltc.ds[j + 1]->SvMax;
					lltc.ds[j]->listSV = lltc.ds[j + 1]->listSV;
				}
				delete lltc.ds[lltc.SoLuong - 1];
				lltc.SoLuong--;
				cout << "Xoa thanh cong!";
				return;
			}
		}

		cout << "Khong tim thay ma lop tin chi tuong ung.\n";
		cout << "\n\nBan Muon Nhap Lai Ma Lop Tin Chi Khong(1=YES/0=NO): ";
		cin >> choice;
	} while (choice == 1);
}

void Sua_LLTC(ListLopTinChi &lltc)
{

}

bool IsFull(ListLopTinChi lltc)
{
	return (lltc.SoLuong == DSDKMAX - 1) ? true : false;
}

//Luu File Lop Tin Chi
void LuuFile_LLTC(ListLopTinChi lltc)
{
	int n = 0;
	fstream FileOut("DSLOPTINCHI.TXT", ios::out);
	while (n < lltc.SoLuong)
	{
		if (n != 0)
			FileOut << endl;

		FileOut << lltc.ds[n]->MALOPTC << endl
			<< lltc.ds[n]->MAMH << endl
			<< lltc.ds[n]->NienKhoa << endl
			<< lltc.ds[n]->HocKy << endl
			<< lltc.ds[n]->Nhom << endl
			<< lltc.ds[n]->SvMin << endl
			<< lltc.ds[n]->SvMax;
		n++;
	}
	FileOut.close();
}

void DocFile_LLTC(ListLopTinChi &lltc)
{
	fstream FileIn("DSLOPTINCHI.TXT", ios::in);
	int memoenable = lltc.SoLuong;
	if (lltc.SoLuong != 0)
		lltc.SoLuong = 0;

	while (!FileIn.eof())
	{
		LopTinChi ltc;

		FileIn >> ltc.MALOPTC
			>> ltc.MAMH
			>> ltc.NienKhoa
			>> ltc.HocKy
			>> ltc.Nhom
			>> ltc.SvMin
			>> ltc.SvMax;

		arrMaLop[ltc.MALOPTC - 1] = 0;

		lltc.SoLuong++;
		if (lltc.SoLuong > memoenable)
			lltc.ds[lltc.SoLuong - 1] = new LopTinChi;

		lltc.ds[lltc.SoLuong - 1]->MALOPTC = ltc.MALOPTC;
		strcpy_s(lltc.ds[lltc.SoLuong - 1]->MAMH, ltc.MAMH);
		lltc.ds[lltc.SoLuong - 1]->Nhom = ltc.Nhom;
		lltc.ds[lltc.SoLuong - 1]->NienKhoa = ltc.NienKhoa;
		lltc.ds[lltc.SoLuong - 1]->HocKy = ltc.HocKy;
		lltc.ds[lltc.SoLuong - 1]->SvMin = ltc.SvMin;
		lltc.ds[lltc.SoLuong - 1]->SvMax = ltc.SvMax;
		lltc.ds[lltc.SoLuong - 1]->listSV = ltc.listSV;
	}
}