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

class Krawedz
{
public:
	int poczatek;
	int koniec;
	int w; // waga
	Krawedz(){ poczatek = 0; koniec = 0; w = 0; };
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

class Wierzcholek  
{
public:
	int sasiad;  // sasiad dla zadanego wierzcholka 
	int waga;  // waga
	Wierzcholek(){ sasiad = 0; waga = 0; };
	Wierzcholek &operator= (Wierzcholek const& c1);
};

class Graf
{
public:
	int V; // wierzcholki
	int E; // krawedzie
	//vector<Krawedz> lista_krawedzi; // wektor krawedzi 
	vector<Krawedz> drzewo;  // drzewo do alg Kruskala
	vector<Wierzcholek> *lista_sasiadujaca; // lista sasiadujaca 
	stack<Wierzcholek> stos; // stos do badania spojnosci
public:
	void stworz_liste_z_pliku(string nazwapliku);
	void generuj_liste(int ilosc, int gestosc);
	void wyswietl();
	bool czy_spojny();
	void prim();
	~Graf();
};

bool cmp(const Krawedz& x, const Krawedz& y);
void sortuj_wektor(vector<Krawedz> *wektor);
LARGE_INTEGER startTimer();
LARGE_INTEGER endTimer();