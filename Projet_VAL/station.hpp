// Projet_VAL.h : fichier Include pour les fichiers Include système standard,
// ou les fichiers Include spécifiques aux projets.

#pragma once
#include <iostream>


class station {
private:
	char name; 
	bool enterStation;
	bool readyToGo;
	bool doorsOpen;
	int nb_persQ;

public:
	station();
	station(char, bool, bool, bool, int);
	void print();
	void setA(char);
	void setB(int);

};


station::station() {

}

station:station(char gare, int pop) {
	name = gare;
	nb_persQ = pop;
}


void station:setA(char gare) {
	name = gare;
}

void rame:setB(int pop) {
	nb_persQ = pop;
}


