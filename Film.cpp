#include"Film.h"
#include<fstream>
#include<string>
using namespace std;

film::film() {
    this->size = 0;
}

film::~film() {

}

void film::getdata() {
    fstream g;
    g.open("Text.txt");
    string id, name, time, genre, str;

    while (!g.eof()) {
        getline(g, str);
        if (!g.eof()) {
            this->size++;
            this->InsertNodeAfter(str);
        }
    }

    g.close();
}

void film::show() {
	this->printList();
}

void film::deleteFilm() {
    cout << "\t\t\tNhap ma phim can xoa : ";
    string obj;
    getline(cin, obj);
    if (!findData(obj))
        cout << "\t\t\tKhong ton tai phim can xoa " << endl;
    else {
        DeleteNode(obj);
        size--;
    }
}


void film::update(string filename) {
    ofstream xoa(filename);
    xoa.close();
    ofstream g;
    this->printListFile(filename);
}
