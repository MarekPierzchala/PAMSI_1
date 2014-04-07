#include "babelkowe.h"

using namespace std;


vector<int> generuj_tablice(string nazwapliku)
{
	ifstream plik;
	plik.open(nazwapliku.c_str());
	int liczba;
	vector<int> tab;
	while (plik >> liczba)
	{
		tab.push_back(liczba);
	}
	return tab;
}

void wyswietl(vector<int> pom)
{
	for (int i = 0; i<pom.size(); i++)
	{
		cout << pom[i] << " ";
	}
	cout << endl;
}


vector<int> sortuj(vector<int> pom)
{
	for (int i = 0; i<pom.size() - 1; i++)
	{
		for (int j = 0; j<pom.size() - 1; j++)
		{
			if (pom[j]>pom[j + 1])
			{
				swap(pom[j], pom[j + 1]);
			}
		}
	}
	return pom;
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