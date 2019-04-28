#include <iostream>
#include <string>
#include <fstream>
#include "game_of_life.h"
using namespace std;

int main() {
	game_of_life the_game;
	the_game.pocetak = true;
	bool dalje;
	do {
		the_game.iscrtaj(the_game.pocetak);
		the_game.sljedeca_generacija();

		cout << "Dalje (1/0): ";
		cin >> dalje;
		system("cls");
		the_game.pocetak = false;
	} while (dalje);

	return 0;
}