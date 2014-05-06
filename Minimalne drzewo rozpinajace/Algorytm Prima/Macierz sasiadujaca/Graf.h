#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <Windows.h>
#include <stack>
#include <queue>

using namespace std;

class Krawedz
{
public:
	int poczatek;
	int koniec;
	int w; // waga
};

struct PorownajKrawedzie
{
	bool operator ()(const Krawedz & k1, const Krawedz & k2)
	{
		//kolejność - rosnąco
		if (k1.w > k2.w) return true;

		if (k1.w < k2.w) return false;

		return false;
	}
};

class Graf
{
public:
	int **Tablica; // Macierz sasiadujaca 
	int V; // wierzcholki
	int E; // krawedzie
	//vector<Krawedz> lista_krawedzi; // wektor krawedzi 
	vector<Krawedz> drzewo;  // drzewo do alg Kruskala
	stack<int> stos;
public:
	void generuj_macierz(int ilosc, int gestosc);
	void stworz_macierz_sasiedztwa(string nazwapliku);
	void wyswietl();
	void prim();
	bool czy_spojny();
	~Graf();
};

bool cmp(const Krawedz& x, const Krawedz& y);
void sortuj_wektor(vector<Krawedz> *wektor);
LARGE_INTEGER startTimer();
LARGE_INTEGER endTimer();