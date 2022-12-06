#pragma once
#ifndef QUANLY_H
#define QUANLY_H

#include<iostream>
#include<string>
#include"Linkedlist.h"

using namespace std;

class quanly :public LinkedList {
private:

public:
	quanly();
	~quanly();
	void getdata();
	void show(const quanly&);
	bool checkday(string);
	void ThemSuat(const quanly&);
	void HuySuat(const quanly&);
	void ThemPhim(const quanly&);
	void HuyPhim(const quanly&);
	void XemDsKhachHang(const quanly&);
	void XemDoanhThu(const quanly&);
	string& operator[](int i) const;
};

#endif