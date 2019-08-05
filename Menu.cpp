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
	if (index == 0) // material
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

		Button(true, "Xem Vat Tu", lBtnShowList, sBtnShowList, ColorCode_Blue, ColorCode_Black);
		Button(false, "Them", lBtnAdd, sBtnAdd, ColorCode_Blue, ColorCode_Black);
		Button(false, "Xoa", lBtnDel, sBtnDel, ColorCode_Blue, ColorCode_Black);
		Button(false, "Sua", lBtnEdit, sBtnDel, ColorCode_Blue, ColorCode_Black);

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
							Button(false, "Sua", lBtnEdit, sBtnDel, ColorCode_Blue, ColorCode_Black);
							Button(true, "Xem Vat Tu", lBtnShowList, sBtnShowList, ColorCode_Blue, ColorCode_Black);
						}
						else if (index == 1)
						{
							Button(false, "Xem Vat Tu", lBtnShowList, sBtnShowList, ColorCode_Blue, ColorCode_Black);
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
							Button(true, "Sua", lBtnEdit, sBtnDel, ColorCode_Blue, ColorCode_Black);
						}
					}
					else if (key == dir_UP)
					{
						index--;
						if (index < 0)
						{
							index = maxBTN - 1;
							Button(false, "Xem Vat Tu", lBtnShowList, sBtnShowList, ColorCode_Blue, ColorCode_Black);
							Button(true, "Sua", lBtnEdit, sBtnDel, ColorCode_Blue, ColorCode_Black);
						}
						else if (index == 2)
						{
							Button(true, "Xoa", lBtnDel, sBtnDel, ColorCode_Blue, ColorCode_Black);
							Button(false, "Sua", lBtnEdit, sBtnDel, ColorCode_Blue, ColorCode_Black);
						}
						else if (index == 1)
						{
							Button(true, "Them", lBtnAdd, sBtnAdd, ColorCode_Blue, ColorCode_Black);
							Button(false, "Xoa", lBtnDel, sBtnDel, ColorCode_Blue, ColorCode_Black);
						}
						else if (index == 0)
						{
							Button(true, "Xem Vat Tu", lBtnShowList, sBtnShowList, ColorCode_Blue, ColorCode_Black);
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
							//material_Show(lm, lcGird, 0);

							dir = key_SPACE;
							break;
						}
						else if (index == 1) // add
						{
							system("cls");
							//materials_Add(lm);

							dir = key_SPACE;
							break;
						}
						else if (index == 2) // remove
						{
							system("cls");
							//materials_Remove(lm);

							dir = key_SPACE;
							break;
						}
						else if (index == 3) // edit
						{
							system("cls");
							//materials_Edit(lm);

							dir = key_SPACE;
							break;
						}
					}
				}
			}
		}
	}
	else if (index == 1) // employees
	{
		SIZE sBtnEdit, sBtnView, sClear;
		POINT lBtnEdit, lBtnView, lClear;
		int space = 0;

		sBtnEdit = sBtnView = { 15, 5 };
		lBtnEdit = { lcBtnHead.x, lcBtnHead.y + 5 + space };
		lBtnView = { lcBtnHead.x, lBtnEdit.y + sBtnEdit.cy + space };
		lClear = { lcBtnHead.x, lcBtnHead.y + 5 };
		sClear = { sBtnView.cx, (lBtnView.y + sBtnView.cy) - lClear.y };


		Button(true, "Sua", lBtnEdit, sBtnEdit, ColorCode_Blue, ColorCode_Black);
		Button(false, "Xem", lBtnView, sBtnView, ColorCode_Blue, ColorCode_Black);

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
							Button(false, "Xem", lBtnView, sBtnView, ColorCode_Blue, ColorCode_Black);
							Button(true, "Sua", lBtnEdit, sBtnEdit, ColorCode_Blue, ColorCode_Black);
						}
						else if (index == 1)
						{
							Button(true, "Xem", lBtnView, sBtnView, ColorCode_Blue, ColorCode_Black);
							Button(false, "Sua", lBtnEdit, sBtnEdit, ColorCode_Blue, ColorCode_Black);
						}
					}
					else if (key == dir_UP)
					{
						index--;
						if (index < 0)
						{
							index = maxBTN - 1;
							Button(false, "Sua", lBtnEdit, sBtnEdit, ColorCode_Blue, ColorCode_Black);
							Button(true, "Xem", lBtnView, sBtnView, ColorCode_Blue, ColorCode_Black);
						}
						else if (index == 0)
						{
							Button(true, "Sua", lBtnEdit, sBtnEdit, ColorCode_Blue, ColorCode_Black);
							Button(false, "Xem", lBtnView, sBtnView, ColorCode_Blue, ColorCode_Black);
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
						if (index == 0) //edit
						{
							system("cls");
							//employees_Edit(le, lcGird);

							dir = key_SPACE;
							break;
						}
						else if (index == 1) // view
						{
							system("cls");
							//employees_Show(le, lm, lcGird);

							dir = key_SPACE;
							break;
						}
					}
				}
			}
		}
	}
	else if (index == 2) // bill
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

		Button(true, "Tao Hoa Don", lCreate, sCreate, ColorCode_Blue, ColorCode_Black);
		Button(false, "Xem", lShow, sShow, ColorCode_Blue, ColorCode_Black);
		Button(false, "Xem Theo Ngay", lShowByDay, sShowByDay, ColorCode_Blue, ColorCode_Black);
		Button(false, "10 Ngay", lTenDay, sTenDay, ColorCode_Blue, ColorCode_Black);

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
							Button(true, "Tao Hoa Don", lCreate, sCreate, ColorCode_Blue, ColorCode_Black);
							Button(false, "10 Ngay", lTenDay, sTenDay, ColorCode_Blue, ColorCode_Black);
						}
						else if (index == 1)
						{
							Button(false, "Tao Hoa Don", lCreate, sCreate, ColorCode_Blue, ColorCode_Black);
							Button(true, "Xem", lShow, sShow, ColorCode_Blue, ColorCode_Black);
						}
						else if (index == 2)
						{
							Button(false, "Xem", lShow, sShow, ColorCode_Blue, ColorCode_Black);
							Button(true, "Xem Theo Ngay", lShowByDay, sShowByDay, ColorCode_Blue, ColorCode_Black);
						}
						else if (index == 3)
						{
							Button(false, "Xem Theo Ngay", lShowByDay, sShowByDay, ColorCode_Blue, ColorCode_Black);
							Button(true, "10 Ngay", lTenDay, sTenDay, ColorCode_Blue, ColorCode_Black);
						}
					}
					else if (key == dir_UP)
					{
						index--;
						if (index < 0)
						{
							index = maxBTN - 1;
							Button(false, "Tao Hoa Don", lCreate, sCreate, ColorCode_Blue, ColorCode_Black);
							Button(true, "10 Ngay", lTenDay, sTenDay, ColorCode_Blue, ColorCode_Black);
						}
						else if (index == 2)
						{
							Button(false, "10 Ngay", lTenDay, sTenDay, ColorCode_Blue, ColorCode_Black);
							Button(true, "Xem Theo Ngay", lShowByDay, sShowByDay, ColorCode_Blue, ColorCode_Black);
						}
						else if (index == 1)
						{
							Button(true, "Xem", lShow, sShow, ColorCode_Blue, ColorCode_Black);
							Button(false, "Xem Theo Ngay", lShowByDay, sShowByDay, ColorCode_Blue, ColorCode_Black);
						}
						else if (index == 0)
						{
							Button(true, "Tao Hoa Don", lCreate, sCreate, ColorCode_Blue, ColorCode_Black);
							Button(false, "Xem", lShow, sShow, ColorCode_Blue, ColorCode_Black);
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
						if (index == 0) // create
						{
							system("cls");
							//bill_buildBill(lb, le, lm);

							dir = key_SPACE;
							break;
						}
						else if (index == 1) // show
						{
							system("cls");
							//bill_Show(lb, lm, lcGird);

							dir = key_SPACE;
							break;
						}
						else if (index == 2) // show by day
						{
							system("cls");
							//bill_ShowByDate(lb, le, lm);

							dir = key_SPACE;
							break;
						}
						else if (index == 3) // ten day
						{
							system("cls");
							//material_showHeightRevenue(lb, lm);

							dir = key_SPACE;
							break;
						}
					}
				}
			}
		}

	}
	else if (index == 3)//data
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
							/*if (messagebox("Ban co muon luu du lieu khong?", YES_NO, POINT()))
							{
								database_SaveMaterial(lm);
								database_SaveEmployees(le);
								database_SaveBill(lb);
								system("cls");
								messagebox("Da luu du lieu thanh cong.", YES, POINT());
							}*/

							dir = key_SPACE;
							break;
						}
						else if (index == 1) // load
						{
							system("cls");

							//database_LoadData(lm, le, lb);

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
	SIZE sBtnEmployees, sBtnMaterial, sBtnBill, sBtnData, sGird;
	POINT lBtnEmployees, lBtnMaterial, lBtnBill, lBtnData;
	int space = 5;

	sBtnEmployees = sBtnMaterial = sBtnBill = sBtnData = { 15, 5 };
	sGird = { sBtnEmployees.cx * 3 + space * 2, 40 };
	lBtnMaterial = { lcDisplay.x + 3, lcDisplay.y + 8 };
	lBtnEmployees = { lBtnMaterial.x + sBtnMaterial.cx + space, lBtnMaterial.y };
	lBtnBill = { lBtnEmployees.x + sBtnEmployees.cx + space, lBtnMaterial.y };
	lBtnData = { lBtnBill.x + sBtnBill.cx + space, lBtnMaterial.y };

	Button(true, "Vat Tu", lBtnMaterial, sBtnMaterial, ColorCode_Blue, ColorCode_Black);
	Button(false, "Nhan Vien", lBtnEmployees, sBtnEmployees, ColorCode_Blue, ColorCode_Black);
	Button(false, "Hoa Don", lBtnBill, sBtnBill, ColorCode_Blue, ColorCode_Black);
	Button(false, "Du Lieu", lBtnData, sBtnData, ColorCode_Blue, ColorCode_Black);

	int maxBTN = 4;
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
				Button(true, "Vat Tu", lBtnMaterial, sBtnMaterial, ColorCode_Blue, ColorCode_Black);
				Button(false, "Nhan Vien", lBtnEmployees, sBtnEmployees, ColorCode_Blue, ColorCode_Black);
				dropDown(lBtnMaterial, index, key, lltc, lsv, lmh);
			}
			else if (index == 1)
			{
				Button(true, "Nhan Vien", lBtnEmployees, sBtnEmployees, ColorCode_Blue, ColorCode_Black);
				Button(false, "Hoa Don", lBtnBill, sBtnBill, ColorCode_Blue, ColorCode_Black);
				dropDown(lBtnEmployees, index, key, lltc, lsv, lmh);
			}
			else if (index == 2)
			{
				Button(true, "Hoa Don", lBtnBill, sBtnBill, ColorCode_Blue, ColorCode_Black);
				Button(false, "Du Lieu", lBtnData, sBtnData, ColorCode_Blue, ColorCode_Black);
				dropDown(lBtnBill, index, key, lltc, lsv, lmh);
			}
			else if (index == 3)
			{
				Button(false, "Vat Tu", lBtnMaterial, sBtnMaterial, ColorCode_Blue, ColorCode_Black);
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
				Button(true, "Vat Tu", lBtnMaterial, sBtnMaterial, ColorCode_Blue, ColorCode_Black);
				Button(false, "Du Lieu", lBtnData, sBtnData, ColorCode_Blue, ColorCode_Black);
				dropDown(lBtnMaterial, index, key, lltc, lsv, lmh);
			}
			else if (index == 1)
			{
				Button(false, "Vat Tu", lBtnMaterial, sBtnMaterial, ColorCode_Blue, ColorCode_Black);
				Button(true, "Nhan Vien", lBtnEmployees, sBtnEmployees, ColorCode_Blue, ColorCode_Black);
				dropDown(lBtnEmployees, index, key, lltc, lsv, lmh);
			}
			else if (index == 2)
			{
				Button(false, "Nhan Vien", lBtnEmployees, sBtnEmployees, ColorCode_Blue, ColorCode_Black);
				Button(true, "Hoa Don", lBtnBill, sBtnBill, ColorCode_Blue, ColorCode_Black);
				dropDown(lBtnBill, index, key, lltc, lsv, lmh);
			}
			else if (index == 3)
			{
				Button(false, "Hoa Don", lBtnBill, sBtnBill, ColorCode_Blue, ColorCode_Black);
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

	lShowText = { lGird.x + 13, lGird.y + 1 };
	lShowSelect = { lGird.x + 12, lGird.y + 7 };
	sGird = { 110, 42 };
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