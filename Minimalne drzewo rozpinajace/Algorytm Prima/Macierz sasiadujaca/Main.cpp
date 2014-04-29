#include "Graf.h"

using namespace std;

int main()
{
	Graf tab1;

	//tab1.stworz_macierz_sasiedztwa("plik1.txt");
	tab1.generuj_macierz(4, 61);
	tab1.wyswietl();
	tab1.prim();

	system("pause");
}