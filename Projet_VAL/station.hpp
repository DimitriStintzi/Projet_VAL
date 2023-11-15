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
	rame(int, int, float, int);
	void print();
	void setA(int, int);
	void setB(float, int);

};


rame::rame() {

}

rame::rame(int s1, int pos, float vit, int peuple) {
	serie = s1;
	position = pos;
	vitesse = vit;
	nb_pers = peuple;
}


void rame::setA(int s1, int pos) {
	serie = s1;
	position = pos;
}

void rame::setB(float vit, int peuple) {
	vitesse = vit;
	nb_pers = peuple;
}


