#include "gra.h"

using namespace std;

void gra::rozgrywka()
{
	wyswietl();
	int gracz=2;
	while (1)
	{
		aktualny = 2;
		graj();
		ruch rch = minmax(1, 0);
		cout << endl << "BIJE " << rch.stal.x << "-" << rch.stal.y << " na " << rch.stoi.x << " - " << rch.stoi.y << endl;
		//cout << "TO: " << Plansza[rch.stal.x][rch.stal.y] << endl;
		//wyswietl();
		rusz_sie(rch, 1);

		cz_damkaK();
		zlicz();
		if (dwojki == 0)
		{
			cout << endl << "WYGRAL GRACZ 1 !!" << endl;
			break;
		}
		if (jedynki == 0)
		{
			cout << endl << "WYGRAL GRACZ 2 !!" << endl;
			break;
		}
		wyswietl();
	}
}