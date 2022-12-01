#include <iostream>
#include <fstream>
#include "KhachHang.h"

using namespace std;

void QLbanve() {
nhap_lua_chon:
	system("cls");
	cout << "\t\t\t 1. Xem danh sach phim hien co " << endl;
	cout << "\t\t\t 2. Xem lich chieu trong ngay" << endl;
	cout << "\t\t\t 3. Mua ve " << endl;
	cout << "\t\t\t 0. Thoat " << endl;
	int selection;
	cout << "\t\t\t\t -> Nhap lua chon cua ban: ";
	cin >> selection;
	if (selection > 3 || selection < 0) {
		cout << "\t\t\t Nhap lua chon khong hop le. Vui long nhap lai!"; 
		system("pause"); 
		goto nhap_lua_chon;
	}

	guest g;

	switch (selection) {
	case 1:
		g.XemDSPhim();
		break;
	case 2:
		system("cls");
		int date;
		cout << "\t\t\tNhap ngay ma ban muon mua ve: ";
		cin >> date;

		// ktra ngay <= today + 7

		g.XemLichChieuTrongNgay(date);
		break;
	case 3:
		g.banVe();
		break;
	}

}


void QLrapphim() {
nhap_lua_chon:
	system("cls");
	cout << "\t\t\t 1. Xem danh sach phim hien co " << endl;
	cout << "\t\t\t 2. Xem lich chieu" << endl;
	cout << "\t\t\t 3. Them suat chieu" << endl;
	cout << "\t\t\t 4. Huy suat chieu" << endl;
	cout << "\t\t\t 5. Them phim" << endl;
	cout << "\t\t\t 6. Xoa phim" << endl;
	cout << "\t\t\t 7. Xem danh sach khach hang" << endl;
	cout << "\t\t\t 8. Xem doanh thu trong ngay hom nay" << endl;
	cout << "\t\t\t 0. Thoat " << endl;
	int selection;
	cout << "\t\t\t\t -> Nhap lua chon cua ban: ";
	cin >> selection;
	if (selection > 8 || selection < 0) {
		cout << "\t\t\t Lua chon khong hop le. Vui long nhap lai! ";
		goto nhap_lua_chon;
	}
	switch (selection) {
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		break;
	case 7:
		break;
	case 8:
		break;
	}
}

void thoatCT() {
	cout << "thoat" << endl;
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