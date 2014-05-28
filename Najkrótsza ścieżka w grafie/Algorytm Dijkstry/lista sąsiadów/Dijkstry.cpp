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

bool operator < (const Wezel &k1, const Wezel &k2)
{
	return (k1.g > k2.g);
}


int Graf::dijkstry(int a, int b)
{
	boost::heap::fibonacci_heap<Wezel> Q;  // kopiec fibonacciego 
	boost::heap::fibonacci_heap<Wezel>::handle_type *handle = new boost::heap::fibonacci_heap<Wezel>::handle_type[V]; // tablica uchwytow 
	bool *odwiedzone = new bool[V];  // tablica odwiedzonych wierzcholkow
	bool *czy_w_kolejce = new bool[V]; // tablica, ktora sprawdza, czy dany wezel jest juz w kolejce priorytetowej
	int *droga = new int[V];  // tablica z poprzednimi wierzcholkami 
	Wezel *koszt = new Wezel[V];   // tablica z wierzcholkami, po ktorych sie poruszamy  

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
		Wezel y = Q.top();
		int x = y.nr;
		Q.pop();
		czy_w_kolejce[x] = false;  // sciagamy wezel z kolejki 
		for (int i = 0; i < lista_sasiadujaca[x].size(); i++)
		{
			if (odwiedzone[lista_sasiadujaca[x][i].sasiad] == false)
			{
				if (koszt[lista_sasiadujaca[x][i].sasiad].g > koszt[x].g + lista_sasiadujaca[x][i].waga)
				{
					koszt[lista_sasiadujaca[x][i].sasiad].g = koszt[x].g + lista_sasiadujaca[x][i].waga;
					droga[lista_sasiadujaca[x][i].sasiad] = x;

					if (czy_w_kolejce[lista_sasiadujaca[x][i].sasiad] == false)  // sprawdzam, czy dany wezel juz nie jest w kolejce
					{
						handle[koszt[lista_sasiadujaca[x][i].sasiad].nr] = Q.push(koszt[lista_sasiadujaca[x][i].sasiad]); // dodaje sasiadow i dodaje uchwyt na sasiada
						czy_w_kolejce[lista_sasiadujaca[x][i].sasiad] = true;  // wezel jest juz w kolejce 
					}
					else
					{
						Q.update(handle[koszt[lista_sasiadujaca[x][i].sasiad].nr], koszt[lista_sasiadujaca[x][i].sasiad]);  // aktualizuje wierzcholek
					}
				}
				if (czy_w_kolejce[lista_sasiadujaca[x][i].sasiad] == false)  // sprawdzam, czy dany wezel juz nie jest w kolejce
				{
					handle[koszt[lista_sasiadujaca[x][i].sasiad].nr] = Q.push(koszt[lista_sasiadujaca[x][i].sasiad]); // dodaje sasiadow i dodaje uchwyt na sasiada
					czy_w_kolejce[lista_sasiadujaca[x][i].sasiad] = true;  // wezel jest juz w kolejce 
				}
			}
			odwiedzone[x] = true;  // ustawiam odwiedzony wierzcholek
		}
		/*if (odwiedzone[b] == true)
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