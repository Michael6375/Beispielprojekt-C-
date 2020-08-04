#include <iostream>	//f�r cout
#include "Hase.h"	

int calculate_vorrat(int anzahl);		//Vorw�rtsdeklaration f�r eine Funktion um den Anzug der Karotten zu berechnen

hase::hase()				//Konstruktor
{
	vorrat = 31;			//Initialisierung des Vorrats
	position = 0;			//Position wird auf 0 gesetzt
	fehlversuche = 0;		//fehlversuche wird auf 0 gesetzt
	Name = "Hase";			//Figur bekommt den Name Hase
}

bool hase::ziehe(int felder) {		//�berschriebene Methode ziehe (in Spielfigur virtuell)

	vorrat_alt = vorrat;								//letzten Vorrat in vorrat_alt speichern bevor dieser �berschrieben wird
	int abzug_vorrat = calculate_vorrat(felder);		//abzug_vorrat wird die berechneten abzuziehenden Karotten zugewiesen

	if (vorrat >= abzug_vorrat) {				//hier wird geschaut ob Hase �berhaupt ziehen kann
		vorrat = vorrat - abzug_vorrat;			//wenn ja wird der Vorrat dementsprechend verringert
		position = position + felder;			//zugleich aber auch seine Position erh�hrt
		std::cout << "Position: " << position << " Vorrat: " << vorrat << std::endl; //Textausgabe
		return true;		//Vorzeitiges beenden der Funktion
	}

	else {		//Falls Hase nicht ziehen kann
		std::cout << "hat zu wenig Karotten um zu ziehen" << std::endl;	//Textausgabe
		fehlversuche++;		//fehlversuche wird erh�ht
		if (fehlversuche == 3) {	//wenn fehlversuche = 3
			vorrat = vorrat + getvorrat(felder);	//Hase bekommt zus�tzlichen Vorrat
			position = position - felder;			//geht die gew�rfelten Felder daf�r aber zur�ck
			fehlversuche = 0;						//fehlversuche wird wieder auf 0 gesetzt
		}
		std::cout << "Position: " << position << " Vorrat: " << vorrat << std::endl;	//Textausgabe
		return false;	//Verlassen der Funktion
	}
}

int hase::getvorrat(int felder) {		//um zu erhaltende Karotten zu berechnen
	int _vorrat = felder * 10;			//Formel
	return _vorrat;						//R�ckgabe des Werts
}

void hase::return_vorrat(int felder) {	//falls Hase eienen R�ckwertszug machen muss vom Ereignisfeld aus
	int zusatz = getvorrat(felder);		//Berechnung der zu erhaltenden Karotten
	vorrat = vorrat + zusatz;			//Erh�hung des Vorrats
}


int calculate_vorrat(int felder) {		// weitere Funktion von Hase um den Abzug des Vorrats zu bekommen

	int abzug_vorrat = 0;				//Variable, die den abzuziehenden Wert am Ende zur�ckgibt
	for (int i = 1; i <= felder; i++)	//Berechnung
		abzug_vorrat += i;				//Berechnung
	return abzug_vorrat;				//R�ckgabe
}