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