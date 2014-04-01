#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <class Typ>
class Kopiec
{
	vector<Typ> tablica;
	int licznik;
public:
	void wstaw(Typ wartosc);
	int zwroc_rodzica(int index);
	int zwroc_prawe_dziecko(int index);
	int zwroc_lewe_dziecko(int index); 
	void usun(int indeks);
	void napraw_w_dol(int i);
	void napraw_w_gore(int i);
	Typ top();
	void pop();
	Typ operator[](int i);
	void zamien(Kopiec<Typ> pom);
	void stworz_z_tablicy(vector<Typ> pom);
	void polacz(Kopiec<Typ> pom);
	void decreasd(int i);
	void increasd(int i);
	int rozmiar();
	void updated(int i);
	void wyswietl();
	Kopiec();
};


template <class Typ>
void Kopiec<Typ>::wstaw(Typ wartosc)
{
	tablica.push_back(wartosc);
	int s;
	s = tablica.size()-1;
	while (s != 0)
	{
		if (s == 1 || s == 2)
		{
			if (tablica[0]>tablica[s])
			{
				swap(tablica[0], tablica[s]);
			}
			else
			{
				break;
			}
		}
		else
		{
			if (tablica[((s - 1) / 2)] > tablica[s])
			{
				swap(tablica[((s - 1) / 2)], tablica[s]);
				s /= 2;
			}
			else
			{
				break;
			}
		}

	}
	licznik++;
}

template <class Typ>
int Kopiec<Typ>::zwroc_rodzica(int index)
{
	int s;
	if (index > 0){
		s = (index - 1) / 2;
		return s;
	}
	else
	{
		cout << "Korzen nie ma rodzica! " << endl;
	}
}


template <class Typ>
int Kopiec<Typ>::zwroc_prawe_dziecko(int index)
{
	int s;
	s = 2 * index + 2;
	return s;
}


template <class Typ>
int Kopiec<Typ>::zwroc_lewe_dziecko(int index)
{
	int s;
	s = 2 * index + 1;
	return s;
}


template <class Typ>
void Kopiec<Typ>::usun(int indeks)
{
	tablica.erase(tablica.begin()+(indeks-1));\
	licznik--;
}


template <class Typ>
void Kopiec<Typ>::napraw_w_dol(int i)
{
	int lewy=0, prawy=0;
	while (i <= tablica.size())
	{
		lewy = (2 * i + 1);
		prawy = (2 * i + 2);
		if (lewy < tablica.size())
		{
			if (tablica[i] > tablica[lewy])
			{
				swap(tablica[i], tablica[lewy]);
			}
		}
		if (prawy<tablica.size())
		{
			if (tablica[i] > tablica[prawy])
			{
				swap(tablica[i], tablica[prawy]);
			}
		}
		i++;

	}
	
}


template <class Typ>
void Kopiec<Typ>::napraw_w_gore(int i)
{
	while (i != 0)
	{
		if (i == 1 || i == 2)
		{
			if (tablica[0] > tablica[i])
			{
				swap(tablica[0], tablica[i]);
			}
			else
			{
				break;
			}
		}
		else
		{
			if (tablica[((i - 1) / 2)] > tablica[i])
			{
				swap(tablica[((i - 1) / 2)], tablica[i]);
				i /= 2;
			}
			else
			{
				break;
			}
		}
	}
}


template <class Typ>
void Kopiec<Typ>::wyswietl()
{
	for (int i = 0; i<tablica.size(); i++)
	{
		cout << tablica[i] << " ";
	}
}

template <class Typ>
Typ Kopiec<Typ>::top()
{
	return tablica[0];
}


template <class Typ>
void Kopiec<Typ>::pop()
{
	tablica[0] = tablica[tablica.size()-1];
	tablica.pop_back();
	licznik--;
}


template <class Typ>
Typ Kopiec<Typ>::operator[](int i)
{
	if (i >= 0 && i < tablica.size())
	{
		return tablica[i];
	}
	else
	{
		cout << "Kopiec nie ma tylu elementow!" << endl;
	}
}


template <class Typ>
void Kopiec<Typ>::zamien(Kopiec<Typ> pom)
{
	tablica.swap(pom.tablica);
}


template <class Typ>
void Kopiec<Typ>::stworz_z_tablicy(vector<Typ> pom)
{
	for (int i = 0; i < pom.size(); i++){
		tablica.push_back(pom[i]);
		licznik++;
	}
}


template <class Typ>
void Kopiec<Typ>::polacz(Kopiec<Typ> pom)
{
	for (int i = 0; i < pom.tablica.size(); i++){
		tablica.push_back(pom.tablica[i]);
		licznik++;
	}
}

template <class Typ>
void Kopiec<Typ>::decreasd(int i)
{
	napraw_w_gore(i);
}


template <class Typ>
void Kopiec<Typ>::increasd(int i)
{
	napraw_w_dol(i);
}

template <class Typ>
void Kopiec<Typ>::updated(int i)
{
	napraw_w_dol(i);
	napraw_w_gore(i);
}


template <class Typ>
int Kopiec<Typ>::rozmiar()
{
	return tablica.size();
}

template <class Typ>
Kopiec<Typ>::Kopiec()
{
	licznik = 0;
}

