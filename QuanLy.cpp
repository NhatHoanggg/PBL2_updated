#include"QuanLy.h"
#include <string>
#include <iomanip>
#include <ctime>
#include <iostream>
#include <fstream>

#pragma warning(disable : 4996)

using namespace std;

quanly::quanly() {

}

quanly::~quanly() {

}

void quanly::getdata() {
	fstream f;
	string tmp;
	f.open("DSPhimHienCo.txt");
	while (!f.eof())
	{
		getline(f, tmp);
		if (!f.eof())
			this->InsertNodeAfter(tmp);
	}
	f.close();
}

string& quanly::operator[](int i) const
{
	return this->findNode(i);
}

void quanly::show(const quanly& q) {

	
}
bool quanly::checkday(string date) {
	time_t theTime = time(NULL);
	struct tm* aTime = localtime(&theTime);
	
	int day = aTime->tm_mday;
	int month = aTime->tm_mon + 1; // Month is 0 – 11, add 1 to get a jan-dec 1-12 concept
	int year = aTime->tm_year + 1900; // Year is # years since 1900

	string s, st;
	int _day, _month, _year;
	st = date.substr(0, date.find("/"));
	_day = atoi(st.c_str());
	st = date.substr(date.find("/") + 1, date.find_last_of("/"));
	_month = atoi(st.c_str());
	st = date.substr(date.find_last_of("/") + 1, date.length());
	_year = atoi(st.c_str());

	if (_year < year)
		return false;
	int dayofmonths[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
		dayofmonths[1] = 29;
	}

	if (_day >= day && _day <= day + 5 && month == _month && day + 5 <= dayofmonths[month - 1]) {
		return true;
	}

	if (_day <= day + 5 - dayofmonths[month - 1] && _month == month + 1) {
		return true;
	}
	if (day + 5 > 31 && month == 12 && _month == 1 && _day <= day + 5 - 31 && year == _year - 1) {
		return true;
	}
	return false;
}

void quanly::ThemPhim(const quanly& q) {
	cin.ignore();

	system("cls");
	cout << "\t\t\t\tTHEM PHIM: " << endl;
	string ma, ten, tgian, theloai;
	
	cout << "\t\t\tNhap phim ban muon them: ";
	getline(cin, ten);

	do {
		cout << "\t\t\tNhap ma phim: ";
		getline(cin, ma);
		if (findData(ma))
			cout << "\t\t\tMa phim da ton tai" << endl;
	}
	while (findData(ma));
	cout << "\t\t\tNhap thoi luong: "; 
	getline(cin, tgian);
	cout << "\t\t\tNhap the loai: ";
	getline(cin, theloai);
	string tmp;
	tmp = ma + "|" + ten + "|" + tgian + "|" + theloai;
	InsertNodeAfter(tmp);
	fstream f;
	f.open("DSPhimHienCo.txt", ios::app);
	f << tmp << endl;
	f.close();
	
}

void quanly::HuyPhim(const quanly& q) {
	cin.ignore();
	system("cls");
	cout << "\t\t\t\tHUY PHIM: " << endl;

	string ma;
	do {

		cout << "\t\t\tNhap ma phim muon huy: ";
		
		getline(cin, ma);
		if (!findData(ma)) {
			cout << "\t\t\tMa phim khong ton tai" << endl;
		}

	} while (!findData(ma));

	DeleteNode(ma);

	ofstream f;
	f.open("DSPhimHienCo.txt");
	f.close();

	fstream g;
	g.open("DSPhimHienCo.txt");
	for (int i = 1; i <= sizeofList(); i++) {
		g << q[i] << endl;
	}
	g.close();
}



void quanly::XemDoanhThu(const quanly& q) {
nhap:
	system("cls");
	cout << "\t\t\t\t\t XEM DOANH THU \n"; 
	cout << "\t\t\t\t Nhap lua chon cua ban : " << endl;
	cout << "\t\t\t\t 1. Xem Doanh thu trong ngay" << endl;
	cout << "\t\t\t\t 2. Xem Doanh thu trong thang " << endl;
	cout << "\t\t\t\t 3. Xem Doanh thu trong quy" << endl;
	cout << "\t\t\t\t 4. Xem Doanh thu trong nam" << endl;
	int selec;
	cout << "\t\t\t\t Nhap lua chon cua ban : "; 
	cin >> selec; 
	if (selec < 0 || selec > 4) {
		cout << "\t\t\t\t Nhap lua chon khong hop le. Vui long nhap lai. " << endl;
		goto nhap;
	}

	switch (selec) {
	case 1:
		XemDoanhThuTrongNgay(q);
		break;
	case 2: 
		XemDoanhThuTrongThang(q);
		break;
	case 3:
		XemDoanhThuTrongQuy(q);
		break;
	case 4:
		XemDoanhThuTrongNam(q);
		break;
	}
} 

void quanly::XemDoanhThuTrongNgay(const quanly&) {
	system("cls");

	time_t theTime = time(NULL);
	struct tm* aTime = localtime(&theTime);
	//cout << date << " ";
	int day = aTime->tm_mday;
	int month = aTime->tm_mon + 1; // Month is 0 – 11, add 1 to get a jan-dec 1-12 concept
	int year = aTime->tm_year + 1900; // Year is # years since 1900
	string st;
	st = to_string(day) + "/" + to_string(month) + "/" + to_string(year);
	cout << "\t\t\t\t DOANH THU TRONG NGAY " << st << endl;

	fstream f;
	string s, s1;
	int value, revenue = 0;
	f.open("DSKhachHang.txt");
	while (!f.eof()) {
		getline(f, s);
		if (!f.eof() && s.find(st) < s.length()) {
			s1 = s.substr(s.find_last_of("|") + 1, s.length());
			value = atoi(s1.c_str());
			revenue += value;
		}
	}
	cout << "\t\t\t\t Doanh thu trong ngay " << st << " : " << revenue << " VND " << endl;

}

void quanly::XemDoanhThuTrongThang(const quanly&) {
	system("cls");

	time_t theTime = time(NULL);
	struct tm* aTime = localtime(&theTime);
	//cout << date << " ";
	int day = aTime->tm_mday;
	int month = aTime->tm_mon + 1; // Month is 0 – 11, add 1 to get a jan-dec 1-12 concept
	int year = aTime->tm_year + 1900; // Year is # years since 1900
	string st;
	st =  to_string(month) + "/" + to_string(year);
	cout << "\t\t\t\t DOANH THU TRONG THANG " << st << endl;

	fstream f;
	string s, s1;
	int value, revenue = 0;
	f.open("DSKhachHang.txt");
	while (!f.eof()) {
		getline(f, s);
		if (!f.eof() && s.find(st) < s.length()) {
			s1 = s.substr(s.find_last_of("|") + 1, s.length());
			value = atoi(s1.c_str());
			revenue += value;
		}
	}
	cout << "\t\t\t\t > Doanh thu trong thang "<< st << " : " << revenue << " VND" << endl;

}

void quanly::XemDoanhThuTrongQuy(const quanly&) {
	system("cls");

	time_t theTime = time(NULL);
	struct tm* aTime = localtime(&theTime);
	//cout << date << " ";
	int day = aTime->tm_mday;
	int month = aTime->tm_mon + 1; // Month is 0 – 11, add 1 to get a jan-dec 1-12 concept
	int year = aTime->tm_year + 1900; // Year is # years since 1900
	string st;
	st = to_string(day) + "/" + to_string(month) + "/" + to_string(year);


	fstream f;
	string s, s1, s2;
	int value, quy1 = 0 , quy2 = 0, quy3 = 0, quy4 = 0 , tmp;
	//string q1, q2, q3, q4;

	f.open("DSKhachHang.txt");
	while (!f.eof()) {
		getline(f, s);
		if (!f.eof()) {
			
			s1 = s.substr(0, s.find("|"));
			s1.erase(0, s1.find("/") + 1);
			s1.erase(s1.find("/"), s1.length());
			tmp = atoi(s1.c_str());
			s2 = s.substr(s.find_last_of("|") + 1, s.length());
			value = atoi(s2.c_str());
			if (tmp <= 3 && tmp >= 1)
				quy1 += value;
			else if (tmp <= 6)
				quy2 += value;
			else if (tmp <= 9)
				quy3 += value;
			else
				quy4 += value;
		}
	}

	cout << "\t\t\t\t Doanh Thu Quy 1 nam " << year << " : " << quy1 << " VND " << endl;
	cout << "\t\t\t\t Doanh Thu Quy 2 nam " << year << " : " << quy2 << " VND " << endl;
	cout << "\t\t\t\t Doanh Thu Quy 3 nam " << year << " : " << quy3 << " VND " << endl;
	cout << "\t\t\t\t Doanh Thu Quy 4 nam " << year << " : " << quy4 << " VND " << endl;
}

void quanly::XemDoanhThuTrongNam(const quanly&) {
	system("cls");

	time_t theTime = time(NULL);
	struct tm* aTime = localtime(&theTime);
	//cout << date << " ";
	int day = aTime->tm_mday;
	int month = aTime->tm_mon + 1; // Month is 0 – 11, add 1 to get a jan-dec 1-12 concept
	int year = aTime->tm_year + 1900; // Year is # years since 1900
	string st;
	st = to_string(year);
	cout << "\t\t\t\t XEM DOANH THU TRONG NAM " << st << endl;

	fstream f;
	string s, s1;
	int value, revenue = 0;
	f.open("DSKhachHang.txt");
	while (!f.eof()) {
		getline(f, s);
		if (!f.eof() && s.find(st) < s.length()) {
			s1 = s.substr(s.find_last_of("|") + 1, s.length());
			value = atoi(s1.c_str());
			revenue += value;
		}
	}
	cout << "\t\t\t\t > Doanh thu trong nam " << year << " la " << revenue << " VND " << endl;
}