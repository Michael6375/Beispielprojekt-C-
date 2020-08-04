#pragma once
#include "Spielfigur.h"		
//da Pointer auf Spielfiguren übergeben werden und auch Methoden von Spielfigur aufgerufen werden

class Spielbrett {
public:
	void frei_ziehen(Spielfiegur *c);		//der Zug kostet die Figur keinen Vorrat
	void ziehe_zurück(Spielfiegur *c);		//die Figur muss einen Rückwertszug machen
	void nochmal_ziehen(Spielfiegur *c);	//die Figur darf nochmal ziehen
};