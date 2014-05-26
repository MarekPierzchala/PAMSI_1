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
	int sasiad;  // sasiad dla zadanego wierzcholka 
	int waga;  // waga
	Wierzcholek(){ sasiad = 0; waga = 0; };
	Wierzcholek &operator= (Wierzcholek const& c1);
};

struct Krawedz
{
	int poczatek;
	int koniec;
	int waga;
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
	void Graf::bf();
	~Graf();
};



LARGE_INTEGER startTimer();
LARGE_INTEGER endTimer();