#include "Tablica.h"
using namespace std;

void Tablica::wczytaj(string nazwapliku)
{
	ifstream plik;
	plik.open(nazwapliku.c_str());
	int liczba;
	plik >> rozmiar;
	while (plik >> liczba)
	{
		tablica.push_back(liczba);
	}

}

void Tablica::wyswietl()
{
	for (int i = 0; i < tablica.size(); i++)
	{
		cout << tablica[i] << endl;
	}
}

void Tablica::zamien(int i, int j)
{
	int a;
	a = tablica[i-1];
	tablica[i-1] = tablica[j-1];
	tablica[j-1] = a;
}

void Tablica::odwroc()
{
	int pom;
	for (int i = 0; i < tablica.size()*0.5; i++)
	{
		pom = tablica[i];
		tablica[i] = tablica[tablica.size() - 1 - i];
		tablica[tablica.size() - 1 - i] = pom;
	}
}

void Tablica::dodaj_element(int element)
{
	tablica.push_back(element);
}

int Tablica::wez_element(int elem)
{
	return tablica[elem];
}

int Tablica::romiar()
{
	return rozmiar;
}

void Tablica::dodaj_tab(Tablica jed)
{
	int n;
	n = jed.romiar();
	cout << "N: " << n << endl;
	for (int i = 0; i < n; i++)
	{
		tablica.push_back(jed.wez_element(i));
	}
}

bool Tablica::operator ==(Tablica pomocnicza)
{
	for (int i = 0; i < tablica.size(); i++)
	{
		if (tablica[i] != pomocnicza.wez_element(i))
		{

			return false;
		}
	}
	return true;
}