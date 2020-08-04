#pragma once
#include <vector>			//für den Vector von Pointern auf Spielfiguren
#include "Spielfigur.h"		//für die Spielfiguren im Vector
#include "Spielbrett.h"		//für die Instanz neuesBrett

class spiel {
private:
	int ziel;										//Spielfeldende
	int _anz_hasen;									//Anzahl von Hasen
	int _anz_igel;									//Anzahl von Igel
	std::vector <Spielfiegur*> Figuren;				//Array in dem Pointer auf alle Spielfiguren gespeichert werden
	Spielbrett neuesBrett;							//Instanz von Spielbrett

public:
	spiel(int felder, int anz_hasen, int anz_igel);	//Konstruktor
	int getZiel();									//gibt Spielfeldende zurück
	int würfle();									//gibt random Zahl zwischen 1 und 6 zurück
	void macheZug();								//sorgt dafür, dass alle Figuren ziehen auch mit Spezialfelder-Zügen
	bool getStand();								//schaut ob eine Spielfigur am Ende ist und bricht das Programm dann ab
};