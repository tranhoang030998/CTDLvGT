#pragma once
//danh sach dang ky
struct DangKy {
	char MASV[13];
	float DIEM;
};
struct  ListDangKy {
	DangKy dangky;
	struct ListDangKy* next;
};

