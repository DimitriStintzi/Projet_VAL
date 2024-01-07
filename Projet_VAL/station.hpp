// Projet_VAL.h : fichier Include pour les fichiers Include système standard,
// ou les fichiers Include spécifiques aux projets.

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

class Station { // Création de la classe station
private: // Définition des variables
    string name; // Le nom de la station
    bool enterStation; // booléen qui défini si le métro arrive en gare ou non (arrive = True)
    bool readyToGo; // booléen qui défini si le métro peut partir (pret = True)
    bool doorsOpen; // booléen qui défini si les portes sont ouvertes ou non (ouverte = True)
    int nb_persQ; // le nombre de personne à quai (seulement les personnes qui attendent le métro
    Vector2i position;

public:
    Station(); // Déclaration du constructeur par défaut
    Station(string stationName, bool dispo, bool pret, bool porte, int NbUsagers, Vector2i pos); // Déclaration du constructeur prenant des paramètres
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