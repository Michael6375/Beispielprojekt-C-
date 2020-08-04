#pragma once
#include <vector>			//f�r den Vector von Pointern auf Spielfiguren
#include "Spielfigur.h"		//f�r die Spielfiguren im Vector
#include "Spielbrett.h"		//f�r die Instanz neuesBrett

class spiel {
private:
	int ziel;										//Spielfeldende
	int _anz_hasen;									//Anzahl von Hasen
	int _anz_igel;									//Anzahl von Igel
	std::vector <Spielfiegur*> Figuren;				//Array in dem Pointer auf alle Spielfiguren gespeichert werden
	Spielbrett neuesBrett;							//Instanz von Spielbrett

public:
	spiel(int felder, int anz_hasen, int anz_igel);	//Konstruktor
	int getZiel();									//gibt Spielfeldende zur�ck
	int w�rfle();									//gibt random Zahl zwischen 1 und 6 zur�ck
	void macheZug();								//sorgt daf�r, dass alle Figuren ziehen auch mit Spezialfelder-Z�gen
	bool getStand();								//schaut ob eine Spielfigur am Ende ist und bricht das Programm dann ab
};