#include "Kopiec.h"

using namespace std;

int main()
{
	Kopiec tab;
	double suma = 0;
	double czas;
	int a = 0, il;
	ofstream plik("wnioski1q2.csv");
	for (il = 1; il <= 15; il = il + 1)
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
			tab.wstaw(nazwa_pliku1);

			LARGE_INTEGER performanceCountStart, performanceCountEnd;
			LARGE_INTEGER Freq, TimeDiff;
			performanceCountStart = startTimer(); //zapamiętujemy czas początkowy 

			tab.sortuj();

			performanceCountEnd = endTimer(); //zapamiętujemy koniec czasu 
			QueryPerformanceFrequency(&Freq);
			long long tm = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
			TimeDiff.QuadPart = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
			double DeltaTime = (double)TimeDiff.QuadPart / (double)Freq.QuadPart;
			//cout<<endl<<"Time:"<<DeltaTime<<"[s]"<<endl;//---
			//cout<<endl<<"Time:"<<DeltaTime*1000<<"[ms]"<<endl;//---
			//cout<<endl<<"Time:"<<DeltaTime*1000000<<"[us]"<<endl;//---
			//cout<<endl<<"Time:"<<DeltaTime*1000000000<<"[ns]"<<endl;//---
			czas = DeltaTime;

			suma += czas;
		}
		cout << endl << "Czas:" << suma / 5 << endl;
		plik << il << "," << suma / 5 << endl;
		plik.flush();

	}
	cout << endl << "KONIEC" << endl;

	system("pause");
}