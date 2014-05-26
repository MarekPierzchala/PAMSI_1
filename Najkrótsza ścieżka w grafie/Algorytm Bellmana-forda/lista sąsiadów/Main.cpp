#include "bf.h"

using namespace std;

int main()
{
	Graf tab;
	bool pom = false;


	//tab.wyswietl();
	while (pom != true)
	{
		//tab.stworz_liste_z_pliku("plik2.txt");
		tab.generuj_liste(1000, 80);
		pom = tab.czy_spojny();
	}
	//tab.wyswietl();

	LARGE_INTEGER performanceCountStart, performanceCountEnd;
	LARGE_INTEGER Freq, TimeDiff;
	performanceCountStart = startTimer(); //zapamiętujemy czas początkowy  

	tab.bf();

	performanceCountEnd = endTimer(); //zapamiętujemy koniec czasu 
	QueryPerformanceFrequency(&Freq);
	long long tm = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
	TimeDiff.QuadPart = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
	double DeltaTime = (double)TimeDiff.QuadPart / (double)Freq.QuadPart;
	cout << endl << "Czas:" << DeltaTime << "[s]" << endl;//---
	//cout<<endl<<"Czas:"<<DeltaTime*1000<<"[ms]"<<endl;//---
	//cout<<endl<<"Czas:"<<DeltaTime*1000000<<"[us]"<<endl;//---
	//cout<<endl<<"Czas:"<<DeltaTime*1000000000<<"[ns]"<<endl;//---


	system("pause");
}