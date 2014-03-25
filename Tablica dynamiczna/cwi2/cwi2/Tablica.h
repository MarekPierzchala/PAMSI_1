#pragma once
#ifndef TABLICA_H
#define TABLICA_H
#include <iostream>
using namespace std;

template <class Typ>
class Tablica
{
	Typ *tablica;
	int rozmiar;
public:
	Tablica();
	Tablica(Tablica<Typ> &t1);
	~Tablica();
	Typ* zm_rozm(int nowyrozmiar);
	Typ* dodaj(Typ element);
	Typ* usun();
	void zap_rozm(int a);
	int wielkosc();
	Typ& operator [] (int i);
	const Typ& operator [] (int i) const;
	template <class Typ> friend ostream& operator<< (ostream &wyjscie, Tablica<Typ> const& tb);
	template <class Typ> friend istream & operator >> (istream & wejscie, Tablica<Typ> &tb);
	void* poczatek();
	void* koniec();
	Tablica<Typ>& operator =(const Tablica<Typ> &t1);
	void zm_tb(Tablica<Typ> &tb);
};


/*********************************************************************************************************************************/
/*KONSTRUKTOR DOMYSLNY*/
template <class Typ>
Tablica<Typ>::Tablica()
{
	rozmiar = 0;
	tablica = NULL;
}


/*********************************************************************************************************************************/
/*KONSTRUKTOR KOPIUJACY*/
template <class Typ>
Tablica<Typ>::Tablica(Tablica<Typ> &t1)
{
	rozmiar = t1.rozmiar;
	tablica = new Typ[rozmiar];
	for (int i = 0; i < rozmiar; i++)
	{
		tablica[i] = t1.tablica[i];
	}
}

/*********************************************************************************************************************************/
/*DEKONSTRUKTOR*/
template <class Typ>
Tablica<Typ>::~Tablica()
{
	delete[] tablica;
}


/*********************************************************************************************************************************/
/*FUNKCJA ZMIENIAJACA ROZMIAR TABLICY*/
template <class Typ>
Typ* Tablica<Typ>::zm_rozm(int nowyrozmiar)
{
	Typ* tmp = new Typ[rozmiar];
	for (int i = 0; i < rozmiar; i++)
	{
		tmp[i] = tablica[i];
	}
	tablica = new Typ[nowyrozmiar];
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
	delete[] tmp;
	return tablica;
}



/*********************************************************************************************************************************/
/*FUNKCJA ZAPISUJACA ROZMIAR TABLICY*/
template <class Typ>
void Tablica<Typ>::zap_rozm(int a)
{
	rozmiar = a;
}


/*********************************************************************************************************************************/
/*FUNKCJA ZWRACAJACA WIELKOSC TABLICY*/
template <class Typ>
int Tablica<Typ>::wielkosc()
{
	return rozmiar;
}


/*********************************************************************************************************************************/
/*FUNKCJA, KTORA DODAJE KOLEJNY ELEMENT NA TABLICE*/
template <class Typ>
Typ* Tablica<Typ>::dodaj(Typ element)
{
	Typ* tmp = new Typ[rozmiar];
	for (int i = 0; i < rozmiar; i++)
	{
		tmp[i] = tablica[i];
	}
	tablica = new Typ[rozmiar + 1];
	for (int i = 0; i < rozmiar + 1; i++)
	{
		if (i < rozmiar)
		{
			tablica[i] = tmp[i];

		}
		else
		{
			tablica[i] = element;
		}
	}
	rozmiar = rozmiar + 1;
	delete[] tmp;
	return tablica;
}


/*********************************************************************************************************************************/
/*FUNKCJA, KTORA USUWA OSTATNI ELEMENT*/
template <class Typ>
Typ* Tablica<Typ>::usun()
{
	Typ* tmp = new Typ[rozmiar];
	if (rozmiar == 0)
	{
		cout << "Blad! Tablica jest juz pusta!" << endl;
	}
	else
	{
		
		for (int i = 0; i < rozmiar; i++)
		{
			tmp[i] = tablica[i];
		}
		tablica = new Typ[rozmiar - 1];
		for (int i = 0; i < rozmiar - 1; i++)
		{
			tablica[i] = tmp[i];
		}
	}
	rozmiar = rozmiar - 1;
	delete[] tmp;
	return tablica;
}


/*********************************************************************************************************************************/
/*PRZECIAZENIE OPERATORA []*/
template <class Typ>
Typ& Tablica<Typ>::operator [] (int i)
{
	if (i >= 0 && i <= rozmiar)
	{
		return tablica[i];
	}
	else
	{
		cout << "Blad! Tablica ma za maly rozmiar!" << endl;
	}
}


/*********************************************************************************************************************************/
/*PRZECIAZENIE OPERATORA [] CONST*/
template <class Typ>
const Typ& Tablica<Typ>::operator [] (int i) const
{
	if (i >= 0 && i <= rozmiar)
	{
		return tablica[i];
	}
	else
	{
		cout << "Blad! Tablica ma za maly rozmiar!" << endl;
	}
}


/*********************************************************************************************************************************/
/*PRZECIAZENIE OPERATORA WYJSCIA*/
template <class Typ>
ostream& operator<< (ostream &wyjscie, Tablica<Typ> const& tb)
{
	for (int i = 0; i < tb.rozmiar; i++)
	{
		wyjscie << tb.tablica[i] << endl;
	}
	return wyjscie;
}


/*********************************************************************************************************************************/
/*PRZECIAZENIE OPERATORA WEJSCIA*/
template <class Typ>
istream & operator >> (istream & wejscie, Tablica<Typ> &tb)
{
	tb.tablica = new Typ[tb.rozmiar];
	for (int i = 0; i < tb.rozmiar; i++)
	{
		wejscie >> tb.tablica[i];
	}
	return wejscie;
}


/*********************************************************************************************************************************/
/*FUNKCJA ZWRACAJACA WSKAZNIK NA PIERWSZY ELEMENT*/
template <class Typ>
void* Tablica<Typ>::poczatek()
{
	return reinterpret_cast<void*>(tablica);
}

/*********************************************************************************************************************************/
/*FUNKCJA ZWRACAJACA WSKAZNIK NA OSTATNI ELEMENT*/
template <class Typ>
void* Tablica<Typ>::koniec()
{
	return reinterpret_cast<void*>(tablica+rozmiar);
}



/*********************************************************************************************************************************/
/*FUNKCJA ZMIENIAJACA ZAWARTOSC DWOCH TABLIC*/
template <class Typ>
void Tablica<Typ>::zm_tb(Tablica<Typ> &tb)
{
	Typ* pom = new Typ[rozmiar];
	if (rozmiar != tb.rozmiar)
	{
		cout << "Blad! Nie mozna zamienic zawartosci tablic! Zle rozmiary!" << endl;
	}
	else
	{

		for (int i = 0; i < rozmiar; i++)
		{
			pom[i] = tablica[i];
		}
		for (int i = 0; i < rozmiar; i++)
		{
			tablica[i] = tb.tablica[i];
		}
		for (int i = 0; i < rozmiar; i++)
		{
			tb.tablica[i] = pom[i];
		}
	}
}


/*********************************************************************************************************************************/
/*PRZECIAZENIE OPERATORA = */
template <class Typ>
Tablica<Typ>& Tablica<Typ>::operator =(const Tablica<Typ> &t1)
{
	if (rozmiar != t1.rozmiar)
	{
		delete[] tablica;
		tablica = new Typ[t1.rozmiar];
	}
	for (int i = 0; i < 0; i++)
	{
		tablica[i] = t1.tablica[i];
	}
	rozmiar = t1.rozmiar;
	return *tablica;
}


#endif