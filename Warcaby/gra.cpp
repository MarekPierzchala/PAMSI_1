#include "gra.h"

using namespace std;

void gra::graj()
{
	int kto = aktualny;
	miejsce poczatkowe;
	miejsce docelowe;
	cout << "Teraz kolej gracza " << "(" << kto << ")" << endl;
	cout << "Ktory pionek chcesz przesunac ?" << endl;
	cin >> poczatkowe.x >> poczatkowe.y;
	cout << endl << "W ktore miejsce? " << endl;
	cin >> docelowe.x >> docelowe.y;
	if (czy_bicie_damki(poczatkowe) == true)
	{
		bicie_damki(poczatkowe, docelowe);
	}
	if (czy_ruch_damki(poczatkowe) == true)
	{
		ruch_damki(poczatkowe, docelowe);
	}
	if (czy_ruch(kto, poczatkowe, docelowe) == true)
	{
		wykonaj_ruch(kto, poczatkowe, docelowe);
	}
	else
	{
		if (czy_bicie(kto, poczatkowe, docelowe) == true)
		{
			wykonaj_bicie(kto, poczatkowe, docelowe);
		}
		else
		{
			cout << "WCHODZE!" << endl;
			graj();
		}
	}
	damka_dwa();
	aktualny = 1;

}

gra::gra()
{
	aktualny = 2;
	jedynki = 8;
	dwojki = 8;
	for (int i = 0; i < 8; i++)  // ustawia puste pola
	{
		for (int j = 0; j < 8; j++)
		{
			Plansza[i][j] = 0;  // puste pole 
		}
	}

	for (int i = 0; i < 8; i++) // ustawia niedostepne pola
	{
		for (int j = 0; j < 8; j = j + 2)
		{
			if (i == 1 || i == 3 || i == 5 || i == 7)
			{
				if (j == 0 || j == 2 || j == 4 || j == 6)
				{
					j = j + 1;
				}
			}
			Plansza[i][j] = 9;  // pole niedostepne 
		}
	}


	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (i == 0 || i == 1)
			{
				if (Plansza[i][j] == 0)
					Plansza[i][j] = 1; // pionki czarne
			}
			if (i == 6 || i == 7)
			{
				if (Plansza[i][j] == 0)
					Plansza[i][j] = 2; // pionki biale
			}
		}
	}
}



void gra::wyswietl()
{
	for (int i = 0; i < 8; i++)
	{
		if (i == 0)
			cout << setw(6) << i;
		else
			cout << setw(3) << i;
	}
	cout << endl << endl;
	for (int i = 0; i < 8; i++)
	{
		cout << i << ": ";
		for (int j = 0; j < 8; j++)
		{
			cout << setw(3) << Plansza[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

bool gra::czy_bicie(int kto, miejsce poczatkowe, miejsce docelowe)
{
	if (kto == 1)  // pionek bialy
	{
		if (Plansza[poczatkowe.x][poczatkowe.y] != 1)  // sprawdza czy jest tam bialy pionek
		{
			//cout << "Blad! Podales zle wspolrzedne, tu nie ma pionka 2, sprobuje jeszcze raz" << endl;
			return false;
		}
		if (poczatkowe.x == 0)
		{
			if (docelowe.x != 2)
			{
				//cout << "Blad! Niedozwolony ruch, sprobuje jeszcze raz  QQQ" << endl;
				return false;
			}
		}
		else
		{
			if (docelowe.x != poczatkowe.x + 2)
			{
				//cout << "Blad! Niedozwolony ruch, sprobuje jeszcze raz WWW" << endl;
				return false;
			}
		}
		if (Plansza[docelowe.x][docelowe.y] != 0)
		{
			//cout << "Blad! Pole zajete, sprobuje jeszcze raz EEE" << endl;
			return false;
		}
		if (docelowe.y > poczatkowe.y)
		{
			if (Plansza[docelowe.x - 1][docelowe.y - 1] != 2)
			{
				//cout << "Blad! Co ty chcesz zbic? RRR" << endl;
				return false;
			}
		}
		if (docelowe.y < poczatkowe.y)
		{
			if (Plansza[docelowe.x - 1][docelowe.y + 1] != 2)
			{
				//cout << "Blad! Co ty chcesz zbic? TTT" << endl;
				return false;
			}
		}
	}


	if (kto == 2)  // pionek bialy
	{
		if (Plansza[poczatkowe.x][poczatkowe.y] != 2  )  // sprawdza czy jest tam bialy pionek
		{
			//cout << "Blad! Podales zle wspolrzedne, tu nie ma pionka 2, sprobuj jeszcze raz" << endl;
			return false;
		}
		if (poczatkowe.x == 7)
		{
			if (docelowe.x != 5)
			{
				//cout << "Blad! Niedozwolony ruch, sprobuje jeszcze raz YYY" << endl;
				return false;
			}
		}
		else
		{
			if (docelowe.x != poczatkowe.x - 2)
			{ 
				//cout << "Blad! Niedozwolony ruch, sprobuje jeszcze raz UUU" << endl;
				return false;
			}
		}
		if (Plansza[docelowe.x][docelowe.y] != 0)
		{
			//cout << "Blad! Pole zajete, sprobuje jeszcze raz III" << endl;
			return false;
		}
		if (docelowe.y > poczatkowe.y)
		{
			if (Plansza[docelowe.x + 1][docelowe.y - 1] != 1)
			{
				//cout << "Blad! Co ty chcesz zbic? OOO" << endl;
				return false;
			}
		}
		if (docelowe.y < poczatkowe.y)
		{
			if (Plansza[docelowe.x + 1][docelowe.y + 1] != 1)
			{
				//cout << "Blad! Co ty chcesz zbic? PPP" << endl;
				return false;
			}
		}
	}
	return true;
}

bool gra::czy_ruch(int kto, miejsce poczatkowe, miejsce docelowe)
{

	if (poczatkowe.x<0 || poczatkowe.x>7 || poczatkowe.y<0 || poczatkowe.y>7 || docelowe.x<0 || docelowe.x>7 || docelowe.y<0 || docelowe.y>7)
	{
		cout << "Blad! Wpisales zle wspolrzedne, zakres 0 - 7, sprobuj jeszcze raz" << endl;
		return false;
	}


		if (poczatkowe.y == 0)
		{
			if (docelowe.y != 1)
			{
				cout << "Blad! Niedozwolony ruch, sprobuje jeszcze raz AAA" << endl;
				return false;
			}
		}
		if (poczatkowe.y == 7)
		{
			if (docelowe.y != 6)
			{
				cout << "Blad! Niedozwolony ruch, sprobuje jeszcze raz SSS" << endl;
				return false;
			}
		}
		else
		{
			if (docelowe.y != poczatkowe.y - 1 && docelowe.y != poczatkowe.y + 1)
			{
				cout << "Blad! Niedozwolony ruch, sprobuje jeszcze raz DDD" << endl;
				return false;

			}
		}
	

	if (kto == 1)  // pionek czarny 
	{
		if (Plansza[poczatkowe.x][poczatkowe.y] != 1) // sprawdza, czy jest tam czarny pionek
		{
			cout << "Blad! Podales zle wspolrzedne, tu nie ma pionka 1, sprobuje jeszcze raz FFF" << endl;
			return false;
		}
		if (poczatkowe.x == 0)
		{
			if (docelowe.x != 1)
			{
				cout << "Blad! Niedozwolony ruch, sprobuje jeszcze raz GGG" << endl;
				return false;
			}
		}
		else
		{
			if (docelowe.x != poczatkowe.x + 1)
			{
				cout << "Blad! Niedozwolony ruch, sprobuje jeszcze raz HHH" << endl;
				return false;
			}
		}
		if (Plansza[docelowe.x][docelowe.y] != 0)
		{
			cout << "Blad! Pole zajete, sprobuje jeszcze raz JJJ" << endl;
			return false;
		}

		if (Plansza[poczatkowe.x][poczatkowe.y] == 1) // wykonuje ruch czarnym pionkiem
		{
			return true;
		}
	}

	if (kto == 2)  // pionek bialy
	{
		if ((Plansza[poczatkowe.x][poczatkowe.y] != 2) && (Plansza[poczatkowe.x][poczatkowe.y] != 8))  // sprawdza czy jest tam bialy pionek
		{
			cout << "Blad! Podales zle wspolrzedne, tu nie ma pionka 2, sprobuje jeszcze raz KKK" << endl;
			return false;
		}
		if (poczatkowe.x == 7)
		{
			if (docelowe.x != 6)
			{
				cout << "Blad! Niedozwolony ruch, sprobuje jeszcze raz LLL" << endl;
				return false;
			}
		}
		else
		{
			if (docelowe.x != poczatkowe.x - 1 )
			{
				cout << docelowe.x << "-" << poczatkowe.x;
				cout << "Blad! Niedozwolony ruch, sprobuje jeszcze raz ZZZ" << endl;
				return false;
			}
		}
		if (Plansza[docelowe.x][docelowe.y] != 0)
		{
			cout << "Blad! Pole zajete, sprobuje jeszcze raz XXX" << endl;
			return false;
		}
		if (Plansza[poczatkowe.x][poczatkowe.y] == 2)  // wykonuje ruch pionkiem bialym
		{
			return true;
		}
	}
}


void gra::wykonaj_ruch(int kto, miejsce poczatkowe, miejsce docelowe)
{



	if (kto == 1)  // pionek czarny 
	{
			Plansza[poczatkowe.x][poczatkowe.y] = 0;
			Plansza[docelowe.x][docelowe.y] = 1;
	}

	if (kto == 2)  // pionek bialy
	{	
			Plansza[poczatkowe.x][poczatkowe.y] = 0;
			Plansza[docelowe.x][docelowe.y] = 2;
	}

}

void gra::wykonaj_bicie(int kto, miejsce poczatkowe, miejsce docelowe)
{



	if (kto == 1)  // pionek czarny 
	{
		Plansza[poczatkowe.x][poczatkowe.y] = 0;
		Plansza[docelowe.x][docelowe.y] = 1;
		if (docelowe.x > poczatkowe.x)
		{
			if (docelowe.y > poczatkowe.y)
			{
				Plansza[docelowe.x - 1][docelowe.y - 1] = 0;
				//dwojki--;
			}
			else
			{
				Plansza[docelowe.x - 1][docelowe.y + 1] = 0;
				//dwojki--;
			}
		}
		else
		{
			if (docelowe.y > poczatkowe.y)
			{
				Plansza[docelowe.x + 1][docelowe.y - 1] = 0;
				//dwojki--;
			}
			else
			{
				Plansza[docelowe.x + 1][docelowe.y + 1] = 0;
				//dwojki--;
			}
		}
	}

	if (kto == 2)  // pionek bialy
	{
		Plansza[poczatkowe.x][poczatkowe.y] = 0;
		Plansza[docelowe.x][docelowe.y] = 2;
		if (docelowe.x > poczatkowe.x)
		{
			if (docelowe.y > poczatkowe.y)
			{
				Plansza[docelowe.x - 1][docelowe.y - 1] = 0;
				//jedynki--;
			}
			else
			{
				Plansza[docelowe.x - 1][docelowe.y + 1] = 0;
				//jedynki--;
			}
		}
		else
		{
			if (docelowe.y > poczatkowe.y)
			{
				Plansza[docelowe.x + 1][docelowe.y - 1] = 0;
				//jedynki--;
			}
			else
			{
				Plansza[docelowe.x + 1][docelowe.y + 1] = 0;
				//jedynki--;
			}
		}
	}

}

void gra::damka_dwa()
{
	for (int j = 0; j < 8; j++)
	{
		if (Plansza[0][j] == 2)
			Plansza[0][j] = 8;
	}
}

bool gra::czy_bicie_damki(miejsce pozycja)
{
	int x = pozycja.x; int y = pozycja.y;
	if (Plansza[x][y] == 8 && (Plansza[x - 1][y - 1] == 1 || Plansza[x - 1][y - 1] == 7) && Plansza[x - 2][y - 2] == 0)
		return true;
	if (Plansza[x][y] == 8 && (Plansza[x - 1][y + 1] == 1 || Plansza[x - 1][y + 1] == 7) && Plansza[x - 2][y + 2] == 0)
		return true;
	if (Plansza[x][y] == 8 && (Plansza[x + 1][y - 1] == 1 || Plansza[x + 1][y - 1] == 7) && Plansza[x + 2][y - 2] == 0)
		return true;
	if (Plansza[x][y] == 8 && (Plansza[x + 1][y + 1] == 1 || Plansza[x + 1][y + 1] == 7) && Plansza[x + 2][y + 2] == 0)
		return true;

	return false;
}

void gra::bicie_damki(miejsce poczatkowe, miejsce docelowe)
{
	if (poczatkowe.x > docelowe.x)
	{
		if (poczatkowe.y > docelowe.y)
		{
			Plansza[poczatkowe.x][poczatkowe.y] = 0;
			Plansza[docelowe.x][docelowe.y] = 8;
			Plansza[docelowe.x + 1][docelowe.y + 1] = 0;
		}
		else
		{
			Plansza[poczatkowe.x][poczatkowe.y] = 0;
			Plansza[docelowe.x][docelowe.y] = 8;
			Plansza[docelowe.x + 1][docelowe.y - 1] = 0;
		}
	}
	else
	{
		if (poczatkowe.y > docelowe.y)
		{
			Plansza[poczatkowe.x][poczatkowe.y] = 0;
			Plansza[docelowe.x][docelowe.y] = 8;
			Plansza[docelowe.x - 1][docelowe.y + 1] = 0;
		}
		else
		{
			Plansza[poczatkowe.x][poczatkowe.y] = 0;
			Plansza[docelowe.x][docelowe.y] = 8;
			Plansza[docelowe.x - 1][docelowe.y - 1] = 0;
		}
	}
}

void gra::ruch_damki(miejsce poczatkowe, miejsce docelowe)
{
	Plansza[poczatkowe.x][poczatkowe.y] = 0;
	Plansza[docelowe.x][docelowe.y] = 8;
}

bool gra::czy_ruch_damki(miejsce pozycja)
{
	int x = pozycja.x; int y = pozycja.y;
	if (Plansza[x][y] == 8  && Plansza[x - 1][y - 1] == 0)
		return true;
	if (Plansza[x][y] == 8  && Plansza[x - 1][y + 1] == 0)
		return true;
	if (Plansza[x][y] == 8  && Plansza[x + 1][y - 1] == 0)
		return true;
	if (Plansza[x][y] == 8  && Plansza[x + 1][y + 1] == 0)
		return true;

	return false;
}

void gra::zlicz()
{
	jedynki = 0;
	dwojki = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (Plansza[i][j] == 1 || Plansza[i][j] == 7)
				jedynki++;
			if (Plansza[i][j] == 2 || Plansza[i][j] == 8)
				dwojki++;
		}
	}
}