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
void Initial_LLTC(ListLopTinChi &lltc)
{
	for (int i = 0; i < DSDKMAX; i++)
	{
		arrMaLop[i] = i + 1;
	}
}

void Nhap(LopTinChi *ltc, POINT p)
{
	ltc->MALOPTC = ChonMaLopTinChi();
	char mmh[15], nk[5], hk[11], n[5], max[10], min[10] = "\0";
	strcpy_s(mmh, "\0");
	strcpy_s(nk, "\0");
	strcpy_s(n, "\0");
	strcpy_s(max, "\0");
	strcpy_s(hk, "\0");
	EnterLTCFrame(p, false);
	gotoxy(p.x + 14, p.y + 5); cout << ltc->MALOPTC;
	strcpy_s(mmh, EntryData(mmh, { p.x + 14, p.y + 7 }, eModeImportData::UPPER_NUMBER, 5));
	strcpy_s(nk, EntryData(nk, { p.x + 14, p.y + 9 }, eModeImportData::NUMBER, 4));
	strcpy_s(hk, EntryData(hk, { p.x + 14, p.y + 11 }, eModeImportData::NUMBER, 3));
	strcpy_s(n, EntryData(n, { p.x + 14, p.y + 13 }, eModeImportData::NUMBER, 2));
	strcpy_s(max, EntryData(max, { p.x + 14, p.y + 15 }, eModeImportData::NUMBER, 3));
	strcpy_s(min, EntryData(min, { p.x + 14, p.y + 17 }, eModeImportData::NUMBER, 3));

	strcpy_s(ltc->MAMH, mmh);
	ltc->NienKhoa = atoi(nk);
	ltc->HocKy = atoi(hk);
	ltc->Nhom = atoi(n);
	ltc->SvMax = atoi(max);
	ltc->SvMin = atoi(min);

	Button(true, "XONG", { p.x + 23, p.y + 19 }, { 8, 3 }, ColorCode_Blue, ColorCode_Black);
	_getch();
}


void Xuat(LopTinChi *ltc, POINT p)
{   // 0        9           21          33       42     49       58       67
	//"| Ma Lop | M Mon Hoc | Niem Khoa | Hoc Ky | Nhom | SV Max | Sv Min |\n";
	gotoxy(p.x, p.y); cout << "| " << ltc->MALOPTC;
	gotoxy(p.x + 9, p.y); cout  << "| "<< ltc->MAMH;
	gotoxy(p.x + 21, p.y); cout << "| " <<  ltc->NienKhoa;
	gotoxy(p.x + 33, p.y); cout << "| " <<  ltc->HocKy;
	gotoxy(p.x + 58, p.y); cout << "| " <<  ltc->SvMin;
	gotoxy(p.x + 49, p.y); cout << "| " <<  ltc->SvMax;
	gotoxy(p.x + 42, p.y); cout << "| " <<  ltc->Nhom;
	gotoxy(p.x + 67, p.y); cout << "|";
}

void Nhap_LLTC(ListLopTinChi& lltc)
{
	int choice = 0;
	do {
		LopTinChi ltc;
		//nhap vao 1 nut

		lltc.ds[lltc.SoLuong] = new LopTinChi;
		Nhap(lltc.ds[lltc.SoLuong], {10, 10});

		// dua nut ltc vao lltc
		lltc.SoLuong += 1;
		//fflush(stdin);
		system("cls");
		choice = Alert("Ban Muon Mo Them Lop Tin Chi Khong(Y to Yes or any key to NO)", { 15, 15 });
	} while (choice == 1);
}

void Xuat_LLTC(ListLopTinChi lltc)
{
	POINT p = {10, 10};
	ShowListLTCFrame(p);
	for (int i = 0; i < lltc.SoLuong; i++)
	{
		Xuat(lltc.ds[i], {p.x, p.y + 6 + (i * 2)});
		
		gotoxy( p.x, p.y + 7 + (i * 2)); cout << "|------------------------------------------------------------------|";
	}
}

void Them_LLTC(ListLopTinChi& lltc)
{
	if (IsFull(lltc))
		return;
	LopTinChi ltc;
	//nhap vao 1 nut
	lltc.ds[lltc.SoLuong] = new LopTinChi;
	Nhap(lltc.ds[lltc.SoLuong++], {7, 7});
	Alert("Da mo them lop tin chi thanh cong!", {15, 5}, ColorCode_Red, 1000, ColorCode_White);
}

void Sua_LLTC(ListLopTinChi &lltc)
{
	if (lltc.SoLuong <= 0)
		return;

	int choice = 0;
	do
	{
		system("cls");
		POINT p = { 5, 5 };
		int mltc;
		EnterCodeLTCFrame(p);
		char val[6];
		strcpy_s(val, "\0");
		//TODO:Enter code LTC
		mltc = atoi(EntryData(val, {p.x + 14, p.y + 5}, eModeImportData::NUMBER, 4));
		for (int i = 0; i < lltc.SoLuong; i++)
		{
			if (lltc.ds[i]->MALOPTC == mltc)
			{
				char mmh[15], nk[5], hk[11], n[5], max[10], min[10] = "\0";
				strcpy_s(mmh, lltc.ds[i]->MAMH);
				_itoa_s(lltc.ds[i]->HocKy, hk, 10);
				_itoa_s(lltc.ds[i]->NienKhoa, nk, 10);
				_itoa_s(lltc.ds[i]->Nhom, n, 10);
				_itoa_s(lltc.ds[i]->SvMax, max, 10);
				_itoa_s(lltc.ds[i]->SvMin, min, 10);
				EnterLTCFrame(p, false);
				gotoxy(p.x + 14, p.y + 5); cout << lltc.ds[i]->MALOPTC;
				strcpy_s(mmh, EntryData(mmh, { p.x + 14, p.y + 7 }, eModeImportData::UPPER_NUMBER, 5));
				strcpy_s(nk, EntryData(nk, { p.x + 14, p.y + 9 }, eModeImportData::NUMBER, 4));
				strcpy_s(hk, EntryData(hk, { p.x + 14, p.y + 11 }, eModeImportData::NUMBER, 3));
				strcpy_s(n, EntryData(n, { p.x + 14, p.y + 13 }, eModeImportData::NUMBER, 2));
				strcpy_s(max, EntryData(max, { p.x + 14, p.y + 15 }, eModeImportData::NUMBER, 3));
				strcpy_s(min, EntryData(min, { p.x + 14, p.y + 17 }, eModeImportData::NUMBER, 3));

				strcpy_s(lltc.ds[i]->MAMH, mmh);
				lltc.ds[i]->NienKhoa = atoi(nk);
				lltc.ds[i]->HocKy = atoi(hk);
				lltc.ds[i]->Nhom = atoi(n);
				lltc.ds[i]->SvMax = atoi(max);
				lltc.ds[i]->SvMin = atoi(min);

				Button(true, "XONG", { p.x + 23, p.y + 19 }, { 8, 3 }, ColorCode_Blue, ColorCode_Black);
				_getch();

				Alert("Sua thanh cong", { 3, 3 }, ColorCode_Red, 1000, ColorCode_White);
				return;
			}
		}

		Alert("Khong tim thay ma lop tin chi tuong ung.", { 3, 3 }, ColorCode_Red, 1000, ColorCode_White);
		choice = Alert("Ban Muon Nhap Lai Ma Lop Tin Chi Khong(y/any key): ", { 3, 3 });
	} while (choice == 1);
}

void Xoa_LLTC(ListLopTinChi &lltc)
{
	if (lltc.SoLuong <= 0)
		return;

	int choice = 0;
	do
	{
		system("cls");
		POINT p = { 5, 5 };
		int mltc;
		EnterCodeLTCFrame(p);
		char val[6];
		strcpy_s(val, "\0");
		//TODO:Enter code LTC
		mltc = atoi(EntryData(val, { p.x + 14, p.y + 5 }, eModeImportData::NUMBER, 4));
		for (int i = 0; i < lltc.SoLuong; i++)
		{
			if (lltc.ds[i]->MALOPTC == mltc)
			{
				//TODO: Show detail this ltc
				ShowListToDeleteLTCFrame({ p.x, p.y + 8 });
				Xuat(lltc.ds[i], { p.x, p.y + 14 });

				//TODO: Show two button for option delete or not.
				if (TwoOptionYN({ p.x + 10, p.y + 17 }) == 1)
					return;

				//TODO: Delete current LTC and update List.
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
				Alert("Xoa thanh cong", { 3, 3 }, ColorCode_Red, 1000, ColorCode_White);
				return;
			}
		}

		Alert("Khong tim thay ma lop tin chi tuong ung.", { 3, 3 }, ColorCode_Red, 1000, ColorCode_White);
		choice = Alert("Ban Muon Nhap Lai Ma Lop Tin Chi Khong(y/any key): ", { 3, 3 });
	} while (choice == 1);
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