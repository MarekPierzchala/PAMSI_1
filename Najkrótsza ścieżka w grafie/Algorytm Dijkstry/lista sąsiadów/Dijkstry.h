#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <Windows.h>
#include <stack>
#include <boost/heap/fibonacci_heap.hpp>  // fibonacci z boost

using namespace std;


class Wierzcholek
{
public:
	int sasiad;  // sasiad dla zadanego wierzcholka 
	int waga;  // waga
	Wierzcholek(){ sasiad = 0; waga = 0; };
	Wierzcholek &operator= (Wierzcholek const& c1);
};

struct Wezel
{
	int nr; // numer wierzcholka
	int g; // droga 
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
	int dijkstry(int a, int b);
	~Graf();
};

struct por
{
	bool operator ()(const Wezel & k1, const Wezel& k2)
	{
		//kolejność - rosnąco
		if (k1.g > k2.g) return true;

		if (k1.g < k2.g) return false;

		return false;
	}
};

LARGE_INTEGER startTimer();
LARGE_INTEGER endTimer();