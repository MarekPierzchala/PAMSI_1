﻿#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <Windows.h>
#include <stack>
#include <queue>
#include <conio.h>

using namespace std;

struct Wierzcholek
{
	int nr; // numer wierzcholka
	int g; // droga 
};

class Graf
{
public:
	int V; // wierzcholki
	int E; // krawedzie
	int **Tablica;  // macierz sasiedztwa
public:
	void generuj_macierz(int ilosc, int gestosc);
	void stworz_macierz_sasiedztwa(string nazwapliku);
	bool czy_spojny();
	void wyswietl();
	int dijkstry(int a, int b);
	~Graf();
};

struct por
{
	bool operator ()(const Wierzcholek & k1, const Wierzcholek& k2)
	{
		//kolejność - rosnąco
		if (k1.g > k2.g) return true;

		if (k1.g < k2.g) return false;

		return false;
	}
};
LARGE_INTEGER startTimer();
LARGE_INTEGER endTimer();