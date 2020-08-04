#pragma once
#include "Spielfigur.h"

class hase : public Spielfiegur {			//hase erbt Name, vorrat, position und vorrat_alt
private:

	int fehlversuche;						//hat speziell nur hase für den 3 Fehlversuch macht er einen Rückwertszug

public:
	hase();									//Konstruktor wo auch Membervariablen initialisiert werden, davon welche in der Klasse Spielfigur
	bool ziehe(int felder);					//Funktion ziehen von Hase 
	void return_vorrat(int felder);			//Funktion die die Anzahl vom Vorrat überschreibt und die Funktion getvorrat dabei nutzt
	int getvorrat(int felder);				//berechnet dazukommende Karotten beim Rückwertszug
};