#pragma once

#include <iostream>
#include <iomanip>

using namespace std;


struct miejsce
{
	int x;
	int y;
};


class gra
{
public:
	int Plansza[8][8];
	int biale;
	int czarne;
	int aktualny;
public:
	void wyswietl();
	void graj();
	bool czy_bicie(int kto, miejsce poczatkowe, miejsce docelowe);
	void wykonaj_ruch(int kto, miejsce poczatkowe, miejsce docelowe);
	void wykonaj_bicie(int kto, miejsce poczatkowe, miejsce docelowe);
	bool czy_ruch(int kto, miejsce poczatkowe, miejsce docelowe);
	gra();
};

