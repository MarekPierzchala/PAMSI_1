#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>

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
public:
	void generuj_macierz(int ilosc, int gestosc);
	void stworz_macierz_sasiedztwa(string nazwapliku);
	void wyswietl();
	void prim();
	~Graf();
};

bool cmp(const Krawedz& x, const Krawedz& y);
void sortuj_wektor(vector<Krawedz> *wektor);