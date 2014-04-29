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

void Graf::generuj_macierz(int ilosc, int gestosc)
{
	V = ilosc;  // liczba wierzcholkow 
	int liczba;
	Tablica = new int*[ilosc];  // tworze wiersze macierzy
	for (int i = 0; i < ilosc; i++)
	{
		Tablica[i] = new int[ilosc];  // tworze kolumny macierzy
	}

	for (int i = 0; i < ilosc; i++)
	{
		for (int j = 0; j < i; j++)
		{
			int losowa = rand() % 100; //losowanie liczby pseudolosowej
			if (losowa < gestosc) //(1)
			{
				liczba = rand() % (ilosc * ilosc) + 1;
				Tablica[i][j] = Tablica[j][i] = liczba;//(2)
			}
			else
			{
				Tablica[i][j] = Tablica[j][i] = 0;//(3)
			}

		}
	}

	for (int i = 0; i < ilosc; i++)
	{
		Tablica[i][i] = 0;
	}
}

void Graf::stworz_macierz_sasiedztwa(string nazwapliku)
{
	ifstream plik;
	plik.open(nazwapliku.c_str());
	int v1, v2, wag;
	plik >> V;  // liczba wierzcholkow
	plik >> E;  // liczba krawedzi
	Tablica = new int*[V];
	for (int i = 0; i < V; i++)
	{
		Tablica[i] = new int[V];
	}
	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < V; j++)
		{
			Tablica[i][j] = 0;
		}
	}
	while (plik >> v1 >> v2 >> wag)
	{
		Tablica[v1][v2] = wag;  // zamiast "1" wrzucam wage
		Tablica[v2][v1] = wag;	// zamiast "1" wrzucam wage
	}
}

void Graf::wyswietl()
{
	for (int i = 0; i < V; i++)
	{
		cout << endl << setw(3) << i << ":";
		for (int j = 0; j < V; j++)
		{
			cout << setw(3) << Tablica[i][j];
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
		for (int i = 0; i<V; i++)
		{
			//sprawdzenie, czy drugi koniec krawedzi nalezy do drzewa 0, bo zaczynamy od wierzcholka 0
			//czy nie lezy na przekatnej oraz czy waga jest rozna od zera
			if (kolor_wierzcholka[i] != 0 && i != wierzcholek && Tablica[wierzcholek][i] != 0)
			{
				nowa.koniec = i;
				nowa.w = Tablica[wierzcholek][i];
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
	for (int i = 0; i < V; i++)
	{
		delete[] Tablica[i];
	}
	delete[] Tablica;
}
