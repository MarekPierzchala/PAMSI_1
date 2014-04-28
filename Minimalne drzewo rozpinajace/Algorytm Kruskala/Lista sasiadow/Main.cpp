#include "Graf.h"

using namespace std;

int main()
{
	Graf tab1;
	//tab1.stworz_liste_z_pliku("plik1.txt");
	tab1.generuj_liste(4, 111);
	tab1.wyswietl();
	tab1.kruskal();
	//tab1.wyswietl();
	system("pause");
}