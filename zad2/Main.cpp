#include "Tablica.h"
using namespace std;

int main()
{
	Tablica test, test2;
	test.wczytaj("p1.txt");
	//test.zamien(1, 3);
	//test.wyswietl();
	//test.odwroc();
	//test.dodaj_element(13);
	//test.wyswietl();
	test2.wczytaj("p2.txt");
	//test2.wyswietl();
	//cout << endl;
	//test.dodaj_tab(test2);
	//test.wyswietl();
	if (test == test2)
	{
		cout << "ok!!" << endl;
	}
	else
	{
		cout << "zle!!" << endl;
	}

	getchar();

}