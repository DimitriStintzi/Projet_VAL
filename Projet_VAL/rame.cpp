#include <iostream>
#include <fstream>
using namespace std;
#include "rame.hpp"

rame::rame() {

}

rame::rame(int Snum, int usagers) {
	serie = Snum;
	nb_pers = usagers;
}

void rame::setA(int Snum) {
	serie = Snum;
}

void rame::setB(int usagers) {
	nb_pers = usagers;
}

void rame::set_info() {
	cout << "Entrez les informations : " << endl;
	cin >> serie >> nb_pers;
}


int rame::get_A() {
	return serie;
}

int rame::get_B() {
	return nb_pers;
}

void rame::get_info() {
	cout << "(serie = " << serie << ", nb_pers = " << nb_pers << ")" << endl;
}



rame rame::operator+(const rame& other)
{
	rame result;
	result.serie = this->serie + other.serie;
	result.nb_pers = this->nb_pers + other.nb_pers;
	return result;
};

int main() {
	rame tr1;
	tr1.set_info();
	tr1.get_info();

	rame tr2;
	tr2.set_info();
	tr2.get_info();

	rame tr3;
	tr3 = tr2 + tr1;
	tr3.get_info();




}