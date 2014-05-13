#include "Dijkstry.h"

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
		for (int i = 0; i < lista_sasiadujaca[wierz].size(); i++)
		{
			pom.poczatek = wierz;
			pom.koniec = lista_sasiadujaca[wierz][i].sasiad;
			pom.w = lista_sasiadujaca[wierz][i].waga;
			lista.push(pom);
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