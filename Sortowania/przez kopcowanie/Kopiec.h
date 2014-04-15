#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <Windows.h>
#include <sstream>
#include <algorithm>

using namespace std;

class Kopiec
{
	vector<int> tablica;
	vector<int> sortowana;
	int licznik;
public:
	void wstaw(string nazwapliku);
	void napraw_w_dol(int i);
	void sortuj();
	void wyswietl();
	void wyswietl_posortowana();
	int rozmiar();
};

LARGE_INTEGER startTimer();
LARGE_INTEGER endTimer();