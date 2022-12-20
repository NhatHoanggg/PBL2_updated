#include <iostream>
#include <fstream>
#include "KhachHang.h"
#include "QuanLy.h"
#include <iostream>
using namespace std;

void QLbanve() {
nhap_lua_chon:
	system("cls");
	cout << "\t\t\t\t\tBAN VE" << endl << endl;
	cout << "\t\t\t 1. Xem danh sach phim hien co " << endl;
	cout << "\t\t\t 2. Xem lich chieu theo ngay " << endl;
	cout << "\t\t\t 3. Xem danh sach lich chieu theo phim " << endl;
	cout << "\t\t\t 4. Mua ve xem phim" << endl;
	cout << "\t\t\t 5. Sua ve xem phim" << endl;
	cout << "\t\t\t 0. Thoat " << endl;
	int selection;
	cout << "\t\t\t\t -> Nhap lua chon cua ban: ";
	cin >> selection;
	if (selection > 5 || selection < 0) {
		cout << "\t\t\t Nhap lua chon khong hop le. Vui long nhap lai!"; 
		system("pause"); 
		goto nhap_lua_chon;
	}

	guest g;
	string date;

	switch (selection) {
	case 1:
		g.XemDSPhim();
		break;
	case 2:
		nhap_ngay_mua_ve:
		system("cls");
		cout << "\t\t\t\tXEM LICH CHIEU THEO NGAY: " << endl << endl;
		cout << "\t\t\tNhap ngay ma ban muon xem lich chieu: ";
		cin >> date;
		// ktra ngay <= today + 5
		if (!g.checkday(date))
		{
			cout << "\t\t\tNhap ngay khong hop le. vui long nhap lai" << endl;
			system("pause");
			goto nhap_ngay_mua_ve;
		}
		g.XemLichChieuTheoNgay(date);
		break;
	case 3:
		g.XemLichChieuTheoPhim();
		break;
	case 4:
		g.banVe();
		break;
	case 5:
		g.suaVe();
		break;
	}

}


void QLrapphim() {
nhap_lua_chon:
	system("cls");
	quanly q;
	q.getdata();
	cout << "\t\t\t\t QUAN LY" << endl << endl;
	cout << "\t\t\t 1. Them suat chieu" << endl;
	cout << "\t\t\t 2. Huy suat chieu" << endl;
	cout << "\t\t\t 3. Xem doanh thu " << endl;
	cout << "\t\t\t 0. Thoat " << endl;
	int selection;
	cout << "\t\t\t\t -> Nhap lua chon cua ban: ";
	cin >> selection;
	if (selection > 3 || selection < 0) {
		cout << "\t\t\t Lua chon khong hop le. Vui long nhap lai! ";
		goto nhap_lua_chon;
	}
	switch (selection) {
	case 1:
		q.ThemSuat(q);
		break;
	case 2:
		q.HuySuat(q);
		break;
	case 3:
		q.XemDoanhThu(q);
		break;
	}
}


void thoatCT() {
	cout << "\t\t\t\tNHAN PHIM BAT KI DE KET THUC CHUONG TRINH! " << endl << endl;
}


void title() {
	fstream f;
	f.open("Title.txt");
	string s;
	while (!f.eof()) {
		getline(f, s);
		cout << s << endl;
	}
	f.close();
}

int main() {
	while (1) {
	nhap_lua_chon:
		system("cls");
		int selection ;
		//title();
		cout << "\t\t\t NHAP LUA CHON CUA BAN: " << endl;
		cout << "\t\t\t 1.  QUAN LY BAN VE" << endl;
		cout << "\t\t\t 2.  QUAN LY RAP PHIM" << endl;
		cout << "\t\t\t\t --> Nhap lua chon : ";
		cin >> selection;

		if (selection > 2 || selection < 1) {
			cout << "\t\t\t Nhap khong hop le. Vui long nhap lai ! "; 
			system("pause");
			goto nhap_lua_chon;
		}

		switch (selection) {
		case 1:
			QLbanve();
			break;
		case 2:
			QLrapphim();
			break;
		}

		char stop = 'K';

		cout << "\t\t\t BAN CO MUON TIEP TUC KHONG ? [ C / K ]  " ;
		cin >> stop;
		stop = toupper(stop);
		if (stop == 'K') {
			thoatCT();
			break;
		}
	}
	return 0;
}