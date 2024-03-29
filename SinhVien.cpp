#include "SinhVien.h"

void InsertTail_SV(ListSinhVien &lsv, NoteSV *data)
{
	for (NoteSV *p = lsv; p != NULL; p = p->next)
	{
		if (p->next == NULL)
		{
			data->next = NULL;
			p->next = data;
			return;
		}
	}
}

void InsertHead_SV(ListSinhVien &lsv, NoteSV *data)
{
	data->next = lsv;
	lsv = data;
}

void InsertBack_SV(ListSinhVien &lsv, NoteSV *data)
{
	NoteSV *temp = lsv->next->next;
	lsv->next->next = data;
	data->next = temp;
}

void InsertFront_SV(ListSinhVien &l_sv, NoteSV *data)
{
	int a = 0;
	a++;
	NoteSV *temp = l_sv->next;
	l_sv->next = data;
	data->next = temp;

}

NoteSV* FinStudent(ListSinhVien lsv, char* studentCode)
{
	if (lsv == NULL)
		return NULL;
	for (NoteSV *p = lsv; p != NULL; p = p->next)
	{
		if (strcmp(studentCode, p->sinhvien.MASV) == 0)
		{
			return p;
		}
	}
	return NULL;
}

NoteSV* FindClass(ListSinhVien lsv, NoteSV *data)
{
	if (lsv == NULL)
		return NULL;
	if (strcmp(data->sinhvien.MALOP, lsv->sinhvien.MALOP) == 0)
		return lsv;
	for (NoteSV *p = lsv; p->next != NULL; p = p->next)
	{
		if (strcmp(data->sinhvien.MALOP, p->next->sinhvien.MALOP) == 0)
		{
			return p;
		}
	}
	return NULL;
}

int CountSV(ListSinhVien lsv)
{
	int count = 0;
	for (NoteSV *p = lsv; p != NULL; p = p->next)
	{
		count++;
	}
	return count;
}

void InsertSV(ListSinhVien &lsv, NoteSV *data)
{
	if (lsv == NULL)
	{
		InsertHead_SV(lsv, data);
		return;
	}
	else
	{
		NoteSV* sv = FindClass(lsv, data);

		if (sv == NULL)
		{
			if (lsv == NULL)
			{
				InsertHead_SV(lsv, data);
				return;
			}
			else //TODO: Insert by class code doesn't exits
			{
				if (strcmp(data->sinhvien.MALOP, lsv->sinhvien.MALOP) < 0)
				{
					InsertHead_SV(lsv, data);
				}
				for (NoteSV *p = lsv; ; p = p->next)
				{
					if (p->next == NULL)
					{
						InsertTail_SV(lsv, data);
						return;
					}
					if (strcmp(data->sinhvien.MALOP, p->next->sinhvien.MALOP) < 0)
					{
						InsertFront_SV(p, data);
						return;
					}
				}
			}
		}
		else
		{
			int totalSV = CountSV(lsv);
			if (CountSV(sv) == totalSV)//Class on the head of linker list
			{
				if (strcmp(data->sinhvien.MASV, lsv->sinhvien.MASV) <= 0)
				{
					InsertHead_SV(lsv, data);
					return;
				}
				else
				{
					for (NoteSV *p = sv; ; p = p->next)
					{
						if (p->next == NULL)
						{
							InsertTail_SV(sv, data);
							return;
						}
						if (strcmp(data->sinhvien.MALOP, p->next->sinhvien.MALOP) != 0) // SV next not belong this class
						{
							InsertBack_SV(p, data);
							return;
						}
						else
						{
							if (strcmp(data->sinhvien.MASV, p->next->sinhvien.MASV) <= 0)
							{
								InsertFront_SV(p, data);
								return;
							}
						}

					}
				}
			}
			else
			{
				for (NoteSV *p = sv; ; p = p->next)
				{
					if (p->next == NULL)
					{
						InsertTail_SV(sv, data);
						return;
					}
					if (strcmp(data->sinhvien.MALOP, p->next->sinhvien.MALOP) != 0) // SV next not belong this class
					{
						InsertBack_SV(lsv, data);
						return;
					}
					else
					{
						if (strcmp(data->sinhvien.MASV, p->next->sinhvien.MASV) <= 0)
						{
							InsertFront_SV(p, data);
							return;
						}
					}
				}
			}
		}
	}
}

void Nhap_SV(ListSinhVien &lsv)
{
	POINT p = { 10, 10 };
	NoteSV *noteSV;
	while (true)
	{
		system("cls");

		EnterSVFrame(p);

		char msv[15], ml[11], ho[11], ten[7], sex[2], nnh[5], sdt[11];
		strcpy_s(msv, "\0");
		strcpy_s(ml, "\0");
		strcpy_s(ho, "\0");
		strcpy_s(ten, "\0");
		strcpy_s(sex, "\0");
		strcpy_s(nnh, "\0");
		strcpy_s(sdt, "\0");

		EntryData(msv, { p.x + 20, p.y + 5 }, eModeImportData::UPPER_NUMBER, 12);
		EntryData(ml, { p.x + 20, p.y + 7 }, eModeImportData::UPPER_NUMBER, 10);
		EntryData(ho, { p.x + 20, p.y + 9 }, eModeImportData::UPPER_LOWER, 20);
		EntryData(ten, { p.x + 20, p.y + 11 }, eModeImportData::UPPER_LOWER, 11);
		EntryData(sex, { p.x + 20, p.y + 13 }, eModeImportData::SEX, 1);
		EntryData(sdt, { p.x + 20, p.y + 15 }, eModeImportData::NUMBER, 10);
		EntryData(nnh, { p.x + 20, p.y + 17 }, eModeImportData::NUMBER, 4);

		noteSV = new NoteSV;
		strcpy_s(noteSV->sinhvien.MASV, msv);
		strcpy_s(noteSV->sinhvien.MALOP, ml);
		strcpy_s(noteSV->sinhvien.Ho, ho);
		strcpy_s(noteSV->sinhvien.Ten, ten);
		strcpy_s(noteSV->sinhvien.SDT, sdt);

		noteSV->sinhvien.NamNhapHoc = atoi(nnh);
		noteSV->sinhvien.Phai = atoi(sex);


		InsertSV(lsv, noteSV);

		if (TwoOptionYN({ p.x + 4, p.y + 19 }) == 1)
		{
			return;
		}
	}
}

void Xuat_SV(ListSinhVien lsv)
{
	//1            13              29          41          53          65                  85        95        
	//|   Ma SV    |       Ho      |    Ten    |  Ma Lop   | Gioi Tinh |         SDT       |  Nam NH |

	system("cls");
	POINT lc = { 10, 10 };
	ShowListSVFrame(lc);
	int i = 0;
	for (NoteSV *p = lsv; p != NULL; p = p->next)
	{
		gotoxy(lc.x, lc.y + 6 + i * 2); cout << "| " << p->sinhvien.MASV;
		gotoxy(lc.x + 13, lc.y + 6 + i * 2); cout << "| " << p->sinhvien.Ho;
		gotoxy(lc.x + 29, lc.y + 6 + i * 2); cout << "| " << p->sinhvien.Ten;
		gotoxy(lc.x + 41, lc.y + 6 + i * 2); cout << "| " << p->sinhvien.MALOP;
		gotoxy(lc.x + 53, lc.y + 6 + i * 2); cout << "| " << (p->sinhvien.Phai == true ? "Nam" : "Nu");
		gotoxy(lc.x + 65, lc.y + 6 + i * 2); cout << "| " << p->sinhvien.SDT;
		gotoxy(lc.x + 85, lc.y + 6 + i * 2); cout << "| " << p->sinhvien.NamNhapHoc;
		gotoxy(lc.x + 95, lc.y + 6 + i * 2); cout << "|";
		gotoxy(lc.x, lc.y + 6 + i * 2 + 1); cout << "|----------------------------------------------------------------------------------------------|";
		i++;
	}
}

void Them_SV(ListSinhVien &lsv)
{
	POINT p = { 10, 10 };
	NoteSV *noteSV;

		system("cls");

		EnterSVFrame(p);

		char msv[15], ml[11], ho[11], ten[7], sex[2], nnh[5], sdt[11];
		strcpy_s(msv, "\0");
		strcpy_s(ml, "\0");
		strcpy_s(ho, "\0");
		strcpy_s(ten, "\0");
		strcpy_s(sex, "\0");
		strcpy_s(nnh, "\0");
		strcpy_s(sdt, "\0");

		while(true)
		{
			bool isExist = false;
			EntryData(msv, { p.x + 20, p.y + 5 }, eModeImportData::UPPER_NUMBER, 12);
			for (NoteSV *p = lsv; p != NULL; p = p->next)
			{
				if (strcmp(msv, p->sinhvien.MASV) == 0)
				{
					isExist = true;
					break;
				}
			}
			if (isExist)
			{
				Alert("Sinh Vien da ton tai...", { p.x, p.y - 5 }, ColorCode_Red, 3000 ,ColorCode_White);
				strcpy_s(msv, "\0");
			}
			else
				break;
		}
		
		EntryData(ml, { p.x + 20, p.y + 7 }, eModeImportData::UPPER_NUMBER, 10);
		EntryData(ho, { p.x + 20, p.y + 9 }, eModeImportData::UPPER_LOWER, 20);
		EntryData(ten, { p.x + 20, p.y + 11 }, eModeImportData::UPPER_LOWER, 11);
		EntryData(sex, { p.x + 20, p.y + 13 }, eModeImportData::SEX, 1);
		EntryData(sdt, { p.x + 20, p.y + 15 }, eModeImportData::NUMBER, 10);
		EntryData(nnh, { p.x + 20, p.y + 17 }, eModeImportData::NUMBER, 4);

		noteSV = new NoteSV;
		strcpy_s(noteSV->sinhvien.MASV, msv);
		strcpy_s(noteSV->sinhvien.MALOP, ml);
		strcpy_s(noteSV->sinhvien.Ho, ho);
		strcpy_s(noteSV->sinhvien.Ten, ten);
		strcpy_s(noteSV->sinhvien.SDT, sdt);

		noteSV->sinhvien.NamNhapHoc = atoi(nnh);
		noteSV->sinhvien.Phai = atoi(sex);

		InsertSV(lsv, noteSV);
		Alert("Da them Sinh Vien thanh cong...", { p.x, p.y - 5 }, ColorCode_Red, 3000, ColorCode_White);
}

void Xoa_SV(ListSinhVien &lsv)
{
	POINT lc = { 10, 10 };

	EnterMaSVFrame(lc);

	char msv[15] = "\0";

	while (true)
	{
		bool isExist = false;
		EntryData(msv, { lc.x + 14, lc.y + 5 }, eModeImportData::UPPER_NUMBER, 12);

		if (strcmp(msv, lsv->sinhvien.MASV) == 0)
		{
			NoteSV *nSV = lsv;
			lsv = lsv->next;
			delete nSV;
			isExist = true;
			break;
		}
		for (NoteSV *p = lsv; p->next != NULL; p = p->next)
		{
			if (strcmp(msv, p->next->sinhvien.MASV) == 0)
			{
				NoteSV *nSV = p->next;
				p->next = nSV->next;
				delete nSV;
				isExist = true;
				break;
			}
		}
		if (isExist)
		{
			Alert("Da xoa Sinh Vien thanh cong...", { lc.x, lc.y - 5 }, ColorCode_Red, 3000, ColorCode_White);
			break;
		}
		else
		{
			Alert("Ma Sinh Vien khong ton tai...", { lc.x, lc.y - 5 }, ColorCode_Red, 3000, ColorCode_White);
			strcpy_s(msv, "\0");
		}
	}

}

void ShowByClass_SV(ListSinhVien lsv)
{
	POINT lc = { 10, 10 };


	while (true)
	{
		char classCode[11];
		bool isExist = false;
		strcpy_s(classCode, "\0");

		EnterClassCodeFrame(lc);

		EntryData(classCode, { lc.x + 14, lc.y + 5 }, eModeImportData::UPPER_NUMBER, 10);

		if (strcmp(classCode, "") == 0)
			return;

		int i = 0;
		for (NoteSV *p = lsv; p != NULL; p = p->next)
		{
			if (strcmp(p->sinhvien.MALOP, classCode) == 0)
			{
				gotoxy(lc.x, lc.y + 6 + i * 2); cout << "| " << p->sinhvien.MASV;
				gotoxy(lc.x + 13, lc.y + 6 + i * 2); cout << "| " << p->sinhvien.Ho;
				gotoxy(lc.x + 29, lc.y + 6 + i * 2); cout << "| " << p->sinhvien.Ten;
				gotoxy(lc.x + 41, lc.y + 6 + i * 2); cout << "| " << p->sinhvien.MALOP;
				gotoxy(lc.x + 53, lc.y + 6 + i * 2); cout << "| " << (p->sinhvien.Phai == true ? "Nam" : "Nu");
				gotoxy(lc.x + 65, lc.y + 6 + i * 2); cout << "| " << p->sinhvien.SDT;
				gotoxy(lc.x + 85, lc.y + 6 + i * 2); cout << "| " << p->sinhvien.NamNhapHoc;
				gotoxy(lc.x + 95, lc.y + 6 + i * 2); cout << "|";
				gotoxy(lc.x, lc.y + 6 + i * 2 + 1); cout << "|----------------------------------------------------------------------------------------------|";
				i++;
				isExist = true;
			}
		}

		if (!isExist)
		{
			Alert("Ma lop Khong ton tai!", { lc.x,lc.y - 5 }, ColorCode_Red, 2000, ColorCode_White);
		}
		else
		{

			ShowListSVFrame(lc);
			_getch();
			return;
		}
	}
}

void DeleteLSV(ListSinhVien &lsv)
{
	for (NoteSV *p = lsv; p != NULL;)
	{
		NoteSV *temp = p;
		p = p->next;
		delete temp;
	}
}

void LuuFile_LSV(ListSinhVien lsv)
{
	fstream FileOut("DSSINHVIEN.TXT", ios::out);

	int index = 0;
	for (NoteSV *p = lsv; p != NULL; p = p->next)
	{
		if (index++ != 0)
			FileOut << endl;
		FileOut << p->sinhvien.MASV << endl
			<< p->sinhvien.MALOP << endl
			<< p->sinhvien.Ho << endl
			<< p->sinhvien.Ten << endl
			<< p->sinhvien.Phai << endl
			<< p->sinhvien.SDT << endl
			<< p->sinhvien.NamNhapHoc;
	}
	FileOut.close();
}

void DocFile_LSV(ListSinhVien &lsv)
{
	fstream FileIn("DSSINHVIEN.TXT", ios::in);

	if (CountSV(lsv) != 0)
		DeleteLSV(lsv);

	NoteSV *val;
	while (!FileIn.eof())
	{
		val = new NoteSV;

		FileIn >> val->sinhvien.MASV
			>> val->sinhvien.MALOP
			>> val->sinhvien.Ho
			>> val->sinhvien.Ten
			>> val->sinhvien.Phai
			>> val->sinhvien.SDT
			>> val->sinhvien.NamNhapHoc;
		InsertSV(lsv, val);
	}

	FileIn.close();
}