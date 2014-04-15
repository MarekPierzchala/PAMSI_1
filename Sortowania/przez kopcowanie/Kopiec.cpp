#include "Kopiec.h"

using namespace std;

void Kopiec::wstaw(string nazwapliku)
{
	ifstream plik;
	plik.open(nazwapliku.c_str());
	int liczba;
	while (plik >> liczba)
	{
		tablica.push_back(liczba);
		if (tablica.size() > 1)
		{
			napraw_w_dol(0);
		}
	}
}



void Kopiec::napraw_w_dol(int i)
{
	int lewy = 0, prawy = 0;
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


void Kopiec::sortuj()
{
	int s = tablica.size();
	for (int i = 0; i<s; i++)
	{
		sortowana.push_back(tablica[0]);
		tablica[0] = tablica[tablica.size() - 1];
		tablica.pop_back();
		napraw_w_dol(0);
	}
}

void Kopiec::wyswietl()
{
	for (int i = 0; i<tablica.size(); i++)
	{
		cout << tablica[i] << " ";
	}
}

void Kopiec::wyswietl_posortowana()
{
	for (int i = 0; i<sortowana.size(); i++)
	{
		cout << sortowana[i] << " ";
	}
}


int Kopiec::rozmiar()
{
	return tablica.size();
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