#pragma once

#include <iostream>
#include <iomanip>
#include <vector>
#include <list>
#include <queue>
#include <string>

using namespace std;

#define MAX = 25;
#define INF = 100000;

struct miejsce
{
	int x;
	int y;
};

class ruch
{
public:
	miejsce stoi;
	miejsce stal;
	string co;
	int waga;
	ruch() { stoi.x = 0; stoi.y = 0; waga = 0; };
};

struct PorownajPionki
{
	bool operator ()(const ruch & k1, const ruch & k2)
	{
		if (k1.waga < k2.waga) return true;
		if (k1.waga > k2.waga) return false;
		return false;
	}
};

class gra
{
public:
	int Plansza[8][8];
	int jedynki;
	int dwojki;
	int aktualny;
	ruch ruch_pom; 
		ruch naj;
	vector<ruch> lista; 
	vector<ruch> lista1;
	priority_queue<ruch, vector<ruch>, PorownajPionki> mozliwosci;
	//list<ruch> lista_ruch; 

public:
	void wyswietl();
	void rozgrywka();
	gra();
	void zlicz();
	// RUCHY GRACZA
	bool czy_bicie(int kto, miejsce poczatkowe, miejsce docelowe);
	void wykonaj_ruch(int kto, miejsce poczatkowe, miejsce docelowe);
	void wykonaj_bicie(int kto, miejsce poczatkowe, miejsce docelowe);
	bool czy_ruch(int kto, miejsce poczatkowe, miejsce docelowe);
	void graj();
	void damka_dwa();
	bool czy_bicie_damki(miejsce pozycja);
	bool czy_ruch_damki(miejsce pozycja);
	void ruch_damki(miejsce poczatkowe, miejsce docelowe);
	void bicie_damki(miejsce poczatkowe, miejsce docelowe);
	// RUCHY KOMPUTERA
	void bezpieczenstwo();
	bool ruch_po_damke(miejsce stoi);
	bool czy_bicie_damkiK(miejsce pozycja);
	bool czy_ruch_damkiK(miejsce pozycja);
	void ruch_damkiK(miejsce poczatkowe, miejsce docelowe);
	void bicie_damkiK(miejsce poczatkowe, miejsce docelowe);
	void cz_damkaK();
	ruch rusz_sie(ruch rch, int gracz);
	void cofnij_sie(ruch rch, int gracz);
	int zwroc_pole(int x, int y);
	miejsce zwroc_wspolrzedne(int x);
	void stworz_liste_ruchow( int kto);
	bool czy_pionek(int kto, miejsce pozycja);
	bool czy_mozliwosc_ruchu( int kto, miejsce pozycja);
	bool czy_mozliwosc_bicia( int kto, miejsce pozycja);
	bool czy_mozliwosc_biciaN( int kto, miejsce pozycja);
	bool czy_mozliwosc_ruchuN( int kto, miejsce pozycja);
	bool chron_sie(miejsce pozycja, int kto);
	bool czy_luka(int kto, miejsce pozycja);
	bool czy_niebezpieczenstwo(miejsce pozycja, int kto);
	void ruch_komputera();
	int OcenStan(ruch docelowe, int gracz);
	int minmax(int gracz, int glebokosc, int max, int min);
	int Ocensytacje(int gracz);
	int ocena(int gracz);
	ruch minmax(int gracz, int glebokosc);
};

