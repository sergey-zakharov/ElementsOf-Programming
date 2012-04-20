#pragma once

#include <iostream>
#include <cstdlib>
#include <vector>

#include "GSDFinder.h"
#include "Integer.h"
#include "Polynome.h"
#include "Fraction.h"

int main(){

	GSDFinder<Polynome> finder;
	//Integer a,b;
	
	int n;

	//srand(time(NULL));
	Polynome poly;
	poly.generate();
	std::cout << poly << std::endl;
	//std::cout << a << " "<< b << std::endl;
	//std::cout << finder.find(poly1,poly2) << std::endl;
	//Fraction a(3,5);
	//Fraction b(7,8);
	//Fraction c = a+b;
	//Fraction d = a-b;
	//Fraction e = a*b;
	//Fraction f = a/b;
	//std::cout << c << " " << d << " " << e << " " << f;

	return 0;
}
