#include "game_of_life.h"
#include <ctime>

bool game_of_life::slucajna_vrijednost()
{
	if (rand() % 4 == 1)		//25% šanse da piksel preživi
		return true;
	else
		return false;
}

bool game_of_life::celija_zauzeta(int i, int j)
{
	//_generacija je tipa bool, ukoliko je *, _generacija je true, inaèe je false
	if (this->_generacija[i][j])
		return true;
	else
		return false;
}

game_of_life::game_of_life()
{
}

void game_of_life::sljedeca_generacija()
{
	int counter;
	//provjeravaj svaki piksel
	for (int row = 0; row < 20; row++) {
		for (int column = 0; column < 40; column++) {
			this->_generacija[row][column] = celija_zauzeta(row, column);		//provjeri da li je æelija zauzeta
			counter = count_neighbours(row, column);		//dohvati broj susjeda od zadanog piksela 
			if ((counter == 2 || counter == 3) && (this->_generacija[row][column] = true))	//preživljava ukoliko je broj susjeda 2 ili 3 živo
				this->_sljedeca_generacija[row][column] = true;
			else if ((counter <= 2 || counter >= 3) && (this->_generacija[row][column] = true))	//umire ukoliko je broj susjeda manji od 2 ili veæi od 3 
				this->_sljedeca_generacija[row][column] = false;
			else if (counter == 3 && (this->_generacija[row][column] = false))	//ukoliko je broj živih susjeda 3, oživi
				this->_sljedeca_generacija[row][column] = true;
		}
	}
}

void game_of_life::iscrtaj(bool pocetak)
{
	//za prvo iscrtavanje
	if (pocetak)
	{
		for (int row = 0; row < 20; row++) {			//za svaki piksel
			for (int column = 0; column < 40; column++) {
				if (slucajna_vrijednost()) {
					this->_generacija[row][column] = true;		//ukoliko je true, oživi piksel
					cout << "*";
				}
				else {
					this->_generacija[row][column] = false;		//ukoliko je false, mrtav piksel 
					cout << "-";
				}
			}
			cout << endl;
		}
	}
	//svako sljedeæe iscrtavanje
	if (!pocetak) {
		for (int row = 0; row < 20; row++) {
			for (int column = 0; column < 40; column++) {
				if (this->_sljedeca_generacija[row][column] == true)			//nacrtaj * ukoliko je živ piksel
					cout << "*";
				else
					cout << "-";
			}
			cout << endl;
		}
	}
}

int game_of_life::count_neighbours(int row, int column)
{
	int counter = 0;
	//skeiraj 8 susjednih piksela oko sebe, kreni od gore-lijevo i završi na dolje-desno
	for (int i = -1; i < 2; i++) {
		for (int j = -1; j < 2; j++) {
			if ((_generacija[i][j] == true) && (_generacija[i][j] != _generacija[row][column]))		//poveæaj brojaè živih ukoliko je susjedni piksel živ, ali isljuèi piksel u sredini, 5.piksel 
				counter++;
		}
	}
	return counter;
}
