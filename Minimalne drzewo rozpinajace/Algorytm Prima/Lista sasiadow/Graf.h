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
	//Krawedz(){ poczatek = 0; koniec = 0; w = 0; };
};

class Wierzcholek  
{
public:
	int sasiad;  // sasiad dla zadanego wierzcholka 
	int waga;  // waga
	Wierzcholek(){ sasiad = 0; waga = 0; };
};

class Graf
{
public:
	int V; // wierzcholki
	int E; // krawedzie
	vector<Krawedz> lista_krawedzi; // wektor krawedzi 
	vector<Krawedz> drzewo;  // drzewo do alg Kruskala
	vector<Wierzcholek> *lista_sasiadujaca; // lista sasiadujaca 
	vector<int> *lista_sasiedztwa; // lista sasiadujaca potrzebna do wyswietlania
public:
	void stworz_liste_z_pliku(string nazwapliku);
	void generuj_liste(int ilosc, int gestosc);
	void wyswietl();
	void prim();
	~Graf();
};

bool cmp(const Krawedz& x, const Krawedz& y);
void sortuj_wektor(vector<Krawedz> *wektor);