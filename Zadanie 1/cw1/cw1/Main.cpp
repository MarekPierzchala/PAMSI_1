#include "Tablica.h"

using namespace std;

int main()
{
	Tablica tab1;
	int a, b = 5;
	cout << "podaj rozmiar: ";
	cin >> a;
	tab1.zap_rozm(a);
	tab1.wczytaj(cin);
	tab1.wyswietl(cout);
	//tab1.zm_rozm(b);
	//tab1.wyswietl(cout);
	cout << "TAB 2:"  << endl;
	Tablica tab2(tab1);
	tab2.wyswietl(cout);
	cout << "rozmiar tablicy: " << tab1.wielkosc() << endl;
	tab1.zwolnij();
	system("pause");
}