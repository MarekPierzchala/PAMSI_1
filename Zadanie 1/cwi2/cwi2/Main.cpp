#include "Tablica.h"

using namespace std;

int main()
{
	Tablica<char> tab1, tab2, tab3;
	int a, b;
	cout << "podaj rozmiar: ";
	cin >> a;
	tab1.zap_rozm(a);
	cin >> tab1;
	cout << "Tablica 1: " << endl << tab1;
	cout << "rozmiar tablicy: " << tab1.wielkosc() << endl;
	//cout << "poczatek: " << tab1.poczatek() << " i Koniec" << tab1.koniec() << endl;
	
	cout << "podaj rozmiar: ";
	cin >> b;
	tab2.zap_rozm(b);
	cin >> tab2;
	cout << "Tablica 2: " << endl << tab2;
	cout << "rozmiar tablicy: " << tab2.wielkosc() << endl;
	Tablica<char> tab4 = tab2;
	cout << "kopiujacy" << endl << tab4 << endl;
	
	cout << "ZNAK! : " << tab1[2];

	system("pause");
	return 0;
}