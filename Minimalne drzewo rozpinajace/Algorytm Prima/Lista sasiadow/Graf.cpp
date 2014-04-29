#include "Graf.h"

using namespace std;

bool cmp(const Krawedz& x, const Krawedz& y)
{
	return x.w>y.w;
}

void sortuj_wektor(vector<Krawedz> *wektor)
{
	sort(wektor->begin(), wektor->end(), cmp);
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
	lista_sasiedztwa = new vector<int>[V];
	while (plik >> v1 >> v2 >> wg)
	{
		pomoc.sasiad = v2;
		pomoc.waga = wg;
		lista_sasiadujaca[v1].push_back(pomoc);
		lista_sasiedztwa[v1].push_back(v2);
		if (v1 != v2)
		{
			pomoc.sasiad = v1;
			pomoc.waga = wg;
			lista_sasiadujaca[v2].push_back(pomoc);
			lista_sasiedztwa[v2].push_back(v1);
		}
	}
}

void Graf::generuj_liste(int ilosc, int gestosc)
{
	V = ilosc;
	Wierzcholek pomoc;
	lista_sasiadujaca = new vector<Wierzcholek>[V];
	lista_sasiedztwa = new vector<int>[V];
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
				lista_sasiedztwa[i].push_back(j);
				if (i != j)
				{
					pomoc.sasiad = i;
					pomoc.waga = k;
					lista_sasiadujaca[j].push_back(pomoc);
					lista_sasiedztwa[j].push_back(i);
				}
				
			}
		}
	}
}

void Graf::wyswietl()
{
	for (int i = 0; i < V; i++)
	{
		cout << endl << setw(2) << i << ":";
		for (vector<int>::iterator it = lista_sasiedztwa[i].begin(); it != lista_sasiedztwa[i].end(); it++)
		{
			cout << " " << *it;
		}
	}
	cout << endl;
}

void Graf::prim()
{
	Krawedz nowa;
	int suma = 0;
	int *kolor_wierzcholka;
	int wierzcholek = 0;
	kolor_wierzcholka = new int[V];
	for (int i = 0; i < V; i++)
		kolor_wierzcholka[i] = i;  // koloruje wierzcholki 

	while (drzewo.size() < V - 1)
	{
		nowa.poczatek = wierzcholek;
		for (int i = 0; i < lista_sasiadujaca[wierzcholek].size(); i++)
		{
			// sprawdzenie, czy drugi koniec krawedzi nalezy do drzewa z wierzcholkiem 0 
			if (kolor_wierzcholka[lista_sasiadujaca[wierzcholek][i].sasiad] != 0)
			{
				nowa.koniec = lista_sasiadujaca[wierzcholek][i].sasiad;
				nowa.w = lista_sasiadujaca[wierzcholek][i].waga;
				lista_krawedzi.push_back(nowa);
			}
		}

		sortuj_wektor(&lista_krawedzi); // sortuje krawedzie odwrotnie, bo z vectora zdejmuje sie od tylu

		for (bool cykl = true; cykl;)
		{
			nowa = lista_krawedzi[lista_krawedzi.size() - 1];  // biore najkrotsza krawedz
			lista_krawedzi.pop_back();

			if ((kolor_wierzcholka[nowa.poczatek] == 0 && kolor_wierzcholka[nowa.koniec] != 0) || (kolor_wierzcholka[nowa.poczatek] != 0 && kolor_wierzcholka[nowa.koniec] == 0))
				cykl = false;
		}

		drzewo.push_back(nowa); //dolaczenie krawedzi
		suma = suma + nowa.w; //policzenie wagi drzewa

		if (kolor_wierzcholka[nowa.poczatek] == 0)
			wierzcholek = nowa.koniec;

		else
			wierzcholek = nowa.poczatek;

		kolor_wierzcholka[wierzcholek] = 0; //przypisanie go do drzewa 0

	}
	cout << "Wynik algorytmu Prima: " << suma << endl;
	delete[] kolor_wierzcholka;
}


Graf::~Graf()
{
	delete[] lista_sasiadujaca;
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
