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
	//Polynome poly, poly2;
	Fraction one2(0,1);//,*/ one2(-12,1), one3(1, 1), one4(-42, 1);
	Fraction two1(1,1), two2(0,1);
	std::vector<Fraction> one;
	std::vector<Fraction> two;

	one.push_back(one2);
	//one.push_back(one1);

	two.push_back(two2);
	two.push_back(two1);

	Polynome poly(one);
	Polynome poly2(two);

	std::cout << poly << std::endl;
	std::cout << poly2 << std::endl << std::endl;
	//Polynome poly3 = poly%poly2;
	Fraction frac(10, 11);
	Fraction zero(0, 11);
//	poly2.setNthCoef(10, frac);
//	poly2.setNthCoef(3, frac);
//	poly2.setNthCoef(3, zero);
//	poly2.normalize();
//	poly2.setNthCoef(13, frac);
  Polynome multResult = poly%poly2;
	std::cout << "multResult: " << multResult << std::endl;
	//std::cout << poly2 << std::endl;
	//std::cout << finder.find(poly1,poly2) << std::endl;
	/*Fraction a(3,5);
	Fraction b(7,8);
	Fraction c = a+b;
	Fraction d = a-b;
	Fraction e = a*b;
	Fraction f = a/b;
	std::cout << "a: " << a << ", b: " << b << ", c: " << c << ", d:"<< d <<"e: " << e << ", f: " <<f << std::endl;
*/
	return 0;
}
