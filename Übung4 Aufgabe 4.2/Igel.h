#pragma once
#include "Spielfigur.h"					//da Igel von Spielfigur erbt

class igel : public Spielfiegur {
										//hase erbt Name, vorrat, position und vorrat_alt
public:
	igel();								//Konstruktor wo auch Membervariablen initialisiert werden, davon ALLE in der Klasse Spielfigur
	void return_vorrat();				//virtuelle Methode von Spielfigur f�r Igel unentscheident, muss aber �berschrieben werden
	bool ziehe(int felder);				//virtuelle Methode von Spielfigur wird hier �berschrieben nach den Regeln wie Igel zieht
	void getSalat();					//Methode wie Igel wieder Salat erh�lt
};