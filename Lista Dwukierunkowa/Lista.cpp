#include "Lista.h"

using namespace std;

int main()
{
	element<char> el, el1, el2, el3, el4, el5;
	Lista<char> lis;
	el.dodaj('a');
	el1.dodaj('b');
	el2.dodaj('c');
	el3.dodaj('d');
	el4.dodaj('e');
	el5.dodaj('f');
	iterat<char> it, it1;
	it = lis.wskaznik_na_poczatek();
	lis.dodaj_na_poczatek(it, el);
	lis.dodaj_na_koniec(it, el2);
	it = lis.wskaznik_na_element(el);
	lis.dodaj_za(it, el1);
	

	Lista<char> lis1, lis2;
	
	it1 = lis1.wskaznik_na_poczatek();
	lis1.dodaj_na_poczatek(it, el3);
	lis1.dodaj_na_koniec(it, el5);
	it = lis1.wskaznik_na_element(el3);
	lis1.dodaj_za(it, el4);
	

	lis2 = lis;
	cout << "Lista 1: " << endl;
	lis.wyswietl();
	cout << "Lista 2: " << endl;
	lis1.wyswietl();
	cout << "Lista 3: " << endl;
	lis2.usun_koniec();
	lis2.wyswietl();

	system("pause");
}