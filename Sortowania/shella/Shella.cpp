#include "Shella.h"

using namespace std;

void Shella::wstaw(string nazwapliku)
{
	ifstream plik;
	plik.open(nazwapliku.c_str());
	int liczba;
	while (plik >> liczba)
	{
		tablica.push_back(liczba);
	}
}

void Shella::sortuj()
{
	int rozmiar = tablica.size();
	int pom, j;
	for (int p = rozmiar / 2; p >0; p /= 2)
	{
		for (int i = p; i<rozmiar; i++)
		{
			pom = tablica[i];      
			j = i - p;
			while ((j >= 0) && (tablica[j]>pom))
			{
				tablica[j + p] = tablica[j];
				j -= p;
			}
			tablica[j + p] = pom;
		}

	}
}

void Shella::wyswietl()
{
	for (int i = 0; i<tablica.size(); i++)
	{
		cout << tablica[i] << " ";
	}
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