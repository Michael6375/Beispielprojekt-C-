#pragma once
#include <string>		//für den Namen der Spielfigur

class Spielfiegur {

protected:
	int vorrat_alt;		//falls die Figur für den Zug keinen Vorrat braucht ist der alte hier noch gespeichert
	int position;		//auf welchem Feld befindet sich die Figur
	int vorrat;			//für den aktuellen Vorrat
	std::string Name;	//Name der Figur (Hase oder Igel)

public:
	virtual bool ziehe(int felder);				//virtuell, da bei Hase und Igel unterschiedlich
	int get_position();							//gibt die Position von der Figur wieder
	virtual std::string name();					//methode in der die Figur ihren Namen bekommt virtuell daher, da jede Figur einen anderen Namen hat
	void change();								//um den kostet-nichts-zug zu realisieren
	virtual void return_vorrat(int felder);		//virtuelle Methode, wird abgeleitet aber nur von Hase benutzt um beim Rückwertszug zu seinem
												//Vorrat zu kommen
};