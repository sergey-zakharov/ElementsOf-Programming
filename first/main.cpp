
#include <iostream>
#include <fstream>
#include "Executer.h"
#include "tester.h"


int main (){

	//std::fstream infile ("input.txt", std::fstream::in);
	//std::fstream outfile ("output.txt", std::fstream::out);

	int x, n;

	//infile >> x >> n;
	std::cin >> x >> n;
	Executer exec(n);
	MyFunction myFunc;
	Tester myTester(x, n, &myFunc);

	std::vector<int> resVect = exec.run(x);
	std::cout << "Loop lenght: " << resVect[0] << std::endl;
	std::cout << "Tail lenght:  " << resVect[1] << std::endl;
	std::cout << "Is everything right: ";
	if ( myTester.run(resVect))
	{
		std::cout << "yes";	
	}
	else 
		std::cout << "no";
 	std::cout<< std::endl;
	
	return 0;
}
