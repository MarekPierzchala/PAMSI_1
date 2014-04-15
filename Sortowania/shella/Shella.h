#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <Windows.h>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

class Shella
{
	vector<int> tablica;
public:
	void wstaw(string nazwapliku);
	void sortuj();
	void wyswietl();
};

LARGE_INTEGER endTimer();
LARGE_INTEGER startTimer();