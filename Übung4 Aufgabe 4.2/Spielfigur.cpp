#include <iostream>
#include <string>
#include "Spielfigur.h"
#include "Hase.h"
#include "Igel.h"

bool Spielfiegur::ziehe(int felder) { return true; }	//virtuelle Methode ist in Hase und Igel beschrieben

int Spielfiegur::get_position() {		//zeigt die aktuelle Position der Figur
	return position;
}

std::string Spielfiegur::name() {		//gibt den vergebenen Namen der Figur wieder
	return Name;
}

void Spielfiegur::change() {			//Setzt den Vorrat zurück
	vorrat = vorrat_alt;
}

void Spielfiegur::return_vorrat(int felder) {};		//virtuelle Methode, die nur Hase brauct