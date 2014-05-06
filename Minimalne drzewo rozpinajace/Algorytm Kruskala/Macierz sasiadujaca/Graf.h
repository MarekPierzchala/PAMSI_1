#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <windows.h>
#include <algorithm>
#include <iomanip>
#include <stack>

using namespace std;

class Krawedz
{
public:
	int poczatek;  
	int koniec;
	int w; // waga
};

class Graf
{
public:
	int **Tablica; // Macierz sasiadujaca 
	int V; // wierzcholki
	int E; // krawedzie
	vector<Krawedz> lista_krawedzi; // wektor krawedzi 
	vector<Krawedz> drzewo;  // drzewo do alg Kruskala
	stack<int> stos;
public:
	void generuj_macierz(int ilosc, int gestosc);
	void stworz_macierz_sasiedztwa(string nazwapliku);
	void wyswietl();
	void kruskal();
	bool czy_spojny();
	~Graf();
};

bool cmp(const Krawedz& x, const Krawedz& y);
void sortuj_wektor(vector<Krawedz> *wektor);
LARGE_INTEGER startTimer();
LARGE_INTEGER endTimer();