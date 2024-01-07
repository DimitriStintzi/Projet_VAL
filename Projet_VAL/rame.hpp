#pragma once

#include <iostream>
#include <thread>
#include <chrono>
#include <cmath>
#include <SFML/Graphics.hpp>

using namespace std;

class rame {
private:
    int* serie;
    int* passagers;
    bool* etat;  // Tableau de booléens pour l'état de chaque rame

public:
    int size;

    rame(int numSerie, int nombrePassagers, bool etat);

    int getNombrePassagers() const { return passagers[0]; }
    int getNumSerie() const { return serie[0]; }
    void defPassagersRame(int NbUsagers) { *passagers = NbUsagers; };

    void deplacer(float& positionX, float& positionY, float& speed, int& direction, float arretPosX[], float vitesse, sf::RectangleShape& rameShape);

    void depla(int index, bool activer) { etat[index] = activer; }
    bool estEnMouvement(int index) const { return etat[index]; }
};