#include<iostream>
#include "LopTinChi.h"




int main()
{
	LTC_Initial();

	ListLopTinChi lltc;

	LTC_Nhap(lltc);

	LTC_Them(lltc);

	LTC_Xuat(lltc);

	system("pause");
	return 0;
}