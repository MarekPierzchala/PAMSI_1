#include "bf.h"

using namespace std;

void Graf::generuj_liste(int ilosc, int gestosc)
{
	V = ilosc;
	Wierzcholek pomoc;
	lista_sasiadujaca = new vector<Wierzcholek>[V];
	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < i; j++)
		{
			int losowa = rand() % 100;
			if (losowa < gestosc)//(1)
			{
				int k = rand() % (V * V) + 1;
				pomoc.sasiad = j;
				pomoc.waga = k;
				lista_sasiadujaca[i].push_back(pomoc);
				if (i != j)
				{
					pomoc.sasiad = i;
					pomoc.waga = k;
					lista_sasiadujaca[j].push_back(pomoc);
				}

			}
		}
	}
	for (int i = 0; i <= 1; i++)
	{
		if (lista_sasiadujaca[i].empty())
		{
			pomoc.sasiad = 0;
			pomoc.waga = 0;
			lista_sasiadujaca[0].push_back(pomoc);
		}
	}

}

void Graf::stworz_liste_z_pliku(string nazwapliku)
{
	ifstream plik;
	Wierzcholek pomoc;
	int v1, v2, wg;
	plik.open(nazwapliku.c_str());
	plik >> V;  // liczba wierzcholkow
	plik >> E;  // liczba krawedzi
	lista_sasiadujaca = new vector<Wierzcholek>[V];
	while (plik >> v1 >> v2 >> wg)
	{
		pomoc.sasiad = v2;
		pomoc.waga = wg;
		lista_sasiadujaca[v1].push_back(pomoc);
		if (v1 != v2)
		{
			pomoc.sasiad = v1;
			pomoc.waga = wg;
			lista_sasiadujaca[v2].push_back(pomoc);
		}
	}
}

bool Graf::czy_spojny()
{
	Wierzcholek pomoc;
	int licznik = 0;
	stack<Wierzcholek> stos;

	bool *wizyta = new bool[V];
	for (int i = 0; i < V; i++)
		wizyta[i] = false;

	pomoc.waga = lista_sasiadujaca[0][0].waga;
	pomoc.sasiad = lista_sasiadujaca[0][0].sasiad;
	stos.push(pomoc);

	while (!stos.empty())
	{
		pomoc = stos.top();
		stos.pop();
		if (wizyta[pomoc.sasiad] != true)
		{
			wizyta[pomoc.sasiad] = true;
			for (int j = 0; j < lista_sasiadujaca[pomoc.sasiad].size(); j++)
			{
				Wierzcholek druga;
				druga.waga = lista_sasiadujaca[pomoc.sasiad][j].waga;
				druga.sasiad = lista_sasiadujaca[pomoc.sasiad][j].sasiad;
				if (wizyta[druga.sasiad] != true)
					stos.push(druga);

			}
			licznik++;
		}

	}
	if (licznik == V)
	{
		cout << endl << "GRAF JEST SPOJNY! " << endl;
		return true;
	}
	else
	{
		cout << endl << "GRAF NIE JEST SPOJNY! " << endl;
		return false;
	}
	delete[] wizyta;
}

void Graf::wyswietl()
{
	for (int i = 0; i < V; i++)
	{
		cout << endl << setw(2) << i << ":";
		for (int j = 0; j < lista_sasiadujaca[i].size(); j++)
		{
			cout << setw(2) << lista_sasiadujaca[i][j].sasiad;
		}
	}
	cout << endl;
}

void Graf::bf()
{
	Krawedz pomoc;
	int *droga = new int[V];  // tablica z poprzednimi wierzcholkami 
	int *odl = new int[V];   // tablica, zapisujaca najkrotsza sciezke 
	vector<Krawedz> lista_krawedzi;  // zbior wszystkich krawedzi
	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < lista_sasiadujaca[i].size(); j++)
		{
			pomoc.poczatek = i;
			pomoc.koniec = lista_sasiadujaca[i][j].sasiad;
			pomoc.waga = lista_sasiadujaca[i][j].waga;
			lista_krawedzi.push_back(pomoc);
		}
	}
	for (int i = 0; i < V; i++){
		droga[i] = -1;      // wierzcholek, ktorego na pewno nie ma w grafie 
		odl[i] = 123245325325235235;  // nieskonczonosc 
	}

	odl[0] = 0;

	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < lista_krawedzi.size(); j++)
		{
			if (odl[lista_krawedzi[j].koniec] > odl[lista_krawedzi[j].poczatek] + lista_krawedzi[j].waga)
			{
				odl[lista_krawedzi[j].koniec] = odl[lista_krawedzi[j].poczatek] + lista_krawedzi[j].waga;
				droga[lista_krawedzi[j].koniec] = lista_krawedzi[j].poczatek;
			}
		}
	}
	
	cout << "Koszty dojscia z wierzcholka 0 do pozostalych: " << endl << "numer wierzcholka: koszt" << endl;
	for (int i = 1; i < V; i++)
	{
		cout << i << ": ";
		int zm;
		zm = i;
		cout << i << ">";
		if (droga[i] != 0)
		{
			while (droga[i] != 0)
			{
				i = droga[i];
				cout << i << ">";
			}
		}
		cout << 0;
		i = zm;
		cout << " = " << odl[i] << endl;
	}

	delete[] odl;
	delete[] droga;

}

Wierzcholek &Wierzcholek::operator= (Wierzcholek const& c1)
{
	Wierzcholek tmp;
	tmp.sasiad = c1.sasiad;
	tmp.waga = c1.waga;
	sasiad = c1.sasiad;
	waga = c1.waga;
	return tmp;
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

Graf::~Graf()
{
	delete[] lista_sasiadujaca;
}