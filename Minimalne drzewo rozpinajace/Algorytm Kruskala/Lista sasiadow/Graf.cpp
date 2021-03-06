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
	Krawedz pomoc;
	plik.open(nazwapliku.c_str());
	plik >> V;  // liczba wierzcholkow
	plik >> E;  // liczba krawedzi
	lista_sasiadujaca = new vector<int>[V];
	while (plik >> pomoc.poczatek >> pomoc.koniec >> pomoc.w)
	{
		lista_sasiadujaca[pomoc.poczatek].push_back(pomoc.koniec);
		lista_krawedzi.push_back(pomoc);
		if (pomoc.poczatek!=pomoc.koniec)
			lista_sasiadujaca[pomoc.koniec].push_back(pomoc.poczatek);
	}
}

void Graf::generuj_liste(int ilosc, int gestosc)
{
	V = ilosc;
	lista_sasiadujaca = new vector<int>[V];
	Krawedz pomoc;
	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < i; j++)
		{
			int losowa = rand() % 100;
			if (losowa < gestosc)//(1)
			{
				int k = rand() % (V * V) + 1;
				pomoc.poczatek = i;
				pomoc.koniec = j;
				pomoc.w = k;
				lista_krawedzi.push_back(pomoc);
				lista_sasiadujaca[i].push_back(j);
				if (i!=j)
					lista_sasiadujaca[j].push_back(i);
			}
		}
	}
	for (int i = 0; i <= 1; i++)
	{
		if (lista_sasiadujaca[i].empty())
		{
			lista_sasiadujaca[0].push_back(0);
		}
	}
}

bool Graf::czy_spojny()
{
	int licznik = 0;
	int pomoc;

	bool *wizyta = new bool[V];
	for (int i = 0; i < V; i++)
		wizyta[i] = false;

	pomoc = lista_sasiadujaca[0][0];
	stos.push(pomoc);

	while (!stos.empty())
	{
		pomoc = stos.top();
		stos.pop();
		if (wizyta[pomoc] != true)
		{
			wizyta[pomoc] = true;
			for (int j = 0; j < lista_sasiadujaca[pomoc].size(); j++)
			{
				int druga;
				druga = lista_sasiadujaca[pomoc][j];
				if (wizyta[druga] != true)
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
		for (vector<int>::iterator it = lista_sasiadujaca[i].begin(); it != lista_sasiadujaca[i].end(); it++)
		{
			cout << " " << *it;
		}
	}
	cout << endl;
}

void Graf::kruskal()
{
	Krawedz nowa;
	int suma = 0;
	int *kolor_wierzcholka;
	kolor_wierzcholka = new int[V];
	for (int i = 0; i<V; i++)
		kolor_wierzcholka[i] = i;  // koloruje wierzcholki 

	sortuj_wektor(&lista_krawedzi);

	while (drzewo.size() < V - 1)
	{
		nowa = lista_krawedzi[lista_krawedzi.size() - 1];
		//cout << endl << "TO MAM: " << nowa.poczatek << " - " << nowa.koniec << " w = " << nowa.w << endl;
		lista_krawedzi.pop_back();
		if (kolor_wierzcholka[nowa.poczatek] != kolor_wierzcholka[nowa.koniec])
		{
			drzewo.push_back(nowa); //dolaczenie krawedzi
			suma = suma + nowa.w; //policzenie wagi drzewa

			//przekolorowanie drzewa o wyzszym numerze
			int stary_kolor = max(kolor_wierzcholka[nowa.poczatek], kolor_wierzcholka[nowa.koniec]);
			int nowy_kolor = min(kolor_wierzcholka[nowa.poczatek], kolor_wierzcholka[nowa.koniec]);
			for (int i = 0; i<V; i++)
			{
				if (kolor_wierzcholka[i] == stary_kolor)
					kolor_wierzcholka[i] = nowy_kolor;  // sprawdzam caly czas poprzedni wierzcholek
			}
		}
	}
	cout << "Wynik algorytmu Kruskala: " << suma << endl;
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
