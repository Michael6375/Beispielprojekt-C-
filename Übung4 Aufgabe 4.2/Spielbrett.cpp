#include <iostream>
#include "Spielbrett.h"
#include "Spielfigur.h"
#include "Hase.h"
#include "Igel.h"
#include "Spiel.h"

void Spielbrett::frei_ziehen(Spielfiegur *c) {		//Zug kostet nichts
	c->change();		//ruft change-methode von Spielfigur auf und resetet den Vorrat
}

void Spielbrett::nochmal_ziehen(Spielfiegur *c) {	//Figur darf nochmal ziehen
	int anz = rand() % 6 + 1;		//zufällige Zahl zwischen 1 und 6
	c->ziehe(anz);					//Figur zieht nochmal
}

void Spielbrett::ziehe_zurück (Spielfiegur *c) {	//Figur muss zurücksetzen
	int felder = rand() % 6 + 1;		//zahl zwischen 1 und 6

	if (c->name() == "Hase") {			//wenn Hase dann die Methode return_Vorrat (virtuelle Methode von Spielfigur und Methode von Hase)
		c->return_vorrat(felder);
	}
	if (c->name() == "Igel") {			//wenn Igel dann die Methode change (Methode von Spielfigur)
		c->change();
	}

	int hv = felder;				//Hilfsvariable um den Wert zu negieren
	felder = felder - (2 * hv);
	c->ziehe(felder);				//Figur zieht mit einem negativen Wert also Rückwertszug
}