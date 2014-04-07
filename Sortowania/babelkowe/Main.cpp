#include "babelkowe.h"

using namespace std;

int main()
{
	vector<int> tab;
	double suma = 0;
	int a = 0, il;
	ofstream plik("wnioski1q2.csv");
	for (il = 1; il <= 5; il = il +1)
	{
		// zdefiniowane zmienne oraz czesci nazw plikow, ktore sie zmieniac beda;
		string czesc_1 = "plik";
		int liczba = il;
		string czesc_2 = ".txt";
		string nazwa_pliku1;
		suma = 0;

		// konwersja int na string aby nazwa programu mogla sie zmieniac samoczynnie;
		ostringstream numer;
		numer << liczba;
		string element = numer.str();

		//tworzone nazwy plikow
		nazwa_pliku1 = czesc_1 + element + czesc_2;
		for (a = 0; a < 5; a++)
		{
			LARGE_INTEGER performanceCountStart, performanceCountEnd;
			performanceCountStart = startTimer(); //zapamiętujemy czas początkowy 

			tab = generuj_tablice(nazwa_pliku1);
			tab = sortuj(tab);

			performanceCountEnd = endTimer(); //zapamiętujemy koniec czasu 
			double tm = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
			

			suma += tm;
		}
		cout << endl << "Czas:" << suma/5 << endl;
		plik << il << "," << suma/5 << endl;
		plik.flush();

	}
	cout << endl << "KONIEC" << endl;

	system("pause");
}