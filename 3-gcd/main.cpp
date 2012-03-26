#include <iostream>
#include <cstdlib>

#include "GSDFinder.h"
#include "Integer.h"

int main(){

	GSDFinder<Integer> finder;
	Integer a,b;

	srand(time(NULL));
	a = rand()%32563;
	b = rand()%32563;
	

	std::cout << a << " "<< b << std::endl;
	std::cout << finder.find(a,b) << std::endl;


	return 0;
}
