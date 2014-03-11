#include "Lista.h"
#include <fstream>
using namespace std;

/*!
* \file
* \brief Plik zawierajacy wszystkie funkcje programu
*
* Plik zawiera definicję wszystkich funkcji programu
*/



void Lista::zeruj()
{
	lista.clear();
}


int Lista::wielkosc()
{
	return rozmiar;
}

int Lista::ilosc_powtorzen()
{
	return ilosc;
}


/*!
* \brief Funkcja wczytuj
*
* Funkcja wczytuje dane z pliku
* \param [in] nazwapliku - string, zawierajacy nazwe pliku
*/
void Lista::wczytaj(string nazwapliku)
{
	ifstream plik;
	plik.open(nazwapliku.c_str());
	int liczba;
	plik >> rozmiar;
	plik >> ilosc;
	while (plik >> liczba)
	{
		lista.push_back(liczba);
	}

}

/*!
* \brief Funkcja pomnoz
*
* Funkcja mnozy kazdy element vectora razy dwa
*/
void Lista::pomnoz()
{
	for (int i = 0; i < lista.size(); i++)
	{
		lista[i] *= 2;
	}
}

/*!
* \brief Funkcja porownaj
*
* Funkcja porownuje poszczegolne wartosci obu plikow
* \param [in] inna_lista - Lista, zawierajaca wartosci drugiego pliku
* \return zwraca true(1) lub false(0) w zaleznosci, czy dane wartosci sa takie same, czy nie
*/
bool Lista::porownaj(Lista inna_lista)
{
	for (int i = 0; i < lista.size(); i++)
	{
		if (lista[i] != inna_lista.daj_element(i))
		{

			return false;
		}
	}
	return true;
}

/*!
* \brief Funkcja wyswietl
*
* Funkcja wyswietla zawartosc pliku
*/
void Lista::wyswietl()
{
	for (int i = 0; i < lista.size(); i++)
	{
		cout << lista[i] << endl;
	}
}

/*!
* \brief Funkcja daj_element
*
* Funkcja zwraca element o danym wierszu
* \param [in] wiersz - numer wiersza
* \return funkcja zwraca wartosc liczby, znajdujacej sie w danym miejscu
*/
int Lista::daj_element(int wiersz)
{
	return lista[wiersz];
}

LARGE_INTEGER startTimer()
{
	LARGE_INTEGER start;
	DWORD_PTR oldmask = SetThreadAffinityMask(GetCurrentThread(), 0);
	QueryPerformanceCounter(&start);
	SetThreadAffinityMask(GetCurrentThread(), oldmask);
	return start;
}
LARGE_INTEGER endTimer()
{
	LARGE_INTEGER stop;
	DWORD_PTR oldmask = SetThreadAffinityMask(GetCurrentThread(), 0);
	QueryPerformanceCounter(&stop);
	SetThreadAffinityMask(GetCurrentThread(), oldmask);
	return stop;
}