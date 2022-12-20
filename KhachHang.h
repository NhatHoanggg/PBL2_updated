#pragma once
#ifndef KHACHHANG_H
#define KHACHHANG_H

#include <string>
#include <ctime>

using namespace std;

class guest {
private:
	string Name, phoneNum , _date;
	int Num;
public:
	guest();
	~guest();
	void get_Num();
	void get_Name();
	void get_PhoneNum();
	void get_date();
	bool checkday(string date);
	void banVe();
	void suaVe();
	void XemDSPhim();
	void XemLichChieuTheoNgay(string date);
	void XemLichChieuTheoPhim();
};

#endif // !KHACHHANG_H
