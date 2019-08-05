#include "MonHoc.h"

NoteMH* InsertToTreeByCodeJSubject(ListMonHoc &root, NoteMH *data)
{
	if (root == NULL)
	{
		return data;
	}
	
	if (strcmp(data->monHoc.MAMH, root->monHoc.MAMH) < 0)
		root->pLeft = InsertToTreeByCodeJSubject(root->pLeft, data);
	else if (strcmp(data->monHoc.MAMH, root->monHoc.MAMH) > 0)
		root->pRight = InsertToTreeByCodeJSubject(root->pRight, data);
	return root;
}

NoteMH* InsertToTreeByNameSubject(ListMonHoc &root, NoteMH *data)
{
	if (root == NULL)
	{
		return data;
	}

	if (strcmp(data->monHoc.TenMH, root->monHoc.TenMH) < 0)
		root->pLeft = InsertToTreeByNameSubject(root->pLeft, data);
	else if (strcmp(data->monHoc.TenMH, root->monHoc.TenMH) > 0)
		root->pRight = InsertToTreeByNameSubject(root->pRight, data);
	return root;
}

void LNR(NoteMH *root, int &i)
{
	if (root != NULL)
	{
		LNR(root->pLeft, i);
		i++;
		LNR(root->pRight, i);
	}
}

int CountSubjects(ListMonHoc lmh)
{
	int count = 0;
	LNR(lmh, count);
	return count;
}

void WriteToFile(NoteMH*p, fstream &file)
{
	if (p != NULL)
	{
		file << endl << p->monHoc.MAMH << endl
			<< p->monHoc.TenMH << endl
			<< p->monHoc.STCLT << endl
			<< p->monHoc.STCTH;
		WriteToFile(p->pLeft, file);
		WriteToFile(p->pRight, file);
	}
}

void DocFile_LMH(ListMonHoc &lmh)
{
	fstream FileIn("DSMONHOC.TXT", ios::in);

	int quantity;
	FileIn >> quantity;

	NoteMH *mh;

	while (!FileIn.eof())
	{
		mh = new NoteMH;
		mh->pLeft = mh->pRight = NULL;
		FileIn >> mh->monHoc.MAMH
			>> mh->monHoc.TenMH
			>> mh->monHoc.STCLT
			>> mh->monHoc.STCTH;

		lmh = InsertToTreeByCodeJSubject(lmh, mh);
	}

	FileIn.close();
}

void LuuFile_LMH(ListMonHoc lmh)
{
	fstream FileOut("DSMONHOC.TXT", ios::out);

	int quantityNow = CountSubjects(lmh);

	FileOut << quantityNow;
	
	WriteToFile(lmh, FileOut);

	FileOut.close();
}

void Nhap_LMH(ListMonHoc &lmh)
{
	POINT p = { 10, 10 };
	
	NoteMH *data;
	
	while (true)
	{
		system("cls");

		EnterSubjectsFrame(p);

		char mmh[10], tmh[21], stclt[3], stcth[3];
		strcpy_s(mmh, "\0");
		strcpy_s(tmh, "\0");
		strcpy_s(stclt, "\0");
		strcpy_s(stcth, "\0");
		
		EntryData(mmh, { p.x + 20, p.y + 5 }, eModeImportData::UPPER_NUMBER, 8);
		EntryData(tmh, { p.x + 20, p.y + 7 }, eModeImportData::UPPER_NUMBER, 20);
		EntryData(stclt, { p.x + 20, p.y + 9 }, eModeImportData::NUMBER, 2);
		EntryData(stcth, { p.x + 20, p.y + 11 }, eModeImportData::NUMBER, 2);
		
		data = new NoteMH;
		data->pLeft = data->pRight = NULL;
		strcpy_s(data->monHoc.MAMH, mmh);
		strcpy_s(data->monHoc.TenMH, tmh);

		data->monHoc.STCLT = atoi(stclt);
		data->monHoc.STCTH = atoi(stcth);

		lmh = InsertToTreeByCodeJSubject(lmh, data);

		if (TwoOptionYN({ p.x + 4, p.y + 19 }) == 1)
		{
			return;
		}
	}
}

void LNR(NoteMH *root, POINT p, int &i)
{
	if (root != NULL)
	{
		LNR(root->pLeft, p, i);
		gotoxy(p.x,      p.y + i * 2); cout << "| " << root->monHoc.MAMH;
		gotoxy(p.x + 13, p.y + i * 2); cout << "| " << root->monHoc.TenMH;
		gotoxy(p.x + 32, p.y + i * 2); cout << "| " << root->monHoc.STCTH;
		gotoxy(p.x + 48, p.y + i * 2); cout << "| " << root->monHoc.STCLT;
		gotoxy(p.x + 64, p.y + i * 2); cout << "|";
		gotoxy(p.x,      p.y + i * 2 + 1); cout << "|---------------------------------------------------------------|";
		i++;
		LNR(root->pRight, p, i);
		
	}
}

void LNR_InsertToNewTree(NoteMH *root, ListMonHoc &dsmh)
{
	if (root != NULL)
	{
		LNR_InsertToNewTree(root->pLeft, dsmh);
		MonHoc mh = root->monHoc;
		dsmh = InsertToTreeByNameSubject(dsmh, new NoteMH({ mh, NULL, NULL }));
		LNR_InsertToNewTree(root->pRight, dsmh);
	}
}

void Xuat_LMH(ListMonHoc lmh)
{
	//1            14            26              40              55        
	//| Ma Mon Hoc | Ten Mon Hoc | STC Thuc Hanh | STC Ly Thuyet |
	system("cls");
	POINT p = { 10, 10 };
	ShowListSubjectFrame(p);
	int i = 0;
	
	LNR(lmh, {p.x, p.y + 6}, i);
	i++;
}

void Them_MH(ListMonHoc &lmh)
{
	POINT p = { 10, 10 };

	NoteMH *data;

	system("cls");

	EnterSubjectsFrame(p);

	char mmh[10], tmh[21], stclt[3], stcth[3];
	strcpy_s(mmh, "\0");
	strcpy_s(tmh, "\0");
	strcpy_s(stclt, "\0");
	strcpy_s(stcth, "\0");

	EntryData(mmh, { p.x + 20, p.y + 5 }, eModeImportData::UPPER_NUMBER, 8);
	EntryData(tmh, { p.x + 20, p.y + 7 }, eModeImportData::UPPER_NUMBER, 20);
	EntryData(stclt, { p.x + 20, p.y + 9 }, eModeImportData::NUMBER, 2);
	EntryData(stcth, { p.x + 20, p.y + 11 }, eModeImportData::NUMBER, 2);

	data = new NoteMH;
	data->pLeft = data->pRight = NULL;
	strcpy_s(data->monHoc.MAMH, mmh);
	strcpy_s(data->monHoc.TenMH, tmh);

	data->monHoc.STCLT = atoi(stclt);
	data->monHoc.STCTH = atoi(stcth);

	lmh = InsertToTreeByCodeJSubject(lmh, data);

	system("cls");

	ShowListSubjectFrame(p);

	gotoxy(p.x,      p.y + 6 + 1); cout << "| " << data->monHoc.MAMH;
	gotoxy(p.x + 13, p.y + 6 + 1); cout << "| " << data->monHoc.TenMH;
	gotoxy(p.x + 32, p.y + 6 + 1); cout << "| " << data->monHoc.STCTH;
	gotoxy(p.x + 48, p.y + 6 + 1); cout << "| " << data->monHoc.STCLT;
	gotoxy(p.x + 64, p.y + 6 + 1); cout << "|";
	gotoxy(p.x,      p.y + 6 + 1 + 1); cout << "|---------------------------------------------------------------|";

	Alert("Da them thanh cong!", { p.x, p.y - 5 }, ColorCode_Red, 2000, ColorCode_White);
	_getch();
}

NoteMH* SearchNodeByCodeSubject(NoteMH* root, char *CodeSubject)
{
	if (root == NULL)
		return NULL;

	if (strcmp(CodeSubject, root->monHoc.MAMH) == 0)
	{
		return root;
	}
	if (strcmp(CodeSubject, root->monHoc.MAMH) < 0)
	{
		SearchNodeByCodeSubject(root->pLeft, CodeSubject);
	}
	else
	{
		SearchNodeByCodeSubject(root->pRight, CodeSubject);
	}
}

NoteMH* FindToRemove(NoteMH *root, char* CodeSubject) 
{
	if (root == NULL)
		return NULL;
	if (strcmp(root->monHoc.MAMH, CodeSubject) == 0) {
		if (root->pLeft == NULL && root->pRight == NULL)
			return NULL;
		if (root->pLeft != NULL && root->pRight != NULL) {
			// Tìm nút thay thế
			NoteMH *successor = root->pRight;
			while (successor->pLeft != NULL)
				successor = successor->pLeft;

			strcpy_s(root->monHoc.MAMH, successor->monHoc.MAMH);
			FindToRemove(root->pRight, successor->monHoc.MAMH);
			return root;
		}
		if (root->pLeft != NULL)
			return root->pLeft;
		else
			return root->pRight;
	}
	if (CodeSubject > root->monHoc.MAMH)
		root->pRight = FindToRemove(root->pRight, CodeSubject);
	else
		root->pLeft = FindToRemove(root->pLeft, CodeSubject);
	return root;
}

void Xoa_MH(ListMonHoc &lmh)
{
	POINT p = { 10, 10 };
	char codeSubject[11];

	while (true)
	{
		EnterSubjectCodeFrame(p);

		EntryData(codeSubject, { p.x + 14, p.y + 5 }, eModeImportData::UPPER_NUMBER, 10);

		if (strcmp(codeSubject, "") == 0)
			return;

		if (SearchNodeByCodeSubject(lmh, codeSubject) == NULL)
		{
			Alert("Khong tim thay ma mon hoc!", { p.x, p.y - 5 }, ColorCode_Red, 2000, ColorCode_White);
			gotoxy(p.x + 14, p.y + 5); cout << "                           ";
		}
		else
		{
			lmh = FindToRemove(lmh, codeSubject);

			Alert("Da xoa thanh cong!", { p.x, p.y - 5 }, ColorCode_Red, 2000, ColorCode_White);
			return;
		}
	}

}

void Sua_MH(ListMonHoc &lmh)
{
	POINT p = { 10, 10 };
	char codeSubject[11];

	while (true)
	{
		EnterSubjectCodeFrame(p);

		EntryData(codeSubject, { p.x + 14, p.y + 5 }, eModeImportData::UPPER_NUMBER, 10);

		if (strcmp(codeSubject, "") == 0)
			return;

		NoteMH *mh = SearchNodeByCodeSubject(lmh, codeSubject);

		if (mh == NULL)
		{
			Alert("Khong tim thay ma mon hoc!", { p.x, p.y - 5 }, ColorCode_Red, 2000, ColorCode_White);
			gotoxy(p.x + 14, p.y + 5); cout << "                           ";
		}
		else
		{
			char mmh[10], tmh[21], stclt[3], stcth[3];
			strcpy_s(mmh, mh->monHoc.MAMH);
			strcpy_s(tmh, mh->monHoc.TenMH);
			_itoa_s(mh->monHoc.STCLT, stclt, 10);
			_itoa_s(mh->monHoc.STCTH, stcth, 10);

			EntryData(mmh, { p.x + 20, p.y + 5 }, eModeImportData::UPPER_NUMBER, 8);
			EntryData(tmh, { p.x + 20, p.y + 7 }, eModeImportData::UPPER_NUMBER, 20);
			EntryData(stclt, { p.x + 20, p.y + 9 }, eModeImportData::NUMBER, 2);
			EntryData(stcth, { p.x + 20, p.y + 11 }, eModeImportData::NUMBER, 2);

			strcpy_s(mh->monHoc.MAMH, mmh);
			strcpy_s(mh->monHoc.TenMH, tmh);

			mh->monHoc.STCLT = atoi(stclt);
			mh->monHoc.STCTH = atoi(stcth);

			Alert("Da sua thanh cong!", { p.x, p.y - 5 }, ColorCode_Red, 2000, ColorCode_White);
			return;
		}
	}
}

void ShowByNameSubjects(ListMonHoc lmh)
{
	ListMonHoc newLMH = NULL;
	LNR_InsertToNewTree(lmh, newLMH);
	Xuat_LMH(newLMH);
}
