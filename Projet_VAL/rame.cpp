#include "rame.hpp"
using namespace std;

// Implémentation du constructeur
rame::rame(int numSerie, int nombrePassagers, bool etat) {
    this->size = 1;
    this->serie = new int[1];
    this->passagers = new int[1];
    this->etat = new bool[1];

    this->serie[0] = numSerie;
    this->passagers[0] = nombrePassagers;
    this->etat[0] = etat;
}

// Implémentation méthode de déplacement
void rame::deplacer(float& positionX, float& positionY, float& speed, int& direction, float arretPosX[], float vitesse, sf::RectangleShape& rameShape) {
    bool positionAjustee = false;
    int arretActuel = (positionY == 550 && positionX == 1700) ? 10 : 0;

    while (true) {
        bool tousEnMouvement = true;
        // Vérifiez si tous les objets rame ont etat == true
        for (int i = 0; i < size; ++i) {
            if (!etat[i]) {
                tousEnMouvement = false;
                break;
            }
        }

        if (tousEnMouvement) {

            float distanceRestante = abs(positionX - arretPosX[arretActuel]);

            float vitesseAjustee = vitesse * (2.0 / (1.0 + exp(-0.01 * (distanceRestante - 200))));
            positionX += direction * vitesseAjustee;

            if (distanceRestante < 1.0) {
                chrono::seconds attente(1);
                this_thread::sleep_for(attente);
                arretActuel = (arretActuel + 1) % 20;
            }

            if (positionX > 1700 && !positionAjustee) {
                for (int i = 0; i < 16; i++) {
                    positionY += 6.25;
                    chrono::milliseconds attente(100);
                    this_thread::sleep_for(attente);
                }
                positionAjustee = true;
                direction = -1;
            }
            else if (positionX < 50 && !positionAjustee) {
                for (int i = 0; i < 16; i++) {
                    positionY -= 6.25;
                    chrono::milliseconds attente(100);
                    this_thread::sleep_for(attente);
                }
                positionAjustee = true;
                direction = 1;
            }
            else {
                positionAjustee = false;
            }

            rameShape.setPosition(positionX, positionY);
            this_thread::sleep_for(chrono::milliseconds(32));
        }
    }
}