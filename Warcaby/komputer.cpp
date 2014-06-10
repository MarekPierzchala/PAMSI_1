#include "gra.h"

using namespace std;

string nieb;

int gra::zwroc_pole(int x, int y)
{
	if (x == 0 && y == 0) return 0; if (x == 0 && y == 1) return 1; if (x == 0 && y == 2) return 2; if (x == 0 && y == 3) return 3;
	if (x == 0 && y == 4) return 4; if (x == 0 && y == 5) return 5; if (x == 0 && y == 6) return 6; if (x == 0 && y == 7) return 7;
	if (x == 1 && y == 0) return 8; if (x == 1 && y == 1) return 9; if (x == 1 && y == 2) return 10; if (x == 1 && y == 3) return 11;
	if (x == 1 && y == 4) return 12; if (x == 1 && y == 5) return 13; if (x == 1 && y == 6) return 14; if (x == 1 && y == 7) return 15;
	if (x == 2 && y == 0) return 16; if (x == 2 && y == 1) return 17; if (x == 2 && y == 2) return 18; if (x == 2 && y == 3) return 19;
	if (x == 2 && y == 4) return 20; if (x == 2 && y == 5) return 21; if (x == 2 && y == 6) return 22; if (x == 2 && y == 7) return 23;
	if (x == 3 && y == 0) return 24; if (x == 3 && y == 1) return 25; if (x == 3 && y == 2) return 26; if (x == 3 && y == 3) return 27;
	if (x == 3 && y == 4) return 28; if (x == 3 && y == 5) return 29; if (x == 3 && y == 6) return 30; if (x == 3 && y == 7) return 31;
	if (x == 4 && y == 0) return 32; if (x == 4 && y == 1) return 33; if (x == 4 && y == 2) return 34; if (x == 4 && y == 3) return 35;
	if (x == 4 && y == 4) return 36; if (x == 4 && y == 5) return 37; if (x == 4 && y == 6) return 38; if (x == 4 && y == 7) return 39;
	if (x == 5 && y == 0) return 40; if (x == 5 && y == 1) return 41; if (x == 5 && y == 2) return 42; if (x == 5 && y == 3) return 43;
	if (x == 5 && y == 4) return 44; if (x == 5 && y == 5) return 45; if (x == 5 && y == 6) return 46; if (x == 5 && y == 7) return 47;
	if (x == 6 && y == 0) return 48; if (x == 6 && y == 1) return 49; if (x == 6 && y == 2) return 50; if (x == 6 && y == 3) return 51;
	if (x == 6 && y == 4) return 52; if (x == 6 && y == 5) return 53; if (x == 6 && y == 6) return 54; if (x == 6 && y == 7) return 55;
	if (x == 7 && y == 0) return 56; if (x == 7 && y == 1) return 57; if (x == 7 && y == 2) return 58; if (x == 7 && y == 3) return 59;
	if (x == 7 && y == 4) return 60; if (x == 7 && y == 5) return 61; if (x == 7 && y == 6) return 62; if (x == 7 && y == 7) return 63;
}

miejsce gra::zwroc_wspolrzedne(int x)
{
	miejsce pom;
	if (x == 0) { pom.x = 0; pom.y = 0; }if (x == 1) { pom.x = 0; pom.y = 1; } if (x == 2) { pom.x = 0; pom.y = 2; } if (x == 3) { pom.x = 0; pom.y = 3; }
	if (x == 4) { pom.x = 0; pom.y = 4; } if (x == 5) { pom.x = 0; pom.y = 5; } if (x == 6) { pom.x = 0; pom.y = 6; } if (x == 7) { pom.x = 0; pom.y = 7; }
	if (x == 8) { pom.x = 1; pom.y = 0; }if (x == 9) { pom.x = 1; pom.y = 1; } if (x == 10) { pom.x = 1; pom.y = 2; } if (x == 11) { pom.x = 1; pom.y = 3; }
	if (x == 12) { pom.x = 1; pom.y = 4; } if (x == 13) { pom.x = 1; pom.y = 5; } if (x == 14) { pom.x = 1; pom.y = 6; } if (x == 15) { pom.x = 1; pom.y = 7; }
	if (x == 16) { pom.x = 2; pom.y = 0; }if (x == 17) { pom.x = 2; pom.y = 1; } if (x == 18) { pom.x = 2; pom.y = 2; } if (x == 19) { pom.x = 2; pom.y = 3; }
	if (x == 20) { pom.x = 2; pom.y = 4; } if (x == 21) { pom.x = 2; pom.y = 5; } if (x == 22) { pom.x = 2; pom.y = 6; } if (x == 23) { pom.x =2 ; pom.y = 7; }
	if (x == 24) { pom.x = 3; pom.y = 0; }if (x == 25) { pom.x = 3; pom.y = 1; } if (x == 26) { pom.x = 3; pom.y = 2; } if (x == 27) { pom.x = 3; pom.y = 3; }
	if (x == 28) { pom.x = 3; pom.y = 4; } if (x == 29) { pom.x = 3; pom.y = 5; } if (x == 30) { pom.x = 3; pom.y = 6; } if (x == 31) { pom.x = 3; pom.y = 7; }
	if (x == 32) { pom.x = 4; pom.y = 0; }if (x == 33) { pom.x = 4; pom.y = 1; } if (x == 34) { pom.x = 4; pom.y = 2; } if (x == 35) { pom.x = 4; pom.y = 3; }
	if (x == 36) { pom.x = 4; pom.y = 4; } if (x == 37) { pom.x = 4; pom.y = 5; } if (x == 38) { pom.x = 4; pom.y = 6; } if (x == 39) { pom.x = 4; pom.y = 7; }
	if (x == 40) { pom.x = 5; pom.y = 0; }if (x == 41) { pom.x = 5; pom.y = 1; } if (x == 42) { pom.x = 5; pom.y = 2; } if (x == 43) { pom.x = 5; pom.y = 3; }
	if (x == 44) { pom.x = 5; pom.y = 4; } if (x == 45) { pom.x = 5; pom.y = 5; } if (x == 46) { pom.x = 5; pom.y = 6; } if (x == 47) { pom.x = 5; pom.y = 7; }
	if (x == 48) { pom.x = 6; pom.y = 0; }if (x == 49) { pom.x = 6; pom.y = 1; } if (x == 50) { pom.x = 6; pom.y = 2; } if (x == 51) { pom.x = 6; pom.y = 3; }
	if (x == 52) { pom.x = 6; pom.y = 4; } if (x == 53) { pom.x = 6; pom.y = 5; } if (x == 54) { pom.x = 6; pom.y = 6; } if (x == 55) { pom.x = 6; pom.y = 7; }
	if (x == 56) { pom.x = 7; pom.y = 0; }if (x == 57) { pom.x = 7; pom.y = 1; } if (x == 58) { pom.x = 7; pom.y = 2; } if (x == 59) { pom.x = 7; pom.y = 3; }
	if (x == 60) { pom.x = 7; pom.y = 4; } if (x == 61) { pom.x = 7; pom.y = 5; } if (x == 62) { pom.x = 7; pom.y = 6; } if (x == 63) { pom.x = 7; pom.y = 7; }
	return pom;
}


bool gra::czy_pionek(int kto, miejsce pozycja)
{
	if (Plansza[pozycja.x][pozycja.y] == kto)
		return true;
	return false;
}


bool gra::czy_mozliwosc_ruchu(int kto, miejsce pozycja)
{
	int przeciwnik;
	if (kto == 1) przeciwnik = 2;
	if (kto == 2) przeciwnik = 1;
	if (czy_pionek(kto, pozycja) == true)
	{
		if (kto == 1)
		{
			if (Plansza[pozycja.x + 1][pozycja.y + 1] == 0 && pozycja.x<7 && pozycja.y<7)
				return true;
			else
			{
				if (Plansza[pozycja.x + 1][pozycja.y - 1] == 0 && pozycja.x<7 && pozycja.y>0)
					return true;
			}
		}
		if (kto == 2)
		{
			if (Plansza[pozycja.x - 1][pozycja.y + 1] == 0 && pozycja.x>0  && pozycja.y<7)
				return true;
			else
			{
				if (Plansza[pozycja.x - 1][pozycja.y - 1] == 0 && pozycja.x>0 && pozycja.y>0)
					return true;
			}
		}
	}
	return false;
}

bool gra::czy_mozliwosc_bicia(int kto, miejsce pozycja)
{
	int przeciwnik;
	if (kto == 1) przeciwnik = 2;
	if (kto == 2) przeciwnik = 1;
	if (czy_pionek(kto, pozycja) == true)	
	{
		if (kto == 1)
		{
			if (pozycja.x > 5) return false;
			if (Plansza[pozycja.x + 2][pozycja.y - 2] == 0 && pozycja.x<6 && pozycja.y>1)
			{
				if (Plansza[pozycja.x + 1][pozycja.y - 1] == przeciwnik)
					return true;
			}
			if (Plansza[pozycja.x + 2][pozycja.y + 2] == 0 && pozycja.x<6 && pozycja.y<6)
			{
				if (Plansza[pozycja.x + 1][pozycja.y + 1] == przeciwnik)
					return true;
			}
		}
		if (kto == 2)
		{
			if (Plansza[pozycja.x - 2][pozycja.y - 2] == 0 && pozycja.x>1 && pozycja.y>1)
			{
				if (Plansza[pozycja.x - 1][pozycja.y - 1] == przeciwnik)
					return true;
			}
			if (Plansza[pozycja.x - 2][pozycja.y + 2] == 0 && pozycja.x>1 && pozycja.y<6)
			{
				if (Plansza[pozycja.x - 1][pozycja.y + 1] == przeciwnik)
					return true;
			}
		}
	}
	return false;
}

bool gra::czy_mozliwosc_biciaN( int kto, miejsce pozycja)
{
	int przeciwnik;
	if (kto == 1) przeciwnik = 2;
	if (kto == 2) przeciwnik = 1;
	miejsce pom, pom1;
	if (czy_pionek(kto, pozycja) == true)
	{
		if (kto == 1)
		{
			if (pozycja.x > 5) return false;
			pom.x = pozycja.x + 3; pom.y = pozycja.y + 1;
			pom1.x = pozycja.x + 1; pom1.y = pozycja.y + 3;
			if (Plansza[pozycja.x + 1][pozycja.y + 1] == przeciwnik && Plansza[pozycja.x + 2][pozycja.y + 2] == 0 && (Plansza[pozycja.x + 3][pozycja.y + 3] != przeciwnik ))
				return true;
			pom.x = pozycja.x + 3; pom.y = pozycja.y - 1;
			pom1.x = pozycja.x + 1; pom1.y = pozycja.y - 3;
			if (Plansza[pozycja.x + 1][pozycja.y - 1] == przeciwnik && Plansza[pozycja.x + 2][pozycja.y - 2] == 0 && (Plansza[pozycja.x + 3][pozycja.y - 3] != przeciwnik))
				return true;
		}
		if (kto == 2)
		{
			pom.x = pozycja.x - 3; pom.y = pozycja.y + 1;
			pom1.x = pozycja.x -1; pom1.y = pozycja.y + 3;
			if (Plansza[pozycja.x - 1][pozycja.y + 1] == przeciwnik && Plansza[pozycja.x - 2][pozycja.y + 2] == 0 && (Plansza[pozycja.x - 3][pozycja.y + 3] != przeciwnik))
				return true;
			pom.x = pozycja.x - 3; pom.y = pozycja.y - 1;
			pom1.x = pozycja.x - 1; pom1.y = pozycja.y - 3;
			if (Plansza[pozycja.x - 1][pozycja.y - 1] == przeciwnik && Plansza[pozycja.x - 2][pozycja.y - 2] == 0 && (Plansza[pozycja.x - 3][pozycja.y - 3] != przeciwnik))
				return true;
		}
	}
	return false;
}

bool gra::czy_mozliwosc_ruchuN( int kto, miejsce pozycja)
{
	int przeciwnik;
	if (kto == 1) przeciwnik = 2;
	if (kto == 2) przeciwnik = 1;
	miejsce pom, pom1;
	if (czy_pionek(kto, pozycja) == true)
	{
		if (kto == 1)
		{
			pom.x = pozycja.x + 2; pom.y = 0;
			pom1.x = pozycja.x; pom1.y = 2;
			if (pozycja.y == 0 && Plansza[pozycja.x + 1][1] == 0 && (Plansza[pozycja.x + 2][2] != przeciwnik) && pozycja.x<6 )
				return true;
			pom.x = pozycja.x + 2; pom.y = 7;
			pom1.x = pozycja.x; pom1.y = 5;
			if (pozycja.y == 7 && Plansza[pozycja.x + 1][6] == 0 && (Plansza[pozycja.x + 2][5] != przeciwnik) && pozycja.x<6 )
				return true;
			else
			{
				pom.x = pozycja.x + 2; pom.y = pozycja.y;
				pom1.x = pozycja.x; pom1.y = pozycja.y + 2;
				if (Plansza[pozycja.x + 1][pozycja.y + 1] == 0 && (Plansza[pozycja.x + 2][pozycja.y + 2] != przeciwnik) && pozycja.x<6 && pozycja.y<6)
					return true;
				pom.x = pozycja.x + 2; pom.y = pozycja.y;
				pom1.x = pozycja.x; pom1.y = pozycja.y - 2;
				if (Plansza[pozycja.x + 1][pozycja.y - 1] == 0 && (Plansza[pozycja.x + 2][pozycja.y - 2] != przeciwnik) && pozycja.x<6 && pozycja.y>1)
					return true;
			}
		}
		if (kto==2)
		{
			pom.x = pozycja.x + 2; pom.y = 0;
			pom1.x = pozycja.x; pom1.y = 2;
			if (pozycja.y == 0 && Plansza[pozycja.x + 1][1] == 0 && (Plansza[pozycja.x - 2][2] != przeciwnik))
				return true;
			pom.x = pozycja.x + 2; pom.y = 7;
			pom1.x = pozycja.x; pom1.y = 5;
			if (pozycja.y == 7 && Plansza[pozycja.x + 1][6] == 0 && (Plansza[pozycja.x - 2][5] != przeciwnik))
				return true;
			else
			{
				pom.x = pozycja.x + 2; pom.y = pozycja.y;
				pom1.x = pozycja.x; pom1.y = pozycja.y + 2;
				if (Plansza[pozycja.x + 1][pozycja.y + 1] == 0 && (Plansza[pozycja.x - 2][pozycja.y + 2] != przeciwnik))
					return true;
				pom.x = pozycja.x + 2; pom.y = pozycja.y;
				pom1.x = pozycja.x; pom1.y = pozycja.y - 2;
				if (Plansza[pozycja.x + 1][pozycja.y - 1] == 0 && (Plansza[pozycja.x - 2][pozycja.y - 2] != przeciwnik))
					return true;
			}
		}
	}
	return false;
}

void gra::stworz_liste_ruchow(int kto)
{
	int lic = 0;
	int przeciwnik;
	if (kto == 1) przeciwnik = 2;
	if (kto == 2) przeciwnik = 1;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (Plansza[i][j] == kto || Plansza[i][j]==7)
			{
				lic++;
				int stan;
				ruch pom; 
				miejsce tmp; tmp.x = i; tmp.y = j;
				if (czy_bicie_damkiK(tmp) == true)
				{
					cout << endl << "ICH BIN BICIE" << endl;
					//prawa gora
					if (Plansza[tmp.x][tmp.y] == 7 && (Plansza[tmp.x - 1][tmp.y + 1] == 2 || Plansza[tmp.x - 1][tmp.y + 1] == 8) && Plansza[tmp.x - 2][tmp.y + 2] == 0)
					{
						pom.stoi.x = i - 2; pom.stoi.y = j + 2;
						pom.stal.x = i; pom.stal.y = j;
						stan = OcenStan(pom, kto);
						cout << endl<< "YROERHJ IHRE " << endl;
						if (Plansza[tmp.x - 1][tmp.y + 3] == 2 || Plansza[tmp.x - 1][tmp.y + 3] == 8)
						{
							cout << "TUTUTRUT " << endl;
							pom.waga = 15 - 10;
							lista.push_back(pom);
						}
						else
						{
							cout << "TUTUT " << endl; 
							pom.waga = 15;
							pom.waga = 15 + stan;
							lista.push_back(pom);
						}
						pom.co = "BPB";
						//mozliwosci.push(pom);
						
						//lista.push_front(pom);
					}
					//prawy dol
					if (Plansza[tmp.x][tmp.y] == 7 && (Plansza[tmp.x + 1][tmp.y + 1] == 2 || Plansza[tmp.x + 1][tmp.y + 1] == 8) && Plansza[tmp.x + 2][tmp.y + 2] == 0)
					{
						pom.stoi.x = i + 2; pom.stoi.y = j + 2;
						pom.stal.x = i; pom.stal.y = j;
						stan = OcenStan(pom, kto);
						if ((Plansza[i + 3][j + 3] == 2 || Plansza[i + 3][j + 3] == 8) || (Plansza[i + 3][j + 1] == 2 || Plansza[i + 3][j + 1] == 8))
						{
							pom.waga = 15 - 10;
							lista.push_back(pom);
						}
						else
						{
							cout << "TUTUT " << endl;
							pom.waga = 15;
							pom.waga = 15 + stan;
							lista.push_back(pom);
						}
						pom.co = "BPB";
						//mozliwosci.push(pom);
						//lista.push_back(pom);
						//lista.push_front(pom);
					}
					//lewy dol
					if (Plansza[tmp.x][tmp.y] == 7 && (Plansza[tmp.x + 1][tmp.y - 1] == 2 || Plansza[tmp.x + 1][tmp.y - 1] == 8) && Plansza[tmp.x + 2][tmp.y - 2] == 0)
					{
						pom.stoi.x = i + 2; pom.stoi.y = j - 2;
						pom.stal.x = i; pom.stal.y = j;
						stan = OcenStan(pom, kto);
						if ((Plansza[i - 3][j - 1] == 2 || Plansza[i - 3][j - 1] == 8) || (Plansza[i - 3][j - 3] == 2 || Plansza[i - 3][j - 3] == 8))
						{
							pom.waga = 15 - 10;
							lista.push_back(pom);
						}
						else
						{
							cout << "TUTUT " << endl;
							pom.waga = 15;
							pom.waga = 15 + stan;
							lista.push_back(pom);
						}
						pom.co = "BPB";
						//mozliwosci.push(pom);
						//lista.push_back(pom);
						//lista.push_front(pom);
					}
					//lewa gora
					if (Plansza[tmp.x][tmp.y] == 7 && (Plansza[tmp.x - 1][tmp.y - 1] == 2 || Plansza[tmp.x - 1][tmp.y - 1] == 8) && Plansza[tmp.x - 2][tmp.y - 2] == 0)
					{
						pom.stoi.x = i - 2; pom.stoi.y = j - 2;
						pom.stal.x = i; pom.stal.y = j;
						stan = OcenStan(pom, kto);
						if (Plansza[i + 1][j + 3] == 2 || Plansza[i + 1][j + 3] == 8)
						{
							pom.waga = 15 - 10;
							lista.push_back(pom);
						}
						else
						{
							pom.waga = 15;
							pom.waga = 15 + stan;
							lista.push_back(pom);
						}
						pom.co = "BPB";
						//mozliwosci.push(pom);
					//	lista.push_back(pom);
						//lista.push_front(pom);
					}
				
				}
				if (czy_ruch_damkiK(tmp) == true)
				{
					cout << endl << "ICH BIN RUCH" << endl;
					//lewa gora
					if (Plansza[tmp.x][tmp.y] == 7 && Plansza[tmp.x - 1][tmp.y - 1] == 0 && ((Plansza[tmp.x - 2][tmp.y] != 2 || Plansza[tmp.x - 2][tmp.y] != 8) || (Plansza[tmp.x - 2][tmp.y - 2] != 2 || Plansza[tmp.x - 2][tmp.y - 2] != 8)))
					{
						pom.stoi.x = i - 1; pom.stoi.y = j - 1;
						pom.stal.x = i; pom.stal.y = j;
						stan = OcenStan(pom, kto);
						if (Plansza[i][j - 2] == 2 || Plansza[i][j - 2] == 8)
							pom.waga = 13 - 8;
						else
						{
							pom.waga = 13;
							pom.waga = 13 + stan;
						}
						pom.co = "BPB";
						//mozliwosci.push(pom);
						lista.push_back(pom);
						//lista.push_front(pom);
					}
					//prawa gora
					if (Plansza[tmp.x][tmp.y] == 7 && Plansza[tmp.x - 1][tmp.y + 1] == 0 && ((Plansza[tmp.x - 2][tmp.y] != 2 || Plansza[tmp.x - 2][tmp.y] != 8) || (Plansza[tmp.x - 2][tmp.y + 2] != 2 || Plansza[tmp.x - 2][tmp.y + 2] != 8)))
					{
						cout << endl << "TUTAJ HULTAJE!" << endl;
						pom.stoi.x = i - 1; pom.stoi.y = j + 1;
						pom.stal.x = i; pom.stal.y = j;
						stan = OcenStan(pom, kto);
						if (Plansza[i][j + 2] == 2 || Plansza[i][j + 2] == 8)
							pom.waga = 13 - 8;
						else
						{
							pom.waga = 13;
							pom.waga = 13 + stan;
						}
						pom.co = "BPB";
						//mozliwosci.push(pom);
						lista.push_back(pom);
						//lista.push_front(pom);
					}
					//prawy dol 
					if (Plansza[tmp.x][tmp.y] == 7 && Plansza[tmp.x + 1][tmp.y + 1] == 0 )
					{
						pom.stoi.x = i + 1; pom.stoi.y = j + 1;
						pom.stal.x = i; pom.stal.y = j;
						stan = OcenStan(pom, kto);
						if ((Plansza[i + 2][j] == 2 || Plansza[i + 2][j] == 8) || (Plansza[i + 2][j+2] == 2 || Plansza[i + 2][j+2] == 8))
							pom.waga = 13 - 8;
						else
						{
							pom.waga = 13;
							pom.waga = 13 + stan;
						}
						//mozliwosci.push(pom);
						lista.push_back(pom);
						//lista.push_front(pom);
					}
					//lewy dol
					if (Plansza[tmp.x][tmp.y] == 7 && Plansza[tmp.x + 1][tmp.y - 1] == 0)
					{
						pom.stoi.x = i + 1; pom.stoi.y = j - 1;
						pom.stal.x = i; pom.stal.y = j;
						stan = OcenStan(pom, kto);
						if ((Plansza[i + 2][j] == 2 || Plansza[i + 2][j] == 8) || (Plansza[i + 2][j - 2] == 2 || Plansza[i + 2][j - 2] == 8))
							pom.waga = 13 - 8;
						else
						{
							pom.waga = 13;
							pom.waga = 13 + stan;
						}
						pom.co = "BPB";
						//mozliwosci.push(pom);
						lista.push_back(pom);
						//lista.push_front(pom);
					}
				}
				if (ruch_po_damke(tmp) == true)
				{
					if (Plansza[6][tmp.y] && Plansza[7][tmp.y + 1] == 0)
					{
						pom.stoi.x = 7; pom.stoi.y = j + 1;
						pom.stal.x = 6; pom.stal.y = j;
						stan = OcenStan(pom, kto);
						pom.waga = 12;
						pom.waga = 12 + stan;
						pom.co = "BPB";
						//mozliwosci.push(pom);
						lista.push_back(pom);
						//lista.push_front(pom);
					}
					if (Plansza[6][tmp.y] && Plansza[7][tmp.y - 1] == 0)
					{
						pom.stoi.x = 7; pom.stoi.y = j - 1;
						pom.stal.x = 6; pom.stal.y = j;
						stan = OcenStan(pom, kto);
						pom.waga = 12;
						pom.waga = 12 + stan;
						pom.co = "BPB";
						//mozliwosci.push(pom);
						lista.push_back(pom);
						//lista.push_front(pom);
					}
				}
				if (czy_mozliwosc_biciaN(kto, tmp) == true)
				{
					//cout << endl << "MOZLIWOSC BICIA!" << endl;
					if (Plansza[i + 2][j + 2] == 0 && Plansza[i + 1][j + 1] == przeciwnik)
					{
						pom.stoi.x = i + 2; pom.stoi.y = j + 2;
						pom.stal.x = i; pom.stal.y = j;
						stan = OcenStan(pom, kto);
						pom.waga = 14;
						pom.waga = 14 + stan;
						pom.co = "BPB";
						//mozliwosci.push(pom);
						lista.push_back(pom);
						//lista.push_front(pom);
					}
					if (Plansza[i + 2][j - 2] == 0 && Plansza[i + 1][j - 1] == przeciwnik)
					{
						pom.stoi.x = i + 2; pom.stoi.y = j - 2;
						pom.stal.x = i; pom.stal.y = j;
						stan = OcenStan(pom, kto);
						//pom.waga = 10 ;
						pom.waga = 14 + stan;
						pom.co = "BLB";
						//mozliwosci.push(pom);
						lista.push_back(pom);
						//lista.push_front(pom);
					}
				}
				else
				{
					if (czy_mozliwosc_bicia(kto, tmp) == true)
					{
					//	cout << endl << "MOZLIWOSC BICIA! NB" << endl;
						if (Plansza[i + 2][j + 2] == 0 && Plansza[i + 1][j + 1] == przeciwnik)
						{
							pom.stoi.x = i + 2; pom.stoi.y = j + 2;
							pom.stal.x = i; pom.stal.y = j;
							stan = OcenStan(pom, kto);
							//pom.waga = 8 ;
							pom.waga = 13 + stan;
							pom.co = "BP";
						//	mozliwosci.push(pom);
							lista.push_back(pom);
							//lista.push_front(pom);
						}
						if (Plansza[i + 2][j - 2] == 0 && Plansza[i + 1][j - 1] == przeciwnik)
						{
							pom.stoi.x = i + 2; pom.stoi.y = j - 2;
							pom.stal.x = i; pom.stal.y = j;
							stan = OcenStan(pom, kto);
							//pom.waga = 8 ;
							pom.waga = 13 + stan;
							pom.co = "BL";
							//mozliwosci.push(pom);
							lista.push_back(pom);
							//lista.push_front(pom);
						}
					}
				}
				if (czy_mozliwosc_ruchuN(kto, tmp) == true)
				{
				//	cout << endl << "MOZLIWOSC ruchu!" << endl;
					if (Plansza[i + 1][j + 1] == 0)
					{
						//cout << endl << "JEEESTEM" << endl;
						pom.stoi.x = i + 1; pom.stoi.y = j + 1;
						pom.stal.x = i; pom.stal.y = j;
						stan = OcenStan(pom, kto);
						//pom.waga = 6 ;
						pom.waga = 6 + stan;
						pom.co = "RPB";
						//cout << endl << "TUO " << endl;
						//mozliwosci.push(pom);
						
						lista.push_back(pom);
						//lista.push_front(pom);
					}
					if (Plansza[i + 1][j - 1] == 0)
					{
						//cout << endl << "TUO " << endl;
						pom.stoi.x = i + 1; pom.stoi.y = j - 1;
						pom.stal.x = i; pom.stal.y = j;
						stan = OcenStan(pom, kto);
						//pom.waga = 6 ;
						pom.waga = 6 + stan;
						pom.co = "RLB";
						//mozliwosci.push(pom);
						lista.push_back(pom);
						//lista.push_front(pom);
					}

				}
				else
				{
					if (czy_mozliwosc_ruchu(kto, tmp) == true)
					{
						//cout << endl << "MOZLIWOSC ruchu nb!" << endl;
						if (Plansza[i + 1][j + 1] == 0)
						{
							pom.stoi.x = i + 1; pom.stoi.y = j + 1;
							pom.stal.x = i; pom.stal.y = j;
							stan = OcenStan(pom, kto);
							//pom.waga = 4 ;
							pom.waga = 4 + stan;
							pom.co = "RP";
							//mozliwosci.push(pom);
							lista.push_back(pom);
							//lista.push_front(pom);
						}
						if (Plansza[i + 1][j - 1] == 0)
						{
							pom.stoi.x = i + 1; pom.stoi.y = j - 1;
							pom.stal.x = i; pom.stal.y = j;
							stan = OcenStan(pom, kto);
							//pom.waga = 4 ;
							pom.waga = 4 + stan;
							pom.co = "RL";
							//mozliwosci.push(pom);
							lista.push_back(pom);
							//lista.push_front(pom);
						}

					}
				}
				if (chron_sie(tmp, 1) == true)
				{
					miejsce t;
					int x = tmp.x;
					int y = tmp.y;
					if (Plansza[x][y] == 1 && Plansza[x + 1][y + 1] == 2 && Plansza[x - 1][y - 1] == 0)
					{
						 t.x = x - 2; t.y = y;
						if (czy_mozliwosc_ruchuN(1, t) == true)
						{
							pom.stoi.x = x - 1; pom.stoi.y = y - 1;
							pom.stal.x = x-2; pom.stal.y = y;
							stan = OcenStan(pom, kto);
							//pom.waga = 4 ;
							pom.waga = 11 + stan;
						}
						 t.x = x - 2; t.y = y-2;
						if (czy_mozliwosc_ruchuN(1, t) == true)
						{
							pom.stoi.x = x - 1; pom.stoi.y = y - 1;
							pom.stal.x = x - 2; pom.stal.y = y-2;
							stan = OcenStan(pom, kto);
							//pom.waga = 4 ;
							pom.waga = 11 + stan;
						}
					}
					if (Plansza[x][y] == 1 && Plansza[x + 1][y - 1] == 2 && Plansza[x - 1][y + 1] == 0)
					{
						 t.x = x - 2; t.y = y;
						if (czy_mozliwosc_ruchuN(1, t) == true)
						{
							pom.stoi.x = x - 1; pom.stoi.y = y + 1;
							pom.stal.x = x - 2; pom.stal.y = y;
							stan = OcenStan(pom, kto);
							//pom.waga = 4 ;
							pom.waga = 11 + stan;
						}
						 t.x = x - 2; t.y = y + 2;
						if (czy_mozliwosc_ruchuN(1, t) == true)
						{
							pom.stoi.x = x - 1; pom.stoi.y = y + 1;
							pom.stal.x = x - 2; pom.stal.y = y +2;
							stan = OcenStan(pom, kto);
							//pom.waga = 4 ;
							pom.waga = 11 + stan;
						}
					}
				}
				if (czy_luka(1, tmp) == true)
				{
					//cout << endl << endl << "LUKA" << endl << endl;
					//w lewo
					if (Plansza[tmp.x + 1][tmp.y - 1] == 0 && Plansza[tmp.x + 2][tmp.y - 2] == 1)
					{
						pom.stoi.x = i + 1; pom.stoi.y = j + 1;
						pom.stal.x = i; pom.stal.y = j;
						stan = OcenStan(pom, kto);
						//pom.waga = 4 ;
						pom.waga = 7 + stan;
						pom.co = "RL";
						//mozliwosci.push(pom);
						lista.push_back(pom);
						//lista.push_front(pom);
					}
					//w prawo
					if (Plansza[tmp.x + 1][tmp.y + 1] == 0 && Plansza[tmp.x + 2][tmp.y + 2] == 1)
					{
						pom.stoi.x = i + 1; pom.stoi.y = j - 1;
						pom.stal.x = i; pom.stal.y = j;
						stan = OcenStan(pom, kto);
						//pom.waga = 4 ;
						pom.waga = 7 + stan;
						pom.co = "RL";
						//mozliwosci.push(pom);
						lista.push_back(pom);
						//lista.push_front(pom);
					}
				}

			}
		}

	}
	if (kto == 2)
	{
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (Plansza[i][j] == kto || Plansza[i][j]==7)
				{
					int stan;
					ruch pom; pom.stoi.x = i; pom.stoi.y = j;
					miejsce tmp; tmp.x = i; tmp.y = j;
					if (czy_bicie_damkiK(tmp) == true)
					{

					}
					if (czy_mozliwosc_biciaN(kto, tmp) == true)
					{
					
						if (Plansza[i - 2][j + 2] == 0 && Plansza[i - 1][j + 1] == przeciwnik)
						{
							pom.stoi.x = i - 2; pom.stoi.y = j + 2;
							pom.stal.x = i; pom.stal.y = j;
							stan = OcenStan(pom, kto);
							pom.waga = 10 ;
							pom.co = "BPB";
							//mozliwosci.push(pom);
							lista1.push_back(pom);
							//lista.push_front(pom);
						}
						if (Plansza[i - 2][j - 2] == 0 && Plansza[i - 1][j - 1] == przeciwnik)
						{
							pom.stoi.x = i - 2; pom.stoi.y = j - 2;
							pom.stal.x = i; pom.stal.y = j;
							stan = OcenStan(pom, kto);
							pom.waga = 10 ;
							pom.co = "BLB";
							//mozliwosci.push(pom);
							lista1.push_back(pom);
							//lista.push_front(pom);
						}
						
					}
					else
					{
						if (czy_mozliwosc_bicia(kto, tmp) == true)
						{
							
							if (Plansza[i - 2][j + 2] == 0 && Plansza[i - 1][j + 1] == przeciwnik)
							{
								pom.stoi.x = i - 2; pom.stoi.y = j + 2;
								pom.stal.x = i; pom.stal.y = j;
								stan = OcenStan(pom, kto);
								pom.waga = 8 ;
								pom.co = "BP";
								//mozliwosci.push(pom);
								lista1.push_back(pom);
								//lista.push_front(pom);
							}
							if (Plansza[i - 2][j - 2] == 0 && Plansza[i - 1][j - 1] == przeciwnik)
							{
								pom.stoi.x = i - 2; pom.stoi.y = j - 2;
								pom.stal.x = i; pom.stal.y = j;
								stan = OcenStan(pom, kto);
								pom.waga = 8 ;
								pom.co = "BL";
								//mozliwosci.push(pom);
								lista1.push_back(pom);
								//lista.push_front(pom);
							}
						
						}
					}
					if (czy_mozliwosc_ruchuN(kto, tmp) == true)
					{
						
						if (Plansza[i - 1][j + 1] == 0)
						{
							pom.stoi.x = i - 1; pom.stoi.y = j + 1;
							pom.stal.x = i; pom.stal.y = j;
							stan = OcenStan(pom, kto);
							pom.waga = 6 ;

							pom.co = "RPB";
							//mozliwosci.push(pom);
							lista1.push_back(pom);
							//lista.push_front(pom);
						}
						if (Plansza[i- 1][j - 1] == 0)
						{
							pom.stoi.x = i - 1; pom.stoi.y = j - 1;
							pom.stal.x = i; pom.stal.y = j;
							stan = OcenStan(pom, kto);
							pom.waga = 6 ;
							pom.co = "RLB";
							//mozliwosci.push(pom);
							lista1.push_back(pom);
							//lista.push_front(pom);
						}
						
					}
					else
					{
						if (czy_mozliwosc_ruchu(kto, tmp) == true)
						{
					
							if (Plansza[i - 1][j + 1] == 0)
							{
								pom.stoi.x = i - 1; pom.stoi.y = j + 1;
								pom.stal.x = i; pom.stal.y = j;
								stan = OcenStan(pom, kto);
								pom.waga = 4 ;
								pom.co = "RP";
								//mozliwosci.push(pom);
								lista1.push_back(pom);
								//lista.push_front(pom);
							}
							if (Plansza[i -1][j - 1] == 0)
							{
								pom.stoi.x = i - 1; pom.stoi.y = j - 1;
								pom.stal.x = i; pom.stal.y = j;
								stan = OcenStan(pom, kto);
								pom.waga = 4 ;
								pom.co = "RL";
								//mozliwosci.push(pom);
								lista1.push_back(pom);
								//lista.push_front(pom);
							}
							
						}
					}
				}
			}
		}
	}
}

bool gra::chron_sie(miejsce pozycja, int kto)
{
	int x = pozycja.x;
	int y = pozycja.y;
	if (Plansza[x][y] == 1 && Plansza[x + 1][y + 1] == 2 && Plansza[x - 1][y - 1] == 0)
		return true;
	if (Plansza[x][y] == 1 && Plansza[x + 1][y - 1] == 2 && Plansza[x - 1][y + 1] == 0)
		return true;

	return false;
}


int gra::OcenStan(ruch rch, int gracz)
{
	int punkty = 0;

	if (gracz == 1)
	{
	punkty++;
	if (rch.stoi.x > 1 && rch.stoi.x < 4) punkty = punkty + 5; 
	if (rch.stoi.x > 3 && rch.stoi.x < 6) punkty = punkty + 15;
	if (rch.stoi.x > 5 && rch.stoi.x < 8) punkty = punkty + 25;
	}

	return 0;
}

bool gra::czy_luka(int kto, miejsce pozycja)
{
	int x = pozycja.x;
	int y = pozycja.y;
	if (kto == 1)
	{
		//w prawo
		if (Plansza[x + 1][y + 1] == 0 && Plansza[x + 2][y + 2] == 1) return true;
		// w lewo
		if (Plansza[x + 1][y - 1] == 0 && Plansza[x + 2][y - 2] == 1) return true;
	}
	return false;
}

bool gra::ruch_po_damke(miejsce stoi)
{
	if (stoi.x == 6 && Plansza[stoi.x][stoi.y] == 1 && (Plansza[7][stoi.y + 1] == 0 || Plansza[7][stoi.y - 1] == 0))
		return true;
	return false;
}


ruch gra::rusz_sie(ruch rch, int gracz)
{
	if (gracz == 1)
	{
		if (Plansza[rch.stal.x][rch.stal.y] == 7)
		{
			//cout << endl << "SIODEMKA! " << endl;
			Plansza[rch.stoi.x][rch.stoi.y] = 7;
			Plansza[rch.stal.x][rch.stal.y] = 0;
			if (rch.stoi.x < rch.stal.x + 1)
			{
				if (rch.stoi.y > rch.stal.y)
					Plansza[rch.stoi.x - 1][rch.stoi.y - 1] = 0;
				if (rch.stoi.y < rch.stal.y)
					Plansza[rch.stal.x + 1][rch.stal.y - 1] = 0;
			}
			else
			{
				if (rch.stoi.x < rch.stal.x + 1)
				{
					if (rch.stoi.y > rch.stal.y)
						Plansza[rch.stoi.x - 1][rch.stoi.y - 1] = 0;
					if (rch.stoi.y < rch.stal.y)
						Plansza[rch.stal.x + 1][rch.stal.y - 1] = 0;
				}
			}
			return rch;
		}
		else
		{
			if (Plansza[rch.stal.x][rch.stal.y] == 1)
			{
				//cout << endl << "JEDYNKA! " << endl;
				Plansza[rch.stoi.x][rch.stoi.y] = 1;
				Plansza[rch.stal.x][rch.stal.y] = 0;
				if (rch.stoi.x < rch.stal.x + 1)
				{
					if (rch.stoi.y > rch.stal.y)
						Plansza[rch.stoi.x - 1][rch.stoi.y - 1] = 0;
					if (rch.stoi.y < rch.stal.y)
						Plansza[rch.stal.x + 1][rch.stal.y - 1] = 0;
				}
				else
				{
					if (rch.stoi.x > rch.stal.x +1)
					{
						if (rch.stoi.y > rch.stal.y)
							Plansza[rch.stoi.x - 1][rch.stoi.y - 1] = 0;
						if (rch.stoi.y < rch.stal.y)
							Plansza[rch.stal.x + 1][rch.stal.y - 1] = 0;
					}
				}
			}
			return rch;
		}

	}
	if (gracz == 2)
	{
		Plansza[rch.stal.x][rch.stal.y] = 0;
		Plansza[rch.stoi.x][rch.stoi.y] = 2;
		return rch;
	}
}

void gra::cofnij_sie(ruch rch, int gracz)
{
	if (gracz == 1)
	{
		Plansza[rch.stal.x][rch.stal.y] = 1;
		Plansza[rch.stoi.x][rch.stoi.y] = 0;
	}
	if (gracz == 2)
	{
		Plansza[rch.stal.x][rch.stal.y] = 2;
		Plansza[rch.stoi.x][rch.stoi.y] = 0;
	}
}



void gra::ruch_komputera()
{
	stworz_liste_ruchow(aktualny);
	cout << endl << "JESTEM " << endl;
	ruch pom;
	int x = lista.size();
	for (int i= 0; i < x; i++)
	{
		mozliwosci.push(lista[i]);
	}
	pom = mozliwosci.top();
	mozliwosci.pop();
	cout << endl << "RUSZAM " << pom.stal.x << " - " << pom.stal.y << endl << "NA " << pom.stoi.x << " - " << pom.stoi.y << " w: "<< pom.waga<< endl;
	if (czy_mozliwosc_bicia(aktualny, pom.stal) == true || czy_mozliwosc_biciaN(aktualny, pom.stal) == true)
	{
		cout << endl << "BIJE!" << endl;
		Plansza[pom.stal.x][pom.stal.y] = 0;
		Plansza[pom.stoi.x][pom.stoi.y] = aktualny;
		if (pom.stoi.y > pom.stal.y)
			Plansza[pom.stoi.x - 1][pom.stoi.y - 1] = 0;
		if (pom.stoi.y < pom.stal.y)
			Plansza[pom.stoi.x - 1][pom.stoi.y + 1] = 0;
		if (aktualny == 1) dwojki--;
		if (aktualny == 2) jedynki--;
		if (czy_mozliwosc_bicia(aktualny, pom.stoi) == true || czy_mozliwosc_biciaN(aktualny, pom.stal) == true)
		{
			int t = mozliwosci.size();
			for (int i = 0; i < t; i++)
				mozliwosci.pop();
			ruch_komputera();
		}
	}
	else
	{
		cout << endl << "RUCH!" << endl;
		Plansza[pom.stal.x][pom.stal.y] = 0;
		Plansza[pom.stoi.x][pom.stoi.y] = aktualny;
	}
	int q = mozliwosci.size();
	for (int i = 0; i < q; i++)
		mozliwosci.pop();
	int w= lista.size();
	for (int i = 0; i < w; i++)
		lista.pop_back();
	aktualny = 2;
}

bool gra::czy_bicie_damkiK(miejsce pozycja)
{
	int x = pozycja.x; int y = pozycja.y;
	if (Plansza[x][y] == 7 && (Plansza[x - 1][y - 1] == 2 || Plansza[x - 1][y - 1] == 8) && Plansza[x - 2][y - 2] == 0)
		return true;
	if (Plansza[x][y] == 7 && (Plansza[x - 1][y + 1] == 2 || Plansza[x - 1][y + 1] == 8) && Plansza[x - 2][y + 2] == 0)
		return true;
	if (Plansza[x][y] == 7 && (Plansza[x + 1][y - 1] == 2 || Plansza[x + 1][y - 1] == 8) && Plansza[x + 2][y - 2] == 0)
		return true;
	if (Plansza[x][y] == 7 && (Plansza[x + 1][y + 1] == 2 || Plansza[x + 1][y + 1] == 8) && Plansza[x + 2][y + 2] == 0)
		return true;

	return false;
}

void gra::bicie_damkiK(miejsce poczatkowe, miejsce docelowe)
{
	if (poczatkowe.x > docelowe.x)
	{
		if (poczatkowe.y > docelowe.y)
		{
			Plansza[poczatkowe.x][poczatkowe.y] = 0;
			Plansza[docelowe.x][docelowe.y] = 7;
			Plansza[docelowe.x + 1][docelowe.y + 1] = 0;
		}
		else
		{
			Plansza[poczatkowe.x][poczatkowe.y] = 0;
			Plansza[docelowe.x][docelowe.y] = 7;
			Plansza[docelowe.x + 1][docelowe.y - 1] = 0;
		}
	}
	else
	{
		if (poczatkowe.y > docelowe.y)
		{
			Plansza[poczatkowe.x][poczatkowe.y] = 0;
			Plansza[docelowe.x][docelowe.y] = 7;
			Plansza[docelowe.x - 1][docelowe.y + 1] = 0;
		}
		else
		{
			Plansza[poczatkowe.x][poczatkowe.y] = 0;
			Plansza[docelowe.x][docelowe.y] = 7;
			Plansza[docelowe.x - 1][docelowe.y - 1] = 0;
		}
	}
}

void gra::ruch_damkiK(miejsce poczatkowe, miejsce docelowe)
{
	Plansza[poczatkowe.x][poczatkowe.y] = 0;
	Plansza[docelowe.x][docelowe.y] = 7;
}

bool gra::czy_ruch_damkiK(miejsce pozycja)
{
	int x = pozycja.x; int y = pozycja.y;
	if (Plansza[x][y] == 7 && Plansza[x - 1][y - 1] == 0)
		return true;
	if (Plansza[x][y] == 7 && Plansza[x - 1][y + 1] == 0)
		return true;
	if (Plansza[x][y] == 7 && Plansza[x + 1][y - 1] == 0)
		return true;
	if (Plansza[x][y] == 7 && Plansza[x + 1][y + 1] == 0)
		return true;

	return false;
}

void gra::cz_damkaK()
{
	for (int j = 0; j < 8; j++)
	{
		if (Plansza[7][j] == 1)
			Plansza[7][j] = 7;
	}
}


ruch gra::minmax(int gracz, int glebokosc)
{
	int najlepszy=0;
	int max = 0;
	if (glebokosc == 2) return naj;
	int przeciwnik = 0;
	if (gracz == 1) przeciwnik = 2;
	if (gracz == 2) przeciwnik = 1;

	stworz_liste_ruchow(gracz);
	vector<ruch> ruchy;

	if (gracz == 1) ruchy=lista;
	if (gracz == 2) ruchy=lista1;
	/*if (gracz == 1)
	{
		cout << endl << "GR" << gracz << endl;
		for (int i = 0; i < ruchy.size(); i++)
			cout << ruchy[i].stal.x << "-" << ruchy[i].stal.y << " na " << ruchy[i].stoi.x << "-" << ruchy[i].stoi.y << " W: " << ruchy[i].waga << endl;
		system("pause");
	}*/
	for (int i = 0; i < ruchy.size(); i++)
	{
		int dod[8][8];
		for (int k = 0; k < 8; k++)
		{
			for (int t = 0; t < 8; t++)
				dod[k][t] = Plansza[k][t];
		}
		//rusz_sie(ruchy[i], gracz);
		int wynik = ruchy[i].waga;
		//cofnij_sie(ruchy[i], gracz);
		if (gracz == 1 && wynik>najlepszy)
		{
			//cout << endl << endl << "ICHH BINN! " << endl << endl;
			najlepszy = wynik;
			naj = ruchy[i];
			cout << endl << "NAJLE: " << najlepszy << endl << "IND: " << naj.stal.x << "-" << naj.stal.y << " na" << naj.stoi.x << "-" << naj.stoi.y << endl;
		
		}
		minmax(przeciwnik, glebokosc + 1);
	}

	if (gracz == 1)
	{
		int x = lista.size();
		for (int i = 0; i < x; i++)
			lista.pop_back();
	}
	if (gracz == 2) 
	{
		int x = lista1.size();
		for (int i = 0; i < x; i++)
			lista1.pop_back();
	}
	return naj;
}