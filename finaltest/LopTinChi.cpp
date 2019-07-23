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
void Nhap(LopTinChi& ltc)
{
	ltc.MALOPTC = ChonMaLopTinChi();

	cout << "Nhap Ma Mon Hoc: ";
	cin >> ltc.MAMH;
	fflush(stdin);
	cout << "Nhap nien khoa: ";
	cin >> ltc.NienKhoa;
	cout << "Nhap Hoc Ky: ";
	cin >> ltc.HocKy;
	fflush(stdin);
	cout << "Nhap Nhom: ";
	cin >> ltc.Nhom;
	fflush(stdin);
	cout << "Nhap Sinh Vien Min: ";
	cin >> ltc.SvMin;
	fflush(stdin);
	cout << "Nhap Sinh Vien Max: ";
	cin >> ltc.SvMax;
}

void Xuat(LopTinChi ltc)
{
	cout << "\nMa Lop: " << ltc.MALOPTC;
	cout << "\nMa Mon Hoc: " << ltc.MAMH;
	cout << "\nNien khoa: " << ltc.NienKhoa;
	cout << "\nHoc Ky: " << ltc.HocKy;
	cout << "\nSinh Vien Min: " << ltc.SvMin;
	cout << "\nSinh Vien Max: " << ltc.SvMax;
}

void LTC_Nhap(ListLopTinChi& lltc)
{
	int choice = 0;
	do {
		LopTinChi ltc;
		//nhap vao 1 nut
		Nhap(ltc);
		// dua nut ltc vao lltc
		lltc.ds[lltc.SoLuong] = &ltc;
		lltc.SoLuong += 1;
		fflush(stdin);
		cout << "\n\nBan Muon Mo Them Lop Tin Chi Khong(1=YES/0=NO): ";
		cin >> choice;
	} while (choice == 1);
}

void LTC_Xuat(ListLopTinChi lltc)
{
	for (int i = 0; i < lltc.SoLuong; i++)
	{
		Xuat(*lltc.ds[i]);
		cout << "/n";
	}
}

void LTC_Them(ListLopTinChi& lltc)
{
	LopTinChi ltc;
	//nhap vao 1 nut
	Nhap(ltc);
	lltc.ds[lltc.SoLuong] = &ltc;
	lltc.SoLuong += 1;
	

}
int IsFull(ListLopTinChi& lltc) 
{
	return (lltc.SoLuong == DSDKMAX - 1) ? 1 : 0;
}
//Luu File Lop Tin Chi
void LuuFile_LLTC(ListLopTinChi &lltc) {
	int n = 0;
	std::fstream f_open;
	f_open.open("DSLOPTINCHI.txt", ios::out);
	while (n < lltc.SoLuong) 
	{
		f_open << lltc.ds[n]->MALOPTC << endl
			<< lltc.ds[n]->MAMH << endl
			<< lltc.ds[n]->NienKhoa << endl
			<< lltc.ds[n]->HocKy << endl
			<< lltc.ds[n]->Nhom << endl
			<< lltc.ds[n]->SvMin << endl
			<< lltc.ds[n]->SvMax << endl;  //Bo endl fix bug luc doc file (endl o maloptinchi)
		n++;
	}
	f_open.close();
}