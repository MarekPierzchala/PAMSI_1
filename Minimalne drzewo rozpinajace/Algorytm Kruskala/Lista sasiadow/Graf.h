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
	int V; // wierzcholki
	int E; // krawedzie
	vector<Krawedz> lista_krawedzi; // wektor krawedzi 
	vector<Krawedz> drzewo;  // drzewo do alg Kruskala
	vector<int> *lista_sasiadujaca; // lista sasiadujaca 
public:
	void stworz_liste_z_pliku(string nazwapliku);
	void generuj_liste(int ilosc, int gestosc);
	void wyswietl();
	void kruskal();
	~Graf();
};

bool cmp(const Krawedz& x, const Krawedz& y);
void sortuj_wektor(vector<Krawedz> *wektor);