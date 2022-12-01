#include "KhachHang.h"
#include <string>
#include <iostream>
#include <ctime>
#include <fstream>
#include <iomanip>

#pragma warning(disable : 4996)

using namespace std;
 
guest::guest() {

}

guest::~guest() {

}

void guest::get_Name() {
	cout << "\t\t\t Nhap ho ten khach hang: "; 
	cin.ignore();
	getline(cin, Name);

}

void guest::get_PhoneNum() {
nhap_sdt:

	cout << "\t\t\t\ Nhap so dien thoai: ";
	//cin.ignore();
	getline(cin, phoneNum);
	//cout << " leng == " << phoneNum.length() << " sdt ==  " << phoneNum << endl;
	if (phoneNum.length() != 10 || phoneNum[0] != '0') {
		cout << "\t\t\tNhap so dien thoai khong hop le. vui long nhap lai! " << endl;
		goto nhap_sdt;
	}
		
}



void guest::get_Num() {
	nhap_so_ve:
	cout << "\t\t\t\ Nhap so ve muon mua: ";
	cin >> Num;
	if (Num < 0) {
		cout << "\t\t\tNhap so ve khong hop le. vui long nhap lai! " << endl;
		goto nhap_so_ve;
	}
}

void guest::get_date() {
nhap_ngay:
	string s, tmp;
	cout << "\t\t\t Nhap ngay ma ban muon xem (nhap ngay/thang/nam): ";
	cin.ignore();
	getline(cin, s);

	time_t theTime = time(NULL);
	struct tm* aTime = localtime(&theTime);

	int day = aTime->tm_mday;
	int month = aTime->tm_mon + 1; // Month is 0 – 11, add 1 to get a jan-dec 1-12 concept
	int year = aTime->tm_year + 1900; // Year is # years since 1900
	int hour = aTime->tm_hour;
	//int min = aTime->tm_min;

	int _day, _month, _year;
	tmp = s.substr(0, s.find("/"));

	_day = atoi((tmp.c_str()));

	tmp = s.substr(s.find("/") + 1, s.find_last_of("/"));
	_month = atoi((tmp.c_str()));

	tmp = s.substr(s.find_last_of("/") + 1, s.length());
	_year = atoi((tmp.c_str()));


	if (_day < day || _day > day + 5) {
		cout << "\t\t\tNhap ngay khong hop le. Vui long nhap lai" << endl;
		goto nhap_ngay;
	}
	this->_date = s;
}

void guest::banVe() {
	system("cls");
	get_Name();
	get_PhoneNum();
	get_Num();
	get_date();

	//cout << Name << endl;
	//cout << phoneNum << endl;
	//cout << Num << endl;
	//cout << _date << endl;


}


void guest::XemDSPhim() {
	system("cls");
	fstream f;
	f.open("DSPhimHienCo.txt");
	cout << "\t\t\t\t\t DANH SACH PHIM HIEN CO" << endl;
	cout << "\t\t+=============================================================================================+" << endl;
	string maphim, tenphim, thoiluong, theloai;
	while (!f.eof()) {
		getline(f, maphim, '|');
		getline(f, tenphim, '|');
		getline(f, thoiluong, '|');
		getline(f, theloai);
		if (f.eof())
			break;
		cout << "\t\t| " << setw(5) << left << maphim << "|";
		cout << setw(30) << left << tenphim << "|";
		cout << setw(12) << thoiluong << "  |";
		cout << setw(40) << left << theloai << "|" << endl;
	}
	cout << "\t\t+=============================================================================================+" << endl;

	f.close();
}

string findName(string id) {
	fstream f;
	string tenPhim, maPhim, tmp;
	//bool check = false;
	f.open("DSPhimHienCo.txt");
	while (!f.eof()) {
		getline(f, maPhim, '|');
		getline(f, tenPhim, '|');
		getline(f, tmp);
		if (maPhim == id) {
			return tenPhim;
		}
	}
	f.close();
	return "NOT EXIST!";
}

void guest::XemLichChieuTrongNgay(int date) {
	//system("cls");
	fstream f;
	string str,s;
	int daycheck;

	time_t theTime = time(NULL);
	struct tm* aTime = localtime(&theTime);

	int day = aTime->tm_mday;
	int month = aTime->tm_mon + 1; // Month is 0 – 11, add 1 to get a jan-dec 1-12 concept
	int year = aTime->tm_year + 1900; // Year is # years since 1900
	int hour = aTime->tm_hour;
	int mins = aTime->tm_min;
	cout << "\t\t\t\t\t\t" << day << " / " << month << " / " << year << " | " << " Time: " << hour <<":" <<mins<<  endl;
	cout << "\t\t\t\t\t DANH SACH LICH CHIEU TRONG NGAY : " << date << day << " / " << month << " / " << year << endl;
	cout << "\t\t+==============================================================================+" << endl;
	cout << "\t\t| Ma Phim |" << setw(15) << "Ten Phim" << setw(30) << "| Gio Bat Dau |" << " Rap So | So Ghe Trong |" << endl;
	cout << "\t\t+==============================================================================+" << endl;

	for (int i = 1; i <= 4; i++) {
		f.open("rap" + to_string(i) + ".txt");
		while (!f.eof()) {
			getline(f, s);
			str = s.substr(0, s.find("|"));    
			daycheck = atoi((str.c_str()));
			if (!f.eof() && daycheck == date) {
				string s1, s2;
				int last1, last2, count = 0;
				s.erase(0, s.find("|") + 1); // xoa date;
				s1 = s.substr(0, s.find("|")); // s1 = ma phim 
				//cout << "\t\t\t" << s << endl;// ngay - ma phim - gio ... -> ma phim - ten phim - gio - rap

				last1 = s.find_last_of("|");
				for (int j = last1 + 1; j <= s.length(); j++) {
					if (s[j] == '0')
						count++;
				}
				s.erase(last1, s.length());

				last2 = s.find_last_of("|");
				s2 = s.substr(last2 + 1, s.length()); // s2 = gio bat dau

				// tim ten phim findName(s1)

				//cout <<"\t\t\t" << s1 << " "  << findName(s1) << " " << s2 << " " << i << " " << count << endl;
				cout << "\t\t|" << setw(6) << s1 << setw(4) << "|";
				cout << setw(30) << left << findName(s1) << "|";
				cout << setw(7) << right << s2 << setw(7) << "|";
				cout << setw(5) << i << setw(4) << "|";
				cout << setw(10) << count << setw(5) << "|" << endl;

			}

		}
		f.close();

	}
	cout << "\t\t+==============================================================================+" << endl;

}
void guest::update() {
	fstream f;
	f.open("DSKhachHang.txt", ios::app); // ghi tiep vao file 
	system("pause");
	f.close();
}