#pragma once

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


class Wierzcholek
{
public:
	//int numer;  // numer wierzcholka
	int sasiad;  // sasiad dla zadanego wierzcholka 
	int waga;  // waga
	Wierzcholek(){ sasiad = 0; waga = 0; };
	Wierzcholek &operator= (Wierzcholek const& c1);
};

class Krawedz
{
public:
	int poczatek;
	int koniec;
	int w; // waga
	Krawedz(){ poczatek = 0; koniec = 0; w = 0; };
};

class Graf
{
public:
	int V; // wierzcholki
	int E; // krawedzie
	vector<Wierzcholek> *lista_sasiadujaca; // lista sasiadujaca 
public:
	void generuj_liste(int ilosc, int gestosc);
	void stworz_liste_z_pliku(string nazwapliku);
	bool czy_spojny();
	void wyswietl();
	void dijkstry();
	~Graf();
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

LARGE_INTEGER startTimer();
LARGE_INTEGER endTimer();