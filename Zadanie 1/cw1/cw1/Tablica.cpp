#include "Tablica.h"
using namespace std;


/****************************************************************************************************************/
/*FUNKCJA ZMIENIAJACA ROZMIAR TABLICY*/
char* Tablica::zm_rozm(int nowyrozmiar)
{
	char* tmp = new char[rozmiar];
	for (int i = 0; i < rozmiar; i++)
	{
		tmp[i] = tablica[i];
	}
	tablica = new char[nowyrozmiar];
	for (int i = 0; i < nowyrozmiar; i++)
	{
		if (i < rozmiar)
		{
			tablica[i] = tmp[i];

		}
		else
		{
			tablica[i] = '0';
		}
	}
	rozmiar = nowyrozmiar;
	return tablica;
}


/****************************************************************************************************************/
/*FUNKCJA WYSWIETLA TABLICE*/
void Tablica::wyswietl(ostream &am)
{
	for (int i = 0; i < rozmiar; i++)
	{
		am << tablica[i] << endl;
	}
}


/****************************************************************************************************************/
/*FUNKCJA ALOKUJE NOWA TABLICE*/
char* Tablica::wczytaj(istream &am)
{
	tablica = new char[rozmiar];
	for (int i = 0; i < rozmiar; i++)
	{
		am >> tablica[i];
	}
	return tablica;
}


/****************************************************************************************************************/
/*FUNKCJA ZAPISUJACA ROZMIAR TABLICY*/
void Tablica::zap_rozm(int a)
{
	rozmiar = a;
}


/****************************************************************************************************************/
/*FUNKCJA ZWRACAJACA ROZMIAR TABLICY*/
int Tablica::wielkosc()
{
	return rozmiar;
}


/****************************************************************************************************************/
/*FUNKCJA ZWALNIA PAMIEC*/
void Tablica::zwolnij()
{
	delete[] tablica;
}


/*********************************************************************************************************************************/
/*KONSTRUKTOR DOMYSLNY*/
Tablica::Tablica()
{
	rozmiar = 0;
	tablica = NULL;
}


/*********************************************************************************************************************************/
/*KONSTRUKTOR KOPIUJACY*/
Tablica::Tablica(Tablica &t1)
{
	rozmiar = t1.rozmiar;
	tablica = new char[rozmiar];
	for (int i = 0; i < rozmiar; i++)
	{
		tablica[i] = t1.tablica[i];
	}
}


