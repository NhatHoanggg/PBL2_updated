#include "KhachHang.h"
#include <string>
#include <iostream>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <vector>

#pragma warning(disable : 4996)

using namespace std;
 
string findName(string id) {
	fstream f;
	string tenPhim, maPhim, tmp;
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

guest::guest() {

}

guest::~guest() {

}

void guest::get_Name() {
	cout << "\t\t\tNhap ho ten khach hang: "; 
	cin.ignore();
	getline(cin, Name);

}

void guest::get_PhoneNum() {
nhap_sdt:

	cout << "\t\t\tNhap so dien thoai: ";

	getline(cin, phoneNum);

	if (phoneNum.length() != 10 || phoneNum[0] != '0') {
		cout << "\t\t\tNhap so dien thoai khong hop le. vui long nhap lai! " << endl;
		goto nhap_sdt;
	}
		
}



void guest::get_Num() {
	nhap_so_ve:
	cout << "\t\t\t\Nhap so ve muon mua: ";
	cin >> Num;
	if (Num < 0) {
		cout << "\t\t\tNhap so ve khong hop le. vui long nhap lai! " << endl;
		goto nhap_so_ve;
	}
}

bool guest::checkday(string date) {
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


void guest::get_date() {
nhap_ngay:
	string s, tmp;
	cout << "\t\t\tNhap ngay ma ban muon xem (nhap ngay/thang/nam): ";
	//cin.ignore();
	fflush(stdin);
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

	tmp = s.substr(0, s.find("|"));

	if (!checkday(s)) {
		cout << "\t\t\tNhap ngay khong hop le. Vui long nhap lai" << endl;
		goto nhap_ngay;
	}
	this->_date = s;
}


void guest::XemDSPhim() {
	system("cls");
	fstream f;
	f.open("DSPhimHienCo.txt");
	cout << "\t\t\t\t\t DANH SACH PHIM HIEN CO" << endl;
	cout << "\t\t+=============================================================================================+" << endl;
	cout << "\t\t|  Ma  |         Ten Phim             |  Thoi Luong  |             The Loai                   |" << endl;
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



void guest::XemLichChieuTheoNgay(string date) {
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
	cout << "\t\t\t\t\t\t TODAY:" << day << " / " << month << " / " << year << " | " << " Time: " << hour <<":" <<mins <<endl;
	cout << "\t\t\t\t\t DANH SACH LICH CHIEU TRONG NGAY : " << date << endl;
	cout << "\t\t+==============================================================================+" << endl;
	cout << "\t\t| Ma Phim |" << setw(15) << "Ten Phim" << setw(30) << "| Gio Bat Dau |" << " Rap So | So Ghe Trong |" << endl;
	cout << "\t\t+==============================================================================+" << endl;

	for (int i = 1; i <= 4; i++) {
		f.open("rap" + to_string(i) + ".txt");
		while (!f.eof()) {
			getline(f, s);

			str = s.substr(0, s.find("|"));    
			daycheck = atoi((str.c_str()));

			if (!f.eof() && str == date) {
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

void guest::XemLichChieuTheoPhim() {
	nhap:
	XemDSPhim();
	cout << "\n\t\t\t - Nhap ma phim ban muon xem lich: ";
	string maPhim;
	cin >> maPhim;
	//getline(cin,maPhim);
	//cout << findName(maPhim) << endl;
	if (findName(maPhim) == "NOT EXIST!") {
		cout << "\t\t\t - Ma phim khong ton tai hoac khong hop le. Vui long nhap lai!" << endl;
		system("pause");
		goto nhap;
	}
	string s, today;
	time_t theTime = time(NULL);
	struct tm* aTime = localtime(&theTime);

	int day = aTime->tm_mday;
	int month = aTime->tm_mon + 1; // Month is 0 – 11, add 1 to get a jan-dec 1-12 concept
	int year = aTime->tm_year + 1900; // Year is # years since 1900
	int hour = aTime->tm_hour;
	int mins = aTime->tm_min;
	today = to_string(day) + "/" + to_string(month) + "/" + to_string(year);
	system("cls");
	cout << "\n\t\t\t\t TODAY :  " << today << "|  TIME: " << hour << ":" << mins << endl << endl;
	cout << "\n\t\t\t LICH CHIEU PHIM: " << findName(maPhim) << endl << endl;
	cout << "\t\t+================================================+" << endl;
	cout << "\t\t| Ngay chieu | Gio Chieu | Rap so | So ghe trong |" << endl;
	cout << "\t\t+================================================+" << endl;

	fstream f;
	
	for (int i = 1; i <= 4; i++) {
		f.open("rap" + to_string(i) + ".txt");
		
		while (!f.eof()) {
			getline(f, s);
			string s1, s2, s3;
			int count = 0;
			s1 = s.substr(0, s.find("|")); // s1 : ngay chieu 
			s.erase(0, s.find("|") + 1);
			s2 = s.substr(0, s.find("|")); // s2 : ma phim
			s.erase(0, s.find("|") + 1);
			s3 = s.substr(0, s.find("|")); // s3 : gio chieu 
			s.erase(0, s.find("|") + 1);
			for (int j = 0; j <= s.length(); j++) {
				if (s[j] == '0') {
					count++;  // dem ghe trong 
				}
			}
			if (!f.eof() && maPhim == s2 && checkday(s1)) {
				cout << "\t\t|" << setw(11) << right << s1 << setw(2) << "|";
				cout << setw(7) << s3 << setw(5) << "|" ;
				cout << setw(5) << i << setw(4) << "|" ;
				cout << setw(8) << count << setw(7) << "|" << endl;
			}
		}
		f.close();
	}
	cout << "\t\t+================================================+" << endl << endl ;

}


void guest::banVe() {
	system("cls");
	cout << "\t\t\t NHAP THONG TIN KHACH HANG : " << endl << endl;
	get_Name();
	get_PhoneNum();
	//get_Num();
	get_date();

	//cout << Name << endl;
	//cout << phoneNum << endl;
	//cout << Num << endl;
	//cout << _date << endl;
	system("cls");
	XemLichChieuTheoNgay(_date);
	string maPhim, suat;
	cout << "\t\t\tNhap ma phim ban muon xem: ";
nhap_phim:
	getline(cin, maPhim);
	if (findName(maPhim) == "NOT EXIST!") {
		cout << "\t\t\tMa phim khong hop le hoac khong ton tai. Vui long nhap lai! " << endl;
		goto nhap_phim;
	}
	//cout << "\t\t\tNhap suat ma ban muon xem: ";
	//getline(cin, suat);
	fstream f;
	string s, today;
	time_t theTime = time(NULL);
	struct tm* aTime = localtime(&theTime);

	int day = aTime->tm_mday;
	int month = aTime->tm_mon + 1; // Month is 0 – 11, add 1 to get a jan-dec 1-12 concept
	int year = aTime->tm_year + 1900; // Year is # years since 1900
	int hour = aTime->tm_hour;
	int mins = aTime->tm_min;
	today = to_string(day) + "/" + to_string(month) + "/" + to_string(year);
	
	system("cls");
	cout << "\n\t\t\t\t TODAY :  " << today << "|  TIME: " << hour << ":" << mins << endl << endl;
	cout << "\n\t\t\t\t LICH CHIEU PHIM: " << findName(maPhim) << endl << endl;
	cout << "\t\t\t+===================================+" << endl;
	cout << "\t\t\t| Gio Chieu | Rap so | So ghe trong |" << endl;
	cout << "\t\t\t+===================================+" << endl;

	vector<string> ds;

	bool ktra = false;
	int d = 0;
	for (int i = 1; i <= 4; i++) {
		f.open("rap" + to_string(i) + ".txt");
		while (!f.eof()) {
			getline(f, s);
			string s1, s2, s3, tmp;
			int count = 0;
			s1 = s.substr(0, s.find("|")); // s1 : ngay chieu 
			s.erase(0, s.find("|") + 1);
			s2 = s.substr(0, s.find("|")); // s2 : ma phim
			s.erase(0, s.find("|") + 1);
			s3 = s.substr(0, s.find("|")); // s3 : gio chieu 
			s.erase(0, s.find("|") + 1);
			for (int j = 0; j <= s.length(); j++) 
				if (s[j] == '0')
					count++;  // dem ghe trong 
			if (!f.eof() && _date == s1 && s2 == maPhim) { 
				tmp = s3 + "|" + to_string(i) + "|" + to_string(count) +  "|" + s;
				ds.push_back(tmp);
				//cout << s3 <<" " << i << " " << count << endl;
				cout <<"\t\t\t|" << setw(7) << s3 << setw(5) << "|";
				cout << setw(5) << i << setw(4) << "|";
				cout << setw(8) << count << setw(7) << "|" << endl;
				ktra = true;
				d++;
				}
			}
		f.close();
	}
	cout << "\t\t\t+===================================+" << endl;
	if (!ktra) {
		int selec = 0;
		cout << "\t\t\tNgay " << _date << " khong ton tai suat chieu nao cho phim " << findName(maPhim) << endl;
		cout << "\t\t\tNhap lua chon cua ban:" << endl;
		cout << "\t\t\t - 1: Nhap lai phim khac" << endl;
		cout << "\t\t\t - 2: Thoat chuong trinh" << endl;
		cin >> selec;
		switch (selec) {
		case 1:
			goto nhap_phim;
			break;
		case 2:
			exit;
		}
	}
nhap_suat_xem:
	bool kt = false;
	int vt, key;
	string s1, s2, s3;
	cout << "\t\t\tNhap suat xem: "; 
	getline(cin, suat);
	for (int i = 0; i < ds.size(); i++) {
		//suat - rap - cho
		s1 = ds[i].substr(0, ds[i].find("|"));
		ds[i].erase(0, ds[i].find("|") + 1);
		s2 = ds[i].substr(0, ds[i].find("|"));
		ds[i].erase(0, ds[i].find("|") + 1);
		s3 = ds[i].substr(0, ds[i].find("|"));
		ds[i].erase(0, ds[i].find("|") + 1);
		vt = atoi(s3.c_str());
		if (s1 == suat) {
			kt = true;
			key = i;
			break;
		}
	}
	
	if (!kt) { 
		cout << "\t\t\tSuat xem khong hop le. Vui long nhap lai." << endl;
		goto nhap_suat_xem;
	}
	if (vt == 0) {
		cout << "\t\t\tSuat nay khong con ghe trong. Vui long chon suat khac" << endl;
		goto nhap_suat_xem;
	}
nhap_so_ve:
	
	get_Num();
	if (Num > vt) {
		cout << "\t\t\tSo ve lon hon hon so ghe trong. Vui long nhap lai hoac chon suat xem khac." << endl;
		cout << "\t\t\t->Nhap lai? [c/k]"; 
		char selec;
		cin >> selec;
		selec = toupper(selec);
		if (selec == 'C')
			goto nhap_so_ve;
		else
			goto nhap_suat_xem;
	}

	int index = 0;
	vector <string> pos;
show:
	system("cls");
	cout << "\t\t\t\t RAP SO " << s2 << " / SUAT CHIEU : " << s1 <<  endl << endl;
	cout << "\t\t\t" << setw(5) <<" ";
	for (int i = 0; i < 10; i++)
		//cout << setw(5) << char(65+i);
		cout << setw(5) << i + 1; 
	cout << endl;
	cout << "\t\t\t" << setw(8) << "---------------------------------------------------------" << endl;
	for (int i = 0; i < 10; i++) {
		//cout << "\t\t\t" << setw(2) << i+1 << "|";
		cout << "\t\t\t" << setw(3) << char(i + 65)<< " |";
		for (int j = 0; j < 10; j++)
			cout << setw(5) << ds[key][i * 10 + j];
		cout << endl;
	}
	cout << "\t\t\t\t\t\t\t * Gia ve: 50.000 VND." << endl;
	cout << endl;
	string str, ch, numbers;
	ch = "ABCDEFGHIJ";
	numbers = "12345678910";
	//int i = 0;
	while (index < Num){
		nhap_vi_tri:
		int vti, vtj;
		cout << "\t\t\tNhap vi tri nguoi thu " << index+1 << " : "; 
		cin >> str;
		str[0] = toupper(str[0]);
		vti = ch.find(str[0]);
		vtj = numbers.find(str[1]);
		if (str.length() == 3)
			vtj = 9;
		if (ds[key][vti * 10 + vtj] == '1') {
			cout << "\t\t\tCho nay da co nguoi ngoi. Vui long chon cho khac! " << endl;
			goto nhap_vi_tri;
		}
		ds[key][vti * 10 + vtj] = '1';
		index++;
		pos.push_back(str);
		goto show;
	}
	// XUAT HOA DON -> LUU GIA TRI;

	system("cls");
	cout << "\t\t\t+------------------------------------------------+" << endl;
	cout << "\t\t\t|            HOA DON MUA VE XEM PHIM             |" << endl;
	cout << "\t\t\t+------------------------------------------------+" << endl;
	cout << "\t\t\t|" << setw(15) << "Khach Hang: " << setw(30) << Name << setw(4) << "|" << endl;
	cout << "\t\t\t|" << setw(3) << " " << setw(15) << "So Dien Thoai: " << setw(27) << phoneNum << setw(4) << "|" << endl;
	cout << "\t\t\t|" << setw(3) << " " << setw(10) << "Ngay Xem: " << setw(32) << _date << setw(4) << "|" << endl;
	cout << "\t\t\t|" << setw(3) << " " << setw(10) << "Ten Phim: " << setw(32) << findName(maPhim) << setw(4) << "|" << endl;
	cout << "\t\t\t|" << setw(3) << " " << setw(10) << "Suat Xem: " << setw(32) << suat << setw(4) << "|" << endl;
	cout << "\t\t\t|" << setw(3) << " " << setw(10) << "So Ve Mua: " << setw(31) << Num << setw(4) << "|" << endl;
	cout << "\t\t\t|" << setw(3) << " " << "Danh Sach Vi Tri Da Chon: " << setw(20) << "|" << endl;

	for (int i = 0; i < Num; i++) {
		cout << "\t\t\t|\t\t" << " - Vi tri thu " << i + 1 << ": " << setw(10) << pos[i] << setw(7) << "|" << endl;
	}

	cout << "\t\t\t|\t" << "- THANH TIEN : " << setw(12) << Num * 50000 << "VND" << setw(12) << "|" << endl;
	cout << "\t\t\t|" << setw(3) << " " << "Hoa don xuat luc " << setw(2) << hour << ":" << setw(2) << mins;
	cout << setw(7) << "Ngay " << setw(2) << day << " / " << month << " / " << year << setw(3) << "|" << endl;
	cout << "\t\t\t+------------------------------------------------+" << endl;

	// luu thong tin khach hang vao file ; 
	//fstream f;
	f.open("DSKhachHang.txt",ios :: app);
	// ten|sdt|ngayxem|maphim|sove|vitri...|Thanh tien
	f << _date <<"|" << Name << "|" << phoneNum << "|" << maPhim << "|" << Num << "|";
	for (int i = 0; i < Num; i++)
		f << pos[i] << "|";
	f << Num * 50000  << endl;
	f.close();
	//cap nhat du lieu rap chieu 
	//ngay - ma - gio - vitri 
	string info;
	info = _date + "|" + maPhim + "|" + suat + "|";
	vector <string> list;
	string tmp;
	f.open("rap" + s2 + ".txt");
	while (!f.eof()) {
		getline(f, tmp);
		if (tmp.find(info) == 0) {
			info = info + ds[key];
			tmp = info;
		}
		if (!f.eof())
			list.push_back(tmp);
	}

	ofstream g;
	g.open("rap" + s2 + ".txt");
	for (int i = 0; i < list.size(); i++) {
		g << list[i] << endl;
	}
	g.close();
	
}


void guest::update() {
	fstream f;
	f.open("DSKhachHang.txt", ios::app); // ghi tiep vao file 
	system("pause");
	f.close();
}

