#include <iostream>
#include "Lista.h"
using namespace std;
/*!
* \file
* \brief Glowny plik programu
*
* Plik zawiera main
*/

/*!
* \brief Funkcja main
*
* Funkcja main
*/
int main()
{
	int n;
	Lista test;
	Lista test2;
	test.wczytaj("plik1.txt");
	n = test.ilosc_powtorzen();

	LARGE_INTEGER performanceCountStart, performanceCountEnd;
	performanceCountStart = startTimer(); //zapamiętujemy czas początkowy 

	for (int i = 0; i < n; i++)
	{
		test.zeruj();
		test2.zeruj();
		test.wczytaj("plik1.txt");
		test.pomnoz();
		//cout << "tablica" << endl;
		//test.wyswietl();
		test2.wczytaj("plik2.txt");
		//cout << "tab 2" << endl;
		//test2.wyswietl();
	}

	performanceCountEnd = endTimer(); //zapamiętujemy koniec czasu 
	double tm = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
	cout << endl << "Czas:" << tm << endl;

	if (test.porownaj(test2) == 1)
	{
		cout << "Wyniki sa identyczne!" << endl;
	}
	else
	{
		cout << "Blad! nie wszystko sie zgadza!" << endl;
	}



	getchar();
	return 0;

}
