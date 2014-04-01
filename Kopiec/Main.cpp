#include "Kopiec.h"
#include <cstdlib>
#include <time.h>
using namespace std;

int main()
{
	Kopiec<int> drzewo;
	int wartosci;
	drzewo.wstaw(1); drzewo.wstaw(2);
	srand((unsigned)time(NULL));
	for (int i = 0; i<1024; i++)
	{
		wartosci = (rand() % 4440)+1;
		drzewo.wstaw(wartosci);
	}
	for (int i = 0; i<drzewo.rozmiar(); i++)
	{
		drzewo.napraw_w_dol(i);
	}
	cout << "Rodzic: " << drzewo.zwroc_rodzica(12) << " wartosc: " << drzewo[drzewo.zwroc_rodzica(12)] << endl;
	cout << "Dzieci: " << endl << "Lewe: " << drzewo[drzewo.zwroc_lewe_dziecko(5)] << endl << "prawe: " << drzewo[drzewo.zwroc_prawe_dziecko(5)] << endl;
	drzewo.wyswietl();
	drzewo.pop();
	for (int i = 0; i<drzewo.rozmiar(); i++)
	{
		drzewo.napraw_w_dol(i);
	}
	cout << endl << endl;
	drzewo.wyswietl();
	system("pause");
}