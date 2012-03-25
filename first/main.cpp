#include <iostream>
#include <fstream>
#include "PrecycleLengthFinderWrapper.h"
#include <utility>

int main (int argc, char* argv[]){
	if (argc == 4)
	{
		int num = atoi(argv[3]);

		PrecycleLengthFinderWrapper<std::pair<int, int> > helper(0, num);
		std::pair<int, int> p;

		p.first = atoi(argv[1]);
		p.second = atoi(argv[2]);
		
		
		helper.run(p);
	}
	else if (argc == 3)
	{	
		int num = atoi(argv[2]);
		PrecycleLengthFinderWrapper<int> helper(1, num);
		int argum = atoi(argv[1]); 
		helper.run(argum);
	}
	else if (argc < 3){
		std::cerr << "Not enough arguments" << std::endl;
		exit(1);
	}
	else if (argc > 3){
		std::cerr << "Too much arguments" << std::endl;
		exit(1);
	}
	
	return 0;
}
