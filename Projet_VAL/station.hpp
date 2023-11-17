// Projet_VAL.h : fichier Include pour les fichiers Include système standard,
// ou les fichiers Include spécifiques aux projets.

#pragma once
#include <iostream>
#include <string>

class station {
private:
	string name;
	bool enterStation;
	bool readyToGo;
	bool doorsOpen;
	int nb_persQ;

public:
	station();
	station(string, bool, bool, bool, int);
	void print();
	void setA(string);
	void setB(int);

};


station::station() {

}

station::station(string gare, int pop) {
	name = gare;
	nb_persQ = pop;
}


void station::setA(string gare) {
	name = gare;
}

void rame::setB(int pop) {
	nb_persQ = pop;
}


