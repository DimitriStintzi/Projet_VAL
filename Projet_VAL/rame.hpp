// Projet_VAL.h : fichier Include pour les fichiers Include système standard,
// ou les fichiers Include spécifiques aux projets.

#pragma once
#include <iostream>

class rame {
	private : 
		int serie;
		int position; //faire un tableau de départ/arrivée
		float vitesse;		
		bool doorsOpen;
		int nb_pers;

public :
	rame();
	rame(int, int, float, int);
	void print();
	void setA(int, int);
	void setB(float, int);

};


rame::rame() {

}

rame::rame(int s1, int pos, float vit, int usagers) {
	serie = s1;
	position = pos;
	vitesse = vit;
	nb_pers = usagers;
}


void rame::setA(int s1, int pos) {
	serie = s1;
	position = pos;
}

void rame::setB(float vit, int usagers) {
	vitesse = vit;
	nb_pers = usagers;
}

	
