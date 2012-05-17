
#include "Polynome.h"
#include "Fraction.h"

#ifndef TESTER_H_
#define TESTER_H_

class Tester{

public:
	int run(int);
};

int Tester::run(int nTimes){
	srand(time(NULL));

	for (int i=0; i<nTimes; i++)
	{
		Fraction first(rand%100, rand%100+1);
		Fraction second(rand%100, rand%100+1);

	}

	return 0;
}

#endif /* TESTER_H_ */
