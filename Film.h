#pragma once
#ifndef FILM_H
#define FILM_H
#include "LinkedList.h"
#include <string>
using namespace std;

class film : public LinkedList {
private:
	int size;
public:
	film();
	~film();
	void getdata();
	void show();
	void deleteFilm();
	void update(string filename);
};	
#endif // !FILM_H
