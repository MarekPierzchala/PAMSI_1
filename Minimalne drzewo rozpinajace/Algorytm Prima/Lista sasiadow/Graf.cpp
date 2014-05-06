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

void Graf::wyswietl()
{
	for (int i = 0; i < V; i++)
	{
		cout << endl << setw(2) << i << ":";
		for (int j = 0; j < lista_sasiadujaca[i].size(); j++)
		{
			cout << setw(2) << lista_sasiadujaca[i][j].waga;
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

	priority_queue<Krawedz, vector<Krawedz>, PorownajKrawedzie> lista;
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
				//lista_krawedzi.push_back(nowa);
				lista.push(nowa);
			}
		}

		//sortuj_wektor(&lista_krawedzi); // sortuje krawedzie odwrotnie, bo z vectora zdejmuje sie od tylu

		for (bool cykl = true; cykl;)
		{
			//nowa = lista_krawedzi[lista_krawedzi.size() - 1];  // biore najkrotsza krawedz
			//lista_krawedzi.pop_back();
			nowa = lista.top();
			lista.pop();
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


Wierzcholek &Wierzcholek::operator= (Wierzcholek const& c1)
{
	Wierzcholek tmp;
	tmp.sasiad = c1.sasiad;
	tmp.waga = c1.waga;
	sasiad = c1.sasiad;
	waga = c1.waga;
	return tmp;
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
