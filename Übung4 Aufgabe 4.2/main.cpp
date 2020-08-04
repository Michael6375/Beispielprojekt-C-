#include <iostream>
#include <time.h>		//für srand(time(NULL))

#include "Hase.h"
#include "Igel.h"
#include "Spiel.h"

int main() {			

	srand(time(NULL));	//sorgt für Zufall

	int felder, anz_hasen, anz_igel;

	std::cout << "Wie viele Felder soll das Spiel haben? ";
	std::cin >> felder;
	std::cout << "Wie viele Hasen sollen mitspielen? ";
	std::cin >> anz_hasen;
	std::cout << "Wie viele Igel sollen mitspielen? ";
	std::cin >> anz_igel;

	spiel NeuesSpiel(felder, anz_hasen, anz_igel);		//Objekt NeuesSpiel mit Übergababeparameter wie viel Felder Hasen und Igel

	do {
		NeuesSpiel.macheZug();				//wiederholung von machezug bis
	} while (!NeuesSpiel.getStand());		//eine Figur im Ziel ist

	std::cout << std::endl << std::endl;
	system("pause");
	return 0;
}