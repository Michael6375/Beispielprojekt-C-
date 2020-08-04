#include <iostream>		//für cout
#include "Igel.h"

igel::igel() {		//Konstruktor von igel
	vorrat = 10;	//Initialisierung des Vorrats
	position = 0;	//setze Position auf 0
	Name = "Igel";	//Figur heißt Igel
}

bool igel::ziehe(int felder) {		//Methode von igel zum ziehen (in Spielfigur virtuell)

	vorrat_alt = vorrat;			//speichere Vorrat in vorrat_alt

	if (vorrat >= felder) {					//kann igel ziehen
		vorrat = vorrat - felder;			//wenn ja vorrat reduzieren
		position = position + felder;		//und Position erhöhen
		std::cout << "Position: " << position << " Vorrat: " << vorrat << std::endl;	//Textausgabe
		return true;	//Beende Funktion
	}
	else               //falls Igel nicht ziehen kann
	{
		if (vorrat == 0) {		//hat Igel genau keinen Vorrat meht
			this->getSalat();	//erhält er wieder eienen
		}
		std::cout << "Position: " << position << " Vorrat: " << vorrat << std::endl;	//Textausgabe
		return false;		//Beende Funktion
	}
}

void igel::getSalat() {		//Methode die Igels Vorrat wieder auffüllt
	vorrat = 10;			//Vorrat erhöhen
}

void igel::return_vorrat() {}	//Methode, die in Spielfigur virtuell ist, daher überschrieben werden muss aber nur bei Hase 
								//zum Einsatz kommt