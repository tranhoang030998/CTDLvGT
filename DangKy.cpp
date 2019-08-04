#include "DangKy.h"




int Count_LDK(ListDangKy *ldk)
{
	int count = 0;
	for (ListDangKy *p = ldk; p != NULL; p = p->pNext)
	{
		count++;
	}
	return count;
}

//insert sort by MSV
void InsertToListDK(ListDangKy *&ldk, ListDangKy *data)
{
	if (ldk == NULL)
	{
		ldk = data;
		return;
	}

	for (ListDangKy *p = ldk; p != NULL; p = p->pNext)
	{
		if (strcmp(p->ThongTinDangKy.MASV, data->ThongTinDangKy.MASV) <= 0)
		{
			if (p->pNext == NULL)
			{
				p->pNext = data;
				return;
			}
			if (strcmp(p->pNext->ThongTinDangKy.MASV, data->ThongTinDangKy.MASV) >= 0)
			{
				data->pNext = p->pNext;
				p->pNext = data;
				return;
			}
		}
	}

	//Them vao dau
	data->pNext = ldk;
	ldk = data;
}

int Erase_DSDK(ListDangKy *&ldk, char *maSV)
{
	if (ldk == NULL)
		return 0;
	if (strcmp(ldk->ThongTinDangKy.MASV, maSV) == 0)
	{
		ListDangKy *temp = ldk;
		ldk = ldk->pNext;
		delete temp;
		return 1;
	}
	for (ListDangKy *p = ldk; p->pNext != NULL; p = p->pNext)
	{
		if (strcmp(p->pNext->ThongTinDangKy.MASV, maSV) == 0)
		{
			ListDangKy *temp = p->pNext;
			p->pNext = p->pNext->pNext;
			delete temp;
			return 1;
		}
	}
	return 0;
}

void DocFile_DSDK(ListLopTinChi &lltc)
{
	fstream FileIn("DSDANGKY.TXT", ios::in);

	while (!FileIn.eof())
	{
		int mltc = 0;
		int quantity = 0;
		FileIn >> mltc >> quantity;

		ListDangKy *ldk = NULL;

		if (quantity == 0)
		{

		}
		else
		{
			while (quantity-- > 0)
			{
				ListDangKy *noteDK = new ListDangKy;
				FileIn >> noteDK->ThongTinDangKy.MASV;
				FileIn >> noteDK->ThongTinDangKy.DIEM;
				noteDK->pNext = NULL;

				InsertToListDK(ldk, noteDK);
			}
			for (int i = 0; i < lltc.SoLuong; i++)
			{
				if (lltc.ds[i]->MALOPTC == mltc)
					lltc.ds[i]->listSV = ldk;
			}
		}
	}
}

void LuuFile_DSDK(ListLopTinChi lltc)
{
	int n = 0;
	fstream FileOut("DSDANGKY.TXT", ios::out);

	while (n < lltc.SoLuong)
	{
		if (n != 0)
			FileOut << endl;

		FileOut << lltc.ds[n]->MALOPTC << endl;

		ListDangKy *pLDK = lltc.ds[n]->listSV;
		int quantity = Count_LDK(pLDK);
		FileOut << quantity;

		while (pLDK != NULL)
		{
				FileOut << endl;
			FileOut << pLDK->ThongTinDangKy.MASV << endl
				<< pLDK->ThongTinDangKy.DIEM;
			pLDK = pLDK->pNext;
		}
		n++;
	}
	FileOut.close();
}

void ThemSinhVien_DSDK(ListLopTinChi &lltc)
{
	POINT p = { 10, 10 };

	char val[11];
	strcpy_s(val, "\0");
	while (true)
	{
		EnterCodeLTCFrame(p);
		
		EntryData(val, { p.x + 14, p.y + 5 }, eModeImportData::NUMBER, 4);

		if (strcmp(val, "") == 0)
			return;
		else
		{
			int mltc = atoi(val);
			for (int i = 0; i < lltc.SoLuong; i++)
			{
				if (mltc == lltc.ds[i]->MALOPTC)
				{
					system("cls");
					ListDangKy *ndk;
					EnterMaSVFrame(p);

					while (true)
					{
						strcpy_s(val, "\0");
						EntryData(val, { p.x + 14, p.y + 5 }, eModeImportData::UPPER_NUMBER, 10);

						if (strcmp(val, "") == 0)
							return;
						else
						{
							ndk = new ListDangKy;
							strcpy_s(ndk->ThongTinDangKy.MASV, val);
							ndk->ThongTinDangKy.DIEM = 0;
							ndk->pNext = NULL;

							InsertToListDK(lltc.ds[i]->listSV, ndk);
							Alert("Da them sinh vien thanh cong.", { p.x, p.y - 5 }, ColorCode_Red, 2000, ColorCode_White);
							gotoxy(p.x + 14, p.y + 5); cout << "                           ";
						}
					}
				}
			}
			Alert("Ma lop khong ton tai!", { p.x, p.y - 5 }, ColorCode_Red, 2000, ColorCode_Black);
		}
	}
}

void XoaSinhVien_DSDK(ListLopTinChi &lltc)
{
	POINT p = { 10, 10 };

	char val[11];
	strcpy_s(val, "\0");
	while (true)
	{
		EnterCodeLTCFrame(p);

		EntryData(val, { p.x + 14, p.y + 5 }, eModeImportData::NUMBER, 4);

		if (strcmp(val, "") == 0)
			return;
		else
		{
			int mltc = atoi(val);
			for (int i = 0; i < lltc.SoLuong; i++)
			{
				if (mltc == lltc.ds[i]->MALOPTC)
				{
					system("cls");
					EnterMaSVFrame(p);

					while (true)
					{
						strcpy_s(val, "\0");
						EntryData(val, { p.x + 14, p.y + 5 }, eModeImportData::UPPER_NUMBER, 10);

						if (strcmp(val, "") == 0)
							return;
						else
						{
							int rel = Erase_DSDK(lltc.ds[i]->listSV, val);
							if(rel == 1)
								Alert("Da xoa sinh vien thanh cong.", { p.x, p.y - 5 }, ColorCode_Red, 2000, ColorCode_White);
							else if(rel == 0)
								Alert("Khong tim thay ma sinh vien tuong ung.", { p.x, p.y - 5 }, ColorCode_Red, 2000, ColorCode_White);
							gotoxy(p.x + 14, p.y + 5); cout << "                           ";
						}
					}

				}
			}
			Alert("Ma lop khong ton tai!", { p.x, p.y - 5 }, ColorCode_Red, 2000, ColorCode_Black);
		}
	}
}

//TODO: Show to edit the information of student
void SuaSinhVien_DSDK(ListLopTinChi &lltc)
{

}

void Nhap_DSDK(ListDangKy *&ldk)
{
	POINT p = { 10, 10 };

	EnterMaSVFrame(p);
	char val[11];
	strcpy_s(val, "\0");

	while (true)
	{
		ListDangKy *ndk;
		EntryData(val, { p.x + 14, p.y + 5 }, eModeImportData::UPPER_NUMBER, 10);

		if (strcmp(val, "") == 0)
			break;
		else
		{
			ndk = new ListDangKy;
			strcpy_s(ndk->ThongTinDangKy.MASV, val);
			ndk->ThongTinDangKy.DIEM = 0;
			ndk->pNext = NULL;

			InsertToListDK(ldk, ndk);
			Alert("Da them sinh vien thanh cong.", { p.x, p.y - 5 }, ColorCode_Red, 2000, ColorCode_White);
			strcpy_s(val, "\0");
			gotoxy(p.x + 14, p.y + 5); cout << "                           ";
		}
	}
}

//TODO: Show all student by mode show
void Xuat_DSDK(ListLopTinChi lltc, eShowSVDK e)
{

}

void DangKyHoc(ListLopTinChi &lltc, ListSinhVien lsv)
{
	POINT lc = { 10, 10 };
	ListLopTinChi avaliableClass;
	while (true)
	{
		EnterToRegSubjects(lc);
		char msv[15], nk[11], hk[11];
		strcpy_s(msv, "\0");
		strcpy_s(nk, "\0");
		strcpy_s(hk, "\0");
		while (true)
		{
			EntryData(msv, { lc.x + 20, lc.y + 5 }, eModeImportData::UPPER_NUMBER, 12);
			if (strcmp(msv, "") == 0)
				break;
			bool isExists = false;
			for (NoteSV *p = lsv; p != NULL; p = p->next)
			{
				if (strcmp(p->sinhvien.MASV, msv) == 0)
				{
					isExists = true;
					break;
				}
			}
			if (isExists)
			{
				break;
			}
			Alert("Sinh Vien khong ton tai.....", { lc.x, lc.y - 3 }, ColorCode_Red, 3000, ColorCode_White);
			strcpy_s(msv, "\0");
		}
		EntryData(nk, { lc.x + 20, lc.y + 7 }, eModeImportData::NUMBER, 4);
		EntryData(hk, { lc.x + 20, lc.y + 9 }, eModeImportData::NUMBER, 2);

		if (strcmp(msv, "") == 0 || strcmp(nk, "") == 0 || strcmp(hk, "") == 0)
			return;

		for (int i = 0; i < lltc.SoLuong; i++)
		{
			if (atoi(nk) == lltc.ds[i]->NienKhoa && atoi(hk) == lltc.ds[i]->HocKy)
			{
				avaliableClass.ds[avaliableClass.SoLuong] = new LopTinChi;

				avaliableClass.ds[avaliableClass.SoLuong++] = lltc.ds[i];
			}
		}

		if (avaliableClass.SoLuong == 0)
		{
			Alert("Khong ton tai lop nao phu hop.....", { lc.x, lc.y - 5 }, ColorCode_Red, 3000, ColorCode_White);
		}
		else
		{
			while (true)
			{
				system("cls");
				Xuat_LLTC(avaliableClass);
				EnterClassCodeFrame({ lc.x, lc.y - 10 });

				char ml[5];
				strcpy_s(ml, "\0");
				EntryData(ml, { lc.x + 14, lc.y + -5 }, eModeImportData::NUMBER, 4);

				if (strcmp(ml, "") == 0)
					return;

				for (int i = 0; i < avaliableClass.SoLuong; i++)
				{
					if (avaliableClass.ds[i]->MALOPTC == atoi(ml))
					{
						for (ListDangKy *p = avaliableClass.ds[i]->listSV; p != NULL; p = p->pNext)
						{
							if (strcmp(p->ThongTinDangKy.MASV, msv) == 0)
							{
								Alert("Sinh vien da dang ky lop nay.....", { lc.x, lc.y - 3 }, ColorCode_Red, 3000, ColorCode_White);
								return;
							}
						}
						ListDangKy *data = new ListDangKy;
						data->pNext = NULL;
						data->ThongTinDangKy.DIEM = 0;
						strcpy_s(data->ThongTinDangKy.MASV, msv);
						InsertToListDK(avaliableClass.ds[i]->listSV, data);
						//Done
						Alert("Sinh vien da dang ky thanh cong.....", { lc.x, lc.y - 3 }, ColorCode_Red, 3000, ColorCode_White);
						return;
					}
				}
				Alert("Ma lop khong ton tai.....", { lc.x, lc.y - 3 }, ColorCode_Red, 3000, ColorCode_White);
			}
		}
	}
}

void EnterScore(ListDangKy *&ldk, ListSinhVien lsv, POINT lc)
{
	int quantity = Count_LDK(ldk);
	float arrScore[1000] = {0};
	int arrLC[1000] = { 0 };

	EnterInfoScoreFrame(lc);

	int index = 0;
	for (ListDangKy *p = ldk; p != NULL; p = p->pNext)
	{
		NoteSV* sv = FinStudent(lsv, p->ThongTinDangKy.MASV);
		if (sv != NULL)
		{
			// 0      7              18             33          44             57         
			//"|  STT |     Ma SV    |      HO      |    Ten    |   Diem       |
			gotoxy(lc.x,      lc.y + 6 + index * 2); cout << "| " << index + 1;
			gotoxy(lc.x + 7,  lc.y + 6 + index * 2); cout << "| " << sv->sinhvien.MASV;
			gotoxy(lc.x + 22, lc.y + 6 + index * 2); cout << "| " << sv->sinhvien.Ho;
			gotoxy(lc.x + 37, lc.y + 6 + index * 2); cout << "| " << sv->sinhvien.Ten;
			gotoxy(lc.x + 49, lc.y + 6 + index * 2); cout << "| " << p->ThongTinDangKy.DIEM;
			gotoxy(lc.x + 64, lc.y + 6 + index * 2); cout << "|";
			gotoxy(lc.x,      lc.y + 6 + index * 2 + 1); cout << "|---------------------------------------------------------------|";
			arrScore[index] = p->ThongTinDangKy.DIEM;
			arrLC[index++] =  lc.y + 6 + index * 2;
		}
	}

	//TODO: EnterScore
	char score[5];
	for (int i = 0; i < quantity; i++)
	{
		snprintf(score, sizeof score, "%f", arrScore[i]);
		while (true)
		{
			EntryData(score, { lc.x + 51, arrLC[i] }, eModeImportData::SCORE, 4);
			float s = atof(score);
			if ((s < 0 || s > 10) || (s == 0 && s != arrScore[i]))
			{
				snprintf(score, sizeof score, "%f", arrScore[i]);
			}
			else
			{
				gotoxy(lc.x + 51, arrLC[i]); printf_s("%2.2f", s);
				arrScore[i] = s;
				break;
			}
		}
	}

	index = 0;
	for (ListDangKy *p = ldk; p != NULL; p = p->pNext)
	{
		p->ThongTinDangKy.DIEM = arrScore[index++];
	}
}

void NhapDiem(ListLopTinChi &lltc, ListSinhVien lsv, ListMonHoc lmh, bool isShow)
{
	POINT lc = { 10, 10 };
	
	while (true)
	{
		EnterScoreFrame(lc);
		char mmh[15], nk[11], hk[11], nhom[2];
		strcpy_s(mmh, "\0");
		strcpy_s(nk, "\0");
		strcpy_s(hk, "\0");
		strcpy_s(nhom, "\0");

		EntryData(mmh, { lc.x + 20, lc.y + 5 }, eModeImportData::UPPER_NUMBER, 7);
		EntryData(nk, { lc.x + 20, lc.y + 7 }, eModeImportData::NUMBER, 4);
		EntryData(hk, { lc.x + 20, lc.y + 9 }, eModeImportData::NUMBER, 2);
		EntryData(nhom, { lc.x + 20, lc.y + 11 }, eModeImportData::NUMBER, 2);

		if (strcmp(mmh, "") == 0 || strcmp(nk, "") == 0 || strcmp(hk, "") == 0 || strcmp(nhom, "") == 0)
			return;

		int index = -1;

		for (int i = 0; i < lltc.SoLuong; i++)
		{
			if (strcmp(lltc.ds[i]->MAMH, mmh) == 0 && atoi(nk) == lltc.ds[i]->NienKhoa && atoi(hk) == lltc.ds[i]->HocKy && atoi(nhom) == lltc.ds[i]->Nhom)
			{
				index = i;
				break;
			}
		}

		if (index == -1)
		{
			Alert("Khong ton tai mon nao phu hop.....", { lc.x, lc.y - 5 }, ColorCode_Red, 3000, ColorCode_White);
		}
		else
		{
			if (isShow)
			{
				system("cls");
				int row = 0;
				EnterInfoScoreFrame(lc);
				TitleShowScore({ lc.x, lc.y - 3 });

				gotoxy(lc.x + 38, lc.y - 1); cout << SearchNodeByCodeSubject(lmh, lltc.ds[index]->MAMH)->monHoc.TenMH;
				gotoxy(lc.x + 18, lc.y); cout << lltc.ds[index]->NienKhoa;
				gotoxy(lc.x + 37, lc.y); cout << lltc.ds[index]->HocKy;
				gotoxy(lc.x + 53, lc.y); cout << lltc.ds[index]->Nhom;

				for (ListDangKy *p = lltc.ds[index]->listSV; p != NULL; p = p->pNext)
				{
					NoteSV* sv = FinStudent(lsv, p->ThongTinDangKy.MASV);
					if (sv != NULL)
					{
						// 0      7              18             33          44             57         
						//"|  STT |     Ma SV    |      HO      |    Ten    |   Diem       |
						gotoxy(lc.x,      lc.y + 6 + row * 2); cout << "| " << row + 1;
						gotoxy(lc.x + 7,  lc.y + 6 + row * 2); cout << "| " << sv->sinhvien.MASV;
						gotoxy(lc.x + 22, lc.y + 6 + row * 2); cout << "| " << sv->sinhvien.Ho;
						gotoxy(lc.x + 37, lc.y + 6 + row * 2); cout << "| " << sv->sinhvien.Ten;
						gotoxy(lc.x + 49, lc.y + 6 + row * 2); cout << "| " << p->ThongTinDangKy.DIEM;
						gotoxy(lc.x + 64, lc.y + 6 + row * 2); cout << "|";
						gotoxy(lc.x,      lc.y + 6 + row * 2 + 1); cout << "|---------------------------------------------------------------|";
						row++;
					}
				}
				_getch();
				return;
			}
			else
			{
				system("cls");
				EnterScore(lltc.ds[index]->listSV, lsv, lc);
				return;
			}
		}
	}
}

void XemBangDiemTBTheoLop(ListLopTinChi lltc, ListSinhVien lsv, ListMonHoc lmh)
{
	POINT lc = { 10, 10 };
	while (true)
	{
		EnterClassCodeFrame(lc);

		char ml[11] = "\0";
		EntryData(ml, {}, eModeImportData::UPPER_NUMBER, 9);

		for (NoteSV *nSV = lsv; nSV != NULL; nSV = nSV->next)
		{
			if (strcmp(nSV->sinhvien.MALOP, ml) == 0)
			{

			}
		}
	}
}