#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <Windows.h>
#include <string>
using namespace std;

class Tablica
{
private:
	vector<int> tablica;
	int rozmiar;
public:
	void wczytaj(string nazwapliku);
	void wyswietl();
	void zamien(int i, int j);
	void odwroc();
	void dodaj_element(int element);
	int wez_element(int elem);
	int romiar();
	void dodaj_tab(Tablica jed);
	bool operator ==(Tablica pomocnicza);
};

