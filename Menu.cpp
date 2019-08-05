#include "Menu.h"

#include "Menu.h"

void drawText(POINT lcDisplay)
{
	fstream FileIn("Intro.TXT", ios::in);

	if (FileIn.fail())
	{
		cout << "ERROR file Text.";
		Sleep(5000);
		exit(0);
	}
	else
	{
		int line = 1;
		while (!FileIn.eof())
		{
			gotoxy(lcDisplay.x, lcDisplay.y + line++);
			string text;
			getline(FileIn, text);
			if (text == "**")
				break;
			else
				std::cout << text << endl;
		}
	}

	FileIn.close();
}

void dropDown(POINT lcBtnHead, int index, int &dir, ListLopTinChi &lltc, ListSinhVien &lsv, ListMonHoc &lmh)
{
	POINT lcGird = { 2, 2 };
	if (index == 0) // sinhVien
	{
		int space = 0;
		SIZE sBtnShowList, sBtnAdd, sBtnDel, sBtnEdit, sClear;
		POINT lBtnShowList, lBtnAdd, lBtnDel, lBtnEdit, lClear;

		sBtnShowList = sBtnAdd = sBtnDel = sBtnEdit = { 15, 5 };
		lBtnShowList = { lcBtnHead.x, lcBtnHead.y + 5 + space };
		lBtnAdd = { lcBtnHead.x, lBtnShowList.y + sBtnShowList.cy + space };
		lBtnDel = { lcBtnHead.x, lBtnAdd.y + sBtnAdd.cy + space };
		lBtnEdit = { lcBtnHead.x, lBtnDel.y + sBtnDel.cy + space };
		lClear = lBtnShowList;
		sClear = { sBtnShowList.cx, (lBtnEdit.y + sBtnEdit.cy) - lBtnShowList.y };

		Button(true, "DS SV", lBtnShowList, sBtnShowList, ColorCode_Blue, ColorCode_Black);
		Button(false, "Them", lBtnAdd, sBtnAdd, ColorCode_Blue, ColorCode_Black);
		Button(false, "Xoa", lBtnDel, sBtnDel, ColorCode_Blue, ColorCode_Black);
		Button(false, "In All", lBtnEdit, sBtnDel, ColorCode_Blue, ColorCode_Black);

		int maxBTN = 4;
		int index = 0;
		bool isControl = false;
		while (true)
		{
			if (_kbhit())
			{
				char key = _getch();

				if (key == -32)
				{
					isControl = true;
				}
				else if (isControl)
				{
					if (key == dir_LEFT)
					{
						//del list
						dis_Clear(lClear, sClear);
						dir = dir_LEFT;
						break;
					}
					else if (key == dir_RIGHT)
					{
						//del list
						dis_Clear(lClear, sClear);
						dir = dir_RIGHT;
						break;
					}
					else if (key == dir_DOWN)
					{
						index++;
						if (index >= maxBTN)
						{
							index = 0;
							Button(false, "In All", lBtnEdit, sBtnDel, ColorCode_Blue, ColorCode_Black);
							Button(true, "DS SV", lBtnShowList, sBtnShowList, ColorCode_Blue, ColorCode_Black);
						}
						else if (index == 1)
						{
							Button(false, "DS SV", lBtnShowList, sBtnShowList, ColorCode_Blue, ColorCode_Black);
							Button(true, "Them", lBtnAdd, sBtnAdd, ColorCode_Blue, ColorCode_Black);
						}
						else if (index == 2)
						{
							Button(false, "Them", lBtnAdd, sBtnAdd, ColorCode_Blue, ColorCode_Black);
							Button(true, "Xoa", lBtnDel, sBtnDel, ColorCode_Blue, ColorCode_Black);
						}
						else if (index == 3)
						{
							Button(false, "Xoa", lBtnDel, sBtnDel, ColorCode_Blue, ColorCode_Black);
							Button(true, "In All", lBtnEdit, sBtnDel, ColorCode_Blue, ColorCode_Black);
						}
					}
					else if (key == dir_UP)
					{
						index--;
						if (index < 0)
						{
							index = maxBTN - 1;
							Button(false, "DS SV", lBtnShowList, sBtnShowList, ColorCode_Blue, ColorCode_Black);
							Button(true, "In All", lBtnEdit, sBtnDel, ColorCode_Blue, ColorCode_Black);
						}
						else if (index == 2)
						{
							Button(true, "Xoa", lBtnDel, sBtnDel, ColorCode_Blue, ColorCode_Black);
							Button(false, "In All", lBtnEdit, sBtnDel, ColorCode_Blue, ColorCode_Black);
						}
						else if (index == 1)
						{
							Button(true, "Them", lBtnAdd, sBtnAdd, ColorCode_Blue, ColorCode_Black);
							Button(false, "Xoa", lBtnDel, sBtnDel, ColorCode_Blue, ColorCode_Black);
						}
						else if (index == 0)
						{
							Button(true, "DS SV", lBtnShowList, sBtnShowList, ColorCode_Blue, ColorCode_Black);
							Button(false, "Them", lBtnAdd, sBtnAdd, ColorCode_Blue, ColorCode_Black);
						}
					}

					isControl = false;
				}
				else
				{
					if (key == key_ESC)
					{
						//out
						dir = key_ESC;
						break;
					}
					else if (key == key_ENTER)
					{
						if (index == 0) // view
						{
							system("cls");
							ShowByClass_SV(lsv);

							dir = key_SPACE;
							break;
						}
						else if (index == 1) // add
						{
							system("cls");
							Them_SV(lsv);

							dir = key_SPACE;
							break;
						}
						else if (index == 2) // remove
						{
							system("cls");
							Xoa_SV(lsv);

							dir = key_SPACE;
							break;
						}
						else if (index == 3) // view all
						{
							system("cls");
							Xuat_SV(lsv);
							_getch();
							dir = key_SPACE;
							break;
						}
					}
				}
			}
		}
	}
	else if (index == 1) // mon Hoc
	{
		SIZE sCreate, sShow, sShowByDay, sClear, sTenDay;
		POINT lCreate, lShow, lShowByDay, lClear, lTenDay;
		int space = 0;

		sCreate = sShow = sShowByDay = sTenDay = { 15, 5 };
		lCreate = { lcBtnHead.x, lcBtnHead.y + 5 + space };
		lShow = { lCreate.x, lCreate.y + sCreate.cy + space };
		lShowByDay = { lShow.x, lShow.y + sShow.cy + space };
		lTenDay = { lShowByDay.x, lShowByDay.y + sShowByDay.cy + space };

		lClear = { lCreate.x, lCreate.y };
		sClear = { sCreate.cx, (lTenDay.y + sTenDay.cy) - lClear.y };

		Button(true, "Them", lCreate, sCreate, ColorCode_Blue, ColorCode_Black);
		Button(false, "Xoa", lShow, sShow, ColorCode_Blue, ColorCode_Black);
		Button(false, "Sua", lShowByDay, sShowByDay, ColorCode_Blue, ColorCode_Black);
		Button(false, "In Danh Sach", lTenDay, sTenDay, ColorCode_Blue, ColorCode_Black);

		int maxBTN = 4;
		int index = 0;
		bool isControl = false;
		while (true)
		{
			if (_kbhit())
			{
				char key = _getch();

				if (key == -32)
				{
					isControl = true;
				}
				else if (isControl)
				{
					if (key == dir_LEFT)
					{
						//del list
						dis_Clear(lClear, sClear);
						dir = dir_LEFT;
						break;
					}
					else if (key == dir_RIGHT)
					{
						//del list
						dis_Clear(lClear, sClear);
						dir = dir_RIGHT;
						break;
					}
					else if (key == dir_DOWN)
					{
						index++;
						if (index >= maxBTN)
						{
							index = 0;
							Button(true, "Them", lCreate, sCreate, ColorCode_Blue, ColorCode_Black);
							Button(false, "In Danh Sach", lTenDay, sTenDay, ColorCode_Blue, ColorCode_Black);
						}
						else if (index == 1)
						{
							Button(false, "Them", lCreate, sCreate, ColorCode_Blue, ColorCode_Black);
							Button(true, "Xoa", lShow, sShow, ColorCode_Blue, ColorCode_Black);
						}
						else if (index == 2)
						{
							Button(false, "Xoa", lShow, sShow, ColorCode_Blue, ColorCode_Black);
							Button(true, "Sua", lShowByDay, sShowByDay, ColorCode_Blue, ColorCode_Black);
						}
						else if (index == 3)
						{
							Button(false, "Sua", lShowByDay, sShowByDay, ColorCode_Blue, ColorCode_Black);
							Button(true, "In Danh Sach", lTenDay, sTenDay, ColorCode_Blue, ColorCode_Black);
						}
					}
					else if (key == dir_UP)
					{
						index--;
						if (index < 0)
						{
							index = maxBTN - 1;
							Button(false, "Them", lCreate, sCreate, ColorCode_Blue, ColorCode_Black);
							Button(true, "In Danh Sach", lTenDay, sTenDay, ColorCode_Blue, ColorCode_Black);
						}
						else if (index == 2)
						{
							Button(false, "In Danh Sach", lTenDay, sTenDay, ColorCode_Blue, ColorCode_Black);
							Button(true, "Sua", lShowByDay, sShowByDay, ColorCode_Blue, ColorCode_Black);
						}
						else if (index == 1)
						{
							Button(true, "Xoa", lShow, sShow, ColorCode_Blue, ColorCode_Black);
							Button(false, "Sua", lShowByDay, sShowByDay, ColorCode_Blue, ColorCode_Black);
						}
						else if (index == 0)
						{
							Button(true, "Them", lCreate, sCreate, ColorCode_Blue, ColorCode_Black);
							Button(false, "Xoa", lShow, sShow, ColorCode_Blue, ColorCode_Black);
						}
					}
					isControl = false;
				}
				else
				{
					if (key == key_ESC)
					{
						//out
						dir = key_ESC;
						break;
					}
					else if (key == key_ENTER)
					{
						if (index == 0) // them
						{
							system("cls");
							Them_MH(lmh);

							dir = key_SPACE;
							break;
						}
						else if (index == 1) // xoa
						{
							system("cls");
							Xoa_MH(lmh);

							dir = key_SPACE;
							break;
						}
						else if (index == 2) //sua
						{
							system("cls");
							Sua_MH(lmh);

							dir = key_SPACE;
							break;
						}
						else if (index == 3) // in 
						{
							system("cls");
							ShowByNameSubjects(lmh);
							_getch();
							dir = key_SPACE;
							break;
						}
					}
				}
			}
		}

	}
	else if (index == 2) // lOP TIN CHI
	{
		SIZE sCreate, sShow, sShowByDay, sClear, sTenDay;
		POINT lCreate, lShow, lShowByDay, lClear, lTenDay;
		int space = 0;

		sCreate = sShow = sShowByDay = sTenDay = { 15, 5 };
		lCreate = { lcBtnHead.x, lcBtnHead.y + 5 + space };
		lShow = { lCreate.x, lCreate.y + sCreate.cy + space };
		lShowByDay = { lShow.x, lShow.y + sShow.cy + space };
		lTenDay = { lShowByDay.x, lShowByDay.y + sShowByDay.cy + space };

		lClear = { lCreate.x, lCreate.y };
		sClear = { sCreate.cx, (lTenDay.y + sTenDay.cy) - lClear.y };

		Button(true, "Mo Lop", lCreate, sCreate, ColorCode_Blue, ColorCode_Black);
		Button(false, "Xoa", lShow, sShow, ColorCode_Blue, ColorCode_Black);
		Button(false, "Sua", lShowByDay, sShowByDay, ColorCode_Blue, ColorCode_Black);
		Button(false, "In Danh Sach", lTenDay, sTenDay, ColorCode_Blue, ColorCode_Black);

		int maxBTN = 4;
		int index = 0;
		bool isControl = false;
		while (true)
		{
			if (_kbhit())
			{
				char key = _getch();

				if (key == -32)
				{
					isControl = true;
				}
				else if (isControl)
				{
					if (key == dir_LEFT)
					{
						//del list
						dis_Clear(lClear, sClear);
						dir = dir_LEFT;
						break;
					}
					else if (key == dir_RIGHT)
					{
						//del list
						dis_Clear(lClear, sClear);
						dir = dir_RIGHT;
						break;
					}
					else if (key == dir_DOWN)
					{
						index++;
						if (index >= maxBTN)
						{
							index = 0;
							Button(true, "Mo Lop", lCreate, sCreate, ColorCode_Blue, ColorCode_Black);
							Button(false, "In Danh Sach", lTenDay, sTenDay, ColorCode_Blue, ColorCode_Black);
						}
						else if (index == 1)
						{
							Button(false, "Mo Lop", lCreate, sCreate, ColorCode_Blue, ColorCode_Black);
							Button(true, "Xoa", lShow, sShow, ColorCode_Blue, ColorCode_Black);
						}
						else if (index == 2)
						{
							Button(false, "Xoa", lShow, sShow, ColorCode_Blue, ColorCode_Black);
							Button(true, "Sua", lShowByDay, sShowByDay, ColorCode_Blue, ColorCode_Black);
						}
						else if (index == 3)
						{
							Button(false, "Sua", lShowByDay, sShowByDay, ColorCode_Blue, ColorCode_Black);
							Button(true, "In Danh Sach", lTenDay, sTenDay, ColorCode_Blue, ColorCode_Black);
						}
					}
					else if (key == dir_UP)
					{
						index--;
						if (index < 0)
						{
							index = maxBTN - 1;
							Button(false, "Mo Lop", lCreate, sCreate, ColorCode_Blue, ColorCode_Black);
							Button(true, "In Danh Sach", lTenDay, sTenDay, ColorCode_Blue, ColorCode_Black);
						}
						else if (index == 2)
						{
							Button(false, "In Danh Sach", lTenDay, sTenDay, ColorCode_Blue, ColorCode_Black);
							Button(true, "Sua", lShowByDay, sShowByDay, ColorCode_Blue, ColorCode_Black);
						}
						else if (index == 1)
						{
							Button(true, "Xoa", lShow, sShow, ColorCode_Blue, ColorCode_Black);
							Button(false, "Sua", lShowByDay, sShowByDay, ColorCode_Blue, ColorCode_Black);
						}
						else if (index == 0)
						{
							Button(true, "Mo Lop", lCreate, sCreate, ColorCode_Blue, ColorCode_Black);
							Button(false, "Xoa", lShow, sShow, ColorCode_Blue, ColorCode_Black);
						}
					}
					isControl = false;
				}
				else
				{
					if (key == key_ESC)
					{
						//out
						dir = key_ESC;
						break;
					}
					else if (key == key_ENTER)
					{
						if (index == 0) // them
						{
							system("cls");
							Them_LLTC(lltc, lmh);

							dir = key_SPACE;
							break;
						}
						else if (index == 1) // xoa
						{
							system("cls");
							Xoa_LLTC(lltc);

							dir = key_SPACE;
							break;
						}
						else if (index == 2) //sua
						{
							system("cls");
							Sua_LLTC(lltc, lmh);

							dir = key_SPACE;
							break;
						}
						else if (index == 3) // in 
						{
							system("cls");
							Xuat_LLTC(lltc);

							_getch();
							dir = key_SPACE;
							break;
						}
					}
				}
			}
		}
	}
	else if (index == 3) // Bang Diem
	{
		SIZE sCreate, sShow, sShowByDay, sClear, sTenDay;
		POINT lCreate, lShow, lShowByDay, lClear, lTenDay;
		int space = 0;

		sCreate = sShow = sShowByDay = sTenDay = { 15, 5 };
		lCreate = { lcBtnHead.x, lcBtnHead.y + 5 + space };
		lShow = { lCreate.x, lCreate.y + sCreate.cy + space };
		lShowByDay = { lShow.x, lShow.y + sShow.cy + space };
		lTenDay = { lShowByDay.x, lShowByDay.y + sShowByDay.cy + space };

		lClear = { lCreate.x, lCreate.y };
		sClear = { sCreate.cx, (lTenDay.y + sTenDay.cy) - lClear.y };

		Button(true, "Nhap Diem", lCreate, sCreate, ColorCode_Blue, ColorCode_Black);
		Button(false, "Diem Theo Mon", lShow, sShow, ColorCode_Blue, ColorCode_Black);
		Button(false, "Diem TB", lShowByDay, sShowByDay, ColorCode_Blue, ColorCode_Black);
		Button(false, "Diem TK", lTenDay, sTenDay, ColorCode_Blue, ColorCode_Black);

		int maxBTN = 4;
		int index = 0;
		bool isControl = false;
		while (true)
		{
			if (_kbhit())
			{
				char key = _getch();

				if (key == -32)
				{
					isControl = true;
				}
				else if (isControl)
				{
					if (key == dir_LEFT)
					{
						//del list
						dis_Clear(lClear, sClear);
						dir = dir_LEFT;
						break;
					}
					else if (key == dir_RIGHT)
					{
						//del list
						dis_Clear(lClear, sClear);
						dir = dir_RIGHT;
						break;
					}
					else if (key == dir_DOWN)
					{
						index++;
						if (index >= maxBTN)
						{
							index = 0;
							Button(true, "Nhap Diem", lCreate, sCreate, ColorCode_Blue, ColorCode_Black);
							Button(false, "Diem TK", lTenDay, sTenDay, ColorCode_Blue, ColorCode_Black);
						}
						else if (index == 1)
						{
							Button(false, "Nhap Diem", lCreate, sCreate, ColorCode_Blue, ColorCode_Black);
							Button(true, "Diem Theo Mon", lShow, sShow, ColorCode_Blue, ColorCode_Black);
						}
						else if (index == 2)
						{
							Button(false, "Diem Theo Mon", lShow, sShow, ColorCode_Blue, ColorCode_Black);
							Button(true, "Diem TB", lShowByDay, sShowByDay, ColorCode_Blue, ColorCode_Black);
						}
						else if (index == 3)
						{
							Button(false, "Diem TB", lShowByDay, sShowByDay, ColorCode_Blue, ColorCode_Black);
							Button(true, "Diem TK", lTenDay, sTenDay, ColorCode_Blue, ColorCode_Black);
						}
					}
					else if (key == dir_UP)
					{
						index--;
						if (index < 0)
						{
							index = maxBTN - 1;
							Button(false, "Nhap Diem", lCreate, sCreate, ColorCode_Blue, ColorCode_Black);
							Button(true, "Diem TK", lTenDay, sTenDay, ColorCode_Blue, ColorCode_Black);
						}
						else if (index == 2)
						{
							Button(false, "In Danh Sach", lTenDay, sTenDay, ColorCode_Blue, ColorCode_Black);
							Button(true, "Diem TB", lShowByDay, sShowByDay, ColorCode_Blue, ColorCode_Black);
						}
						else if (index == 1)
						{
							Button(true, "Diem Theo Mon", lShow, sShow, ColorCode_Blue, ColorCode_Black);
							Button(false, "Diem TB", lShowByDay, sShowByDay, ColorCode_Blue, ColorCode_Black);
						}
						else if (index == 0)
						{
							Button(true, "Nhap Diem", lCreate, sCreate, ColorCode_Blue, ColorCode_Black);
							Button(false, "Diem Theo Mon", lShow, sShow, ColorCode_Blue, ColorCode_Black);
						}
					}
					isControl = false;
				}
				else
				{
					if (key == key_ESC)
					{
						//out
						dir = key_ESC;
						break;
					}
					else if (key == key_ENTER)
					{
						if (index == 0) // nhap diem
						{
							system("cls");
							NhapDiem(lltc, lsv, lmh, false);

							dir = key_SPACE;
							break;
						}
						else if (index == 1) // in diem theo mon
						{
							system("cls");
							NhapDiem(lltc, lsv, lmh, true);

							dir = key_SPACE;
							break;
						}
						else if (index == 2) // diem trung binh
						{
							system("cls");
							XemBangDiemTBTheoLop(lltc, lsv, lmh);

							dir = key_SPACE;
							break;
						}
						else if (index == 3) // in 
						{
							
							dir = key_SPACE;
							break;
						}
					}
				}
			}
		}
	}
	else if (index == 4)//Reg
	{
		SIZE sCreate, sShow, sShowByDay, sClear, sTenDay;
		POINT lCreate, lShow, lShowByDay, lClear, lTenDay;
		int space = 0;

		sCreate = sShow = sShowByDay = sTenDay = { 15, 5 };
		lCreate = { lcBtnHead.x, lcBtnHead.y + 5 + space };
		lShow = { lCreate.x, lCreate.y + sCreate.cy + space };
		lShowByDay = { lShow.x, lShow.y + sShow.cy + space };
		lTenDay = { lShowByDay.x, lShowByDay.y + sShowByDay.cy + space };

		lClear = { lCreate.x, lCreate.y };
		sClear = { sCreate.cx, (lTenDay.y + sTenDay.cy) - lClear.y };

		Button(true, "Them SV", lCreate, sCreate, ColorCode_Blue, ColorCode_Black);
		Button(false, "Xoa SV", lShow, sShow, ColorCode_Blue, ColorCode_Black);
		Button(false, "Sua SV", lShowByDay, sShowByDay, ColorCode_Blue, ColorCode_Black);
		Button(false, "Dang Ky", lTenDay, sTenDay, ColorCode_Blue, ColorCode_Black);

		int maxBTN = 4;
		int index = 0;
		bool isControl = false;
		while (true)
		{
			if (_kbhit())
			{
				char key = _getch();

				if (key == -32)
				{
					isControl = true;
				}
				else if (isControl)
				{
					if (key == dir_LEFT)
					{
						//del list
						dis_Clear(lClear, sClear);
						dir = dir_LEFT;
						break;
					}
					else if (key == dir_RIGHT)
					{
						//del list
						dis_Clear(lClear, sClear);
						dir = dir_RIGHT;
						break;
					}
					else if (key == dir_DOWN)
					{
						index++;
						if (index >= maxBTN)
						{
							index = 0;
							Button(true, "Them SV", lCreate, sCreate, ColorCode_Blue, ColorCode_Black);
							Button(false, "Dang Ky", lTenDay, sTenDay, ColorCode_Blue, ColorCode_Black);
						}
						else if (index == 1)
						{
							Button(false, "Them SV", lCreate, sCreate, ColorCode_Blue, ColorCode_Black);
							Button(true, "Xoa SV", lShow, sShow, ColorCode_Blue, ColorCode_Black);
						}
						else if (index == 2)
						{
							Button(false, "Xoa SV", lShow, sShow, ColorCode_Blue, ColorCode_Black);
							Button(true, "Sua SV", lShowByDay, sShowByDay, ColorCode_Blue, ColorCode_Black);
						}
						else if (index == 3)
						{
							Button(false, "Sua SV", lShowByDay, sShowByDay, ColorCode_Blue, ColorCode_Black);
							Button(true, "Dang Ky", lTenDay, sTenDay, ColorCode_Blue, ColorCode_Black);
						}
					}
					else if (key == dir_UP)
					{
						index--;
						if (index < 0)
						{
							index = maxBTN - 1;
							Button(false, "Them SV", lCreate, sCreate, ColorCode_Blue, ColorCode_Black);
							Button(true, "Dang Ky", lTenDay, sTenDay, ColorCode_Blue, ColorCode_Black);
						}
						else if (index == 2)
						{
							Button(false, "Dang Ky", lTenDay, sTenDay, ColorCode_Blue, ColorCode_Black);
							Button(true, "Sua", lShowByDay, sShowByDay, ColorCode_Blue, ColorCode_Black);
						}
						else if (index == 1)
						{
							Button(true, "Xoa SV", lShow, sShow, ColorCode_Blue, ColorCode_Black);
							Button(false, "Sua SV", lShowByDay, sShowByDay, ColorCode_Blue, ColorCode_Black);
						}
						else if (index == 0)
						{
							Button(true, "Them SV", lCreate, sCreate, ColorCode_Blue, ColorCode_Black);
							Button(false, "Xoa SV", lShow, sShow, ColorCode_Blue, ColorCode_Black);
						}
					}
					isControl = false;
				}
				else
				{
					if (key == key_ESC)
					{
						//out
						dir = key_ESC;
						break;
					}
					else if (key == key_ENTER)
					{
						if (index == 0) // them SVDK
						{
							system("cls");
							ThemSinhVien_DSDK(lltc);

							dir = key_SPACE;
							break;
						}
						else if (index == 1) // xoa SVDK
						{
							system("cls");
							XoaSinhVien_DSDK(lltc);

							dir = key_SPACE;
							break;
						}
						else if (index == 2) //sua
						{
							system("cls");
							SuaSinhVien_DSDK(lltc);

							dir = key_SPACE;
							break;
						}
						else if (index == 3) // in 
						{
							system("cls");
							DangKyHoc(lltc, lsv);
							dir = key_SPACE;
							break;
						}
					}
				}
			}
		}
	}
	else if (index == 5)//data
	{
		SIZE sBtnSave, sBtnLoad, sClear;
		POINT lBtnSave, lBtnLoad, lClear;
		int space = 0;

		sBtnSave = sBtnLoad = { 15, 5 };
		lBtnSave = { lcBtnHead.x, lcBtnHead.y + 5 + space };
		lBtnLoad = { lcBtnHead.x, lBtnSave.y + sBtnSave.cy + space };
		lClear = lBtnSave;
		sClear = { sBtnSave.cx, (lBtnLoad.y + sBtnLoad.cy) - lClear.y };

		Button(true, "Save", lBtnSave, sBtnSave, ColorCode_Blue, ColorCode_Black);
		Button(false, "Load", lBtnLoad, sBtnLoad, ColorCode_Blue, ColorCode_Black);

		int maxBTN = 2;
		int index = 0;
		bool isControl = false;
		while (true)
		{
			if (_kbhit())
			{
				char key = _getch();

				if (key == -32)
				{
					isControl = true;
				}
				else if (isControl)
				{
					if (key == dir_LEFT)
					{
						//del list
						dis_Clear(lClear, sClear);
						dir = dir_LEFT;
						break;
					}
					else if (key == dir_RIGHT)
					{
						//del list
						dis_Clear(lClear, sClear);
						dir = dir_RIGHT;
						break;
					}
					else if (key == dir_DOWN)
					{
						index++;
						if (index >= maxBTN)
						{
							index = 0;
							Button(true, "Save", lBtnSave, sBtnSave, ColorCode_Blue, ColorCode_Black);
							Button(false, "Load", lBtnLoad, sBtnLoad, ColorCode_Blue, ColorCode_Black);
						}
						else if (index == 1)
						{
							Button(false, "Save", lBtnSave, sBtnSave, ColorCode_Blue, ColorCode_Black);
							Button(true, "Load", lBtnLoad, sBtnLoad, ColorCode_Blue, ColorCode_Black);
						}
					}
					else if (key == dir_UP)
					{
						index--;
						if (index < 0)
						{
							index = maxBTN - 1;
							Button(false, "Save", lBtnSave, sBtnSave, ColorCode_Blue, ColorCode_Black);
							Button(true, "Load", lBtnLoad, sBtnLoad, ColorCode_Blue, ColorCode_Black);
						}
						else if (index == 0)
						{
							Button(true, "Save", lBtnSave, sBtnSave, ColorCode_Blue, ColorCode_Black);
							Button(false, "Load", lBtnLoad, sBtnLoad, ColorCode_Blue, ColorCode_Black);
						}
					}
					isControl = false;
				}
				else
				{
					if (key == key_ESC)
					{
						//out
						dir = key_ESC;
						break;
					}
					else if (key == key_ENTER)
					{
						if (index == 0)//save
						{
							system("cls");
							if (messagebox("Ban co muon luu du lieu khong?", YES_NO, POINT()))
							{
								LuuFile_LSV(lsv);
								LuuFile_LMH(lmh);
								LuuFile_LLTC(lltc);
								LuuFile_DSDK(lltc);
								system("cls");
								messagebox("Da luu du lieu thanh cong.", YES, POINT());
							}

							dir = key_SPACE;
							break;
						}
						else if (index == 1) // load
						{
							system("cls");

							DocFile_LSV(lsv);
							DocFile_LMH(lmh);
							DocFile_LLTC(lltc);
							DocFile_DSDK(lltc);

							dir = key_SPACE;
							break;
						}
					}
				}
			}
		}
	}
}

bool menu_Select(POINT lcDisplay, ListLopTinChi &lltc, ListSinhVien &lsv, ListMonHoc &lmh)
{
	SIZE sBtnEmployees, sBtnMaterial, sBtnBill, sBtnScore, sBtnReg, sBtnData, sGird;
	POINT lBtnEmployees, lBtnMaterial, lBtnBill, lBtnScore, lBtnReg, lBtnData;
	int space = 5;

	sBtnEmployees = sBtnMaterial = sBtnBill = sBtnData = sBtnScore  = sBtnReg= { 15, 5 };
	sGird = { sBtnEmployees.cx * 3 + space * 2, 40 };
	lBtnMaterial = { lcDisplay.x + 3, lcDisplay.y + 8 };
	lBtnEmployees = { lBtnMaterial.x + sBtnMaterial.cx + space, lBtnMaterial.y };
	lBtnBill = { lBtnEmployees.x + sBtnEmployees.cx + space, lBtnMaterial.y };
	lBtnScore = { lBtnBill.x + sBtnBill.cx + space, lBtnMaterial.y };
	lBtnReg = { lBtnScore.x + sBtnScore.cx + space, lBtnScore.y };
	lBtnData = {lBtnReg.x + sBtnReg.cx + space, lBtnReg.y};

	Button(true, "Sinh Vien", lBtnMaterial, sBtnMaterial, ColorCode_Blue, ColorCode_Black);
	Button(false, "Mon Hoc", lBtnEmployees, sBtnEmployees, ColorCode_Blue, ColorCode_Black);
	Button(false, "Lop TC", lBtnBill, sBtnBill, ColorCode_Blue, ColorCode_Black);
	Button(false, "Bang Diem", lBtnScore, sBtnScore, ColorCode_Blue, ColorCode_Black);
	Button(false, "Dang Ky", lBtnReg, sBtnReg, ColorCode_Blue, ColorCode_Black);
	Button(false, "Du Lieu", lBtnData, sBtnData, ColorCode_Blue, ColorCode_Black);

	int maxBTN = 6;
	int index = 0;
	int key = 0;
	dropDown(lBtnMaterial, index, key, lltc, lsv, lmh);
	while (true)
	{
		if (key == dir_LEFT)
		{
			index--;
			if (index < 0)
			{
				index = maxBTN - 1;
			}
			//show
			if (index == 0)
			{
				Button(true, "Sinh Vien", lBtnMaterial, sBtnMaterial, ColorCode_Blue, ColorCode_Black);
				Button(false, "Mon Hoc", lBtnEmployees, sBtnEmployees, ColorCode_Blue, ColorCode_Black);
				dropDown(lBtnMaterial, index, key, lltc, lsv, lmh);
			}
			else if (index == 1)
			{
				Button(true, "Mon Hoc", lBtnEmployees, sBtnEmployees, ColorCode_Blue, ColorCode_Black);
				Button(false, "Lop TC", lBtnBill, sBtnBill, ColorCode_Blue, ColorCode_Black);
				dropDown(lBtnEmployees, index, key, lltc, lsv, lmh);
			}
			else if (index == 2)
			{
				Button(true, "Lop TC", lBtnBill, sBtnBill, ColorCode_Blue, ColorCode_Black);
				Button(false, "Bang Diem", lBtnScore, sBtnScore, ColorCode_Blue, ColorCode_Black);
				dropDown(lBtnBill, index, key, lltc, lsv, lmh);
			}
			else if (index == 3)
			{
				Button(true, "Bang Diem", lBtnScore, sBtnScore, ColorCode_Blue, ColorCode_Black);
				Button(false, "Dang Ky", lBtnReg, sBtnReg, ColorCode_Blue, ColorCode_Black);
				dropDown(lBtnScore, index, key, lltc, lsv, lmh);
			}
			else if (index == 4)
			{
				Button(true, "Dang Ky", lBtnReg, sBtnReg, ColorCode_Blue, ColorCode_Black);
				Button(false, "Du Lieu", lBtnData, sBtnData, ColorCode_Blue, ColorCode_Black);
				dropDown(lBtnReg, index, key, lltc, lsv, lmh);
			}
			else if (index == 5)
			{
				Button(false, "Sinh Vien", lBtnMaterial, sBtnMaterial, ColorCode_Blue, ColorCode_Black);
				Button(true, "Du Lieu", lBtnData, sBtnData, ColorCode_Blue, ColorCode_Black);
				dropDown(lBtnData, index, key, lltc, lsv, lmh);
			}
		}
		else if (key == dir_RIGHT)
		{
			index++;
			if (index >= maxBTN)
			{
				index = 0;
			}
			//show;
			if (index == 0)
			{
				Button(true, "Sinh Vien", lBtnMaterial, sBtnMaterial, ColorCode_Blue, ColorCode_Black);
				Button(false, "Du Lieu", lBtnData, sBtnData, ColorCode_Blue, ColorCode_Black);
				dropDown(lBtnMaterial, index, key, lltc, lsv, lmh);
			}
			else if (index == 1)
			{
				Button(false, "Sinh Vien", lBtnMaterial, sBtnMaterial, ColorCode_Blue, ColorCode_Black);
				Button(true, "Mon Hoc", lBtnEmployees, sBtnEmployees, ColorCode_Blue, ColorCode_Black);
				dropDown(lBtnEmployees, index, key, lltc, lsv, lmh);
			}
			else if (index == 2)
			{
				Button(false, "Mon Hoc", lBtnEmployees, sBtnEmployees, ColorCode_Blue, ColorCode_Black);
				Button(true, "Lop TC", lBtnBill, sBtnBill, ColorCode_Blue, ColorCode_Black);
				dropDown(lBtnBill, index, key, lltc, lsv, lmh);
			}
			else if (index == 3)
			{
				Button(false, "Lop TC", lBtnBill, sBtnBill, ColorCode_Blue, ColorCode_Black);
				Button(true, "Bang Diem", lBtnScore, sBtnScore, ColorCode_Blue, ColorCode_Black);
				dropDown(lBtnScore, index, key, lltc, lsv, lmh);
			}
			else if (index == 4)
			{
				Button(false, "Bang Diem", lBtnScore, sBtnScore, ColorCode_Blue, ColorCode_Black);
				Button(true, "Dang Ky", lBtnReg, sBtnReg, ColorCode_Blue, ColorCode_Black);
				dropDown(lBtnReg, index, key, lltc, lsv, lmh);
			}
			else if(index == 5)
			{
				Button(false, "Dang Ky", lBtnReg, sBtnReg, ColorCode_Blue, ColorCode_Black);
				Button(true, "Du Lieu", lBtnData, sBtnData, ColorCode_Blue, ColorCode_Black);
				dropDown(lBtnData, index, key, lltc, lsv, lmh);
			}
		}
		else if (key == key_ESC) // exit
		{
			return false;
		}
		else if (key == key_SPACE) // continue
		{
			return true;
		}
	}
}

void menu_Show()
{
	ListLopTinChi lltc; Initial_LLTC(lltc);
	ListSinhVien lsv = NULL;
	ListMonHoc lmh = NULL;

	SIZE sGird;
	POINT lGird, lShowText, lShowSelect;


	lGird = { 20, 2 };

	lShowText = { lGird.x + 25, lGird.y + 1 };
	lShowSelect = { lGird.x + 12, lGird.y + 7 };
	sGird = { 140, 42 };
	while (true)
	{
		system("cls");
		drawBox(lGird, sGird, "");

		drawText(lShowText);
		if (menu_Select(lShowSelect, lltc, lsv, lmh) == false) // out
		{
			break;
		}
	}
}