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
	V = ilosc;
	Krawedz pomoc;
	int liczba;
	Tablica = new int*[ilosc];
	for (int i = 0; i < ilosc; i++)
	{
		Tablica[i] = new int[ilosc];
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
				pomoc.poczatek = i;
				pomoc.koniec = j;
				pomoc.w = liczba;
				lista_krawedzi.push_back(pomoc);
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
	Krawedz pomoc; 
	plik.open(nazwapliku.c_str());
	int v1, v2;
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
	while (plik >> v1 >> v2 >> pomoc.w)
	{
		pomoc.poczatek = v1;
		pomoc.koniec = v2;
		Tablica[v1][v2] = pomoc.w;  // zamiast "1" wrzucam wage
		Tablica[v2][v1] = pomoc.w;	// zamiast "1" wrzucam wage
		lista_krawedzi.push_back(pomoc);
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

void Graf::kruskal()
{
	Krawedz nowa; 
	int suma=0;
	int *kolor_wierzcholka;
	kolor_wierzcholka = new int[V];
	for (int i = 0; i<V; i++) 
		kolor_wierzcholka[i] = i;  // koloruje wierzcholki 

	sortuj_wektor(&lista_krawedzi);

	while (drzewo.size() < V - 1)
	{
		nowa = lista_krawedzi[lista_krawedzi.size() - 1];
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
	for (int i = 0; i < V; i++)
	{
		delete[] Tablica[i];
	}
	delete[] Tablica;
}

bool Graf::czy_spojny()
{
	int licznik = 0;
	int pomoc;

	bool *wizyta = new bool[V];
	for (int i = 0; i < V; i++)
		wizyta[i] = false;

	pomoc = 0;
	stos.push(pomoc);

	while (!stos.empty())
	{
		pomoc = stos.top();
		stos.pop();
		if (wizyta[pomoc] != true)
		{
			wizyta[pomoc] = true;
			for (int j = 0; j < V; j++)
			{
				int druga;
				if (Tablica[pomoc][j] != 0)
				{
					druga = j;
					if (wizyta[druga] != true)
						stos.push(druga);
				}

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