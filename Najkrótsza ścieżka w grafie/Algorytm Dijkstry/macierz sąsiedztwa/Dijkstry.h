#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <Windows.h>
#include <stack>
//#include <queue>
//#include <conio.h>
#include <boost/heap/fibonacci_heap.hpp>  // fibonacci z boost

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


LARGE_INTEGER startTimer();
LARGE_INTEGER endTimer();