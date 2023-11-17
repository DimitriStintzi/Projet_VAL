#pragma once
#include <iostream>


class rame {
	private : 
		int serie; 
		int nb_pers;

	public :
		rame();
		rame(int, int);
		
		void setA(int);
		void setB(int);
		void set_info();
		int get_A();
		int get_B();
		void get_info();

		rame operator+(const rame&);
};



	
