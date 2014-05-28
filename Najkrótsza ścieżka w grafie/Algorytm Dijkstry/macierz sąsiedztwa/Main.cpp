#include "Dijkstry.h"

using namespace std;

int main()
{
	Graf tab;
	bool pom = false;
	double suma = 0;
	
	while (pom != true)
	{
		//tab.stworz_macierz_sasiedztwa("plik3.txt");
		tab.generuj_macierz(1000, 100);
		pom = tab.czy_spojny();
	}
	cout << endl;
	//tab.wyswietl();
	for (int i = 0; i < 5; i++)
	{
		LARGE_INTEGER performanceCountStart, performanceCountEnd;
		LARGE_INTEGER Freq, TimeDiff;
		performanceCountStart = startTimer(); //zapamiętujemy czas początkowy  
	
		tab.dijkstry(0, 5);
	
		performanceCountEnd = endTimer(); //zapamiętujemy koniec czasu 
		QueryPerformanceFrequency(&Freq);
		long long tm = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
		TimeDiff.QuadPart = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
		double DeltaTime = (double)TimeDiff.QuadPart / (double)Freq.QuadPart;
		//cout << endl << "Czas:" << DeltaTime << "[s]" << endl;//---
		//cout<<endl<<"Czas:"<<DeltaTime*1000<<"[ms]"<<endl;//---
		//cout<<endl<<"Czas:"<<DeltaTime*1000000<<"[us]"<<endl;//---
		//cout<<endl<<"Czas:"<<DeltaTime*1000000000<<"[ns]"<<endl;//---
		suma += DeltaTime;
	}
	cout << (suma / 5)*1000 << "[ms]" << endl;
	system("pause");
}