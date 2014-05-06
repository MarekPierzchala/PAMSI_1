#include "Graf.h"

using namespace std;

int main()
{
	Graf tab1;
	ofstream plik("wnioski1q2.csv");
	bool pom = false;

	//tab1.stworz_liste_z_pliku("plik1.txt");
	while (pom != true)
	{
		tab1.generuj_liste(4096, 50);
		pom = tab1.czy_spojny();
	}
	//tab1.wyswietl();

	LARGE_INTEGER performanceCountStart, performanceCountEnd;
	LARGE_INTEGER Freq, TimeDiff;
	performanceCountStart = startTimer(); //zapamiętujemy czas początkowy  

	tab1.kruskal();

	performanceCountEnd = endTimer(); //zapamiętujemy koniec czasu 
	QueryPerformanceFrequency(&Freq);
	long long tm = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
	TimeDiff.QuadPart = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
	double DeltaTime = (double)TimeDiff.QuadPart / (double)Freq.QuadPart;
	cout << endl << "Czas:" << DeltaTime << "[s]" << endl;//---
	//cout<<endl<<"Czas:"<<DeltaTime*1000<<"[ms]"<<endl;//---

	plik << 4 << " , " << DeltaTime << endl;  // ilosc wierzcholkow i czas
	plik.flush();

	system("pause");
}