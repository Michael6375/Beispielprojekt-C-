#pragma once
#include "Spielfigur.h"		
//da Pointer auf Spielfiguren �bergeben werden und auch Methoden von Spielfigur aufgerufen werden

class Spielbrett {
public:
	void frei_ziehen(Spielfiegur *c);		//der Zug kostet die Figur keinen Vorrat
	void ziehe_zur�ck(Spielfiegur *c);		//die Figur muss einen R�ckwertszug machen
	void nochmal_ziehen(Spielfiegur *c);	//die Figur darf nochmal ziehen
};