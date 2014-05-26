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
	int **Tablica;  // macierz sasiedztwa
	//vector<Krawedz> lista_krawedzi;  // zbior wszystkich krawedzi
public:
	void generuj_macierz(int ilosc, int gestosc);
	void stworz_macierz_sasiedztwa(string nazwapliku);
	bool czy_spojny();
	void wyswietl();
	void Graf::bf();
	~Graf();
};


LARGE_INTEGER startTimer();
LARGE_INTEGER endTimer();