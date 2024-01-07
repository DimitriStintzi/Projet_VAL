#include "station.hpp"

Station::Station() : name(""), enterStation(false), readyToGo(false), doorsOpen(false), nb_persQ(0) {
}

Station::Station(string stationName, bool dispo, bool pret, bool porte, int NbUsagers, Vector2i pos) : name(stationName), enterStation(dispo), readyToGo(pret), doorsOpen(porte), nb_persQ(NbUsagers), position(pos) {
}


void Station::defNom(string nouveauNom) {
    name = nouveauNom;
}
void Station::EnterStationState(bool Etat) {
    enterStation = Etat;
}
void Station::ReadyToGoState(bool Etat) {
    readyToGo = Etat;
}
void Station::DoorsOpenState(bool Etat) {
    doorsOpen = Etat;
}
void Station::defNbAQuai(int NbUsagers) {
    nb_persQ = NbUsagers;
}

void Station::increasePassengersRandomly() {
    default_random_engine re(chrono::system_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> randomNum{ 0, 20 };
    nb_persQ += randomNum(re);
}

string Station::getName() const {
    return name;
}

int Station::getNbPassengers() const {
    return nb_persQ;
}

bool Station::getStateEnterStation() const {
    return enterStation;
}

bool Station::getStateDoorsOpen() const {
    return doorsOpen;
}

bool Station::getStateReadyToGo() const {
    return readyToGo;
}

Vector2i Station::getPosition() const {
    return position;
}