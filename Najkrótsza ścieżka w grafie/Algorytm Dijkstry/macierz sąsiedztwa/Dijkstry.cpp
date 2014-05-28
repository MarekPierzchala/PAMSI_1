#include "Dijkstry.h"

using namespace std;


void Graf::generuj_macierz(int ilosc, int gestosc)
{
	V = ilosc;  // liczba wierzcholkow 
	int liczba;
	Tablica = new int*[V];  // tworze wiersze macierzy
	for (int i = 0; i < V; i++)
	{
		Tablica[i] = new int[V];  // tworze kolumny macierzy
	}

	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < i; j++)
		{
			int losowa = rand() % 100; //losowanie liczby pseudolosowej
			if (losowa < gestosc) //(1)
			{
				liczba = (rand() % V) + 1;
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

bool operator < (const Wierzcholek &k1, const Wierzcholek &k2)
{
	return (k1.g > k2.g);
}


int Graf::dijkstry(int a, int b)
{
	boost::heap::fibonacci_heap<Wierzcholek> Q;  // kopiec fibonacciego 
	boost::heap::fibonacci_heap<Wierzcholek>::handle_type *handle = new boost::heap::fibonacci_heap<Wierzcholek>::handle_type[V]; // tablica uchwytow 
	bool *odwiedzone = new bool[V];  // tablica odwiedzonych wierzcholkow
	bool *czy_w_kolejce = new bool[V]; // tablica, ktora sprawdza, czy dany wezel jest juz w kolejce priorytetowej
	int *droga = new int[V];  // tablica z poprzednimi wierzcholkami 
	Wierzcholek *koszt = new Wierzcholek[V];   // tablica z wierzcholkami, po ktorych sie poruszamy  

	for (int i = 0; i < V; i++){
		droga[i] = -1;      // wierzcholek, ktorego na pewno nie ma w grafie 
		odwiedzone[i] = false;
		czy_w_kolejce[i] = false;
		koszt[i].g = 123245325325235235;  // wartosc, zawsze wieksza od drogi 
		koszt[i].nr = i;  // numeruje wierzcholki 
	}
	koszt[a].g = 0;  // wartosc drogi do poczatkowego wierzcholka ustawiam na zero
	handle[a] = Q.push(koszt[a]);  // dodaje wierzcholek poczatkowy na stos i uchwyt do niego
	while (!Q.empty())
	{
		Wierzcholek y = Q.top();
		int x = y.nr;
		Q.pop();
		czy_w_kolejce[x] = false;  // sciagamy wezel z kolejki 
		for (int i = 0; i < V; i++)
		{
			if (Tablica[x][i] != 0 && odwiedzone[i]==false)  
			{
				if (koszt[i].g > koszt[x].g + Tablica[x][i])
				{
					koszt[i].g = koszt[x].g + Tablica[x][i];
					droga[i] = x;
					if (czy_w_kolejce[i] == false)  // sprawdzam, czy dany wezel juz nie jest w kolejce
					{
						handle[koszt[i].nr] = Q.push(koszt[i]); // dodaje sasiadow i dodaje uchwyt na sasiada
						czy_w_kolejce[i] = true;  // wezel jest juz w kolejce 
					}
					else
					{
						Q.update(handle[koszt[i].nr], koszt[i]);  // aktualizuje wierzcholek
					}
				}
				if (czy_w_kolejce[i] == false)  // sprawdzam, czy dany wezel juz nie jest w kolejce
				{
					handle[koszt[i].nr] = Q.push(koszt[i]); // dodaje sasiadow i dodaje uchwyt na sasiada
					czy_w_kolejce[i] = true;  // wezel jest juz w kolejce 
				}
			}
			odwiedzone[x] = true;  // juz sprawdzony wierzcholek 
		}
		/*if (odwiedzone[b] == true)  // znalazl wierzcholek docelowy 
		{
			cout << endl << "koszt dojscia z " << a << " do " << b << ": " << koszt[b].g;
			cout << endl << "Droga: " << b;
			d = b;
			while (droga[d] != a)
			{
				d = droga[d];
				cout << ">" << d;
			}
			cout << ">" << a;

			return 0;
		}*/
	}

	/*cout << "Koszty dojscia z wierzcholka startowego do pozostalych: " << endl << "numer wierzcholka: koszt" << endl;
	for (int i = 0; i < V; i++)
	{
		if (i == a)
			i = i + 1;
		cout << i << ": ";
		int zm;
		zm = i;
		cout << i << ">";
		if (droga[i] != a)
		{
			while (droga[i] != a)
			{
				i = droga[i];
				cout << i << ">";
			}
		}
		cout << a;
		i = zm;
		cout << " = " << koszt[i].g << endl;
		
	}*/
	return 0;
	delete[] handle;
	delete[] czy_w_kolejce;
	delete[] odwiedzone;
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