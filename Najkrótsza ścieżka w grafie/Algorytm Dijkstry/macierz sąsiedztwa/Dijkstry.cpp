#include "Dijkstry.h"

using namespace std;

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

bool Graf::czy_spojny()
{
	int licznik = 0;
	int pomoc;
	stack<int> stos;

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


void Graf::dijkstry()
{
	Krawedz pom, pom1;
	priority_queue<Krawedz, vector<Krawedz>, PorownajKrawedzie> lista;
	int *koszt = new int[V];   // tablica z kosztami przejsc 
	int *droga = new int[V];   // tablica z wierzcholkami, po ktorych sie poruszamy  

	for (int i = 0; i < V; i++)
		droga[i] = -1;      // wierzcholek, ktorego na pewno nie ma w grafie 

	for (int i = 0; i < V; i++)
		koszt[i] = 10000;  // wartosc zawsze wieksza od wagi krawedzi
	koszt[0] = 0;

	for (int wierz = 0; wierz < V; wierz++) // sprawdza po kolei wszystkie wierzcholki 
	{
		// umieszczam w kolejce wszystkie krawedzie wychodzace z danego wierzcholka
		for (int i = 0; i < V; i++)
		{
			if (Tablica[wierz][i]!=0)
			{
				pom.poczatek = wierz;
				pom.koniec = i;
				pom.w = Tablica[wierz][i];
				lista.push(pom);
			}
		}
		while (!lista.empty())
		{
			pom1 = lista.top();
			lista.pop();
			// sprawdzam czy znaleziona droga jest krotsza od poprzedniej 
			if (koszt[pom1.koniec] > koszt[pom1.poczatek] + pom1.w)
			{
				koszt[pom1.koniec] = koszt[pom1.poczatek] + pom1.w;
				droga[pom1.koniec] = pom1.poczatek;
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
		cout << " = " << koszt[i] << endl;
	}
	delete[] koszt;
	delete[] droga;
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
	for (int i = 0; i < V; i++)
	{
		delete[] Tablica[i];
	}
	delete[] Tablica;
}