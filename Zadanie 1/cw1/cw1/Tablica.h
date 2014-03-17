#pragma once
#ifndef TABLICA_H
#define TABLICA_H
#include <iostream>
using namespace std;


class Tablica
{

	char *tablica;
	int rozmiar;
public:
	char* zm_rozm(int nowyrozmiar);
	void wyswietl(ostream &am);
	char* wczytaj(istream &am);
	void zap_rozm(int a);
	void zwolnij();
	int wielkosc();
	Tablica();
	Tablica(Tablica &t1);
};

#endif
