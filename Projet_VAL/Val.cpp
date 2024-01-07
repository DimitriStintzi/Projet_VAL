#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include <iostream>
#include <thread>
#include <cmath>
#include <vector>
#include "rame.hpp"
#include "station.hpp"

using namespace sf;
using namespace std;

#define size 10


int main() {
    RenderWindow window(VideoMode(2100, 800), "Panneau de contrôle du VAL", Style::Fullscreen);

    Font font;
    if (!font.loadFromFile("arial.ttf")) {
        cerr << "Erreur lors du chargement de la police" << endl;
        return EXIT_FAILURE;
    }

    int lastClickedStationIndex = -1; // Variable pour suivre la dernière station cliquée
    int lastClickedRameIndex = -1; // Variable pour suivre la dernière rame cliquée


    // Création de plusieurs stations
    Station station1A("Station A aller", false, false, false, 0, Vector2i(150, 440));
    Station station2A("Station B aller", false, false, false, 0, Vector2i(300, 440));
    Station station3A("Station C aller", false, false, false, 0, Vector2i(450, 440));
    Station station4A("Station D aller", false, false, false, 0, Vector2i(600, 440));
    Station station5A("Station E aller", false, false, false, 0, Vector2i(750, 440));
    Station station6A("Station F aller", false, false, false, 0, Vector2i(900, 440));
    Station station7A("Station G aller", false, false, false, 0, Vector2i(1050, 440));
    Station station8A("Station H aller", false, false, false, 0, Vector2i(1200, 440));
    Station station9A("Station I aller", false, false, false, 0, Vector2i(1350, 440));
    Station station10A("Station J aller", false, false, false, 0, Vector2i(1500, 440));

    Station station10R("Station A retour", false, false, false, 0, Vector2i(150, 540));
    Station station9R("Station B retour", false, false, false, 0, Vector2i(300, 540));
    Station station8R("Station C retour", false, false, false, 0, Vector2i(450, 540));
    Station station7R("Station D retour", false, false, false, 0, Vector2i(600, 540));
    Station station6R("Station E retour", false, false, false, 0, Vector2i(750, 540));
    Station station5R("Station F retour", false, false, false, 0, Vector2i(900, 540));
    Station station4R("Station G retour", false, false, false, 0, Vector2i(1050, 540));
    Station station3R("Station H retour", false, false, false, 0, Vector2i(1200, 540));
    Station station2R("Station I retour", false, false, false, 0, Vector2i(1350, 540));
    Station station1R("Station J retour", false, false, false, 0, Vector2i(1500, 540));

    // Lancement des threads pour augmenter les passagers de manière aléatoire dans chaque station
    thread increaseThread1A([&station1A]() { station1A.increasePassengersRandomly(); });
    thread increaseThread2A([&station2A]() { station2A.increasePassengersRandomly(); });
    thread increaseThread3A([&station3A]() { station3A.increasePassengersRandomly(); });
    thread increaseThread4A([&station4A]() { station4A.increasePassengersRandomly(); });
    thread increaseThread5A([&station5A]() { station5A.increasePassengersRandomly(); });
    thread increaseThread6A([&station6A]() { station6A.increasePassengersRandomly(); });
    thread increaseThread7A([&station7A]() { station7A.increasePassengersRandomly(); });
    thread increaseThread8A([&station8A]() { station8A.increasePassengersRandomly(); });
    thread increaseThread9A([&station9A]() { station9A.increasePassengersRandomly(); });
    thread increaseThread10A([&station10A]() { station10A.increasePassengersRandomly(); });

    thread increaseThread1R([&station1R]() { station1R.increasePassengersRandomly(); });
    thread increaseThread2R([&station2R]() { station2R.increasePassengersRandomly(); });
    thread increaseThread3R([&station3R]() { station3R.increasePassengersRandomly(); });
    thread increaseThread4R([&station4R]() { station4R.increasePassengersRandomly(); });
    thread increaseThread5R([&station5R]() { station5R.increasePassengersRandomly(); });
    thread increaseThread6R([&station6R]() { station6R.increasePassengersRandomly(); });
    thread increaseThread7R([&station7R]() { station7R.increasePassengersRandomly(); });
    thread increaseThread8R([&station8R]() { station8R.increasePassengersRandomly(); });
    thread increaseThread9R([&station9R]() { station9R.increasePassengersRandomly(); });
    thread increaseThread10R([&station10R]() { station10R.increasePassengersRandomly(); });

    vector<Station> stations = { station1A, station2A, station3A, station4A, station5A, station6A, station7A, station8A, station9A, station10A, station1R, station2R, station3R, station4R, station5R, station6R, station7R, station8R, station9R, station10R };

    // Fonction pour la mise à jour des passagers
    auto updatePassengers = [](Station& station) {
        while (true) {
            station.increasePassengersRandomly();
            this_thread::sleep_for(chrono::seconds(5));
        }
        };

    // Création des threads pour chaque station
    vector<thread> threadsStation;


    // Initialisation des rames
    RectangleShape rameShapes[size];
    float ramePosX[size];
    float ramePosY[size];
    int sens[size];
    float rameSpeed[size];
    float v = 4.0;

    // Initialisation des positions des rames
    for (int i = 0; i < size; i++) {
        rameShapes[i].setSize(Vector2f(50, 30));
        rameShapes[i].setFillColor(Color::Blue);

        if (i < size) {
            ramePosX[i] = 50;
            ramePosY[i] = 450;
            sens[i] = 1;
        }

        rameSpeed[i] = v * sens[i];
    }
    // Création de l'objet rame
    rame rameObjects[size] = {
        rame(123, 20, true),
        rame(456, 30, true),
        rame(789, 15, true),
        rame(987, 25, true),
        rame(654, 40, true),
        rame(321, 10, true),
        rame(147, 35, true),
        rame(258, 22, true),
        rame(369, 18, true),
        rame(999, 50, true)
    };
    vector<rame> rames = {
        rameObjects[0], rameObjects[1], rameObjects[2], rameObjects[3], rameObjects[4],
        rameObjects[5], rameObjects[6], rameObjects[7], rameObjects[8], rameObjects[9]
    };


    float arretPosX[20];
    // Boucle pour vérifier si une rame est sur chaque station
    for (auto& station : stations) {
        bool rameSurStation = false;

        for (int i = 0; i < size; ++i) {
            if (fabs(ramePosX[i] - station.getPosition().x) < 50.0) {
                // Une rame est sur cette station
                rameSurStation = true;
                break;
            }
        }

        // Si aucune rame n'est sur cette station, définir EnterStationState sur false
        if (!rameSurStation) {
            station.EnterStationState(false);
        }
    }

    // Initialisation des positions des arrêts
    for (int i = 0; i < 10; i++) {
        arretPosX[i] = 150 + i * 150;
    }

    for (int i = 0; i < 10; i++) {
        arretPosX[i + 10] = 1500 - i * 150;
    }

    RectangleShape arretBars[20];

    // Initialisation des formes des arrêts
    for (int i = 0; i < 20; i++) {
        arretBars[i].setPosition(stations[i].getPosition().x, stations[i].getPosition().y);
    }


    // Création des threads de déplacement des rames
    thread threads[size];


    for (int i = 0; i < size; i++) {
        threads[i] = thread(&rame::deplacer, &rameObjects[i], ref(ramePosX[i]), ref(ramePosY[i]), ref(rameSpeed[i]), ref(sens[i]), arretPosX, v, ref(rameShapes[i]));
    }


    // Ajoutez une variable pour indiquer si les rames doivent être arrêtées
    bool stopTrains[size] = { false };

    // Créez un bouton d'arrêt
    RectangleShape stopButton(Vector2f(100, 50));
    stopButton.setFillColor(Color::Red);
    stopButton.setPosition(1050, 700);

    // Créez un tableau de VertexArray pour les lignes reliant les arrêts
    VertexArray lines(LinesStrip, 22);

    RectangleShape infoRect(Vector2f(200, 150)); // Rectangle pour les informations des stations
    RectangleShape rameInfoRect(Vector2f(200, 150)); // Rectangle pour les informations des rames


    // Ajout de la croix pour fermer les informations de la station
    ConvexShape closeCross(4); // Utilisation de 4 points pour créer une croix

    // Configuration des points pour former une croix
    closeCross.setPoint(0, Vector2f(0, 0));
    closeCross.setPoint(1, Vector2f(10, 10));
    closeCross.setPoint(2, Vector2f(0, 10));
    closeCross.setPoint(3, Vector2f(10, 0));

    closeCross.setFillColor(Color::Transparent); // Couleur de remplissage transparente
    closeCross.setOutlineColor(Color::Red); // Couleur de la croix
    closeCross.setOutlineThickness(2.0f); // Épaisseur de la ligne

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
            // Détecter les clics de souris
            if (event.type == Event::MouseButtonPressed) {
                if (event.mouseButton.button == Mouse::Left) {
                    // Récupérer les coordonnées du clic
                    Vector2i mousePos = Mouse::getPosition(window);

                    // Vérifier si le clic est sur une station
                    for (int i = 0; i < 20; ++i) {
                        FloatRect stationBounds(stations[i].getPosition().x, stations[i].getPosition().y, 50, 50);
                        if (stationBounds.contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                            // Clic détecté sur la station, mettre à jour la dernière station cliquée
                            lastClickedStationIndex = static_cast<int>(i);
                        }
                    }

                    // Vérifier si le clic est sur une rame
                    for (int i = 0; i < size; ++i) {
                        FloatRect rameBounds(ramePosX[i], ramePosY[i], 50, 30); // Modifier les dimensions selon les rames
                        if (rameBounds.contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                            // Clic détecté sur la rame i
                            lastClickedRameIndex = i;
                        }
                    }


                    if (lastClickedStationIndex != -1) {
                        // Vérifie si le clic est sur la croix de la fenêtre d'information de la station
                        FloatRect closeBounds(infoRect.getPosition().x + infoRect.getSize().x - 15, infoRect.getPosition().y, 15, 15);
                        if (closeBounds.contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                            lastClickedStationIndex = -1; // Réinitialise l'index de la station sélectionnée
                        }
                    }

                    if (lastClickedRameIndex != -1) {
                        // Vérifie si le clic est sur la croix de la fenêtre d'information de la rame
                        FloatRect closeBounds(rameInfoRect.getPosition().x + rameInfoRect.getSize().x - 15, rameInfoRect.getPosition().y, 15, 15);
                        if (closeBounds.contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                            lastClickedRameIndex = -1; // Réinitialise l'index de la rame sélectionnée
                        }
                    }
                }
            }
            if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
                Vector2f mousePos = window.mapPixelToCoords(Mouse::getPosition(window));
                if (stopButton.getGlobalBounds().contains(mousePos)) {
                    for (int i = 0; i < size; ++i) {
                        stopTrains[i] = !stopTrains[i];
                        rameObjects[i].depla(0, !stopTrains[i]);
                    }
                }
            }
            for (int i = 0; i < size; ++i) {
                // Récupérer l'index de la station où la rame est à l'arrêt
                int stationIndex = -1;
                for (int j = 0; j < 20; ++j) {
                    if (fabs(ramePosX[i] - stations[j].getPosition().x) < 1.0) {
                        stationIndex = j;
                        break;
                    }
                }

                // Si la rame est à l'arrêt sur une station
                if (stationIndex != -1) {
                    int passagersStation = stations[stationIndex].getNbPassengers();
                    int passagersRame = rameObjects[i].getNombrePassagers();
                    int espaceDisponibleDansRame = 300 - passagersRame;

                    // Enlever un nombre aléatoire de passagers de la rame avant l'ajout de nouveaux passagers
                    int passagersEnleves = rand() % passagersRame; // Nombre aléatoire entre 0 et le nombre actuel de passagers dans la rame
                    rameObjects[i].defPassagersRame(passagersRame - passagersEnleves);

                    // Ajouter de nouveaux passagers selon l'espace disponible
                    if (passagersStation > espaceDisponibleDansRame) {
                        // Transférer autant de passagers que possible dans la rame
                        rameObjects[i].defPassagersRame(passagersRame + espaceDisponibleDansRame);
                        stations[stationIndex].defNbAQuai(passagersStation - espaceDisponibleDansRame);
                    }
                    else {
                        // Transférer tous les passagers de la station dans la rame
                        rameObjects[i].defPassagersRame(passagersRame + passagersStation);
                        stations[stationIndex].defNbAQuai(0);
                    }
                    stations[stationIndex].EnterStationState(true);
                }
            }
        }

        window.clear();


        // Dessiner les rectangles pour chaque station
        for (const auto& station : stations) {
            RectangleShape stationShape(Vector2f(50, 50)); // Taille des rectangles pour les stations

            // Vérifier si enterStation est true pour cette station
            if (station.getStateEnterStation()) {
                stationShape.setFillColor(Color::Red); // Couleur rouge si enterStation est true
            }
            else {
                stationShape.setFillColor(Color::Green); // Couleur verte par défaut
            }

            stationShape.setPosition(station.getPosition().x, station.getPosition().y);
            window.draw(stationShape);
        }



        // Dessine le bouton d'arrêt
        window.draw(stopButton);

        // Dessine la ligne reliant les arrêts
        for (int i = 0; i < 20; i++) {
            arretBars[i].setPosition(stations[i].getPosition().x, stations[i].getPosition().y);

            // Mettez à jour les positions pour dessiner les lignes reliant les arrêts
            if (i < 10) {
                lines[i + 1].position = Vector2f(stations[i].getPosition().x + 25, 465); // Mettez à jour Y selon votre besoin
            }
            else {
                lines[i + 1].position = Vector2f(stations[i].getPosition().x + 25, 565); // Mettez à jour Y selon votre besoin
            }
        }

        // Dessine la ligne reliant les arrêts
        lines[0].position = Vector2f(70, 465);
        lines[11].position = Vector2f(1725, 465);
        lines[12].position = Vector2f(1725, 565);
        lines[20].position = Vector2f(70, 565);
        lines[21].position = Vector2f(70, 465);

        for (int i = 0; i < 22; i++) {
            lines[i].color.a = 100;  // Changez l'opacité des lignes (0 à 255)
            lines[i].color.r = 255;  // Rouge (0 à 255)
            lines[i].color.g = 200;    // Vert (0 à 255)
            lines[i].color.b = 20;    // Bleu (0 à 255)
        }

        window.draw(lines);


        // Dessine les rames
        for (int i = 0; i < size; i++) {
            rameShapes[i].setPosition(ramePosX[i], ramePosY[i]);
            window.draw(rameShapes[i]);
        }
        for (int i = 1; i < size; i++) {
            if (abs(ramePosX[i] - ramePosX[i - 1]) < 120) {
                rameObjects[i].depla(0, false);
            }
            else {
                rameObjects[i].depla(0, true);
            }
        }


        if (lastClickedStationIndex != -1) {
            const Station& lastClickedStation = stations[lastClickedStationIndex];

            // Dessiner les rectangles pour afficher les informations de la station
            infoRect.setFillColor(Color::Black); // Couleur de fond du rectangle
            infoRect.setOutlineColor(Color::White); // Couleur de la bordure du rectangle
            infoRect.setOutlineThickness(2.0f); // Épaisseur de la bordure
            infoRect.setPosition(1719, 925); // Position ajustée pour afficher les informations
            window.draw(infoRect);

            Text stationInfoText;
            stationInfoText.setFont(font);
            stationInfoText.setCharacterSize(16);
            stationInfoText.setFillColor(Color::White); // Couleur du texte
            stationInfoText.setPosition(1722, 940);

            string EtatPorte = "Fermée";
            if (lastClickedStation.getStateDoorsOpen()) {
                EtatPorte = "Ouverte";
            }
            string ReadyGo = "Non";
            if (lastClickedStation.getStateReadyToGo()) {
                ReadyGo = "Oui";
            }

            stationInfoText.setString(
                lastClickedStation.getName() + "\n\n\nUsagers en attente: " + to_string(lastClickedStation.getNbPassengers()) +
                "\nPorte : " + EtatPorte + "\nPret a partir : " + ReadyGo
            );
            closeCross.setPosition(infoRect.getPosition().x + infoRect.getSize().x - 15, infoRect.getPosition().y);
            window.draw(closeCross);
            window.draw(stationInfoText);
        }

        // Dessiner les informations pour la rame sélectionnée (si une rame est sélectionnée)
        if (lastClickedRameIndex != -1) {
            const rame& lastClickedRame = rames[lastClickedRameIndex];

            // Créez et dessinez le rectangle d'information
            // Utilisez les méthodes getNumSerie(), getNombrePassagers() et estEnMouvement() de la classe rame pour obtenir les informations
            rameInfoRect.setFillColor(Color::Black);
            rameInfoRect.setOutlineColor(Color::White);
            rameInfoRect.setOutlineThickness(2.0f);
            rameInfoRect.setPosition(10, 925);
            window.draw(rameInfoRect);

            Text rameInfoText;
            rameInfoText.setFont(font);
            rameInfoText.setCharacterSize(16);
            rameInfoText.setFillColor(Color::White);
            rameInfoText.setPosition(13, 940);

            int numSerie = lastClickedRame.getNumSerie();
            int nbPassagers = lastClickedRame.getNombrePassagers();
            bool enMouvement = lastClickedRame.estEnMouvement(lastClickedRameIndex);

            rameInfoText.setString(
                "Rame " + to_string(numSerie) + "\n\n\nPassagers: " + to_string(nbPassagers) +
                "\nEn mouvement : " + (enMouvement ? "Oui" : "Non")
            );
            closeCross.setPosition(rameInfoRect.getPosition().x + rameInfoRect.getSize().x - 15, rameInfoRect.getPosition().y);
            window.draw(closeCross);
            window.draw(rameInfoText);
        }



        window.display();
    }

    // Attend la fin de tous les threads
    for (int i = 0; i < size; i++) {
        threads[i].join();
    }

    for (auto& thread : threadsStation) {
        thread.join();
    }

    increaseThread1A.join();
    increaseThread2A.join();
    increaseThread3A.join();
    increaseThread4A.join();
    increaseThread5A.join();
    increaseThread6A.join();
    increaseThread7A.join();
    increaseThread8A.join();
    increaseThread9A.join();
    increaseThread10A.join();

    increaseThread1R.join();
    increaseThread2R.join();
    increaseThread3R.join();
    increaseThread4R.join();
    increaseThread5R.join();
    increaseThread6R.join();
    increaseThread7R.join();
    increaseThread8R.join();
    increaseThread9R.join();
    increaseThread10R.join();

    return 0;
}