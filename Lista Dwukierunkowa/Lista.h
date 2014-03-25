#pragma once
#include <iostream>
using namespace std;

template <class Typ>
class element{
public:
	element<Typ>* poprzedni;
	element<Typ>* nastepny;
	Typ wartosc;

	element();
	void dodaj(Typ wart);
};

template <class Typ>
class iterat{
public:
	element<Typ>* wskaznik;
	
};

template <class Typ>
class Lista
{
public:
	iterat<Typ> pierwszy;
	//iterat obecny;
	iterat<Typ> ostatni;
	int licznik;
public:
	iterat<Typ> next(iterat<Typ> it);
	iterat<Typ> back(iterat<Typ> it);
	void czy_na_liscie(iterat<Typ> it);
	void dodaj_na_poczatek(iterat<Typ> it, element<Typ> elem);
	void dodaj_na_koniec(iterat<Typ> it, element<Typ> elem);
	void dodaj_przed(iterat<Typ> it, element<Typ> elem);
	void dodaj_za(iterat<Typ> it, element<Typ> elem);
	void usun(iterat<Typ> it);
	void usun_poczatek();
	void usun_koniec();
	void wyswietl();
	void zamien_miejscami(Lista<Typ> &lis);
	iterat<Typ>& operator = (const Lista<Typ> &lis);
	iterat<Typ> wskaznik_na_element(element<Typ> a);
	iterat<Typ> wskaznik_na_poczatek();
	int rozmiar();
	Lista();
	Lista(Lista<Typ> &lis);
	~Lista();
};


/*********************************************************************************************************************************/
/*KONSTRUKTOR WEZLA */
template <class Typ>
element<Typ>::element()
{
	poprzedni = NULL;
	nastepny = NULL;
}


/*********************************************************************************************************************************/
/*FUNKCJA DODAJACA WARTOSC NA DANY WEZEL */
template <class Typ>
void element<Typ>::dodaj(Typ wart)
{
	wartosc = wart;
}


/*********************************************************************************************************************************/
/*FUNKCJA SPRAWDZAJACA CZY DANY ELEMENT JEST NA LISCIE */
template <class Typ>
void Lista<Typ>::czy_na_liscie(iterat<Typ> it)
{
	if (it.wskaznik==NULL)
	{
		cout << "Element nie znajduje sie na liscie! " << endl;
	}
	else
	{
		cout << "Element jest prawidlowo podlaczony ! " << endl;
	}
}



/*********************************************************************************************************************************/
/*FUNKCJA DODAJACA WEZEL NA POCZATEK LISTY */
template <class Typ>
void Lista<Typ>::dodaj_na_poczatek(iterat<Typ> it, element<Typ> elem)
{
	element<Typ>* a = new element<Typ>;
	a->nastepny = pierwszy.wskaznik;
	a->wartosc = elem.wartosc;
	pierwszy.wskaznik = a;
	//obecny.wskaznik = a;
	it.wskaznik = a;
	a->poprzedni = pierwszy.wskaznik;
	if (licznik == 0)
	{
		ostatni.wskaznik = a;
	}
	else
	{
		
		a->nastepny->poprzedni = a;
	}
	elem.nastepny = a->nastepny;
	elem.poprzedni = a->poprzedni;
	elem.wartosc = a->wartosc;
	licznik++;
}


/*********************************************************************************************************************************/
/*FUNKCJA DODAJACA WEZEL NA KONIEC LISTY */
template <class Typ>
void Lista<Typ>::dodaj_na_koniec(iterat<Typ> it, element<Typ> elem)
{
	element<Typ>* a = new element<Typ>;
	a->nastepny = a;
	a->poprzedni = ostatni.wskaznik;
	a->wartosc = elem.wartosc;
	ostatni.wskaznik = a;
	it.wskaznik = a;
	if (licznik == 0)
	{
		pierwszy.wskaznik = a;
		//pierwszy = it;
	}
	else
	{
		ostatni.wskaznik->poprzedni->nastepny = a;
	}
	elem.nastepny = a->nastepny;
	elem.poprzedni = a->poprzedni;
	elem.wartosc = a->wartosc;
	licznik++;
}



/*********************************************************************************************************************************/
/*FUNKCJA DODAJACA WEZEL PRZED WEZEL WSKAZYWANY PRZEZ ITERATOR */
template <class Typ>
void Lista<Typ>::dodaj_przed(iterat<Typ> it, element<Typ> elem)
{
	element<Typ>* a = new element<Typ>;
	//a->nastepny = obecny.wskaznik;
	a->nastepny = it.wskaznik;
	a->wartosc = elem.wartosc;
	a->poprzedni = it.wskaznik->poprzedni;
	it.wskaznik->poprzedni->nastepny = a;
	it.wskaznik->nastepny->poprzedni = a;
	it.wskaznik = a;
	//a->poprzedni = obecny.wskaznik->poprzedni;
	//obecny.wskaznik->poprzedni->nastepny = a;
	//obecny.wskaznik->nastepny->poprzedni = a;
	//obecny.wskaznik = a;
	if (licznik == 1)
	{
		pierwszy.wskaznik = a;
	}
	licznik++;
}



/*********************************************************************************************************************************/
/*FUNKCJA WSTAWIAJACA WEZEL ZA WEZELE WSKAZUJACY PRZEZ ITERATOR */
template <class Typ>
void Lista<Typ>::dodaj_za(iterat<Typ> it, element<Typ> elem)
{
	element<Typ>* a = it.wskaznik;
	element<Typ>* b = new element<Typ>;
	element<Typ>* c = it.wskaznik->nastepny;
	b->nastepny = c;
	b->poprzedni = a;
	b->wartosc = elem.wartosc;
	a->nastepny = b;
	c->poprzedni = b;
	if (b->nastepny == b)
	{
		ostatni.wskaznik = b;
	}
	elem.nastepny = b->nastepny;
	elem.poprzedni = b->poprzedni;
	elem.wartosc = b->wartosc;
	licznik++;
		
}


/*********************************************************************************************************************************/
/*FUNKCJA ZDEJMUJACA WEZEL, NA KTORY WSKAZUJE ITERATOR Z LISTY */
template <class Typ>
void Lista<Typ>::usun(iterat<Typ> it)
{
	//element* b = obecny.wskaznik;
	element<Typ>* b = it.wskaznik;
	element<Typ>* a = b->poprzedni;
	element<Typ>* c = b->nastepny;
	a->nastepny = c;
	c->poprzedni = a;
	if (pierwszy.wskaznik == b)
	{
		pierwszy.wskaznik = c;
	}
	if (ostatni.wskaznik == b)
	{
		ostatni.wskaznik = a;
	}
	licznik--;
}


/*********************************************************************************************************************************/
/*FUNKCJA USUWAJACA PIERWSZY WEZEL */
template <class Typ>
void Lista<Typ>::usun_poczatek()
{
	element<Typ>* a = pierwszy.wskaznik;
	element<Typ>* b = a->nastepny;
	b->poprzedni = b;
	pierwszy.wskaznik = b;
	licznik--;
	delete a;
}


/*********************************************************************************************************************************/
/*FUNKCJA USUWAJACA OSTATNI ELEMENT */
template <class Typ>
void Lista<Typ>::usun_koniec()
{
	element<Typ>* b = ostatni.wskaznik;
	element<Typ>* a = b->poprzedni;
	a->nastepny = a;
	ostatni.wskaznik = a;
	licznik--;
	delete b;
}


/*********************************************************************************************************************************/
/*FUNKCJA WYSWIETLAJACA LISTE DWUKIERUNKOWA */
template <class Typ>
void Lista<Typ>::wyswietl()
{
	iterat<Typ> pom = pierwszy;
	for (int i = 0; i < licznik; i++)
	{
		cout << pom.wskaznik->wartosc << endl;
		pom.wskaznik = pom.wskaznik->nastepny;
	}
}

/*********************************************************************************************************************************/
/*FUNKCJA ZWRACAJACA ITERATOR NA POCZATEK LISTY */
template <class Typ>
iterat<Typ> Lista<Typ>::wskaznik_na_poczatek()
{
	return pierwszy;
}


/*********************************************************************************************************************************/
/*FUNKCJA ZWRACAJACA ITERATOR NA WSKAZANY ELEMENT */
template <class Typ>
iterat<Typ> Lista<Typ>::wskaznik_na_element(element<Typ> a)
{
	iterat<Typ> pom = pierwszy;
	for (int i = 0; 0 < licznik; i++)
	{
		Typ y = pom.wskaznik->wartosc;
		if (y == a.wartosc)
		{
			break;
		}
		else
		{
			pom.wskaznik = pom.wskaznik->nastepny;
		}
	}
	//obecny = pom;
	return pom;
}



/*********************************************************************************************************************************/
/*FUNKCJA ZWRACAJACA ROZMIAR LISTY */
template <class Typ>
int Lista<Typ>::rozmiar()
{
	return licznik;
}


/*********************************************************************************************************************************/
/*FUNKCJA ZWRACAJACA ITERATOR NA NASTEPNY ELEMENT */
template <class Typ>
iterat<Typ> Lista<Typ>::next(iterat<Typ> it)
{
	iterat<Typ> pom;
	pom.wskaznik = it.wskaznik->nastepny;
	return pom;
}


/*********************************************************************************************************************************/
/*FUNKCJA ZWRACAJACA ITERATOR NA POPRZEDNI ELEMENT */
template <class Typ>
iterat<Typ> Lista<Typ>::back(iterat<Typ> it)
{
	iterat<Typ> pom;
	pom.wskaznik = it.wskaznik->poprzedni;
	return it;
}


/*********************************************************************************************************************************/
/*FUNKCJA ZAMIENIAJACA MIEJSCAMI DWIE LISTY */
template <class Typ>
void Lista<Typ>::zamien_miejscami(Lista<Typ> &lis)
{
	Lista<Typ> pom;
	pom.licznik = licznik;
	pom.pierwszy = pierwszy;
	pom.ostatni = ostatni;
	licznik = lis.licznik;
	pierwszy = lis.pierwszy;
	ostatni = lis.ostatni;
	lis = pom;
}


/*********************************************************************************************************************************/
/*PRZECIAZENIE OPERATORA "=" DLA LISTY */
template <class Typ>
iterat<Typ>& Lista<Typ>::operator = (const Lista<Typ> &lis)
{
	licznik = lis.licznik;
	pierwszy = lis.pierwszy;
	ostatni = lis.ostatni;
	return pierwszy;
}


/*********************************************************************************************************************************/
/*KONSTRUKTOR DOMYSLNY*/
template <class Typ>
Lista<Typ>::Lista()
{
	licznik = 0;
	pierwszy.wskaznik = NULL;
	ostatni.wskaznik = NULL;
}


/*********************************************************************************************************************************/
/*KONSTRUKTOR KOPIUJACY DLA LISTY */
template <class Typ>
Lista<Typ>::Lista(Lista<Typ> &lis)
{
	licznik = lis.licznik;
	pierwszy = lis.pierwszy;
	ostatni = lis.ostatni;
}

/*********************************************************************************************************************************/
/*DESTRUKTOR */
template <class Typ>
Lista<Typ>::~Lista()
{
	delete pierwszy.wskaznik;
	delete ostatni.wskaznik;
}
