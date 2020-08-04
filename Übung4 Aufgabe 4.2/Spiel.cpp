#include <iostream>		//f�r cin cout
#include <conio.h>		//f�r _getwch() das nachdem jede Spielfigur seinen Zug gemacht hat kurz gewartet wird

/*Spiel.cpp regelt den gesamten Spielablauf und muss somit Zugriff auf alle Elemente haben*/

#include "Spiel.h"
#include "Spielfigur.h"
#include "Spielbrett.h"
#include "Hase.h"
#include "Igel.h"

spiel::spiel(int felder, int anz_hasen, int anz_igel) {	//Konstruktor von der Klasse spiel
	ziel = felder;
	for (int i = 0; i < anz_hasen; i++) {
		Spielfiegur* Hase = new hase;					//Anzahl der Hasen Initialisieren
		Figuren.push_back(Hase);
	}
	for (int i = 0; i < anz_igel; i++) {
		Spielfiegur* Igel = new igel;					//Anzahl der Igel Initialisieren
		Figuren.push_back(Igel);
	}

	_anz_hasen = anz_hasen;								//Anzahl an Hasen als Membervariable f�r Hase1 ...
	_anz_igel = anz_igel;								//Anzahl an Igel als Membervariable f�r Igel1 ...
};

int spiel::getZiel() {
	return ziel;										//gibt das Spielfeldende zur�ck
}

int spiel::w�rfle() {									//Methode um zuf�llig eine Zahl zwischen 1 und 6 zu generieren
	int ziehen = rand() % 6 + 1;
	return ziehen;
}

void spiel::macheZug() {
	for (unsigned short int i = 0; i < Figuren.size(); i++) {	//iteriert �ber jede Spielfigur und l�sst diese dann ziehen
		if ((i+1) <= _anz_hasen) {
			std::cout << "Hase " << (i + 1) << ": ";				//f�r Hasen
		}
		if ((i+1) > _anz_hasen) {
			std::cout << "Igel " << (i + 1 - _anz_hasen) << ": ";	//f�r Igel
		}
		Figuren[i]->ziehe(w�rfle());							//l�sst die I-te Figur ziehen und �bergiebt das gew�rfelte Ergebnis
		
		int choice = 0;
		if (Figuren[i]->get_position() % 3 == 0)	//bei Feld 3, 6, 9, 12, 15 ...
			choice = 1;
		if (Figuren[i]->get_position() % 5 == 0)	//bei Feld 5, 10, 15, 20 ...
			choice = 2;
		if (Figuren[i]->get_position() % 7 == 0)	//bei Feld 7, 14, 21, 28 ...
			choice = 3;

		switch (choice) {
		case 1: {		//Figur darf nochmal ziehen
			if (Figuren[i]->name() == "Hase") {		//Hase darf nocmal ziehen
				std::cout << Figuren[i]->name() << " " << (i + 1) << ": darf nochmal ziehen." << std::endl;
			}
			if (Figuren[i]->name() == "Igel") {		//Igel darf nochmal ziehen
				std::cout << Figuren[i]->name() << " " << (i + 1 - _anz_hasen) << ": darf nochmal ziehen." << std::endl;
			}

			/*unterscheidung daher da es Hase 1,2,3, ... und Igel 1,2,3,... geben kann und alle Spielfiguren in ein Array gepackt werden
			siehe oben auch die Klammern bei Hase ist es das I-te Element + 1 da das Array bei 0 startet. Bei Igel ist es so, dass er
			erst nach dem Hase Implementiert und in das Array gepackt wird hei�t der erste Igel ist i I + 1 - die Anzahl der Hasen*/

			if ((i + 1) <= _anz_hasen) {
				std::cout << "Hase " << (i + 1) << ": ";				//kleine Vorausgabe von Hase
			}
			if ((i + 1) > _anz_hasen) {
				std::cout << "Igel " << (i + 1 - _anz_hasen) << ": ";	//kleine Vorausgabe von Igel
			}
			neuesBrett.nochmal_ziehen(Figuren[i]);	

			/*Hase bzw. Igel zieht nochmal, indem die Methode nochmal_ziehen von der Klasse Spielbrett aufgerufen wird.
			Innerhalb der nochmal_ziehen Methode wird wiederum die Methode ziehe von Spielfigur auferufen und eine zuf�llige Zahl 
			zwischen eins und sechs �bergeben*/

			break;		//verlassen des switch-case nach erfolgreicher Ausf�hrung
		}
		case 2: {		//Zug der Figur kostet nichts
			if (Figuren[i]->name() == "Hase") {		//Hases zug kostet nichts Pr�gen + Ausgabe
				std::cout << Figuren[i]->name() << " " << (i + 1) << ": der Zug kostet nichts." << std::endl;
			}
			if (Figuren[i]->name() == "Igel") {		//Igels Zug kostet nichts Pr�fen + Ausgabe
				std::cout << Figuren[i]->name() << " " << (i + 1 - _anz_hasen) << ": der Zug kostet nichts." << std::endl;
			}

			/*unterscheidung daher da es Hase 1,2,3, ... und Igel 1,2,3,... geben kann und alle Spielfiguren in ein Array gepackt werden
			siehe oben auch die Klammern bei Hase ist es das I-te Element + 1 da das Array bei 0 startet. Bei Igel ist es so, dass er
			erst nach dem Hase Implementiert und in das Array gepackt wird hei�t der erste Igel ist i I + 1 - die Anzahl der Hasen*/

			if ((i + 1) <= _anz_hasen) {		//kleine Vorausgabe von Hase
				std::cout << "Hase " << (i + 1) << ": bekommt seinen alten Vorrat " << std::endl;
			}
			if ((i + 1) > _anz_hasen) {			//kleine Vorausgabe von Igel
				std::cout << "Igel " << (i + 1 - _anz_hasen) << ": bekommt seinen alten Vorrat " << std::endl;
			}

			neuesBrett.frei_ziehen(Figuren[i]);

			/*Die Methode frei_ziehen wird aufgerufen, die sich in Spielbrett.cpp befindet. Diese wiederum ruft eine Change-Methode auf die sich
			in Spielfigur.cpp befindet. Dort sind zwei Variablen Vorrat_alt also vor dem Ausf�hren des Zugs und Vorrat welcher den Vorrat
			nach ausf�hren des Zugs wiedergibt. Der Vorrat wird auf den alten Stand zur�ckgesetzt indem er den Wert von Vorrat_alt bekommt*/

			break;		//verlassen des switch-case nach erfolgreicher Ausf�hrung
		}
		case 3: {		//Figur muss einen R�ckwertszug machen
			if (Figuren[i]->name() == "Hase") {		//Hase muss R�ckwerts ziehen + Ausgabe
				std::cout << Figuren[i]->name() << " " << (i + 1) << ": muss Rueckwerts ziehen." << std::endl;
			}
			if (Figuren[i]->name() == "Igel") {		//Igelmuss R�ckwerts ziehen + Ausgabe
				std::cout << Figuren[i]->name() << " " << (i + 1 - _anz_hasen) << ": muss Rueckwerts ziehen." << std::endl;
			}

			/*unterscheidung daher da es Hase 1,2,3, ... und Igel 1,2,3,... geben kann und alle Spielfiguren in ein Array gepackt werden
			siehe oben auch die Klammern bei Hase ist es das I-te Element + 1 da das Array bei 0 startet. Bei Igel ist es so, dass er
			erst nach dem Hase Implementiert und in das Array gepackt wird hei�t der erste Igel ist i I + 1 - die Anzahl der Hasen*/

			if ((i + 1) <= _anz_hasen) {		//kleine Vorausgabe von Hase
				std::cout << "Hase " << (i + 1) << ": ";
			}
			if ((i + 1) > _anz_hasen) {			//kleine Vorausgabe von Igel
				std::cout << "Igel " << (i + 1 - _anz_hasen) << ": ";
			}
			neuesBrett.ziehe_zur�ck(Figuren[i]);

			/*hier wird die Methode ziehe_zur�ck von Spielbrett aufefrufen. Dort wird erst eine Zufallszahl zwischen 1 und 6 erzeugt.
			Danach wird wieder zwischen Hase und Igel unterschieden, denn Hase bekommt f�r jedes Feld, dass er R�ckwerts l�uft 10
			Karotten und Hase bekommt im Spiel nur seinen alten Vorrat wieder. Hase ruft somit die virtuelle Methode return_vorrat
			von Spielfigur auf wodurch er zu hase.cpp weitergeleitet wird, wo sein Vorrat erh�ht wird. Igel jedoch ruft lediglich die
			Methode change von Spielfigur.cpp auf um seinen alten Vorrat zu erhalten. danach wird mittels 2er Variablen den Wert den 
			die Spielfigur eigentlich h�tte ziehen sollen negiert und und der Methode ziehe �bergeben*/

			break;				//verlassen des switch-case nach erfolgreicher Ausf�hrung
		}
		default: break;			//falls kein Ereignisfeld getroffen wird
		}
		choice = 0;				//variable choice zur�cksetzen sonst wird immer ein Ereignisfeld getroffen
	}
	_getwch();					//alle Spielfiguren durften einmal ziehen und es wird auf ein Tastendruck gewartet
	std::cout << std::endl;		//zeilenumbruch f�r eine Leerzeile zwischen den Z�gen
}

bool spiel::getStand() {		//Methode von Spiel um zu sehen ob eine Spielfigur schon das Ziel erreicht hat

	for (unsigned int i = 0; i < Figuren.size(); i++) {		//es wird �ber alle Spielfiguren iteriert
		if (Figuren[i]->get_position() >= ziel) {			//Falls eine auf oder �ber dem Ziel ist
			if ((i + 1) <= _anz_hasen) {					//F�r den Hase
				std::cout << "Hase " << (i + 1) << " hat das Ziel als erstes erreicht." << std::endl;
				return true;								//hier wird die Funktion vorzeitig beendet
			}
			if ((i + 1) > _anz_hasen) {						//F�r den Igel
				std::cout << "Igel " << (i + 1 - _anz_hasen) << " hat das Ziel als erstes erreicht." << std::endl;
				return true;								//hier wird die Funktion vorzeitig beendet
			}
		}
	}
	return false;	//falls niemand das Spiel gewonnen hat wird false returnt
}