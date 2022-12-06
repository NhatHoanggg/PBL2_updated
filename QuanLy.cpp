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
	for (int i = 1; i <= 4; i++) {
		f.open("rap" + to_string(i) + ".txt");
		while (!f.eof()) {
			getline(f, tmp);
			if (!f.eof()) {
				this->InsertNodeAfter(tmp);
			}

		}
		f.close();
	}
}

string& quanly::operator[](int i) const
{
	return this->findNode(i);
}

void quanly::show(const quanly& q) {
	//this->printList();
	//cout << this->sizeofList();
	for (int i = 1; i < this->sizeofList() + 1; i++) {
		//cout << this->findNode(i+1) << endl;
		q[i] = to_string(i);
		cout << q[i] << endl;
	}
}
bool quanly::checkday(string date) {
	time_t theTime = time(NULL);
	struct tm* aTime = localtime(&theTime);
	//cout << date << " ";
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
	return false;
}

void quanly::ThemSuat(const quanly& q) {
	cin.ignore();
nhap_ngay:
	system("cls");
	cout << "\t\t\t\tTHEM SUAT CHIEU: " << endl;
	cout << "\t\t\tNhap ngay ban muon them suat chieu: ";
	string ngay, suat, phim, tmp;

	getline(cin, ngay);

	if (!checkday(ngay)) {
		cout << "\t\t\tNgay nhap khong hop le. Vui long nhap lai." << endl;
		goto nhap_ngay;
	}

	cout << "\t\t\tNhap suat chieu: ";
	getline(cin, suat);

	cout << "\t\t\tNhap ma phim: ";
	getline(cin, phim);
	string end = "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
	tmp = ngay + "|" + phim + "|" + suat + "|" + end;

	if (findData(tmp)) {
		cout << "Suat da ton tai . Vui long nhap lai." << endl;
		system("pause");
		goto nhap_ngay;
	}
	InsertNode(tmp);
}

void quanly::HuySuat(const quanly& q) {
	cin.ignore();
nhap_ngay:
	system("cls");
	cout << "\t\t\t\tHUY SUAT CHIEU: " << endl;
	cout << "\t\t\tNhap ngay ban muon them suat chieu: ";
	string ngay, suat, phim, tmp;

	getline(cin, ngay);

	if (!checkday(ngay)) {
		cout << "\t\t\tNgay nhap khong hop le. Vui long nhap lai." << endl;
		goto nhap_ngay;
	}

	cout << "\t\t\tNhap suat chieu: ";
	getline(cin, suat);

	cout << "\t\t\tNhap ma phim: ";
	getline(cin, phim);
	string end = "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
	tmp = ngay + "|" + phim + "|" + suat + "|" + end;

	if (!findData(tmp)) {
		cout << "Suat chieu khong ton tai . Vui long nhap lai." << endl;
		system("pause");
		goto nhap_ngay;
	}
	DeleteNode(tmp);
}

void quanly::ThemPhim(const quanly& q) {

}

void quanly::HuyPhim(const quanly& q) {

}

void quanly::XemDsKhachHang(const quanly& q) {

}

void quanly::XemDoanhThu(const quanly& q) {

}
