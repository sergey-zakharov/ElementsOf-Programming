#include <iostream>
#include <fstream>
#include <utility>

#include "PrecycleLengthFinderWrapper.h"

void printError(const std::string& name){
	std::cout << name << " x0, n  or x0, x1, n" << std::endl;
}



int main (int argc, char* argv[]){

	if (argc == 4)
	{
		int num = atoi(argv[3]);
		MyFunction myFunc(num);
		PrecycleLengthFinderWrapper<std::pair<int, int> > helper(myFunc);
		std::pair<int, int> p;

		p.first = atoi(argv[1]);
		p.second = atoi(argv[2]);


		helper.run(p);
	}
	else if (argc == 3)
	{	
		int num = atoi(argv[2]);
		MyFunction myFunc(num);
		PrecycleLengthFinderWrapper<int> helper(myFunc);
		int argum = atoi(argv[1]); 
		helper.run(argum);
	}
	else {
		printError(argv[0]);
		exit(1);
	}
return 0;
}

