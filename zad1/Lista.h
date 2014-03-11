#ifndef LISTA_H
#define LISTA_H
/*!
* \file
* \brief Definicja klasy Lista
*
* Plik zawiera definicję klasy Lista
*/

#include <iostream>
#include <vector>
#include <windows.h>
using namespace std;
/*!
* \brief Klasa Lista
*
* Klasa zawierajaca vector, ktory przechowuje zawartosc pliku
*/
class Lista
{
private:
	vector<int> lista;
	int rozmiar;
	int ilosc;
public:
	void zeruj();
	int wielkosc();
	int ilosc_powtorzen();
	void wczytaj(string nazwapliku);
	void pomnoz();
	bool porownaj(Lista inna_lista);
	void wyswietl();
	int daj_element(int index);
};
LARGE_INTEGER startTimer();
LARGE_INTEGER endTimer();


#endif
