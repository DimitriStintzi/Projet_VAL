// Projet_VAL.h�: fichier Include pour les fichiers Include syst�me standard,
// ou les fichiers Include sp�cifiques aux projets.

#pragma once
#include <iostream>
#include <string>
#include <random>
#include <ctime>
#include <thread>
#include <chrono>
#include <vector>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Station { // Cr�ation de la classe station
private: // D�finition des variables
    string name; // Le nom de la station
    bool enterStation; // bool�en qui d�fini si le m�tro arrive en gare ou non (arrive = True)
    bool readyToGo; // bool�en qui d�fini si le m�tro peut partir (pret = True)
    bool doorsOpen; // bool�en qui d�fini si les portes sont ouvertes ou non (ouverte = True)
    int nb_persQ; // le nombre de personne � quai (seulement les personnes qui attendent le m�tro
    Vector2i position;

public:
    Station(); // D�claration du constructeur par d�faut
    Station(string stationName, bool dispo, bool pret, bool porte, int NbUsagers, Vector2i pos); // D�claration du constructeur prenant des param�tres
    void defNom(string NouveauNom);
    void EnterStationState(bool Etat);
    void ReadyToGoState(bool Etat);
    void DoorsOpenState(bool Etat);
    void defNbAQuai(int NbUsagers);
    void increasePassengersRandomly();
    string getName() const;
    int getNbPassengers() const;
    bool getStateEnterStation() const;
    bool getStateReadyToGo() const;
    bool getStateDoorsOpen() const;
    Vector2i getPosition() const;
};